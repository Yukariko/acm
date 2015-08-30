#include <iostream>
#include <algorithm>

using namespace std;

const char *color[] = {"White", "Silver", "Gray", "Black", "Red", "Maroon", "Yellow", "Olive", "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple", NULL};
const int R[] = {255,192,128,0,255,128,255,128,0,0,0,0,0,0,255,128};
const int G[] = {255,192,128,0,0,0,255,128,255,128,255,128,0,0,0,0};
const int B[] = {255,192,128,0,0,0,0,0,0,0,255,128,255,128,255,128};

#define SQ(n) ((n)*(n))

int main()
{
	int r,g,b;
	while(cin >> r >> g >> b, r != -1)
	{
		int choose = -1;
		int d = 255*255*3;
		for(int i=0; color[i]; i++)
		{
			int nowd = SQ(R[i]-r) + SQ(G[i]-g) + SQ(B[i]-b);
			if(nowd < d)
			{
				d = nowd;
				choose = i;
			}
		}

		cout << color[choose] << '\n';
	}
	return 0;
}