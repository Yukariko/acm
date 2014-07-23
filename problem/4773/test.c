#define MAX_stack 10
#define EMPTY -987654321
typedef int DATA;
typedef struct stack{DATA data;struct stack *next;}stack;
stack *head[MAX_stack],*tail[MAX_stack];
void push(int index,DATA val)
{
  stack *p=head[index];
  head[index]=(stack *)malloc(sizeof(stack));
  head[index]->data=val;
  head[index]->next=p;
}
DATA pop(int index)
{
  stack *p=head[index];
  DATA result=head[index]->data;
  head[index]=head[index]->next;
  free(p);
  return result;
}
int isEmpty(int index)
{
  return head[index]->data==EMPTY;
}
void init(int index)
{
  head[index]=(stack *)malloc(sizeof(stack));
  head[index]->data=EMPTY;
  head[index]->next=0;
  tail[index]=head[index];
}
void destroy(int index)
{
  for(;!isEmpty(index);)pop(index);
}
stack *find(int index,DATA val)
{
  stack *p=head[index];
  for(;p;p=p->next)if(p->data==val)return p;
  return 0;
}

char a[101],b[101];
int rome[99];
char dim[]="IVXLCDM";
romeinit()
{
  rome['I']=1;rome['V']=5;
  rome['X']=10;rome['L']=50;
  rome['C']=100;rome['D']=500;
  rome['M']=1000;
}
rome2dim(char *a)
{
  int i,p,s;
  for(p=s=i=0;a[i];i++)
  {
    if(p<rome[a[i]])s-=2*p;
    s+=rome[a[i]];
    p=rome[a[i]];
  }
  return s;
}
char *dim2rome(int p,char *a)
{
  int i,m,d,t;
  for(i=0;p;)
  {
    t=p;
    for(m=1000,d=3;t==p;m/=10,d--)
    {
      if(p>=m)
      {
        p-=m;
        a[i++]=dim[2*d];
      }
      else if(p>=m-m/10)
      {
        p-=m-m/10;
        a[i++]=dim[2*d-2];
        a[i++]=dim[2*d];
      }
      else if(p>=m/2)
      {
        p-=m/2;
        a[i++]=dim[2*d-1];
      }
      else if(p>=m/2-m/10)
      {
        p-=m/2-m/10;
        a[i++]=dim[2*d-2];
        a[i++]=dim[2*d-1];
      }
    }
  }
  a[i]=0;
  return a;
}
main(i)
{
  init(0);
  romeinit();
  int p,q,t;
  for(;gets(a);)
  {
    if(a[0]=='+'||a[0]=='-'||a[0]=='*'||a[0]=='/'||a[0]=='=')
    {
      if(a[0]=='=')
      {
        if(isEmpty(0))puts("stack underflow");
        else if(head[0]->data<1||head[0]->data>4999)puts("out of range exception");
        else puts(dim2rome(head[0]->data,b));
        
      }
      else if(head[0]->data==EMPTY||head[0]->next->data==EMPTY)puts("stack underflow");
      else 
      {
        p=pop(0);
        q=pop(0);
        if(a[0]=='+')
        { 
          push(0,p+q); 
        }
        else if(a[0]=='-')
        {
          push(0,q-p);
        }
        else if(a[0]=='*')
        {
          push(0,p*q);
        }
        else if(a[0]=='/')
        {
          if(p==0){puts("division by zero exception");push(0,q);}
          else {push(0,q/p);}
        }
      }
    }
    else
    {
      push(0,rome2dim(a));
    }
  }
}
