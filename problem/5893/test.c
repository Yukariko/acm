main()
{
  char bin[1001];
  char mulBin[1006];
  int len;
  int i,j,k,t;
  len=strlen(gets(bin));
  strcpy(mulBin,bin);
  for(i=len;i<len+4;i++)mulBin[i]='0';
  mulBin[i]=0;
  j=i-1;
  k=0;
  for(i=len-1;j>=0;i--,j--)
  {
    t=k+(i<0?'0':bin[i])+mulBin[j]-'0'*2;
    mulBin[j]=t%2+'0';
    k=t/2;
  }
  if(k)putchar('1');
  puts(mulBin);
}
