long long gcd(long long p,long long q){return q?gcd(q,p%q):p;}

main()
{
	char a[21];
	for(;gets(a);)
	{
		int start,end;

		start = 0;
		for(int i=0; a[i] && a[i]!='.';i++)
			start++;
		if(a[start] == 0)
			strcat(a, ".");

		start = 0;
		for(int i=0; a[i] && a[i]!='(';i++)
			start++;

		if(a[start] == 0)
			strcat(a,"(0)");

		start = 0;
		for(int i=0; a[i] && a[i]!='(';i++)
			start++;

		end = start;
		for(int i=start; a[i] && a[i]!=')';i++)
			end++;

		// q / p
		long long q1,q2,p1,p2;

		q1 = 0;
		p1 = 0;
		for(int i=0;a[i]!='(';i++)
		{
			if(a[i] == '.')
			{
				p1 = 1;
				continue;
			}
			q1 *= 10;
			q1 += a[i] - '0';
			p1 *= 10;
		}

		q2 = q1;
		p2 = p1;

		for(int i=start+1;i<end;i++)
		{
			q2 *= 10;
			q2 += a[i] - '0';
			p2 *= 10;
		}

		q2 -= q1;
		p2 -= p1;
		int t = gcd(q2,p2);
		q2 /= t;
		p2 /= t;

		printf("%lld/%lld\n",q2,p2);
	}
}
