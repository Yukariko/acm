 int t;
 char a[10001];
 char b[10001];
 main()
 {
   for(scanf("%d ",&t);t--;)
   {
     int i,j;
     gets(a);
     j=sqrt(strlen(a))+1e-6;
     for(i=0;a[i];i++)
     {
       int x,y;
       x=i%j;
       y=i/j;
       b[(j-1-x)*j+y]=a[i];
     }
     b[j*j]=0;
     puts(b);
   }
 }
