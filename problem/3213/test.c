/* dp solution
int dp[10001];
f(p,q,s)
{
  if(dp[p+q]<s)return;
  if(p<0||q<0)return;
  dp[p+q]=s;
  if(p+q==0)return;
  if(p>=4)f(p-4,q,s+1);
  else if(p>=3)f(p-3,q,s+1);
  if(p>=2&&q)f(p-2,q-1,s+1);
  else if(p&&q)f(p-1,q-1,s+1);
  else if(p)f(p-1,q,s+1);
  else if(q>=2)f(p,q-2,s+1);
  else f(p,q-1,s+1);
}
dp[i]=987654321;
f(p,q,s);
printf("%d",dp[0]);
*/
main()
{
  int n;
  char b[4];
  scanf("%d ",&n);
  int i;
  int p,q,r;
  p=q=r=0;
  for(i=0;i<n;i++)
  {
    gets(b);
    if(strcmp(b,"1/4")==0)p++;
    if(strcmp(b,"1/2")==0)q++;
    if(strcmp(b,"3/4")==0)r++;
  }
  int s=0;
  for(;r;r--)
  {
    s++;
    if(p)p--;
  }
  for(;q;q--)
  {
    s++;
    if(q>=2)q--;
    else p-=2;
  }
  for(;p>0;)
  {
    s++;
    p-=4;
  }
  printf("%d",s);
}
