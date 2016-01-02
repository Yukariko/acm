#include <bits/stdc++.h>

using namespace std;

int a[5];
const char* color = "RBYG";
int eq_color[127];
int eq_number[10];

int func1()
{
	bool eq = false;
	for(int i=0; color[i]; i++)
		if(eq_color[color[i]] == 5)
			eq = true;

	if(eq == false)
		return 0;

	for(int i=1; i < 5; i++)
		if(a[i-1] + 1 != a[i])
			return 0;

	return 900 + a[4];
}

int func2()
{
	for(int i=1; i < 10; i++)
		if(eq_number[i] >= 4)
			return 800 + i;
	return 0;
}

int func3()
{
	int find3 = 0, find2 = 0;
	for(int i=1; i < 10; i++)
		if(eq_number[i] == 3)
			find3 = i;
		else if(eq_number[i] == 2)
			find2 = i;

	if(find3 && find2)
		return 700 + find3 * 10 + find2;
	return 0;
}

int func4()
{
	for(int i=0; color[i]; i++)
		if(eq_color[color[i]] == 5)
			return 600 + a[4];
	return 0;
}

int func5()
{
	for(int i=1; i < 5; i++)
		if(a[i-1] + 1 != a[i])
			return 0;
	return 500 + a[4];
}

int func6()
{
	for(int i=1; i < 10; i++)
		if(eq_number[i] >= 3)
			return 400 + i;
	return 0;
}

int func7()
{
	int find = 0;
	for(int i=1; i < 10; i++)
		if(eq_number[i] >= 2)
		{
			if(find)
				return 300 + i * 10 + find;
			else
				find = i;
		}
	return 0;
}

int func8()
{
	for(int i=1; i < 10; i++)
		if(eq_number[i] >= 2)
			return 200 + i;
	return 0;
}

int func9()
{
	return 100 + a[4];
}

int main()
{
	for(int i=0; i < 5; i++)
	{
		char c;
		int n;
		scanf(" %c %d", &c, &n);
		a[i] = n;
		eq_color[c]++;
		eq_number[n]++;
	}

	sort(a, a + 5);

	vector<function<int()>> func = {
		func1, func2, func3, func4, func5, func6, func7, func8, func9
	};

	int ans = 0;
	for(int i=0; i < 9; i++)
		ans = max(ans, func[i]());

	printf("%d", ans);
	return 0;
}