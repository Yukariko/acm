int count[1001];
int N,M,L;
int i,s;
main()
{
  scanf("%d%d%d",&N,&M,&L);
  for(i=0;++count[i]!=M;s++)
  {
    if(count[i]%2)i=(i-L<0?N+i-L:i-L);
    else i=(i+L)%N; 
  }
  printf("%d",s);
}

