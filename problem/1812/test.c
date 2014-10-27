main()
{
  int N;
  int a[1000],res;
  int i,sum;
  scanf("%d",&N);
  for(sum=i=0;i<N;i++){scanf("%d",a+i);sum+=a[i];}
  sum/=2;
  for(i=1;i<N;i+=2)sum-=a[i];
  res=sum;
  printf("%d\n",res);
  for(i=0;i<N-1;i++)
  {
  	res=a[i]-res;
    printf("%d\n",res);
  }
}
