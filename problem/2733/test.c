char a[128001];
int n;
main()
{
  
  scanf("%d ",&n);
  int i;
  for(i=1;i<=n;i++)
  {
    int point=0;
    unsigned char arr[32768]={0};
    int stack[10000];
    int stackPoint=0;
    memset(stack,255,4*10000);
    for(;;)
    {
      gets(a);
      if(strcmp("end",a)==0)break;
      int j
      for(j=0;a[j];j++)
      {
        if(a[j]=='%')break;
        switch(a[j])
        {
          case '+':
            arr[j]++;
            break;
          case '-':
            arr[j]--;
            break;
          case '.':
            putchar(a[j]);
            break;
          case '[':
            stack[stackPoint++]=j;
            break;
          case ']':
            break;
        }
      } 
    }
  }
}
