main()
{
  char word[51],temp[51],answer[51];
  gets(word);
  int i,j,k,len=strlen(word);
  int p;
  strcpy(answer,word);
  for(i=0;i<len-2;i++)
  {
    p=0;
    for(k=i;k>=0;k--)temp[p++]=word[k];
    for(j=i+1;j<len-1;j++)
    {
      p=i+1;
      for(k=j;k>i;k--)temp[p++]=word[k];
      for(k=len-1;k>j;k--)temp[p++]=word[k];
      temp[p]=0;
      if(strcmp(temp,answer)==-1)strcpy(answer,temp);
    }
  }
  puts(answer);
}
