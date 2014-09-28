main()
{
  int t;
  char a[51];
  for(scanf("%d ",&t);t--;)
  {
    gets(a);
    int stack,i;
    for(i=stack=0;a[i];i++)
    {
      if(a[i]=='(')stack++;
      if(a[i]==')')
      {
        if(stack==0)break;
        stack--;
      }
    }
    puts(a[i]||stack?"NO":"YES");
  }
}
