char piano[101],*p;
int a,c,k;
main(i)
{
  gets(piano);
  for(p=strtok(piano,"|");p;p=strtok(0,"|"))
  {
    for(i=2;i--;p+=strlen(p)-1)
    {
      if(p[0]=='A'||p[0]=='D'||p[0]=='E'){a+=i;k=0;}
      if(p[0]=='C'||p[0]=='F'||p[0]=='G'){c+=i;k=1;}
    }
  }
  puts(a>c?"A-minor":a<c?"C-major":k?"C-major":"A-minor");
}
