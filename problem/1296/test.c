#include <string.h>
int loveCalc(char *a,char *b)
{
  int L,O,V,E;
  L=O=V=E=0;
  int i;
  for(i=0;a[i];i++)
  {
    if(a[i]=='L')L++;
    if(a[i]=='O')O++;
    if(a[i]=='V')V++;
    if(a[i]=='E')E++;
  }
  for(i=0;b[i];i++)
  {
    if(b[i]=='L')L++;
    if(b[i]=='O')O++;
    if(b[i]=='V')V++;
    if(b[i]=='E')E++;
  }
  return ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E))%100;
}
main()
{
  char minsik[21];
  gets(minsik);
  int n;
  scanf("%d ",&n);
  char girl[51][21];
  int i;
  for(i=0;i<n;i++)gets(girl[i]);
  qsort(girl,n,21,strcmp);
  int t,max=-1,sel;
  for(i=0;i<n;i++)
  {
    t=loveCalc(minsik,girl[i]);
    if(max<t)
    {
      max=t;
      sel=i;
    }
  }
  puts(girl[sel]);
}
