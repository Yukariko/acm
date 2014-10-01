int n,m;
long long map[11];
int max,min;
f(int p,int s,long long k)
{
  int numYes=0;
  for(long long t=k;t;t/=2)numYes+=t%2;
  if(max<numYes){max=numYes;min=s;}
  else if(max==numYes)min=min>s?s:min;
  if(p==n)return;
  f(p+1,s+1,k|map[p]);
  f(p+1,s,k);
}
main()
{
  scanf("%d%d ",&n,&m);
  for(int i=0;i<n;i++)
  {
    char a[51];
    scanf("%*s%s",a);
    for(int j=0;a[j];j++)map[i]=map[i]*2+(a[j]=='Y');
  }
  f(0,0,0);
  printf("%d",max?min:-1);
}
