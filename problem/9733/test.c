char cmd[][3]={"","Re","Pt","Cc","Ea","Tb","Cm","Ex"};
main()
{
  char a[3];
  int total[8]={};
  int i;
  for(;~scanf(" %s",a);)
  {
    total[0]++;
    for(i=1;i<8;i++)
      if(strcmp(a,cmd[i])==0)total[i]++;
  }
  for(i=1;i<8;i++)
  {
    printf("%s %d %.2f\n",cmd[i],total[i],(float)total[i]/total[0]);
  }
  printf("Total %d 1.00",total[0]);
}
