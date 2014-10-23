f(curNum,endNum,opt)
{
  int left,right;

  if(curNum < endNum)
  {
    left = endNum - curNum;
    right = 10 - left;
  }
  else if(curNum > endNum)
  {
    right = curNum - endNum;
    left = 10 - right;
  }
  else
  {
    left = 0;
    right = 0;
  }
  return opt?left:right;
}
main()
{
  int N;
  char init[10001];
  char fin[10001];
  int res[10001];
  int needLeft[10001],needRight[10001];
  int needLeftSum, needRightSum, needLeftCount, needRightCount;

  scanf("%d ",&N);
  gets(init);
  gets(fin);
  
  for(int i=0;init[i];i++)init[i]-='0';
  for(int i=0;fin[i];i++)fin[i]-='0';
  
  needLeftSum = needRightSum = 0;
  needLeftCount = needRightCount = 0;
  
  for(int i=0;i<N;i++)
  {
    int left,right;
    left = f(curNum,1);
    right = f(curNum,0);
    if(left < right)
    {
      needLeftSum += left;
      needLeftCount++;
    }
    else
    {
      needRightSum += right;
      needRightCount++;
    }
    needLeft[i] = left;
    needRight[i] = right;
  }

  int resCount = 0;
  for(int i=0;i<N;i++)
  {
    
  }
  
  printf("%d\n",resCount);
  for(int i=0;i<N;i++)printf("%d %d\n",i+1,res[i]);
}
