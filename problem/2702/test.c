k;f(a,b){k=b?f(b,a%b):a;}main(n,m){for(gets(&n);~scanf("%d%d",&n,&m);printf("%d %d\n",n*m/k,k))f(n,m);}
