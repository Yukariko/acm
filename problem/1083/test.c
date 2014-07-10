int a[51],i,j,t,m,p;
main(n,s){
    for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);scanf("%d",&s);
    for(i=0;i<n&&s>0;i++)
    {
      p=m=0;for(j=i;j<n&&j<=i+s;j++)if(m<=a[j]){m=a[j];p=j;}
      for(j=p;j>i&&s;j--){t=a[j];a[j]=a[j-1];a[j-1]=t;s--;}
    }
    for(i=0;i<n;i++)printf("%d ",a[i]);
}
