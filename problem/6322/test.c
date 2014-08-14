int a,b,c;
main()
{
  int i;
  for(i=1;scanf("%d%d%d",&a,&b,&c),a;i++)
  {
    printf("Triangle #%d\n",i);
    if(a==-1)
    {
      if(sqrt(c*c-b*b) > 0)
        printf("a = %.3f\n\n",sqrt(c*c-b*b));
      else puts("Impossible.\n");
    }
    else if(b==-1)
    {
      if(sqrt(c*c-a*a) > 0)
        printf("b = %.3f\n\n",sqrt(c*c-a*a));
      else puts("Impossible.\n");
    }
    else if(c==-1)
    {
      printf("c = %.3f\n\n",sqrt(a*a+b*b));
    }
  }
}
