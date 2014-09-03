main()
{
  char a[10001];
  char max[101]={};
  int m=0;
  for(;gets(a);)
  {
    int i,s=0;
    for(i=0;a[i];i++)
    {
      if(strncmp(a+i,"E-N-D",5)==0)
      {
        if(m<s)
        {
          m=s;
          strncpy(max,a+i-m,m);
        }
        for(i=0;i<m;i++)
        {
          putchar(max[i]>='A'&&max[i]<='Z'?max[i]+' ':max[i]);
        }
        return;
      }
      if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')||a[i]=='-')
      {
        s++;
      }
      else
      {
        if(m<s)
        {
          m=s;
          strncpy(max,a+i-m,m);
        }
        s=0;
      }
    }
    if(m<s)
    {
      m=s;
      strncpy(max,a+i-m,m);
    }
  }
}
