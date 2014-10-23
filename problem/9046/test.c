main()
{
  int T;
  for(scanf("%d ",&T);T--;)
  {
    char text[256];
    int check[26]={};
    int max=0;
    char res;
    gets(text);
    
    for(int i=0;text[i];i++)
    {
      if(text[i] >= 'a' && text[i] <= 'z')
      {
        int val = ++check[text[i]-'a'];
        if(max<val)
        {
          res = text[i];
          max = val;
        }
        else if (max == val) res = '?';
      }
    }
    printf("%c\n",res);
  }
}
