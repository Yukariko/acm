main()
{
  char a[10001];
  gets(a);
  int i,j,k;
  for(i=j=k=0;a[i];i++)
  {
    if(strncmp(a+i,"JOI",3)==0)j++;
    else if(strncmp(a+i,"IOI",3)==0)k++;
  }
  printf("%d\n%d",j,k);
}
