typedef struct circum{int move,length;}circum;
#define circular(a) (a>=6?a-6:a)
main()
{
  int k;scanf("%d",&k);
  int i;
  circum a[6];
  for(i=0;i<6;i++)
  {
    scanf("%d%d",&a[i].move,&a[i].length);
  }
  int count=6;
  int w=-1,h=-1,pw=-1,ph=-1;
  for(i=0;i<6;i++)
  {
    if(a[i].length==a[circular(i+2)].length+a[circular(i+4)].length)
    {
      if(w==-1)w=a[i].length;
      else h=a[i].length;
    }
    if(a[i].move==a[circular(i+2)].move&&a[circular(i+1)].move==a[circular(i+3)].move)
    {
      pw=a[circular(i+1)].length;
      ph=a[circular(i+2)].length;
    }
  }
  printf("%d",k*(w*h-pw*ph));
}
