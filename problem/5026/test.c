int n;
char a[50];
main()
{
  for(gets(a);gets(a);)
  {
    if(a[0]=='P')puts("skipped");
    else
    {
      int i;
      for(i=0;a[i]!='+';i++);
      printf("%d\n",atoi(a)+atoi(a+i+1));
    }
  }
}
