char a[101],b[101],c;
int i,p,q;
main()
{
  p=strlen(gets(a));
  gets(&c);
  q=strlen(gets(b));
  if(c=='*')for(;i<p+q-1;i++)putchar(48+!i);
  else for(;i<p||i<q;i++)putchar(48+!i+(i==abs(p-q)));
}
