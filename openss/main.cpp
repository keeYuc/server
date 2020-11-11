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
    auto pub = RSAPublicKey_dup(rsa);
    auto pri = RSAPrivateKey_dup(rsa);

    RSA_generate_key_ex(rsa, 1024, num, nullptr);
    

    RSA_free(rsa);

    return 0;
}
