main()
{
  int t;
  char a[100001];
  for(scanf("%d ",&t);t--;)
  {
    int ck[26]={};
    int i,ind;
    gets(a);
    for(i=0;a[i];i++)
    {
      ind=a[i]-'A';
      ck[ind]++;
      if(ck[ind]>=3&&(ck[ind]-3)%4==0&&a[i+1]!=a[i])break;
    }
    puts(!a[i]?"OK":"FAKE");
  }
}
