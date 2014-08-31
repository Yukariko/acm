main()
{
  char che[100001]={};
  long long i,j;
  for(i=2;i<=100000;i++)
  {
    if(che[i]==0)
    {
      for(j=i*i;j<=100000;j+=i)che[j]=1;
    }
  }
  char a[256];
  for(;gets(a),!(a[0]=='0'&&a[1]==0);)
  {
    int max=0,k;
    for(j=5;j;j--)
    {
      for(i=0;a[i+j];i++)
      {
        char t;
        t=a[i+j];
        a[i+j]=0;
        k=atoi(a+i);
        a[i+j]=t;
        if(che[k]==0&&max<k)max=k;
      }
    }
    printf("%d\n",max);
  }
}
