char a[11],b[11];
char alpha[26];
int n,i,s,r,p,q;
main()
{
  scanf("%d %s ",&n,a);
  for(i=0;a[i];i++)alpha[a[i]-'A']++;
  for(;--n;)
  {
    char temp[26]={0};
    gets(b);
    for(i=0;b[i];i++)temp[b[i]-'A']++;
    for(p=q=s=i=0;i<26;i++)
    {
      if(alpha[i]-temp[i]==1)p++;
      if(alpha[i]-temp[i]==-1)q++;
      s+=abs(alpha[i]-temp[i]);
    }
    if(p>1||q>1)continue;
    if(s==2&&p==1&q==1)r++;
    else if(s<2)r++;
  }
  printf("%d",r);
}
