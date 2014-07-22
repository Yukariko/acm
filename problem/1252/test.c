char bin1[81],bin2[81];
char answer[81];
int i,s,c;
reverse(char *p)
{
  int len=strlen(p);
  int i;
  char t;
  for(i=0;i<len/2;i++)
  {
    t=p[i];
    p[i]=p[len-i-1];
    p[len-i-1]=t;
  }
  return p;
}
main()
{
  scanf("%s%s",bin1,bin2);
  reverse(bin1);reverse(bin2);
  for(;bin1[i]||bin2[i];i++)
  {
    bin1[i]=bin1[i]=='1';
    bin2[i]=bin2[i]=='1';
    c=(bin1[i]+bin2[i]+s)%2;
    s=(bin1[i]+bin2[i]+s)/2;
    answer[i]=c+'0';
  }
  if(s)answer[i]='1';
  reverse(answer);
  for(c=i=0;answer[i];i++)
  {
    if(answer[i]=='1')c=1;
    if(c)
    {
      puts(&answer[i]);
      break;
    }
  }
  if(!answer[i])puts("0");
}
