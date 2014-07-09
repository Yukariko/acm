char a[101],b[101],c[101];j;p;
main(i){for(gets(a);~scanf("%s%s",a,b);printf("%s & %s are %sanagrams.\n",a,c,p-i||i!=strlen(c)?"NOT ":""))for(strcpy(c,b),p=i=0;a[i];i++)for(j=0;b[j];j++)if(a[i]==b[j]){b[j]=32;p++;break;}}
