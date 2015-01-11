const char *oper[6] = {">","<",">=","<=","==","!="};
const int len[6] = {1,1,2,2,2,2};
main()
{
	int a,b;
	char cmd[3];
	for(int T=1;scanf("%d%s%d",&a,cmd,&b),cmd[0] != 'E';T++)
	{
		int selOper;
		int tf;
		int cmdLen = strlen(cmd);
		for(int i=0;i<6;i++)
		{
			if(cmdLen == len[i] && strcmp(cmd,oper[i]) == 0)
			{
				selOper = i;
				break;
			}
		}
		
		switch(selOper)
		{
			case 0: tf = a > b; break;
			case 1: tf = a < b; break;
			case 2: tf = a >= b; break;
			case 3: tf = a <= b; break;
			case 4: tf = a == b; break;
			case 5: tf = a != b; break;
		}
		
		printf("Case %d: %s\n",T,tf?"true":"false");
	}
}
