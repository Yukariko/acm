char a[130001];
struct len{char cmd,count;}b[260002];
int n;
main()
{
  
  n=atoi(gets(a));
  int i;
  for(i=1;i<=n;i++)
  {
    int point=0;
    char arr[32768]={0};
    int stack[10000];
    int stackPoint=0;
    int j;
    int isJump=0;
    int k=1,p,t=0;
    int w;
    printf("PROGRAM #%d:\n",i);
    a[0]=0;
    b[0].cmd=b[0].count=0;
    for(j=0;;)
    {
      gets(a+j);
      if(strcmp("end",a+j)==0)break;
      for(;a[j]&&a[j]!='%';j++)
      {
        if(b[k-1].cmd==a[j])
        {
          b[k-1].count++;
        }
        else
        {
          b[k].cmd = a[j];
          b[k].count = 1;
          k++;
        }
      }
      a[j]=0;
    }
    b[k].cmd=0;
    for(p=1;b[p].cmd;p++)
    {
      if(isJump&&b[p].cmd!=']'){continue;}
      switch(b[p].cmd)
      {
        case '+':
          arr[point]=(arr[point]+b[p].count)%256;
          break;
        case '-':
          if (arr[point] >= b[p].count) arr[point]-=b[p].count;
          else for(w=b[p].count;arr[point] < w;w-=arr[point])arr[point]=256-w+point; 
          break;
        case '.':
          for(w=0;w<b[p].count;w++)putchar(arr[point]);
          break;
        case '>':
          point=(point+b[p].count)%32767;
          break;
        case '<':
          if (point >= b[p].count) point-=b[p].count;
          else for(w=b[p].count;point < w;w-=point)point=32768-w+point; 
          break;
        case '[':
          stack[stackPoint++]=p;
          if(arr[point]==0)isJump=1;
          break;
        case ']':
          isJump=0;
          if(stackPoint < 1){puts("COMPILE ERROR");b[p+1].cmd=0;a[0]=0;}
          else
          {
            if(arr[point]!=0){p=stack[--stackPoint]-1;stack[stackPoint]=-1;}
            else stack[--stackPoint]=-1;
          }
          break;
        default:
          break;
      }
    }
    if(stackPoint)puts("COMPILE ERROR");
    else if (a[0])
    {
      puts("");
    }
  }
}
