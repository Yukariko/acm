char *chem[]={"H","He",
"Li","Be","B","C","N","O","F","Ne",
"Na","Mg","Al","Si","P","S","Cl","Ar",
"K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",
"Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe",
"Cs","Ba","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn",
"Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Fl","Lv",
"La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu",
"Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr",0};
char hash[900];
char a[50001];
char dp[50001];
int isok;

f(pos)
{
  if(isok)return;
  if(!a[pos]){isok=1;return;}
  if(dp[pos])return;
  dp[pos]=1;
  if(hash[a[pos]])f(pos+1);
  if(hash[a[pos]*27+a[pos+1]])f(pos+2);
}

main()
{
  for(int i=0;chem[i];i++)
  {
    int val=0;
    for(int j=0;chem[i][j];j++)
    {
      val = val * 27 + (chem[i][j]<'a'?chem[i][j]+32:chem[i][j])-'a'+1;
    }
    hash[val]=1;
  }
  int T;
  for(scanf("%d ",&T);T--;)
  {    
    gets(a);
    memset(dp,0,sizeof(dp));
    for(int i=0;a[i];i++)a[i]-='a'-1;
    isok=0;
    f(0);
    puts(isok==1?"YES":"NO");
  }
}
