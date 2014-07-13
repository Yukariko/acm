int swtch[101];
int i,j,sex,num;
main(t,n)
{
  for(scanf("%d",&n);i<n;scanf("%d",swtch+i++));
  for(scanf("%d",&t);t--;)
  {
    scanf("%d%d",&sex,&num);
    if(sex==1)//male
    {
      for(i=num-1;i<n;i+=num)swtch[i]=!swtch[i];
    }
    else //female
    {
      num--;swtch[num]=!swtch[num];
      for(i=1;num-i>=0&&num+i<n&&swtch[num-i]==swtch[num+i];i++){swtch[num-i]=!swtch[num-i];swtch[num+i]=!swtch[num+i];}
    }
  }
  for(i=0;i<n;i++){printf("%d ",swtch[i]);if(i%20==19)puts("");}
}
