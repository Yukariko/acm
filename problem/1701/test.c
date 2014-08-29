main()
{
  char a[5001],b[2501]={0};
  gets(a);
  int i,j,len;
  len=strlen(a)/2;
  
  for(i=len;i;i--)
  {
    strncpy(b,a,i);
    for(j=i;a[j];j++)
    {
      if(strncmp(a,b,i)==0)
      {
        printf("%d",i);return;
      }
    }
    
  }
}

