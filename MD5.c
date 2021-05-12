#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/hmac.h>
#include <openssl/md5.h>
#include <stdbool.h>
#define SIZE 256
#define MAXDIGIT 10
char *substring(char *string, int position, int length)
{
   char *p;
   int c;
   p = malloc(length+1);
   if (p == NULL)
   {
      printf("Unable to allocate memory.\n");
   }
   for (c = 0; c < length; c++)
   {
      *(p+c) = *(string+position-1);
      string++;
   }
   *(p+c) = '\0';
   return p;
}
bool compare(char * myval, int length)
{
    int iter, i, j, con = 0;
    unsigned char digest[16];
    char hash[16];

    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, myval, strlen(myval));
    MD5_Final(digest, &md5);

    for (i = 0; i < 16; ++i)
        snprintf(&(hash[i * 2]), 16 * 2, "%02x", (unsigned int)digest[i]);

    FILE *f = fopen("hash1Task3", "r");

    char char1;
    char char2;

    char *den = malloc(256);

    while ((char1 = fgetc(f)) != EOF)
    {
        den[iter] = char1;
        iter++;
    }

    char *final = substring(den, 0, 5);

    con = 0;
    for (j = 0; j < 32; j++)
    {
        if (hash[j] != den[j])
            ;
        else
            con++;
    }
    if (con == 32)
    {
        printf("\n%s", myval);
        return false;
    }
    else
        return true;
}
char *randomString(size_t length)
{
    char *ret = malloc(length);
    int z;
    char alphanumeric[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (z = 0; z < length; z++)
    {
        size_t index = (double)rand() / RAND_MAX * (sizeof alphanumeric - 1);
        *(ret + z) = alphanumeric[index];
    }
    *(ret + z) = '\0';
    return ret;
}

int main()
{
    char alphaNumeric[] = "abcdefghijklmnopqrstuvwxyz"
                  "0123456789"
                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";

    int alphaNumericSize = strlen(alphaNumeric);

    char *value = randomString(3);
    int digitVal[MAXDIGIT] = {0};

    int currentDigit = 1, crs = 0, i = 0;
    int tmp1 = 10, tmp = true, iterator = 0;

    while (tmp)
    {
        while (digitVal[0] < alphaNumericSize)
        {
            printf("Comparison Pass %d \n", iterator);
            iterator++;
            tmp = compare(value, currentDigit);
            if (tmp == false)
                break;
            digitVal[0]++;
        }
        while (digitVal[crs] == alphaNumericSize)
        {
            crs++;
            for (i = 0; i < crs; i++)
                digitVal[i] = 0;
            if (crs == currentDigit)
            {
                currentDigit++;
                break;
            }
            else
                digitVal[crs]++;
        }
        crs = 0;
    }
    return 0;
}
