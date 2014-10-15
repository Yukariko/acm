typedef char bool;
int n;
bool find;
char res[101];
f(p,s)
{
  s%=n;
  if(find)return;
  if(s==0)
  {
    find=1;
    res[p]=0;
    return;
  }
  if(p>=100)return;
  res[p]='1';
  f(p+1,s*10+1);
  if(find)return;
  res[p]='0';
  f(p+1,s*10);    
}
main()
{
  res[0]='1';
  for(;scanf("%d",&n),n;)
  {
    find=0;
    f(1,1);
    puts(res);
  }
}
