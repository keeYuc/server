//#include<openssl/bio.h>

#include<iostream>
#include<openssl/pem.h>
#include<string.h>
char* base64Encode(const char* buffer, int length, bool newLine)

{
    BIO* bmem = NULL;
    BIO* b64 = NULL;
    BUF_MEM* bptr;

    b64 = BIO_new(BIO_f_base64());
    if (!newLine)
    {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new(BIO_s_mem());
    b64 = BIO_push(b64, bmem);
    BIO_write(b64, buffer, length);
    BIO_flush(b64);
    BIO_get_mem_ptr(b64, &bptr);
    BIO_set_close(b64, BIO_NOCLOSE);

    char* buff = (char*) malloc(bptr->length + 1);
    memcpy(buff, bptr->data, bptr->length);
    buff[bptr->length] = 0;
    BIO_free_all(b64);

    return buff;
}

// base64 解码
char* base64Decode(char* input, int length, bool newLine)
{
    BIO* b64 = NULL;
    BIO* bmem = NULL;
    char* buffer = (char*) malloc(length);
    memset(buffer, 0, length);
    b64 = BIO_new(BIO_f_base64());
    if (!newLine)
    {
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    }
    bmem = BIO_new_mem_buf(input, length);
    bmem = BIO_push(b64, bmem);
    BIO_read(bmem, buffer, length);
    BIO_free_all(bmem);

    return buffer;
}
int main()
{
    char fuck[] = "sadasdadad";
//    auto a= base64Encode(fuck, sizeof(fuck), false);
//    printf("%s\n", a);
//    auto b=base64Decode(a, sizeof(a), false);
//    printf("%s\n", b);

    auto bio = BIO_new(BIO_s_mem());
    auto b64 = BIO_new(BIO_f_base64());
    BIO_push(b64, bio);
    BIO_write(b64, fuck, sizeof(fuck));
    BIO_flush(b64);
    BUF_MEM* ptr;
    BIO_get_mem_ptr(b64, &ptr);
    char* buf = new char[ptr->length];
    memcpy(buf, ptr->data, ptr->length);
    printf("编码之后的数据: %s\n", buf);

    


}
