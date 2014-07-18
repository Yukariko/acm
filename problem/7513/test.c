char word[51][6];
int i,j,n,m,p,q;
main(k,t)
{
  for(scanf("%d",&t);k<=t;k++)
  {
    scanf("%d ",&m);
    for(i=0;i<m;i++)gets(word+i);
    
    scanf("%d",&n);
    printf("Scenario #%d\n",k);
    for(i=0;i<n;i++)
    {
      scanf("%d",&p);
      for(j=0;j<p;j++){scanf("%d",&q);printf("%s",word[q]);}
      puts("");
    }
    puts("");
  }
}
