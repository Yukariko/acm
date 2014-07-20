#include<string.h>
char word[6][4];
char puzzle[4][4];
f()
{
  int i,j,k;
  int mask[6]={0};
  for(k=i=0;i<3;i++)
  {
    for(j=0;j<6;j++)
    {
      if(mask[j])continue;
      if(!strcmp(puzzle[i],word[j])){mask[j]=1;k++;break;}
    }
    for(j=0;j<6;j++)
    {
      if(mask[j])continue;
      if(puzzle[0][i]==word[j][0]&&puzzle[1][i]==word[j][1]&&puzzle[2][i]==word[j][2]){mask[j]=1;k++;break;}
    }
  }
  if(k==6)
  {
    for(i=0;i<3;i++)puts(puzzle[i]);
    exit(0);
  }
}
main(i,j,k)
{
  for(i=0;i<6;gets(word+i++));
  qsort(word,6,4,strcmp);
  for(i=0;i<6;i++)
  {
    strcpy(puzzle[0],word[i]);
    for(j=0;j<6;j++)
    {
      strcpy(puzzle[1],word[j]);
      for(k=0;k<6;k++)
      {
        if(i==j||j==k||i==k)continue;
        strcpy(puzzle[2],word[k]);
        f();
      }
    }
  }
  puts("0");
}
