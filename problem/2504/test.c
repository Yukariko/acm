struct score{long long val,index;}v[100];
char a[61];
int check[61];
int point[61];
int i,j,c;
long long p,s;
find(long long n)
{
  int t;
  if(n)for(t=0;t<100;t++)if(v[t].val==n)return t;
  return -1;
}
main()
{
  for(gets(a);a[i];i++)
  {
    if(a[i]=='('||a[i]=='[')
    {
      check[j++]=a[i]=='('?')':']';
      point[j]=1;
    }
    if(a[i]==')'||a[i]==']')
    {
      point[j-1]+=(check[j-1]==')'?2:3)*point[j];
      --j;
      if(j<0||check[j]!=a[i]){c=1;break;}
    }
  }
  printf("%d\n",point[0]);
  while(1);
  if(!c&&!j)
  {
    v[0].val=p=1;
    for(i=0;a[i];i++)
    {
      if(a[i]=='('){p*=2;if(find(p)==-1)v[i+1].val=p;}
      if(a[i]=='['){p*=3;if(find(p)==-1)v[i+1].val=p;}
      if(a[i]==')'){c=find(p/2);v[c].index-=1;c=find(p);v[c].index+=1;v[c].val=p;p/=2;}
      if(a[i]==']'){c=find(p/3);v[c].index-=1;c=find(p);v[c].index+=1;v[c].val=p;p/=3;}
    }
     
    for(i=0;i<100;i++)s+=v[i].index>0?v[i].val*v[i].index:0;
  }
  printf("%lld",s);
}
