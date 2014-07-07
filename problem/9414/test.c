s,n,z,i,j,k=5000001,a[41];
main(t){
  for(scanf("%d",&t);t--;)
  {
    for(z=0;scanf("%d",a+z),a[z];z++);
    for(i=0;i<z;i++)
      for(j=i;j>=0;j--)
        if(a[j]<a[j+1])
        {
          n=a[j];
          a[j]=a[j+1];
          a[j+1]=n;
        }
    for(s=i=0;i<z&&s<k;i++)
      s+=2*powl(a[i],i+1);
    s<k?printf("%d\n",s):puts("Too expensive");
  }
}
