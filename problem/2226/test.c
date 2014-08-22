bigplus(char *store,char *a,char *b)
{
  char t[1001]={0};
  int i=strlen(a),j=strlen(b),p,s;
  for(p=0;i||j;p++)
  {
    s = (i?a[i-1]:'0')+(j?b[j-1]:'0')-'0'*2;
    if(s+t[p]>9)t[p+1]+=(s+t[p])/10;
    t[p] = (s+t[p])%10;
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
  int n;
  char i[1001]={0},j[1001]={0},t[1001]={0};
  i[0]='0';
  j[0]='1';
  for(scanf("%d",&n);--n;)
  {
    strcpy(t,j);
    bigplus(j,j,i);
    bigplus(j,j,i);
    strcpy(i,t);
  }
  printf("%s",i);
}
