int a[1001];
int index[1000001]={0};
int n;
int i,j,k,s,m;
int main()
{
  scanf("%d",&n);
  for(i=0;i<n;scanf("%d",a+i++));
  m=1;
  for(i=0;i<n;i++)
  {
    if(index[a[i]])continue;
    index[a[i]]=1;
    k=a[0];s=1;
    for(j=1;j<n;j++)
    {
      if(a[i]==a[j])continue;
      if(k==a[j])s++;
      else
      {
        m=m<s?s:m;
        k=a[j];
        s=1;
      }
    }
    m=m<s?s:m;
  }
  printf("%d",m);
}
