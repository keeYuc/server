#include<openssl/aes.h>
//# define AES_BLOCK_SIZE 32
#include<stdio.h>
#include<string.h>
#include<iostream>

int main()
{

    unsigned char key1[16] = "1234567899";
    unsigned char wen[] = "这是原始数据";
    std::cout << "--------" << sizeof(key1) << "-------" << strlen((char*) key1) << "--------\n";


    int len;
    if (sizeof(wen) % 16 != 0)
    {
        len = ((sizeof(wen) / 16) + 1) * 16;
    } else
    {
        len = sizeof(wen);
    }
    unsigned char out[len];
    unsigned char out1[len];
    unsigned char prt[16];
    unsigned char prt1[16];
    memset(prt, 9, 16);
    memset(prt1, 9, 16);

    AES_KEY key;
    AES_set_encrypt_key(key1, 128, &key);
    AES_cbc_encrypt(wen, out, len, &key, prt, AES_ENCRYPT);
    AES_KEY key12;
    AES_set_decrypt_key(key1, 128, &key12);
    AES_cbc_encrypt(out, out1, len, &key12, prt1, AES_DECRYPT);



    printf("[%s]\n", out1);




    return 0;
}