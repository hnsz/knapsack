#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

int main()
{

//	int pub_key[] = {335, 469, 1005, 846, 394, 922, 1216, 330};
	int priv_key[] = {5, 7, 15, 31, 61, 124, 257, 501};
//	int mul = 67;
	int n = 1231;
	int m_inv = 147;


	int num;
	FILE *infile = stdin;
	FILE *outfile = stdout;
	

	


	while((num = parse_num(infile)) != -1)
	{
		fputc(decrypt_letter(num, priv_key, m_inv, n), outfile);
	}
	return 0;
}
