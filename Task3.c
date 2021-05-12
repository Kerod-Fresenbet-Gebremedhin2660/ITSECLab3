#include <stdio.h>
#include <malloc.h>
#define MAX 1000
#define SIZE 256
#include <string.h>

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

// function to convert Hexadecimal to Binary Number
char * HexToBin(char* hexdec)
{

	long int i = 0;
    char * ret = malloc(MAX);
	while (hexdec[i]) {

		switch (hexdec[i]) {
		case '0':
            strcat(ret, "0000");
			break;
		case '1':
            strcat(ret, "0001");
			break;
		case '2':
            strcat(ret, "0010");
			break;
		case '3':
            strcat(ret, "0011");
			break;
		case '4':
            strcat(ret, "0100");
			break;
		case '5':
            strcat(ret, "0101");
			break;
		case '6':
            strcat(ret, "0110");
			break;
		case '7':
            strcat(ret, "0111");
			break;
		case '8':
            strcat(ret, "1000");
			break;
		case '9':
			strcat(ret, "1001");
            break;
		case 'A':
		case 'a':
            strcat(ret, "1010");
			break;
		case 'B':
		case 'b':
            strcat(ret, "1011");
			break;
		case 'C':
		case 'c':
            strcat(ret, "1100");
			break;
		case 'D':
		case 'd':
            strcat(ret, "1101");
			break;
		case 'E':
		case 'e':
            strcat(ret, "1110");
			break;
		case 'F':
		case 'f':
            strcat(ret, "1111");
			break;
		default:
			printf("\n%c",
				hexdec[i]);
		}
		i++;
	}
    return ret;
}


int main(){
    FILE *fp;
    FILE *fp2;
    fp = fopen("hash1Task3", "r");
    fp2 = fopen("hash2Task3", "r");

    char f1;
    char f2;
    int iterator = 0;
    int count = 0;
    char *hash1 = malloc(SIZE);
    char *hash2 = malloc(SIZE);
    while((f1 = fgetc(fp)) != EOF && (f2 = fgetc(fp2)) != EOF){
        hash1[iterator] = f1;
        hash2[iterator] = f2;
        iterator ++;
    }
    char *delimiter = " ";

    int leng = strlen(hash1);
    char buffer[leng+1];

    char * h1 = substring(hash1, 16, 80);
    char * h2 = substring(hash2, 16, 80);

    printf("%s\n", h1);
    printf("%s\n", h2);

    char *hash1Bin = HexToBin(h1);
    char *hash2Bin = HexToBin(h2);

    printf("\n%s\n", hash1Bin);
    printf("%s\n", hash2Bin);

    for (int i = 0; i <256; i++){
        if(hash1Bin[i] == hash2Bin[i]) 
        {
            printf("%c          %c\n", hash1Bin[i], hash2Bin[i]);
            count++;
            }
    }

    printf("The number of similar bits is %d", count);



    fclose(fp);
    fclose(fp2);
    return 0;
}
