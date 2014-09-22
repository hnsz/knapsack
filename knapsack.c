#include <stdio.h>
#include <stdlib.h>

int encrypt_letter(char ch, int *pub_key)
{
	int num;
	int i;
	//char mask[] = {-128,64,32,16,8,4,2,1};
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
		if(ch == ' ')
			return num;
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
#if 1
//	standalone test
int main()
{
	int pub_key[] = {94, 141, 282, 175, 350, 311, 233, 77};
	int priv_key[] = {2,3,6,12,24,48,96,192};
	int m_inv = 149;
	int n = 389;
	int num;
	char ch;
	FILE *infile = stdin;
	FILE *outfile = stdout;
	

	


/*
	while((ch = fgetc(infile)) != EOF) {
		fprintf(outfile,"%d ", encrypt_letter(ch, pub_key));
	}
*/
	while((num = parse_num(infile)) != -1)
	{
		fputc(decrypt_letter(num, priv_key, m_inv, n), outfile);
	}
	return 0;
}
#endif
