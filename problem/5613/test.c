s;k;main(n){for(scanf("%d",&s);~scanf(" %c%d",&k,&n);s=k=='+'?s+n:k=='-'?s-n:k=='/'?s/n:k=='*'?s*n:s);printf("%d",s);}
