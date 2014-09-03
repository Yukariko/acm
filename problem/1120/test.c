main()
{
  char a[51],b[51];
  scanf("%s %s",a,b);
  int alen,blen;
  alen=strlen(a);
  blen=strlen(b);
  int i,j,max=51;
  for(i=0;b[i+alen-1];i++)
  {
    int s=0;
    for(j=0;a[j];j++)
    {
      if(a[j]!=b[i+j])s++;
    }
    max=max>s?s:max;
  }
  printf("%d",max);
}
