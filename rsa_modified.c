#include <openssl/rsa.h>
#include <string.h>
#include <openssl/bn.h>

int main(void)
{
        RSA *r;
        //Generates a RSA key
        //Remember that this code is just to test your method, in the actual problem we will be using our own key to decrypt.
        //You need to alter the ciphertext without knowing the key 
        r = RSA_generate_key(1024, RSA_F4, NULL, NULL);

        char enc2[256]={'\0'};
        char enc4[256]={'\0'};
        char enc8[256]={'\0'};

        //To see the contents of the rsa including the modulus and exponents 
        RSA_print_fp(stdout,r,0);
        int n,i;

        char s2[128]={'\0'};
        s2[127]='\2';

        char s4[128]={'\0'};
        s4[127]='\4';

        char s8[128]={'\0'};
        s8[127]='\10';

        //Encrypting using textbook RSA - with no padding
        int size;
        size = RSA_public_encrypt(RSA_size(r),s2,enc2,r,RSA_NO_PADDING);
        size = RSA_public_encrypt(RSA_size(r),s4,enc4,r,RSA_NO_PADDING);
        size = RSA_public_encrypt(RSA_size(r),s8,enc8,r,RSA_NO_PADDING);

        printf("Encrypted 2:\n");
        for(i=0;i<size;i++)
        {
            printf("%02x",(unsigned char)enc2[i]);
        }
        printf("\n");

        printf("Encrypted 4:\n");
        for(i=0;i<size;i++)
        {
            printf("%02x",(unsigned char)enc4[i]);
        }
        printf("\n");

        printf("Encrypted 8:\n");
        for(i=0;i<size;i++)
        {
            printf("%02x",(unsigned char)enc8[i]);
        }
        printf("\n");

        RSA_free(r);
        return 0;
}