typedef struct WINDOW
{
  char title[11];
  int sx,sy;
  int w,h;
} WINDOW;

cmp(WINDOW *p,WINDOW *q)
{
  return strcmp(p->title,q->title);
}

main()
{
  int m,n;
  char screen[101][101];
  char new_screen[101][101]={0};
  WINDOW win[101]={0};
  scanf("%d%d ",&m,&n);
  for(int i=0;i<m;i++)
  {
    gets(screen[i]);
  }
  int tnum=0;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(strncmp(&screen[i][j],"-|",2)==0)
      {        
        int k;
        win[tnum].sy=i;
        for(k=i+1;screen[k][j]!='-';k++);win[tnum].h=k-i+1;
        
        int len=0,t;
        for(k=j-1;screen[i][k]!='+';k--);win[tnum].sx=k;
        t=k;
        for(k=j+2;screen[i][k]!='|';win[tnum].title[len++]=screen[i][k++]);win[tnum].title[len]=0;
        for(;screen[i][k]!='+';k++);
        win[tnum].w=k-t+1;
        j=k;
        tnum++;
      }
    }
  }
  qsort(win,tnum,sizeof(WINDOW),cmp);
  for(int i=0;i<m;i++)for(int j=0;j<n;j++)new_screen[i][j]='.';
  for(int i=0;i<tnum;i++)
  {
    for(int j=0;j<win[i].h;j++)
    {
      for(int k=0;k<win[i].w;k++)
      {
        new_screen[j+i][k+i]=screen[win[i].sy+j][win[i].sx+k];
      }
    }
  }
  for(int i=0;i<m;i++)puts(new_screen[i]);
}
