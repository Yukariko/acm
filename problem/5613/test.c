char a[9];s;k;main(n){for(s=atoi(gets(a));~scanf(" %c %d ",&k,&n);s=k=='+'?s+n:k=='-'?s-n:k=='/'?s/n:k=='*'?s*n:s);printf("%d",s);}
