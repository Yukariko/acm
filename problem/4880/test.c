int a,b,c;
int ap,gp;
main()
{
  for(;scanf("%d%d%d",&a,&b,&c),a||b||c;ap=gp=0)
  {
    if(b-a==c-b)
    {
      ap=b-a;
    }
    else
    {
      gp=c/b;
    }
    printf("%s %d\n",ap?"AP":"GP",ap?ap:gp);
  }
}
