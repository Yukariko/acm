main()
{
  int N;
  int i,j,k;
  int s=2,r=0,t;
  scanf("%d",&N);
  for(i=k=1;k<N;i++)
  {
    if(i==s)
    {
      s <<= 1;
      r++;
    }

    for(t=2,j=0;;t<<=1,j++)
    {
      if(((i - (t>>1)) & (t-1)) == 0) break;
    }
    k += 3+j;
  } 
  puts(k==N?"m":"o");
}
