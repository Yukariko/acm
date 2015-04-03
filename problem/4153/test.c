int cmp(int *p,int *q){return *p-*q;}
main()
{
	int a[3];
	for(;scanf("%d%d%d",a,a+1,a+2),*a;)
	{
		qsort(a,3,4,cmp);
		puts(a[2]*a[2] == a[0]*a[0] + a[1]*a[1]? "right":"wrong");
	}
}