long long A,B,C,R=1,D;a[1001];j;
main(i){
  for(scanf("%lld%lld%lld",&A,&B,&C),A%=C;B;B--)
  {
    R=(R*A)%C;
    for(j=1;j<i;j++)if (a[j]==R){break;} 
    if(j!=i)break;
    a[i++]=R;
 //   printf("%d %lld\n",i-1,R);
  }
  printf("%lld",B%(i-j)?a[B%(i-j)]:R);
}
