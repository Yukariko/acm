char map[26][26];
int queue[900]={0};
int n;
int count;
f(i,j)
{
  if(i<0||j<0||i>=n||j>=n||map[i][j]!='1')return;
  count++;
  map[i][j]='0';
  f(i-1,j);f(i+1,j);f(i,j-1);f(i,j+1);
}
cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  scanf("%d ",&n);
  int i,j,k;
  for(i=0;i<n;i++)
  {
    gets(map[i]);
  }
  for(k=i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(map[i][j]=='1')
      {
        count=0;
        f(i,j);
        queue[k++]=count;
      }
    }
  }
  qsort(queue,k,4,cmp);
  printf("%d\n",k);
  for(i=0;i<k;i++)printf("%d\n",queue[i]);
}
