int a[51],i,j,t,m,k,p;
main(n,s){
    while(~scanf("%d",&n)){
    for(i=0;i<n;scanf("%d",a+i++));scanf("%d",&s);
    for(i=0;i<n&&s>0;i++)
    {
      p=m=-1;for(j=i,k=0;j<n&&k<=s;j++,k++)if(m<a[j]){m=a[j];p=j;}
      for(j=p;j>i&&s;j--){t=a[j];a[j]=a[j-1];a[j-1]=t;s--;}
    }
    for(i=0;i<n;i++)printf("%d ",a[i]);
    puts("");
    }
}
