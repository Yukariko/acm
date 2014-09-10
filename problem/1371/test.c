main()
{
  int count[26]={};
  char a[5001];
  int i;
  for(;gets(a);)
  {
    for(i=0;a[i];i++)if(a[i]>' ')count[a[i]-'a']++;
  }
  int max=0;
  for(i=0;i<26;i++)max=max<count[i]?count[i]:max;
  for(i=0;i<26;i++)if(max==count[i])putchar(i+'a');
}
