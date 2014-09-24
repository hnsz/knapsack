#include <stdio.h>
#include <stdlib.h>

int encrypt_letter(char ch, int *pub_key)
{
	int num;
	int i;
	char mask[] = {1,2,4,8,16,32,64,-128};



	for(num=0,i = 0; i < 8; ++i) {

		if(ch & mask[i])
			num += pub_key[i];
	}
	return num;
}


char decrypt_letter(int num, int *priv_key, int m_inv, int n)
{
	int suma = (num * m_inv) % n;
	int i;
	char mask[] = {1,2,4,8,16,32,64,-128};
	char letter;

	for(letter = 0, i = 8; --i >= 0;) {

		if(suma - priv_key[i] >= 0) {

			letter |= mask[i];
			suma -= priv_key[i];
		}
	}
	
	return letter;
}


int parse_num(FILE *infile)
{
	char ch;
	int num = 0;

	while((ch = fgetc(infile)) != EOF)
	{
		if(ch == ' ' || ch == '\n' || ch == '\t') { //otherwise tough luck
			if(num)
				return num;
			else
				continue;
		}
		if(ch >= '0' && ch <= '9') {
			num *= 10;
			num += ch - '0';
		}
		else {
			printf("Error: input (file) isn't in the right format. Exit.\n");
			exit(-1);
		}
	}
	return -1;
}
