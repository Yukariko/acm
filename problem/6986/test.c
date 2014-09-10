cmp(float *a,float *b){return *a>*b?1:*a<*b?-1:0;}
main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  float a[100001];
  int i;
  for(i=0;i<n;i++)scanf("%f",a+i);
  qsort(a,n,sizeof(float),cmp);
  float p=0,q;
  for(i=k;i<n-k;i++)
  {
    p+=a[i];
  }
  p/=n-2*k;
  q=a[k]*k+a[n-k-1]*k;
  for(i=k;i<n-k;i++)
  {
    q+=a[i];
  }
  q/=n;
  printf("%.2f\n%.2f",p+1e-6,q+1e-6);
}
