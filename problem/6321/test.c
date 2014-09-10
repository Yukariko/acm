main()
{
  int t;
  scanf("%d ",&t);
  int i,j;
  char a[51];
  for(i=1;i<=t;i++)
  {
    gets(a);
    printf("String #%d\n",i);
    for(j=0;a[j];j++)putchar(a[j]+1>'Z'?'A':a[j]+1);
    puts("\n");
  }
}
