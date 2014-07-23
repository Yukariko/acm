char a[101];
int rome[99];
char dim[]="IVXLCDM";
init()
{
  rome['I']=1;rome['V']=5;
  rome['X']=10;rome['L']=50;
  rome['C']=100;rome['D']=500;
  rome['M']=1000;
}
rome2dim(char *a)
{
  int i,p,s;
  for(p=s=i=0;a[i];i++)
  {
    if(p<rome[a[i]])s-=2*p;
    s+=rome[a[i]];
    p=rome[a[i]];
  }
  return s;
}
dim2rome(int p)
{
  int i,m,d,t;
  for(i=0;p;)
  {
    t=p;
    for(m=1000,d=3;t==p;m/=10,d--)
    {
      if(p>=m)
      {
        p-=m;
        a[i++]=dim[2*d];
      }
      else if(p>=m-m/10)
      {
        p-=m-m/10;
        a[i++]=dim[2*d-2];
        a[i++]=dim[2*d];
      }
      else if(p>=m/2)
      {
        p-=m/2;
        a[i++]=dim[2*d-1];
      }
      else if(p>=m/2-m/10)
      {
        p-=m/2-m/10;
        a[i++]=dim[2*d-2];
        a[i++]=dim[2*d-1];
      }
    }
  }
  a[i]=0;
}
main(i)
{
  init();
  i=rome2dim(gets(a))+rome2dim(gets(a));
  dim2rome(i);
  printf("%d\n%s",i,a);
}
