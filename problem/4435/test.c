main()
{
  const int gandalf[]={1,2,3,3,4,10};
  const int sauron[]={1,2,2,2,3,5,10};
  int t,j;
  scanf("%d",&t);
  for(j=1;j<=t;j++)
  {
    int i,k,gs,ss;
    for(i=gs=0;i<6;i++)
    {
      scanf("%d",&k);
      gs+=gandalf[i]*k;
    }
    for(i=ss=0;i<7;i++)
    {
      scanf("%d",&k);
      ss+=sauron[i]*k;
    }
    printf("Battle %d: %s\n",j,gs>ss?"Good triumphs over Evil":gs<ss?"Evil eradicates all trace of Good":"No victor on this battle field");
  }
}
