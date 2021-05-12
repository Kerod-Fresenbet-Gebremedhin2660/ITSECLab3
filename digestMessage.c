#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<openssl/evp.h>
#include<openssl/sha.h>
#include <assert.h>
int digest_message(const unsigned char *message, size_t message_len, unsigned char **digest, unsigned int *digest_len);
int digest_message(const unsigned char *message, size_t message_len, unsigned char **digest, unsigned int *digest_len)
{
        //printf("%s","first");
	EVP_MD_CTX *mdctx;

	if((mdctx = EVP_MD_CTX_new()) == NULL){
		//handleErrors();
                printf("%s","err1");
                return -1;
}
	if(1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL)){
		//handleErrors();
                 printf("%s","err2");
                 return -1;

}
	if(1 != EVP_DigestUpdate(mdctx, message, message_len)){
		//handleErrors();
                printf("%s","err3");
                return -1;
}
	if((*digest = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_sha256()))) == NULL){
		//handleErrors();
               printf("%s","err4");
               return -1;
}
	if(1 != EVP_DigestFinal_ex(mdctx, *digest, digest_len)){
		//handleErrors();
               printf("%s","err5");
              return -1;
}

	printf("%s","yes");
       EVP_MD_CTX_free(mdctx);
       return 0;
}

int main(){
   unsigned char **digest;
   size_t len=5;
   unsigned int dlen2;
   unsigned int *dlen;
   dlen=&dlen2;
   const unsigned char name [2]  = "ab";

    printf("%d",digest_message(name , len, digest, dlen));
    return 0;
}