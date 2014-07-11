#define TOP 0
#define LEFT 0
#define RIGHT 1
#define DOWN 2
visible_dice[][3]={ // face of dice. enum top, left, right
{1,2,3},{1,3,5},{1,5,4},{1,4,2},
{2,1,4},{2,4,6},{2,6,3},{2,3,1},
{3,1,2},{3,2,6},{3,6,5},{3,5,1},
{4,2,1},{4,1,5},{4,5,6},{4,6,2},
{5,1,3},{5,3,6},{5,6,4},{5,4,1},
{6,3,2},{6,2,4},{6,4,5},{6,5,3} 
};
turn_dice[][3]={//enum left,right,down
 {9,12,16},{17,7,13},{14,11,4},{5,19,8},
 {13,8,21},{22,3,9},{10,15,0},{1,20,12},
 {4,16,20},{21,0,17},{18,6,1},{2,23,7},
 {0,21,19},{16,4,22},{23,2,5},{6,18,3},
 {8,13,23},{20,1,14},{15,10,2},{3,22,11},
 {7,17,15},{12,9,18},{19,5,10},{11,14,6} 
};
long long s;i;j;state;rotate;t;
main(r,c)
{
  rotate=LEFT;
  for(scanf("%d%d",&r,&c);j<r;j++)
  { 
    rotate=rotate==LEFT?RIGHT:LEFT;
    s+=c/4*14;
    t=c%4;
    for(i=0;i<t-1;i++)
    {
     // printf("%d ",visible_dice[state][TOP]);
      s+=visible_dice[state][TOP];
      state = turn_dice[state][rotate];
    }
    if(t>0)
    {
     // printf("%d\n",visible_dice[state][TOP]);
      s+=visible_dice[state][TOP];
      state = turn_dice[state][DOWN];
    }
  }
  printf("%lld",s);
}
