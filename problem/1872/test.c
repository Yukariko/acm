char a[10001];
int rome[128];
char dim[]="mdclxvi";
init()
{
  rome['i']=1;rome['v']=5;
  rome['x']=10;rome['l']=50;
  rome['c']=100;rome['d']=500;
  rome['m']=1000;
}
long long rome2dim(char *b)
{
  int i;
  long long s;
  for(s=i=0;b[i];i++)
  {
    s+=rome[b[i]];
  }
  return s;
}

main(m,k,j,i,n)
{
  init();
  for(scanf("%d ",&n);n--;)
  {
    gets(a);
    char b[10001]={0};
    int count[7]={100000,1,3,1,3,1,3};
    for(m=j=k=0;k<7;k++)
    for(i=m;a[i];i++)
    {
      if(a[i]==dim[k]&&count[k])
      {
        count[k]--;
        b[j++]=a[i];
        m=i;
      }
    }
    b[j]=0;
    printf("%lld\n",rome2dim(b));
  }
}
