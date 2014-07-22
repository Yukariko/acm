int A[50001],B[50001];
int markA[50001],markB[50001];
char selectA[50001],selectB[50001];
int m,n;
int i,k;
main()
{
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
        selectA[i]='1';
        selectB[A[i]]='0';
        markA[B[A[i]]]--;
        k=0;
      }
    }
  }
  for(k=0;!k;)
  {
    k=1;
    for(i=1;i<=n;i++)
    {
      if(!selectB[i]&&markB[i]==0)
      {
        selectB[i]='1';
        selectA[B[i]]='0';
        markB[A[B[i]]]--;
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
      markA[B[A[i]]]--;
    }
  }
  for(i=1;i<=n;i++)
  {
    if(!selectB[i])
    {
      selectB[i]='1';
      selectA[B[i]]='0';
      markB[A[B[i]]]--;
    }
  }
  for(i=1;i<=m;i++)putchar(selectA[i]?selectA[i]:'?');puts("");
  for(i=1;i<=n;i++)putchar(selectB[i]?selectB[i]:'?');puts("");
}
