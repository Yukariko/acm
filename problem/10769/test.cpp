#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	char a[256];
	gets(a);

	int happy=0, sad=0;

	for(int i=0; a[i]; i++)
	{
		if(strncmp(a+i, ":-(",3) == 0)
			sad++;
		else if(strncmp(a+i,":-)",3) == 0)
			happy++;
	}
	

	if(happy + sad == 0)
		puts("none");
	else if(happy == sad)
		puts("unsure");
	else if(happy < sad)
		puts("sad");
	else
		puts("happy");

	return 0;
}