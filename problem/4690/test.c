main()
{
  int a,b,c,d;
  for(a=2;a<=100;a++)
  {
    for(b=2;b<=100;b++)
    {
      for(c=b+1;c<=100;c++)
      {
        for(d=c+1;d<=100;d++)
        {
          if(b*b*b+c*c*c+d*d*d == a*a*a)
            printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
        }
      }
    }
  }
}
