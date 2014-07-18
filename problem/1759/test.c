char crypt[16],t;
char print[16];
int i,j,L,C;
f(i,c)
{
  if(c==L)
  {
    int vowel=0,consonant=0;
    for(i=0;i<L;i++)
    {
      if(print[i]=='a'||print[i]=='e'||print[i]=='i'||print[i]=='o'||print[i]=='u')vowel++;
      else consonant++;
    }
    if(vowel>0&&consonant>1)puts(print);
    return;
  }
  for(;i<C;i++)
  {
    if(crypt[i])
    {
      print[c]=crypt[i];
      f(i+1,c+1);
    }
  }
}
main()
{
  for(scanf("%d%d",&L,&C);i<C;i++)scanf(" %c",crypt+i);
  for(i=0;i<C;i++)for(j=i;j>0;j--)if(crypt[j]<crypt[j-1]){t=crypt[j-1];crypt[j-1]=crypt[j];crypt[j]=t;}
  f(0,0);
}
