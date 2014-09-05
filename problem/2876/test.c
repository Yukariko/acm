main()
{
  int n;
  scanf("%d",&n);
  int grade[2][6]={};
  for(;n--;)
  {
    int p,q;
    scanf("%d%d",&p,&q);
    grade[0][p]++;
    grade[1][q]++;
  }
  int max=1;
  int i;
  for(i=1;i<6;i++)
  {
    max=grade[0][max]<grade[0][i]?i:max;
  }
  int max2=1;
  for(i=1;i<6;i++)
  {
    max2=grade[1][max]<grade[1][i]?i:max;
  }
  if(grade[0][max]>grade[1][max2])
  {
    max2=grade[0][max];
  }
  else
  {
    max2=grade[1][max2];
  }
  printf("%d %d",max2,max);
}
