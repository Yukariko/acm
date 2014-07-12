char s[101];i;c;j;k;
main()
{
  for(gets(s);s[i];i++)s[i]-'_'?s[i]<97?(j=1):0:(c=1);
  for(i=0;s[i]&&k<2;i++)k=s[i]-'_'?0:k+1;
  if((c&&j)||s[i-1]=='_'||s[0]<97||k>1)puts("Error!"); 
  else if(c)for(i=0;s[i];i++)s[i]-'_'?(putchar(s[i]-j),j=0):(j=32);
  else for(i=0;s[i];i++)s[i]<97?printf("_%c",s[i]+32):putchar(s[i]);
}
