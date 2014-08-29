make_pi(int *pi,char *p)
{
  int i=1,j=0;
  pi[1]=0;
  for(;p[i];)
  {
    if(!j||p[i]==p[j])
    {
      j++;i++;pi[i]=j;
    }
    else j=pi[j];
  }
}
kmp(int *pi,char *p,char *q,int pi_len)
{
  int dp[5002]={};
  int i,j;
  for(i=j=1;p[i];)
  {
    if(!j||p[i]==q[j]){i++;j++;}
    else j=pi[j];
    dp[j]++;
  }
  for(j=pi_len+1;j&&dp[j]<2;j--);
  return j-1;
}
main()
{
  char a[5002],b[5002];
  int pi[5002];
  int i,j;
  int len1,max=0,res;
  len1=strlen(gets(a+1));
  strcpy(b+1,a+1);
  for(i=0;i<len1;i++)
  {
    make_pi(pi,a+i);
    res=kmp(pi,b,a+i,len1-i);
    max=max<res?res:max;
    if(len1-i<=max)break;
  }
  printf("%d",max);
}
