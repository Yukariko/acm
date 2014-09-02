main()
{
  char a[1001];
  for(;gets(a),a[0]!='0';)
  {
    int i,s=0;
    for(i=0;a[i];i++)
    {
      s+=a[i]-'0';
    }
    int k;
    for(;s>=10;)
    {
      for(k=0;s;s/=10)k+=s%10;
      s=k;
    }
    printf("%d\n",s);
  }
}
