int t;
int l,n;
int ant;
int max,min,p,q;
main()
{
  for(scanf("%d",&t);t--;)
  {
    max=min=0;
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
