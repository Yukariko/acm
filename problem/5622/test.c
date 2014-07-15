int alpha[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
char dial[16];
int i,s;

main()
{
  for(gets(dial);dial[i];i++)s+=alpha[dial[i]-65]+1;
  printf("%d",s);
}
