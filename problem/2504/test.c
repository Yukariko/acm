char a[31];
int check[31];
int point[31];
int i,j;
main()
{
  for(gets(a);a[i];i++)
  {
    if(a[i]=='('||a[i]=='[')
    {
      check[j++]=a[i]=='('?')':']';
    }
    if(a[i]==')'||a[i]==']')
    {
      --j;if(j<0||check[j]!=a[i]){point[0]=0;break;}
      point[j]+=(check[j]==')'?2:3)*(point[j+1]?point[j+1]:1);
      point[j+1]=0;
    }
  }
  printf("%d",point[0]);
}
