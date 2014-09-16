char b[201];
match(i,n)
{
  int j,k,t;
  if(i>=n)return 1;
  if(b[i]=='0')
  {
    if(i+1<n&&b[i+1]=='1')return match(i+2,n);
    else return 0;
  }
  if(b[i]=='1')
  {
    for(j=i+1;j<n&&b[j]=='0';j++);
    if(j-i<=2||b[j]!='1')return 0;
    for(k=j+1;k<n&&b[k]=='1';k++);
    if (k-j>1&&b[k]=='0')
    {
      j=match(k-1,n);
      if(j)return j;
    }
    return match(k,n);
  }
}
main()
{
  for(;gets(b);)
  {
    puts(match(0,strlen(b))?"SUBMARINE":"NOISE");
  }
}
