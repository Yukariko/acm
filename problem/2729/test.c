bigplus(char *store,char *a,char *b)
{
  char t[1001]={0};
  int i=strlen(a),j=strlen(b),p,s;
  for(p=0;i||j;p++)
  {
    s = (i?a[i-1]:'0')+(j?b[j-1]:'0')-'0'*2;
    if(s+t[p]>0)t[p+1]+=(s+t[p])/2;
    t[p] = (s+t[p])%2;
    if(i>0)i--;
    if(j>0)j--;
  }
  if(!t[p])p--;
  for(i=0;i<=p;i++)
   store[p-i]=t[i]+'0';
  store[p+1]=0;
}
main()
{
  int t;
  for(scanf("%d ",&t);t--;)
  {
    char i[1001]={0},j[1001]={0};
    scanf(" %s %s",i,j);
    bigplus(i,i,j);
    int k=0;
    if(strlen(i)>1)for(;i[k]=='0';k++);
    printf("%s\n",&i[k]);
  }
}
