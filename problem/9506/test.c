main()
{
  int n;
  for(;scanf("%d",&n),n!=-1;)
  {
    int i,s=0;
    for(i=1;i<n;i++)
    {
      if(n%i==0)s+=i;
    }
    if(s!=n){printf("%d is NOT perfect.\n",n);continue;}
    printf("%d = 1",n);
    for(i=2;i<n;i++)if(n%i==0)printf(" + %d",i);
    puts("");
  }
}
