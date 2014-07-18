char n[11];
int s;
int digit_w[10]={5,0,7,7,2,7,7,1,7,7};
int digit_h[10][2]={{3,3},{2,2},{2,1},{2,2},{3,2},{1,2},{1,3},{2,2},{3,3},{3,2}};
int i,j,k;
main()
{
  scanf("%d%s",&s,n);
  for(i=0;i<2*s+3;i++)
  {
    for(k=0;n[k];k++)
    {
      if(i==0||i==s+1||i==2*s+2)
      {
        for(j=0;j<s+2;j++)
        {
          if(j==0||j==s+1)putchar(' ');
          else putchar(digit_w[n[k]-'0']&(1<<(i/(s+1)))?'-':' ');
        }
      }
      else
      {
        putchar(digit_h[n[k]-'0'][i>s]&1?'|':' ');
        for(j=0;j<s;j++)putchar(' ');
        putchar(digit_h[n[k]-'0'][i>s]&2?'|':' ');
      }
      putchar(' ');
    }
    puts("");
  }
}
