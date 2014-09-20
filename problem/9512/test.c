char word[101][130][258];
char frontWord[101][258];
int n;
int count[101];
find(char *ck)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<count[i];j++)
    {
      if(strcmp(ck,word[i][j])==0)return i;
    }
  }
  return -1;
}
main()
{

  scanf("%d ",&n);
  int i,j,k;
  int p;
  char a[258];
  for(i=0;i<n;i++)
  {
    scanf("%s",frontWord[i]);
    gets(a);
    for(k=j=0;a[j];j++)
    {
      if((a[j]>='a'&&a[j]<='z')||a[j]=='\''||a[j]=='-'||(a[j]>='A'&&a[j]<='Z'))
      {
        word[i][count[i]][k++]=toupper(a[j]);
      }
      else if(k){count[i]++;k=0;}
    }
    if(k)count[i]++;
  }
  char aword[258];
  gets(a);
  for(;gets(a);)
  {
    for(k=i=0;a[i];i++)
    {
      if((a[i]>='a'&&a[i]<='z')||a[i]=='\''||a[i]=='-'||(a[i]>='A'&&a[i]<='Z'))
      {
        aword[k++]=toupper(a[i]);
      }
      else if(k)
      {
        aword[k]=0;
        k=0;
        j=find(aword);
        if(j!=-1)
        {
          puts(frontWord[j]);
          break;
        }
      }
    }
    if(k)
    {
      aword[k]=0;
      j=find(aword);
      if(j!=-1)puts(frontWord[j]);
    }
  }
}
