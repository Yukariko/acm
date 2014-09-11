main()
{
  char c;
  int a,b;
  for(;scanf(" %c%d%c%d",&c,&a,&c,&b),a;)
  {
    char k[31]={};
    int i=29;
    for(;b>0;b=(b-1)/26)k[i--]=(b-1)%26+'A';
    printf("%s%d\n",k+i+1,a);
  }
}
