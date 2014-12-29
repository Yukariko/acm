char a[100];
int len;
int n;
int check[51];
char result[100][3];

getNum(char p,char q){return (p-'0') * 10 + (q-'0');}

f(pos, k)
{
	if(k == 0)
	{	
		int i;
		for(i=0;i<len;i++)
		{
			if(result[i][0]) printf("%s ",result[i]);
		}
		exit(0);
	}
	if(!a[pos] || a[pos] == '0')return;
	if(!check[a[pos]-'0'])
	{
		check[a[pos]-'0'] = 1;
		result[pos][0]=a[pos];
		f(pos+1,k-1);
		result[pos][0]=0;
		check[a[pos]-'0'] = 0;
	}
	if(a[pos+1] && a[pos+1] != '.' && getNum(a[pos],a[pos+1]) <= n && !check[getNum(a[pos],a[pos+1])])
	{
		check[getNum(a[pos],a[pos+1])] = 1;
		result[pos][0]=a[pos];
		result[pos][1]=a[pos+1];
		f(pos+2,k-1);
		result[pos][0]=result[pos][1]=0;
		check[getNum(a[pos],a[pos+1])] = 0;
	}
}

main()
{
	len = strlen(gets(a));
	n = len >= 10? 9 + (len - 9) / 2 : len;
	f(0,n);
}
