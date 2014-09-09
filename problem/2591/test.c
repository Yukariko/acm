char a[43];
long long fibo[42];
int count;
long long s=1;
f(i)
{
  if(a[i]==0){s*=fibo[count];return;}
  if(a[i+1]=='0'){s*=fibo[count];count=0;f(i+2);}
  else
  {
    if(a[i+1]&&a[i+2]!='0'&&(a[i]-'0')*10+(a[i+1]-'0')<=34){count++;}
    else {s*=fibo[count];count=0;}
    f(i+1);
  }
}
main()
{
  long long i=1,j=0,k;
  for(k=0;k<40;k++)
  {
    i=i+j;
    j=i-j;
    fibo[k]=i;
  }
  gets(a);
  f(0);
  printf("%lld",s);
}
