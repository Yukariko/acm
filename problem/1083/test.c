a[51][9],i,j,t[9],r[9],*m,k,p;
f(char *x,char *y)
{
  strcpy(t,x);strcat(t,y);
  strcpy(r,y);strcat(r,x);
  return strcmp(t,r);
}

main(n,s){
  for(scanf("%d",&n);i<n;scanf("%s",a+i++));scanf("%d",&s);
  for(i=0;i<=n&&s>0;i++)
  {
    p=-1;m=" ";for(j=i,k=0;j<n&&k<=s;j++,k++)if(f(m,a[j])==-1){m=a[j];p=j;}
    for(j=p;j>0&&s;j--)
    {
      k=f(a[j],a[j-1]);
      if(k==1||(k==0&&strcmp(a[j],a[j-1])==1)){strcpy(t,a[j]);strcpy(a[j],a[j-1]);strcpy(a[j-1],t);s--;}
    }
  }
  for(i=0;i<n;i++)printf("%s ",a[i]);
}
