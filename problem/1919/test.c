char a[1001],b[1001];
int aIndex[27];bIndex[27];
int i,s;
main()
{
  gets(a);gets(b);
  for(i=0;a[i];i++)aIndex[a[i]-'a']++;
  for(i=0;b[i];i++)bIndex[b[i]-'a']++;
  for(i=0;i<26;i++)s+=abs(aIndex[i]-bIndex[i]);
  printf("%d",s);
}
