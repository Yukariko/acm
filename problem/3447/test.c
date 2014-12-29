main()
{
  char a[101];
  for(;gets(a);)
  {
    int len = strlen(a);
    int stack[101][4] = {};
    int point = 0;
    int i,j;
    for(i=0;i<len;i++)
    {
      if(a[i] == 'B')
      {
        point++;
        stack[point][0] = 1;
        stack[point][1] = i;
      }
      else if(stack[point][0] == 1 && a[i] == 'U')
      {
        stack[point][0] = 2;
        stack[point][2] = i;
      }
      else if(stack[point][0] == 2 && a[i] == 'G')
      {
        stack[point][3] = i;
        for(j=1;j<4;j++)a[stack[point][j]] = 0;
        point--;
      }
      else
      {
        if(point)point--;
      }
    }   
    for(i=0;i<len;i++)if(a[i])putchar(a[i]);
    puts("");
  }
}
