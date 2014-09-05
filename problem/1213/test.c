cmp(char *a,char *b){return *a>*b?1:*a<*b?-1:0;}
check(char *a)
{
  char t=a[0];
  int i,j=0,k=0,s;
  for(s=i=1;a[i];i++)
  {
    if(t!=a[i])
    {
      t=a[i];
      if(s%2==1){j++;k=i-1;}
      s=1;
    }
    else s++;
  }
  if(s%2==1){j++;k=i-1;}
  if(j>1)return -1;
  if(j==0)return -2;
  return k;
}
main()
{
  char a[51]={};
  char palin[51]={};
  int len=strlen(gets(a));
  int i,j,k;
  qsort(a,len,sizeof(char),cmp);
  k=check(a);
  if(k==-1){puts("I'm Sorry Hansoo");return;}
  for(j=i=0;i<len;i++)
  {
    if((k!=-2&&a[i]!=a[k])||a[i]==a[i+1])
    {
      palin[j++]=a[i];
      palin[len-j]=a[i];
      i++;
    }
  }
  if(k!=-2)
  {
    for(i=0;palin[i];i++);
  	palin[i]=a[k];
  }
  puts(palin);
}
