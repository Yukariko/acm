int P,N;
float D,A,B,F;
main()
{
  for(scanf("%d",&P);P--;)
  {
    scanf("%d%f%f%f%f",&N,&D,&A,&B,&F);
    printf("%d %.2f\n",N,D/(A+B)*F);
  }
}
