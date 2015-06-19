#include <stdio.h>

struct tree {
	int left,right;
};

struct tree a[99];

void preorder(int i)
{
	if(i >= 'A')
	{
		putchar(i);
		preorder(a[i].left);
		preorder(a[i].right);
	}
}
void inorder(int i)
{
	if(i >= 'A')
	{
		inorder(a[i].left);
		putchar(i);
		inorder(a[i].right);
	}
}
void postorder(int i)
{
	if(i >= 'A')
	{
		postorder(a[i].left);
		postorder(a[i].right);
		putchar(i);
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
  	{
		char node, left, right;
		scanf(" %c %c %c",&node,&left,&right);
		a[node].left=left;
		a[node].right=right;
	}
  
	preorder('A');
	puts("");
	inorder('A');
	puts("");
	postorder('A');
	puts("");
	return 0;
}
