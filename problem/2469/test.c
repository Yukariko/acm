char map[1001][27];
char order[27];
int k,n;
f(p,h,e)
{
  if(p<0||p>=k)return 0;
  int i;
  for(i=h;i<=e;i++)
  {
    if(p>0&&map[i][p-1]=='-')p--;
    else if(p<k-1&&map[i][p]=='-')p++;
  }
  return p;
}
find(p)
{
  int i;
  for(i=0;i<k;i++)if(order[i]-'A'==p)return i;
}
main()
{
  scanf("%d%d ",&k,&n);
  gets(order);
  char choice[27][2]={};
  int i,j,l;
  for(i=0;i<n;i++){gets(map[i]);if(map[i][0]=='?')l=i;}
  for(i=0;i<k;i++)
  {
    j=f(i,0,l);
    if(f(j-1,l+1,n-1)==find(i)){choice[j][1]++;choice[j+1][0]++;}
    else if(f(j,l+1,n-1)==find(i)){choice[j][0]++;choice[j+1][0]++;}
    else if(f(j+1,l+1,n-1)==find(i)){choice[j][0]++;choice[j+1][1]++;}
  }
  char res[27]={};
  for(i=1;i<k;i++)
  {
    if(choice[i][0]<2&&choice[i][1]<2)break;
    else res[i]=choice[i][0]?'*':'-';
  }
  if(i!=k)for(i=0;i<k-1;i++)putchar('x');
  else puts(res+1);
}
