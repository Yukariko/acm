char map[21][21];
int r,c;
int max;
f(int i,int j,int k,char *arr)
{
  if(i<0||j<0||i>=r||j>=c||arr[map[i][j]-'A'])return;
  char a[30]={};
  int p;
  for(p=0;p<26;p++)a[p]=arr[p];
  a[map[i][j]-'A']=1;
  f(i-1,j,k+1,a);f(i+1,j,k+1,a);f(i,j-1,k+1,a);f(i,j+1,k+1,a);
  max=max<k?k:max;
}
main()
{
  scanf("%d%d ",&r,&c);
  int i;
  for(i=0;i<r;i++)gets(map[i]);
  char a[30]={};
  f(0,0,1,a);
  printf("%d",max);
}
