int rome[128];
char dim[]="mdclxvi";
init()
{
  rome['i']=1;rome['v']=5;
  rome['x']=10;rome['l']=50;
  rome['c']=100;rome['d']=500;
  rome['m']=1000;
}
main(m,k,j,i,n)
{
  init();
  for(scanf("%d ",&n);n--;)
  {
    char a[10001];
    gets(a);
    int count[7]={10000,1,3,1,3,1,3};
    long long s=0;
    for(m=j=k=0;k<7;k++)
    for(i=m;a[i];i++)
    {
      if(a[i]==dim[k]&&count[k]>0)
      {
        count[k]--;
        s+=rome[a[i]];
        m=i;
      }
      else if(a[i]==dim[k]&&count[k]==0)
      {
        if(k==2||k==4)
        {
          int t;
          for(t=i;t>m;t--)if(a[t]==dim[k+2])break;
          if(t!=m)
          {
            s+=rome[a[i]]-rome[a[t]];
            m=i;
            count[k]--;
            count[k+1]=count[k+2]=0;
          }
        }
      }
    }
    printf("%lld\n",s);
  }
}
