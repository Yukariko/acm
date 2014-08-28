main()
{
  int a,b;
  for(;scanf("%d%d",&a,&b),a;)
  {
    int min=a<b?a:b;
    int max=a<b?b:a;
    printf("%d\n",min*2-max);
  }
}
