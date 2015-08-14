#include <iostream>
#include <cstdio>

using namespace std;


const char *question[24][3] = {
	{"how to install",NULL,"-"},
	{"what is",NULL,"-"},
	{NULL,"not working","-"},
	{"why use",NULL,"-"},
	{"who use",NULL,"-"},
	{"disadvantages of",NULL,"-"},
	{"advantages of",NULL,"-"},
	{NULL,"open source projects","-"},
	{NULL,"tutorial","-"},
	{NULL,"performance","-"},
	{NULL,"sucks","-"},
	{"getting started",NULL,"-"},
	{NULL,"-","-"},
	{NULL,"reference","-"},
	{NULL,"solution","-"},
	{NULL,"example code","-"},
	{"difference between",NULL,"and C++"},
	{NULL,"site:acmicpc.net","-"},
	{NULL,"filetype:pdf","-"},
	{NULL,"slides","-"},
	{"how to make",NULL,"-"},
	{NULL,"jobs","-"},
	{NULL,"time","-"},
	{"best os x",NULL,"app"}
};

int main()
{
	int T;
	scanf("%d",&T);

	while(T--)
	{
		int N;
		char a[101];

		scanf("%d ",&N);
		gets(a);

		N--;
		for(int i=0; i < 3; i++)
			if(question[N][i] == NULL)
				printf("%s ",a);
			else if(question[N][i] != "-")
				printf("%s ",question[N][i]);
		
		puts("");
	}
	return 0;
}