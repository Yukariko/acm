float x,y,s;main(){for(scanf("%f%f%d",&x,&y,&s),s=x/y;~scanf("%f%f",&x,&y);)s=x/y<s?x/y:s;printf("%.2f",s*1000);}
