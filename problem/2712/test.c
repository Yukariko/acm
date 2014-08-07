int t;
float n;
char d[3];
main()
{
  for(scanf("%d",&t);t--;)
  {
    scanf("%f %s",&n,d);
    if(!strcmp(d,"kg"))
    {
      printf("%.4f %s",n*2.2046,"lb"); 
    }
    if(!strcmp(d,"lb"))
    {
      printf("%.4f %s",n*0.4536,"kg"); 
    }
    if(!strcmp(d,"l"))
    {
      printf("%.4f %s",n*0.2642,"g"); 
    }
    if(!strcmp(d,"g"))
    {
      printf("%.4f %s",n*3.7854,"l"); 
    }
    puts("");
  }
}
