main()
{
  float k,s;
  scanf("%f",&k);
  for(;scanf("%f",&s),s!=999;)
  {
    printf("%.2f\n",s-k);
    k=s;
  }
}
