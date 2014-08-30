int A[50001],B[50001];
int markA[50001],markB[50001];
char selectA[50001],selectB[50001];
main()
{
  int m,n;
  int i,k,t;
  scanf("%d%d",&m,&n);
  for(i=1;i<=m;i++){scanf("%d",A+i);markB[A[i]]++;}
  for(i=1;i<=n;i++){scanf("%d",B+i);markA[B[i]]++;}
  for(;!k;)
  {
    k=1;
    for(i=1;i<=m;i++)
    {
      if(!selectA[i]&&markA[i]==0)
      {
        t=B[A[i]];
        selectA[i]='1';
        selectB[A[i]]='0';
        markA[t]--;
        if(markA[t]==0)i=t-1;
        k=0;
      }
    }
    for(i=1;i<=n;i++)
    {
      if(!selectB[i]&&markB[i]==0)
      {
        t=A[B[i]];
        selectB[i]='1';
        selectA[B[i]]='0';
        markB[t]--;
        if(markB[t]==0)i=t-1;
        k=0;
      }
    }
  }
  for(i=1;i<=m;i++)
  {
    if(!selectA[i])
    {
      selectA[i]='1';
      selectB[A[i]]='0';
    }
  }
  for(i=1;i<=n;i++)
  {
    if(!selectB[i])
    {
      selectB[i]='1';
      selectA[B[i]]='0';
    }
  }
  puts(selectA+1);puts(selectB+1); 
}
