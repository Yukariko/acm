int n;
char a[1001],b[1001];
main()
{
  int i;
  scanf("%d ",&n);
  gets(a);gets(b);
  if(n&1)
  {
    int j;
    for(j=0;b[j];j++)if(b[j]==a[j])break;
    if(b[j]){puts("Deletion failed");return;}
  }
  else
  {
    int j;
    for(j=0;b[j];j++)if(b[j]!=a[j])break;
    if(b[j]){puts("Deletion failed");return;}
  }
  puts("Deletion succeeded");
}
