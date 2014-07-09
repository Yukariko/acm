long long A;B,C;
f(long long a,int b)
{
  if(b==0)return 1;
  if(b==1)return a%C;
  if(b%2==0)return f((a*a)%C,b/2);
  else return (a*f((a*a)%C,(b-1)/2))%C;
}
main(i){
  scanf("%lld%d%d",&A,&B,&C);
  printf("%d",f(A,B));
}
