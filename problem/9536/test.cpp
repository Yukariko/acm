#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	scanf("%d ",&T);

	while(T--)
	{
		char a[10001];
		gets(a);
		string w[101];
		int wc = 0;

		char *p = strtok(a, " ");
		do
			w[wc++] = p;
		while(p = strtok(NULL, " "));

		string animal;
		while(cin >> animal >> animal, animal == "goes")
		{
			cin >> animal;
			for(int i=0; i < wc; i++)
				if(w[i] == animal)
					w[i][0] = 0;
		}
		for(int i=0; i < wc; i++)
			if(w[i][0])
				cout << w[i] << " ";
		gets(a);
		cout << endl;
	}

	return 0;
}