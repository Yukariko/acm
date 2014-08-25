main()
{
  int n;
  scanf("%d",&n);
  int stack[100001];
  char print[200001][2]={0};
  int i,j,k,p;
  int sIndex=0;
  int max=0;
  for(p=i=0;i<n;i++)
  {
    scanf("%d",&k);
    if(max<k)
    {
      for(j=max+1;j<=k;j++)
      {
        stack[sIndex++]=j;
        print[p++][0]='+';
      }
      sIndex--;
    }
    else
    {
      if(stack[sIndex-1]!=k){puts("NO");return;}
      sIndex--;
    }
    print[p++][0]='-';
    max=max<k?k:max;
  }
  for(i=0;i<p;i++)puts(print[i]);
}
