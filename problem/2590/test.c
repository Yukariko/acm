#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a>b?b:a)
int a[7];

three(num,two,one)
{
  int i,pick,res=101;
  if(num==0)
  {
    return three(a[3],two,one);
  }
  for(i=0;i<=5;i++)
  {
    pick=1+three(num-1,MAX(two-i,0),MAX(one-20+i*4,0));
    res=MIN(res,pick);
  }
  return res==101?0:res;
}
four(num,two,one)
{
  int i,pick,res=101;
  if(num==0)
  {
    return three(a[3],two,one);
  }
  for(i=0;i<=5;i++)
  {
    pick=1+four(num-1,MAX(two-i,0),MAX(one-20+i*4,0));
    res=MIN(res,pick);
  }
  return res==101?0:res;
}
main()
{
  int i,j,k,s;
  
  for(i=1;i<=6;i++)scanf("%d",a+i);
  
  s=a[6];
  for(;a[5];a[5]--)
  {
    a[0]=MAX(a[0]-11,0);
    s++;
  }
  for(;a[4];a[4]--)
  {
    j=MAX(a[2]-5,0);
    a[0]=MAX(a[0]-20+(a[2]-j)*4,0);
    a[2]=j;
    s++;
  }
  s+=a[3]/4;
  a[3]%=4;
  if(a[3]==3)
  {
    j=MAX(a[2]-1,0);
    a[0]=MAX(a[0]-9+(a[2]-j)*4,0);
    a[2]=j;
    s++;    
  }
  else if(a[3]==2)
  {
    j=MAX(a[2]-3,0);
    a[0]=MAX(a[0]-18+(a[2]-j)*4,0);
    a[2]=j;
    s++;        
  }
  else if(a[3]==1)
  {
    j=MAX(a[2]-5,0);
    a[0]=MAX(a[0]-27+(a[2]-j)*4,0);
    a[2]=j;
    s++;        
  }
  s+=a[2]/9;
  a[2]%=9;
  if(a[2])
  {
    j=MAX(a[2]-9,0);
    a[0]=MAX(a[0]-36+(a[2]-j)*4,0);
    a[2]=j;
    s++;      
  }
  s+=(a[0]+35)/36;
  printf("%d",s);
}
