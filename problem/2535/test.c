typedef struct RANK{int country,num,score;}RANK;
cmp(RANK *a,RANK *b)
{
  return a->score>b->score?-1:1;
}
main()
{
  int n;
  RANK r[101];
  int ck[101]={0};
  scanf("%d",&n);
  int i,k;
  for(i=0;i<n;i++)
  {
    scanf("%d%d%d",&r[i].country,&r[i].num,&r[i].score);
  }
  qsort(r,n,sizeof(RANK),cmp);
  for(k=i=0;i<n;i++)
  {
    if(ck[r[i].country]<2)
    {
      printf("%d %d\n",r[i].country,r[i].num);
      ck[r[i].country]++;
      k++;
      if(k==3)break;
    }
  }
}
