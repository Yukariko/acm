char a[101],b[101];
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
char *dim2rome(int p,char *a)
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
  return a;
}
main(i)
{
  init();
  int p,q,t;
  for(p=q=-1;gets(a);)
  {
    if(a[0]=='+'||a[0]=='-'||a[0]=='*'||a[0]=='/'||a[0]=='=')
    {
      if(a[0]=='=')
      {
        if(q==-1)puts("stack underflow");
        else if(q<1||q>4999)puts("out of range exception");
        else puts(dim2rome(q,b));
      }
      else if(p==-1||q==-1)puts("stack underflow");
      else if(a[0]=='+')
      {
        t=q;
        q=p+q;
        p=t;
      }
      else if(a[0]=='-')
      {
        t=q;
        q=p-q;
        p=t;
      }
      else if(a[0]=='*')
      {
        t=q;
        q=q*p;
        p=t;
      }
      else if(a[0]=='/')
      {
        if(q==0){puts("division by zero exception");q=p;p=-1;}
        else {t=q;q=p/q;p=t;}
      }
    }
    else
    {
      p=q;
      q=rome2dim(a);
    }
  }
}
