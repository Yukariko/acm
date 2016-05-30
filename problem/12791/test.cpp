#include <bits/stdc++.h>

using namespace std;

vector<pair<int, string>> a = {
	{1967, "DavidBowie"},
	{1969, "SpaceOddity"},
	{1970, "TheManWhoSoldTheWorld"},
	{1971, "HunkyDory"},
	{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
	{1973, "AladdinSane"},
	{1973, "PinUps"},
	{1974, "DiamondDogs"},
	{1975, "YoungAmericans"},
	{1976, "StationToStation"},
	{1977, "Low"},
	{1977, "Heroes"},
	{1979, "Lodger"},
	{1980, "ScaryMonstersAndSuperCreeps"},
	{1983, "LetsDance"},
	{1984, "Tonight"},
	{1987, "NeverLetMeDown"},
	{1993, "BlackTieWhiteNoise"},
	{1995, "1.Outside"},
	{1997, "Earthling"},
	{1999, "Hours"},
	{2002, "Heathen"},
	{2003, "Reality"},
	{2013, "TheNextDay"},
	{2016, "BlackStar"}
};

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		int s, e;
		scanf("%d%d", &s, &e);

		int ans = 0;
		for(size_t i=0; i < a.size(); i++)
			if(s <= a[i].first && a[i].first <= e)
				ans++;

		printf("%d\n", ans);
		for(size_t i=0; i < a.size(); i++)
			if(s <= a[i].first && a[i].first <= e)
				printf("%d %s\n", a[i].first, a[i].second.c_str());
	}
	return 0;
}