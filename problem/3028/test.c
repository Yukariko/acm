char a[51];
int i,k;
main()
{
  gets(a);
  for(;a[i];i++)
  {
    if(a[i]=='A')
    {
      if(k==0||k==1)k=k==1?0:1;
    }
    if(a[i]=='B')
    {
      if(k==1||k==2)k=k==2?1:2;
    }
    if(a[i]=='C')
    {
      if(k==0||k==2)k=k==2?0:2;
    }
  }
  printf("%d",k+1);
}
