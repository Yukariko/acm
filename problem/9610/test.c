int x,y,s0,s1,s2,s3,s4;
main(n)
{
  for(scanf("%d",&n);n--;)
  {
    scanf("%d%d",&x,&y);
    if(x>0&&y>0)s1++;
    else if(x<0&&y>0)s2++;
    else if(x<0&&y<0)s3++;
    else if(x>0&&y<0)s4++;
    else s0++;
  }
  printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d",s1,s2,s3,s4,s0);
}
