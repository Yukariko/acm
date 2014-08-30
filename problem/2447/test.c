char a[6562][6562];
main(){
  int n;
  int i,j,k=1,l=2,t=3,p;
  scanf("%d",&n);
  for(i=0;i<n;i++)a[0][i]='*';
  for(j=1;j<n;j++)
  {
    if(k<=j&&j<l)
    {
      for(p=i=0;i<n;i++)
      {
        a[j][i]=p>=k&&p<l?' ':a[j-k][i];
        p=p+1==t?0:p+1;
      }
    }
    else if(j==l)
    {
      for(i=0;i<k;i++)strcpy(a[j++],a[i]);
      k+=l;l=k*2;t*=3;
      j--;
    }
  }
  for(i=0;i<n;i++)puts(a[i]);
}
