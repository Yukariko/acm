struct WORDBOOK{int len;char word[51];}wordbook[20001];
int i,temp;
cmp(struct WORDBOOK *a,struct WORDBOOK *b)
{
  return a->len > b->len?1:a->len < b->len?-1:strcmp(a->word,b->word);
}
main(n)
{
  for(scanf("%d ",&n);gets(wordbook[i].word);++i)wordbook[i].len=strlen(wordbook[i].word);
  qsort(wordbook,n,sizeof(struct WORDBOOK),cmp);
  for(i=1;i<=n;i++)if(strcmp(wordbook[temp].word,wordbook[i].word)){puts(wordbook[temp].word);temp=i;}
}
