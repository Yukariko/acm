main()
{
  int n1,n2,t;
  char a[27],b[27],res[55]={},check[27];
  
  scanf("%d%d ",&n1,&n2);
  gets(a);gets(b);
  scanf("%d",&t);

  int i,j;
  for(i=0;a[i];i++)check[a[i]-'A']=1;
  for(i=0;b[i];i++)check[b[i]-'A']=-1;
  
  j=0;
  for(i=strlen(a)-1;i>=0;i--)res[j++]=a[i];
  strcat(res,b);
  for(;t--;)
  {
    char temp[55]={};
    for(i=0;i<n1+n2;i++)
    {
      if(i<n1+n2-1&&check[res[i]-'A']==1&&check[res[i+1]-'A']==-1)
      {
        temp[i]=res[i+1];
        temp[i+1]=res[i];
        i++;
      }
      else temp[i]=res[i];
    }
    strcpy(res,temp);
  }
  puts(res);
}
