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

        //variables to store ciphertext and decrypted text
        char buffer[256]={'\0'};
        char buffer2[256]={'\0'};

        //To see the contents of the rsa including the modulus and exponents 
        RSA_print_fp(stdout,r,0);
        int n,i;

        //Creating a message to be encoded. Here the message is 000...<127 times>4 or big endian representation of 4. 
        //You can modify this as required 
        char s1[128]={'\0'};
        s1[127]='\4';

        //Encrypting using textbook RSA - with no padding
        int size1 = RSA_public_encrypt(RSA_size(r),s1,buffer,r,RSA_NO_PADDING);
        printf ("%d\n",size1);
        printf("Encrypted:\n");
        //Printing the encrypted string
        for(i=0;i<size1;i++)
        {
                printf("%02x",(unsigned char)buffer[i]);
        }
        //Decrypting the ciphertext with RSA
        int sm = RSA_private_decrypt(size1,buffer,buffer2,r,RSA_NO_PADDING);
        printf("\nDecrypted\n");
        //Printing the decrypted value
        for(i=0;i<sm;i++)
        {
                printf("%02x",(unsigned char)buffer2[i]);
	}

        printf("\n");
        RSA_free(r);
        return 0;
}