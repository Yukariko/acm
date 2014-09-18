main()
{
  char a[21],b[11];
  int i,c;
  for(scanf("%s%s",a,b);a[i]==b[i];c+=a[i]=='8');
  printf("%d",strlen(b)==strlen(a)?c:0);
}
