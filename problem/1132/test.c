typedef struct SCORE{double s;int no;}SCORE;
cmp(SCORE *a,SCORE *b){return b->s>a->s?1:a->s>b->s?-1:0;}
main()
{
  int n;
  int count[13][11]={0};
  char a[51][13];
  SCORE score[11]={0};
  int encode[11];
  int i,j,k,l=0;
  scanf("%d ",&n);
  for(j=0;j<n;j++)
  {
    k=strlen(gets(a[j]));
    l=12;
    for(i=k-1;i>=0;i--,l--)count[l][a[j][i]-'A']++;
  }
  for(i=0;i<10;i++)score[i].no=i;
  double s=1;
  for(k=12;k>=0;k--)
  {
    for(i=0;i<10;i++)
    {
      score[i].s+=count[k][i]*s;
    }
    s*=10;
  }
  qsort(score,10,sizeof(SCORE),cmp);
  j=9;
  for(i=0;i<10;i++)
  {
    encode[score[i].no]='0'+j--;
  }
  long long p=0;
  for(i=0;i<n;i++)
  {
    for(j=0;a[i][j];j++)a[i][j]=encode[a[i][j]-'A'];
    a[i][j]=0;
    puts(a[i]);
    p+=atol(a[i]);
  }
  printf("%lld",p);
}
