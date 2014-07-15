char n[1000001];
int i,k,s;
main(){
  for(gets(n);n[1];k++)
  {
    for(s=i=0;n[i];i++)
    {
      s+=n[i]-'0';
    }
    sprintf(n,"%d",s);
  }
  printf("%d\n%s",k,(n[0]-'0')%3?"NO":"YES");
}
