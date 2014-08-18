main()
{
  int x,y,k,t;
  for(;~scanf("%d%d",&x,&y);)
  {
    //It's not my solution. but more efficient.
    //long long Z=Y*100ll/X, t=100ll*(X-Y);
    //printf("%lld\n", Z<99?t/(99-Z)+!!(t%(99-Z))-X:-1);
    k=floor(((double)y/x)*100);
    int first=0,last=1000000001,mid;
    while(first<=last)
    {
      mid=(first+last)/2;
      t=floor(((double)(y+mid)/(x+mid))*100);
      if(k<t)last=mid-1;
      else first=mid+1;
    }
    printf("%d\n",first>1000000000?-1:first<0?-1:first);
  }
}
