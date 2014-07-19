char channel[101][11];
int i,j,now;
swap(char *a,char *b)
{
  char t[101];
  strcpy(t,a);strcpy(a,b);strcpy(b,t);
}
main(N)
{
  for(scanf("%d ",&N);i<N;gets(channel+i++));
  for(;strcmp(channel[j],"KBS1");j++)putchar('1');
  for(;j--;swap(channel[j],channel[j+1]))putchar('4');
  for(;strcmp(channel[++j],"KBS2");)putchar('1');
  for(;j-->1;swap(channel[j],channel[j+1]))putchar('4');
}
