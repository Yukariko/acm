char a[101],b[1001][101];
i;j;c;k;p;
f(char *a,char *b){
  int x=strlen(a);
  int y=strlen(b);
  return x>y?1:x<y?-1:strcmp(a,b);
}
main(n){
  for(scanf("%d\n",&n);n--;)
  {
    gets(a);
    for(i=0;a[i];p?j++:i++)
      for(c=p=k=0;a[i]>44&&a[i]<97;i++)
      {
        p=1;
        if(!c){
          b[j][0]=48;
          if(a[i]!=48)c=1;
        }
        if(c)b[j][k++]=a[i];
      }
  }
  qsort(b,j,101,f);
  for(i=0;i<j;i++)
  {
    printf("%s\n",b[i]);
  }
}
