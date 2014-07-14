char a[1002],b[1002];
char plus[1003],minus[1003],multiple[1000002];
int end_a,end_b;
int sign_a,sign_b;
int add,num;
int i,j,k;
str2num(l)
{
  for(l=0;a[l];l++)a[l]-='0';for(l=0;b[l];l++)b[l]-='0';
}
num2str(char *arr)
{
  int l;
  for(l=0;arr[l];l++)arr[l]+='0';
}
main()
{
  gets(a);gets(b);
  end_a=strlen(a)-1;end_b=strlen(b)-1;
  sign_a=a[0]=='-'?-1:1;sign_b=b[0]=='-'?-1:1;
  str2num(0);
  for(i=end_a,j=end_b,k=1002;i>=0||j>=0;i--,j--,k--)
  {
    if(a[i]<0)i=-1;
    if(b[j]<0)j=-1;
    num=(i<0?0:a[i])*sign_a+(j<0?0:b[j])*sign_b+add;
    if(num<0){num=10+num;add=-1;}
    else {add=num/10;num%=10;}
    plus[k]=num+'0';
  }
  plus[k]=add+'0';
  printf("%s\n",add?&plus[k]:&plus[k+1]);
}
