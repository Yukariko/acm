char cointoss[41];
int i,p;
main()
{
  for(scanf("%d ",&p);p--;puts(""))
  {
    int seq[8]={0};
    gets(cointoss);
    for(i=0;i<40;i++)cointoss[i]=cointoss[i]=='H';
    for(i=0;i<38;i++)seq[cointoss[i]*4+cointoss[i+1]*2+cointoss[i+2]]++;
    for(i=0;i<8;i++)printf("%d ",seq[i]);
  }
}
