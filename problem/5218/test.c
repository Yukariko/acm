main()
{
  int t;
  for(scanf("%d",&t);t--;)
  {
    char a[21],b[21];
    scanf(" %s %s",a,b);
    printf("Distances :");
    int i;
    for(i=0;a[i];i++)
    {
      printf(" %d",a[i]<=b[i]?b[i]-a[i]:b[i]+26-a[i]);
    }
    puts("");
  }
}
