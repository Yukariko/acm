#define MAX(a,b) (a>b?a:b)
make_pi(int *pi,char *p)
{
  int i=1,j=0;
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
  int i,j,max=1;
  for(i=j=1;p[i];)
  {
    if(!j||p[i]==q[j]){i++;j++;}
    else j=pi[j];
    max=max<j?j:max;
    if(j==pi_len+1) return max-1;
  }
  return max-1;
}
main()
{
  char a[4002],b[4002];
  int pi[4002]={};
  int i,j;
  int len1,len2,max=0,res;
  len1=strlen(gets(a+1));
  len2=strlen(gets(b+1));
  if(len1<len2)
  {
    for(i=0;i<len1;i++)
    {
      make_pi(pi,a+i);
      res=kmp(pi,b,a+i,len1-i);
      max=max<res?res:max;
    }
  }
  else
  {
    for(i=0;i<len2;i++)
    {
      make_pi(pi,b+i);
      res=kmp(pi,a,b+i,len2-i);
      max=max<res?res:max;
    }
  }
  printf("%d",max);
}
