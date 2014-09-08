main()
{
  int n;
  scanf("%d",&n);
  int s=0;
  char a[102]={0};
  int i,j,k=100,len=1,bol,t;
  a[k]='0';
  for(s=0;s<n-1;s++)
  {
    bol=0;
    for(i=k;i>k-len;i--)
    {
      if(a[i-1]==0||a[i-1]>a[i]+1)
      {
        if(a[i]+1>'9')
        {
          bol=1;
          break;
        }
        else
        {
          j='0';
          for(t=k;t>i;t--)a[t]=j++;
          a[i]+=1;
          break;
        }
      }
    }
    if(bol)
    {
      len++;
      j='0';
      for(i=k;i>k-len;i--)a[i]=j++;
      if(j>'9'+1){puts("-1");return;}
    }
  }
  puts(a+k-len+1);
}
