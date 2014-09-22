#include <stdio.h>


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

	for(letter = 0, i = 8; --i;) {

		if(suma - priv_key[i] >= 0) {

			letter |= mask[i];
			suma -= priv_key[i];
		}
	}
	
	return letter;
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
	char letter = 'p';
	char decrypted_letter;

	num = encrypt_letter(letter, pub_key);
	
	printf("Encrypted letter '%c' into number %d.\n", letter, num);

	decrypted_letter = decrypt_letter(num, priv_key, m_inv, n);

	printf("Decrypted number %d into letter '%c'.\n", num, decrypted_letter);
	return 0;
}
#endif
