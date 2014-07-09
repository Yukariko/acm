struct tree{int left,right;}a[99];node;left;right;
p(i){if(i>64){putchar(i);p(a[i].left);p(a[i].right);}}
q(i){if(i>64){q(a[i].left);putchar(i);q(a[i].right);}}
r(i){if(i>64){r(a[i].left);r(a[i].right);putchar(i);}}
main(i){
  for(gets(&i);~scanf("%c %c %c\n",&node,&left,&right);)
  {
    a[node].left=left;
    a[node].right=right;
  }
  p(65);puts("");q(65);puts("");r(65);puts("");
}
