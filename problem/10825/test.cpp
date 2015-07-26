#include <iostream>
#include <algorithm>

using namespace std;

struct student
{
	string name;
	int lang;
	int eng;
	int math;
};

bool cmp(const student &p, const student &q)
{
	if(p.lang != q.lang)
		return p.lang > q.lang;
	if(p.eng != q.eng)
		return p.eng < q.eng;
	if(p.math != q.math)
		return p.math > q.math;
	return p.name < q.name;
}

int main()
{
	int N;

	cin >> N;

	student st[N];
	for(int i=0; i < N; i++)
		cin >> st[i].name >> st[i].lang >> st[i].eng >> st[i].math;

	sort(st, st + N, cmp);

	for(int i=0; i < N; i++)
		cout << st[i].name << "\n";
	return 0;
}