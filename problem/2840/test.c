struct point{int spin;char letter;}point[101];
int chain[26],check[99];
int state;
main(i,n,k)
{
  for(scanf("%d%d",&n,&k);i<=k;i++)scanf("%d %c",&point[i].spin,&point[i].letter);
  for(chain[0]=--i;i>1;i--)
  {
    state=(state+point[i].spin)%n;
    if(chain[state]&&point[chain[state]].letter!=point[i-1].letter){puts("!");return;}
    chain[state]=i-1;
  }
  for(i=0;i<n;i++)if(chain[i]&&check[point[chain[i]].letter]++){puts("!");return;}
  for(i=0;i<n;i++)printf("%c",chain[i]?point[chain[i]].letter:'?');
}
