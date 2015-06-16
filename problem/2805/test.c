#include <stdio.h>

int a[1000001];

int main()
{
  int n,m;
  int max,min;
  int mid,s;
  scanf("%d%d",&n,&m);
  scanf("%d",a);

  max=min=a[0];
  for(int i=1;i<n;i++)
  {
    scanf("%d",&a[i]);
    if(max<a[i])
      max=a[i];
    else if(min>a[i])
      min=a[i];
  }
  
  while(min<=max)
  {
    mid=(max+min)/2;
    s=0;
    for(int i=0;i<n && s <m ;i++)
      if(a[i]>mid)
        s+=a[i]-mid;
        
    if(s<m)
			max=mid-1;
    else if(s>m)
			min=mid+1;
    else
		{
			max=mid;
			break;
		}
  }
  printf("%d",max);
}

