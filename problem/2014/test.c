cmp(int *a,int *b){return *a>*b?1:*a<*b?-1:0;}
int queue[1000001];
main()
{
  int k,n;
  scanf("%d%d",&k,&n);
  
  int i,j;
  for(i=0;i<k;i++)
  {
    scanf("%d",queue+i);
  }
  qsort(queue,k,4,cmp);
  int start,end;
  for(start=0;start<n;start=end)
  {
    end=k;
    for(j=start;j<end;j++)
    for(i=j-start;i<end;i++)
    {
      queue[k++]=queue[j]*queue[i];
    }
  }
  qsort(queue,k,4,cmp);
  printf("%d\n",k);
  for(i=0;i<100;i++)printf("%d ",queue[i]);
  printf("%d",queue[n-1]);
}
