main()
{
  int N,M;
  char a[1000001];
  scanf("%d%d ",&N,&M);
  gets(a);
  
  int i,count=0,res=0;
  for(i=0;i<M;i++)
  {
    if(count == 0)
    {
      if(strncmp(&a[i],"IOI",3) == 0){i+=2;count++;}
    }
    else
    {
      if(a[i]=='O' && a[i+1] == 'I'){i++;count++;}
      else {i--;count=0;}
    }
    if(count >= N) res++;
  }
  printf("%d",res);
}
