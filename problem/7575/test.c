int program[101][1001],length[1001];
int match[1001],reverse[1001],reverse_match[1001];
int N,K,L;
pi(int *q,int *p)
{
  int i=1,j=0;
  for(;i<=K;)
  {
    if(!j||p[i]==p[j])
    {
      j++;i++;q[i]=j;
    }
    else j=q[j];
  }
}
kmp(int *q,int *a,int *p,int len)
{
  int i,j;
  for(i=j=1;i<=len;)
  {
    if(!j||a[i]==p[j]){i++;j++;}
    else j=q[j];
    if(j==K+1) return 1;
  }
  return 0;
}
main()
{
  int i,j,k,t,q,s;
  
  scanf("%d%d",&N,&K);
  for(i=0;i<N;i++)
  {
    scanf("%d",&length[i]);
    for(j=1;j<=length[i];scanf("%d",&program[i][j++]));
  }
  for(i=1;program[0][i+K];i++)
  {
    pi(match,&program[0][i-1]);
    for(j=1;j<=K;j++)
    {
      reverse[j]=program[0][i+K-j];
    }
    pi(reverse_match,reverse);
    for(s=j=1;j<N;j++)
    {
      if(kmp(match,program[j],&program[0][i-1],length[j]))s++;
      else if(kmp(reverse_match,program[j],reverse,length[j]))s++;
      else break;
    }
    if(s==N){puts("YES");return;}
  }
  puts("NO");
}
