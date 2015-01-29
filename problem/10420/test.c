const int DAY[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int leap(int x){return x%4?0:x%100?1:x%400?0:1;}

main()
{
	int N;
	int year = 2014, month = 4, day = 2;
	scanf("%d",&N);
	N--;
	for(;N;)
	{
		int t = month == 2 && leap(year)?29: DAY[month];
		t -= day - 1;
		if(N < t)
		{
			day += N;
			break;
		}
		N -= t;
		month++;
		if(month == 13)
		{
			month = 1;
			year++;
		}
		day = 1;
	}
	printf("%.4d-%.2d-%.2d",year,month,day);
}
