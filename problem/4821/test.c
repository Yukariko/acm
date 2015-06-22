#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N;
	for(;scanf("%d",&N),N;)
	{
		char a[1001] = {};
		int low,high;
		char tok;

		do {
			scanf("%d%c",&low,&tok);
			if(tok == '-')
				scanf("%d%c",&high,&tok);
			else
				high = low;
			if(low > high || low > N)
				continue;
			if(high > N)
				high = N;

			for(;low <= high; low++)
				if(a[low] == 0)
					a[low] = 1;
		} while(tok != '\n');

		int ret = 0;
		for(int i=1;i<=N;i++)
			if(a[i])
				ret++;
		printf("%d\n",ret);
	}

	return 0;
}