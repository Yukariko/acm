int a;
int k;
int s;
main()
{
  for(;scanf("%d",&a),a;)
  {
    int c[10001]={0};
    for(s=0;!c[a];s++)
    {
      c[a]=1;
      k=a*a;
      a=k/100%10000;
    }
    printf("%d\n",s);
  }
}
