main()
{
  int n;
  char a[200001];
  int count[26]={};
  scanf("%d ",&n); 
  gets(a);
  int i;
  for(i=0;a[i];i++)count[a[i]-'a']++;
  int max=0;
  for(i=0;i<26;i++)max=max<count[i]?count[i]:max;
  printf("%d",max==1?0:max);
}
