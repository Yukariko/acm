typedef struct words {char word[16];int index;} words;
char answer[2501][16];
words submit[2501];
int hash[2501];
int i,j,n,size,s;
sort(words *item1,words *item2)
{
  return strcmp(item1->word,item2->word);
}
cmp(char *key,words *value)
{
  return strcmp(key,value->word);
}
main()
{
  for(scanf("%d",&n);i<n;scanf(" %s",answer[i++]));
  for(i=0;i<n;submit[i].index=i++)scanf(" %s",submit[i].word);
  for(i=0;i<n;hash[i++]=-1);
  size = sizeof(words);
  qsort(submit,n,size,sort);
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(hash[i]==-1)hash[i]=((words *)bsearch(answer[i],submit,n,size,cmp))->index;
      if(hash[j]==-1)hash[j]=((words *)bsearch(answer[j],submit,n,size,cmp))->index;
      if(hash[i]<hash[j])s++;
    }
  }
  printf("%d/%d",s,n*(n-1)/2);
}
