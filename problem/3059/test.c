s;i;a[99];char b[1001];
main(n){
  for(gets(b);gets(b);n++)
  {
    for(s=i=0;b[i];i++)a[b[i]]=n;
    for(i=65;i<91;i++)s+=a[i]-n?i:0;
    printf("%d\n",s);
  }
}
