main()
{
  char a[8],b[8];
  char r[21]={};
  scanf("%s%s",a,b);
  int p=strlen(a)-1,q=strlen(b)-1;
  int i,s=0;
  for(i=19;p>=0||q>=0;i--)
  {
    s=(p<0?'0':a[p])+(q<0?'0':b[q])-2*'0';
    r[i]=s%10+'0';
    if(s>=10)r[--i]=s/10+'0';
    p--;
    q--;
  }
  puts(r+i+1);
}
