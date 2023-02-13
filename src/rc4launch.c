#include <stdio.h>
#include <stdlib.h>
#include "RC4.h"
#include "Hex2Str.h"

unsigned char execArg = 0;

int main(int argc, char const *argv[])
{

	char *source = NULL,
		 *rc4key = NULL,
		 *outstream = NULL;
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] != '-')
		{
			if (source == NULL)
			{
				source = argv[i];
			}
			else
			{
				rc4key = argv[i];
			}
		}
		else
		{
			for (int j = 1; j < strlen(argv[i]); j++)
			{
				if (argv[i][j] == 's' || argv[i][j] == 'S')
					execArg += j == 1 ? 0 : 0;
				else if (argv[i][j] == 'x' || argv[i][j] == 'X')
					execArg += j == 1 ? 1 : 2;
				else
					execArg = -1;
			}
		}
	}

	if (execArg == 1 || execArg == 3)
	{
		short a = strlen(source);
		char *temp = (char *)malloc(strlen(source) / 2 + 1);
		HexStrToByte(source, temp, strlen(source));
		outstream = RC4_Encrypt(temp, strlen(temp), rc4key, strlen(rc4key));
		outstream[strlen(source) / 2] = 0;
		if (execArg == 1)
		{
			puts(outstream);
		}
		else
		{
			for (int i = 0; i < strlen(outstream); i++)
			{
				printf("%02hhx", outstream[i]);
			}
			printf("\n");
		}
		free(temp);
		temp = NULL;
	}
	else if (execArg == 0 || execArg == 2)
	{
		outstream = RC4_Encrypt(source, strlen(source), rc4key, strlen(rc4key));
		outstream[strlen(source)] = 0;
		if (execArg == 0)
		{
			puts(outstream);
		}
		else
		{
			for (int i = 0; i < strlen(outstream); i++)
			{
				printf("%02hhx", outstream[i]);
			}
			printf("\n");
		}
	}
	else
	{
		puts("Input argument has invalid");
	}
	freeRC4Source();
	outstream = NULL;
	return 0;
}
