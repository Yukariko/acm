cmp(char *a,char *b){return strcmp(b,a);}
char a[100001][12];
main()
{
  int n;
  scanf("%d ",&n);
  int i,j,k;
  for(i=0;i<n;i++)gets(a[i]);
  qsort(a,n,12,cmp);
  for(i=0;i<n;i++)
  {
    for(j=0;a[i][j]!=' ';j++);
    for(k=0;a[i+k][j+1]=='l';k++);
    if(k)i+=k*2-1;
    else {a[i][j]=0;puts(a[i]);}
  }
}
