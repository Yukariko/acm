main()
{
	char a[10001];
	for(int	T=1;gets(a),*a != '0';T++)
	{
		int i;
		for(i=1;a[i];i++)
		{
			if(a[0] != '1') break;
			if(a[i+1] == 0 && a[i] != '2') break;
			if(a[i] == '1') break;
			if(a[i] == '2' && (a[i+1] || (a[i-1] != '4' && a[i-1] != '6'))) break;
			if(a[i] == '3' && a[i-1] != '4' && a[i-1] != '6') break;
			if(a[i] == '4' && a[i-1] != '3' && a[i-1] != '1') break;
			if(a[i] == '5' && a[i-1] != '3' && a[i-1] != '1') break;
			if(a[i] == '6' && a[i-1] != '8') break;
			if(a[i] == '7' && a[i-1] != '8') break;
			if(a[i] == '8' && a[i-1] != '5' && a[i-1] != '7') break;
		}
		printf("%d. %s\n",T,a[i] || i == 1?"NOT":"VALID");
	}
}
