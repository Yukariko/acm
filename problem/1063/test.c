main()
{
  char king[3];
  char stone[3];
  char move[3];
  int n;
  scanf("%s %s %d ",king,stone,&n);
  for(;n--;)
  {
    gets(move);
    char x=0,y=0;
    switch(move[0])
    {
    case 'R':
      x=1;y=0;
      if(move[1]=='T')y=1;
      if(move[1]=='B')y=-1;
      break;
    case 'L':
      x=-1;y=0;
      if(move[1]=='T')y=1;
      if(move[1]=='B')y=-1;
      break;
    case 'B':
      x=0;y=-1;
      break;
    case 'T':
      x=0;y=1;
      break;
    }
    if(king[0]+x>'H'||king[0]+x<'A'||king[1]+y>'8'||king[1]+y<'1')continue;
    king[0]+=x;king[1]+=y;
    if(strcmp(king,stone)==0){
      if(stone[0]+x>'H'||stone[0]+x<'A'||stone[1]+y>'8'||stone[1]+y<'1')
      {
        king[0]-=x;king[1]-=y;
        continue;
      }
      stone[0]+=x;stone[1]+=y;
    }
  }
  puts(king);
  puts(stone);
}
