#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

int main()
{

	int pub_key[] = {335, 469, 1005, 846, 394, 922, 1216, 330};
	//int priv_key[] = {5, 7, 15, 31, 61, 124, 257, 501};
	//int mul = 67;
	//int n = 1231;
	//int m_inv = 147;


	char ch;
	FILE *infile = stdin;
	FILE *outfile = stdout;
	

	


	while((ch = fgetc(infile)) != EOF) {
		fprintf(outfile,"%d ", encrypt_letter(ch, pub_key));
	}


	return 0;
}
