#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char *vowel = "aiyeou";
const char *conso = "bkxznhdcwgpvjqtsrlmf";
int isvowel(char p)
{
	for(int i=0; vowel[i]; i++)
		if(vowel[i] == p)
			return i;
	return -1;
}

int isconso(char p)
{
	for(int i=0; conso[i]; i++)
		if(conso[i] == p)
			return i;
	return -1;
}

int main()
{
	char a[101];
	for(;gets(a);)
	{
		for(int i=0;a[i];i++)
		{
			if(isalpha(a[i]))
			{
				char p;
				if((p = isvowel(a[i] | 32)) != -1)
					p = vowel[(p+3) % 6];
				else
					p = conso[(isconso(a[i] | 32) + 10) % 20];

				a[i] = a[i] >= 'a'? p: p - 32;
			}
		}
		puts(a);
	}
	return 0;
}