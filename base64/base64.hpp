#ifndef BASE64_HPP_
#define BASE64_HPP_

#include<vector>
#include<string>
#include <stdexcept>
static const unsigned char Base64EncodeMap[64] =
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};
static unsigned char Base64DecodeMap[256] =
{
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x3E, 0xFF, 0xFF, 0xFF, 0x3F,
    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF,
    0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
    0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E,
    0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
    0x17, 0x18, 0x19, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
    0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30,
    0x31, 0x32, 0x33, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
class Base64Encrypt
{
public:
    Base64Encrypt() : _groupLength(0) {}
    Base64Encrypt(const void* input, size_t length) : Base64Encrypt()
    {
        Update(input, length);
    }

    void Update(const void* input, size_t length)
    {
        static const size_t LEN = 3;
        _buf.reserve(_buf.size() + (length - (LEN - _groupLength) + LEN - 1) / LEN * 4 + 1);
        const unsigned char* buff = reinterpret_cast<const unsigned char*>(input);
        unsigned int i;

        for (i = 0; i < length; ++i)
        {
            _group[_groupLength++] = buff[i];
            if (_groupLength == LEN)
            {
                Encode();
            }
        }
    }
    const unsigned char* CipherText()
    {
        Final();
        return _buf.data();
    }
    std::string GetString()
    {
        const char* pstr = (const char*) CipherText();
        size_t length = GetSize();
        return std::string(pstr, length);
    }
    void Reset()
    {
        _buf.clear();
        _groupLength = 0;
        for (unsigned int i = 0; i < sizeof(_group) / sizeof(_group[0]); ++i)
        {
            _group[i] = 0;
        }
    }
    size_t GetSize()
    {
        CipherText();
        return _buf.size();
    }

private:
    Base64Encrypt(const Base64Encrypt&) = delete;
    Base64Encrypt& operator = (const Base64Encrypt&) = delete;

    void Encode()
    {
        unsigned char index;

        // 0 index byte
        index = _group[0] >> 2;
        _buf.push_back(Base64EncodeMap[index]);
        // 1 index byte
        index = ((_group[0] & 0x03) << 4) | (_group[1] >> 4);
        _buf.push_back(Base64EncodeMap[index]);
        // 2 index byte
        index = ((_group[1] & 0x0F) << 2) | (_group[2] >> 6);
        _buf.push_back(Base64EncodeMap[index]);
        // 3 index byte
        index = _group[2] & 0x3F;
        _buf.push_back(Base64EncodeMap[index]);

        _groupLength = 0;
    }
    void Final()
    {
        unsigned char index;

        if (_groupLength == 1)
        {
            _group[1] = 0;
            // 0 index byte
            index = _group[0] >> 2;
            _buf.push_back(Base64EncodeMap[index]);
            // 1 index byte
            index = ((_group[0] & 0x03) << 4) | (_group[1] >> 4);
            _buf.push_back(Base64EncodeMap[index]);
            // 2 index byte
            _buf.push_back('=');
            // 3 index byte
            _buf.push_back('=');
        } else if (_groupLength == 2)
        {
            _group[2] = 0;
            // 0 index byte
            index = _group[0] >> 2;
            _buf.push_back(Base64EncodeMap[index]);
            // 1 index byte
            index = ((_group[0] & 0x03) << 4) | (_group[1] >> 4);
            _buf.push_back(Base64EncodeMap[index]);
            // 2 index byte
            index = ((_group[1] & 0x0F) << 2) | (_group[2] >> 6);
            _buf.push_back(Base64EncodeMap[index]);
            // 3 index byte
            _buf.push_back('=');
        }

        _groupLength = 0;
    }

private:
    std::vector<unsigned char> _buf;
    unsigned char _group[3];
    int _groupLength;

    static const unsigned char Base64EncodeMap[64];
};
class Base64Decrypt
{
public:
    Base64Decrypt() : _groupLength(0) {}
    Base64Decrypt(const void* input, size_t length) : Base64Decrypt()
    {
        Update(input, length);
    }

    void Update(const void* input, size_t length)
    {
        static const size_t LEN = 4;
        _buf.reserve(_buf.size() + (length + (LEN - _groupLength) + LEN - 1) / LEN * 3 + 1);
        const unsigned char* buff = reinterpret_cast<const unsigned char*>(input);
        unsigned int i;

        for (i = 0; i < length; ++i)
        {
            if (Base64DecodeMap[buff[i]] == 0xFF)
            {
                throw std::invalid_argument("ciphertext is illegal");
            }

            _group[_groupLength++] = buff[i];
            if (_groupLength == LEN)
            {
                Decode();
            }
        }
    }

    const unsigned char* PlainText()
    {
        if (_groupLength)
        {
            throw std::invalid_argument("ciphertext's length must be a multiple of 4");
        }
        return _buf.data();
    }
    void Reset()
    {
        _buf.clear();
        _groupLength = 0;
        for (unsigned int i = 0; i < sizeof(_group) / sizeof(_group[0]); ++i)
        {
            _group[i] = 0;
        }
    }
    size_t GetSize()
    {
        PlainText();
        return _buf.size();
    }

private:
    Base64Decrypt(const Base64Decrypt&) = delete;
    Base64Decrypt& operator = (const Base64Decrypt&) = delete;

    void Decode()
    {
        unsigned char buff[3];
        unsigned int top = 1;
        if (_group[0] == '=' || _group[1] == '=')
        {
            throw std::invalid_argument("ciphertext is illegal");
        }

        buff[0] = (Base64DecodeMap[_group[0]] << 2) | (Base64DecodeMap[_group[1]] >> 4);
        if (_group[2] != '=')
        {
            buff[1] = ((Base64DecodeMap[_group[1]] & 0x0F) << 4) | (Base64DecodeMap[_group[2]] >> 2);
            top = 2;
        }
        if (_group[3] != '=')
        {
            buff[2] = (Base64DecodeMap[_group[2]] << 6) | Base64DecodeMap[_group[3]];
            top = 3;
        }

        for (unsigned int i = 0; i < top; ++i)
        {
            _buf.push_back(buff[i]);
        }

        _groupLength = 0;
    }

private:
    std::vector<unsigned char> _buf;
    unsigned char _group[4];
    int _groupLength;

    static unsigned char Base64DecodeMap[256];
};
#endif