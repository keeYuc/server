#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<iostream>
#include<stdio.h>
#include"../cpp-base64/base64.h"

int main()
{
    //printf("s");
    auto rsa = RSA_new();
    auto num = BN_new();
    BN_set_word(num, 12345);
    //printf("s");
    char unsigned buff[] = "accdefg123";
    char  unsigned buff1[128];
    char unsigned buff2[128];
    bzero(buff1, 128);
    bzero(buff2, 128);
    RSA_generate_key_ex(rsa, 1024, num, nullptr);
    auto pub_key = RSAPublicKey_dup(rsa);
    auto pri_key = RSAPrivateKey_dup(rsa);
    printf("加密内容是[%s]\n", buff);
    // int n = RSA_public_encrypt(sizeof(buff), buff, buff1, pri_key, RSA_PKCS1_PADDING);
    // int n1 = RSA_private_decrypt(sizeof(buff), buff1, buff2, pub_key, RSA_PKCS1_PADDING);
    //std::cout << "----" << n << "---" << n1 << "-------" << std::endl;
    // int n = RSA_private_encrypt(sizeof(buff), buff, buff1, pri_key, RSA_PKCS1_PADDING);
    // int n1 = RSA_public_decrypt(sizeof(buff1), buff1, buff2, pub_key, RSA_PKCS1_PADDING);
    // std::cout << "----" << n << "---" << n1 << "-------" << std::endl;
    // auto fd = fopen("./pub.txt", "w+");
    // auto fd1 = fopen("./pri.txt", "w+");
    // PEM_write_RSAPublicKey(fd, pub_key);
    // PEM_write_RSAPrivateKey(fd1, pri_key, nullptr, nullptr, 0, nullptr, nullptr);
    // fclose(fd);
    // fclose(fd1);
    // RSA_public_encrypt(11, buff, buff1, pub_key, RSA_PKCS1_PADDING);
    // RSA_private_decrypt(11, buff1, buff2, pri_key, RSA_PKCS1_PADDING);
    unsigned int a123;
    RSA_sign(NID_md5, buff, sizeof(buff), buff1, &a123, pri_key);
    int n1 = RSA_verify(NID_md5, buff, sizeof(buff), buff1, a123, pub_key);
    std::cout << "n1:" << n1 << std::endl;
    //printf("解密内容是[%s]\n", buff2);
    RSA_free(rsa);

    return 0;
}
