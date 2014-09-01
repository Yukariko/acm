typedef struct LinkedList
{
  char c;
  struct LinkedList *left,*right;
} LinkedList;
LinkedList *head,*tail;
void init()
{
  head=(LinkedList *)malloc(sizeof(LinkedList));
  head->left=0;
  head->right=0;
  tail=head;
}
void push(char c)
{
  tail->right=(LinkedList *)malloc(sizeof(LinkedList));
  tail->right->c=c;
  tail->right->left=tail;
  tail=tail->right;
  tail->right=0;
}
main()
{
  init();
  char a[100001];
  gets(a);
  int i;
  for(i=0;a[i];i++)push(a[i]);
  int n;
  LinkedList *ptr=tail,*tmp;
  for(scanf("%d ",&n);n--;)
  {
    gets(a);
    if(a[0]=='L')if(ptr!=head)ptr=ptr->left;
    if(a[0]=='D')if(ptr->right)ptr=ptr->right;
    if(a[0]=='B')
    {
      if(ptr!=head)
      {
        tmp=ptr;
        ptr->left->right=ptr->right;
        if(ptr->right)ptr->right->left=ptr->left;
        ptr=ptr->left;
        free(tmp);
      }

    }
    if(a[0]=='P')
    {
      tmp=ptr->right;
      ptr->right=(LinkedList *)malloc(sizeof(LinkedList));
      ptr->right->left=ptr;
      ptr->right->c=a[2];
      ptr->right->right=tmp;
      ptr=ptr->right;
      if(tmp)tmp->left=ptr;
    }
  }
  for(ptr=head->right;ptr&&ptr->c;ptr=ptr->right)printf("%c",ptr->c);
}
