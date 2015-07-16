#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char *bigplus(char *store,char *a,char *b)
{
	char t[1001]={0};
	int i=strlen(a),j=strlen(b),p,s;
	for(p=0;i||j;p++)
	{
		s = (i?a[i-1]-'0':0)+(j?b[j-1]-'0':0);
		if(s+t[p]>9)t[p+1]+=(s+t[p])/10;
		t[p] = (s+t[p])%10;
		if(i>0)i--;
		if(j>0)j--;
	}
	if(!t[p])p--;
	for(i=0;i<=p;i++)
	 store[p-i]=t[i]+'0';
	store[p+1]=0;
	return store;
}

int main()
{
	char a[61];
	while(gets(a))
	{
		int len = strlen(a);

		int b[10] = {};
		for(int i=0; a[i]; i++)
			b[a[i]-'0']++;

		char s[101] = "0";

		bool find = true;
		for(int cnt = 0; cnt < len; cnt++)
		{
			bigplus(s,s,a);

			int tb[10] = {};
			for(int i=0; s[i]; i++)
				tb[s[i]-'0']++;

			for(int i=0; i < 10; i++)
				if(tb[i] != b[i])
					find = false;

			if(!find)
				break;
		}

		if(find)
			cout << a << " is cyclic" << endl;
		else
			cout << a << " is not cyclic" << endl;

	}
	return 0;
}
