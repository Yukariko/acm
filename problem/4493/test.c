int t,n;
char a,b;
main()
{
  for(scanf("%d",&t);t--;)
  {
    int win1=0,win2=0;
    for(scanf("%d",&n);n--;)
    {
      scanf(" %c %c",&a,&b);
      if(a==b)continue;
      if(a=='R')
      {
        if(b=='P')win2++;
        else win1++;
      }
      if(a=='P')
      {
        if(b=='S')win2++;
        else win1++;
      }
      if(a=='S')
      {
        if(b=='R')win2++;
        else win1++;
      }
    }
    if(win1==win2)puts("TIE");
    else printf("Player %d\n",win1>win2?1:2);
  }
}
