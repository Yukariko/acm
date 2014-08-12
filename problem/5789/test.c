main()
{
  char a[1001];
  for(gets(a);gets(a);puts(a[strlen(a)/2-1]==a[strlen(a)/2]?"Do-it":"Do-it-Not"));
}
