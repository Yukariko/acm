main()
{
  int r,c,zr,zc;
  scanf("%d%d%d%d ",&r,&c,&zr,&zc);
  char map[51][51];
  int i,j,k,l;
  for(i=0;i<r;i++)gets(map[i]);
  char res[255][255]={};
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      for(k=0;k<zr;k++)
      {
        for(l=0;l<zc;l++)
        {
          res[i*zr+k][j*zc+l]=map[i][j];
        }
      }
    }
  }
  for(i=0;i<r*zr;i++)puts(res[i]);
}
