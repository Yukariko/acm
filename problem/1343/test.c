main()
{
  char board[501];
  int i,j,k;
  for(i=0;board[i];i++)
  {
    if(board[i]=='X')
    {
      for(j=i;board[j]=='X';j++);
      k=j-i;
      if(k&1){puts("-1");return;}
      for(;i+4<=j;i+=4){board[i]='A';board[i+1]='A';board[i+2]='A';board[i+3]='A';}
      if(k%4==2){board[i]='B';board[i+1]='B';i+=2;}
    }
  }
  puts(board);
}
