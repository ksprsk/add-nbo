#include <stdio.h>
#include <stdlib.h>
#include "nbo.h"

uint32_t f2u32(char *filename)
{
	FILE* fp=NULL;
	fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("open error\n");
        exit(-1);
    }
	fseek(fp,0,SEEK_END);
	if(ftell(fp)!=4)
	{
		printf("wrong file length\n");
		fclose(fp);
		exit(-1);
	}
	fseek(fp,0,SEEK_SET);
	uint32_t buf;
	fread(&buf,4,1,fp);
	fclose(fp);
	return my_ntohl(buf);
}

int main(int argc,char **argv) {
	if(argc!=3)
	{
		printf("Usage: %s <file1> <file2>\n",argv[0]);
		return 0;
	}
	uint32_t a=f2u32(argv[1]);
	uint32_t b=f2u32(argv[2]);
	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",a,a,b,b,a+b,a+b);
}
