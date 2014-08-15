int t;
int l,n;
int ant;
main()
{
  for(scanf("%d",&t);t--;)
  {
    int max=0,min=0,p,q;
    for(scanf("%d%d",&l,&n);n--;)
    {
      scanf("%d",&ant);
      p=l-ant>ant?l-ant:ant;
      q=l-p;
      max=max<p?p:max;
      min=min<q?q:min;
    }
    printf("%d %d\n",min,max);
  }
}
