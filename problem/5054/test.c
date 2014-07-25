int min,max;
int t,n,k;
main()
{
  for(scanf("%d",&t);t--;)
  {
    min=99;max=0;
    for(scanf("%d",&n);n--;min=k<min?k:min){scanf("%d",&k);max=max<k?k:max;}
    printf("%d\n",(max-min)*2);
  }
}
