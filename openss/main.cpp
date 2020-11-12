#include<string.h>
#include<openssl/rsa.h>
#include<iostream>
#include<stdio.h>

int main()
{
    //printf("s");
    auto rsa = RSA_new();
    auto num = BN_new();
    BN_set_word(num, 12345);
    //printf("s");
    char buff[11] = "accdefg123";
    char buff1[11];
    char buff2[11];
    RSA_generate_key_ex(rsa, 1024, num, nullptr);
    auto pub = RSAPublicKey_dup(rsa);
    auto pri = RSAPrivateKey_dup(rsa);
    //printf("%s\n", (char*) pub);printf("%s\n", (char*) pri);
    RSA_public_encrypt(11, (unsigned char*) buff, (unsigned char*) buff1, pub, RSA_PKCS1_PADDING);
    RSA_private_decrypt(11, (unsigned char*) buff1, (unsigned char*) buff2, pri, RSA_PKCS1_PADDING);
    printf("%s\n", buff2);
    RSA_free(rsa);

    return 0;
}
