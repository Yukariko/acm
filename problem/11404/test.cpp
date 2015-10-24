#include <bits/stdc++.h>

using namespace std;

typedef long long lint;
typedef long double llf;
static char _buffer[1024];
static int _currentChar = 0;
static int _charsNumber = 0;
 
static inline int _read() {
	if (_charsNumber < 0) {
	exit(1);
	}
	if (!_charsNumber || _currentChar == _charsNumber) {
	_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
	_currentChar = 0;
	}
	if (_charsNumber <= 0) {
	return -1;
	}
	return _buffer[_currentChar++];
}
 
static inline long long _readLong() {
	int c, s;
	lint x;
	c = _read();
	while (c <= 32) c = _read();
	x = 0;
	s = 1;
	if (c == '-') {
	s = -1;
	c = _read();
	}
	while (c > 32) {
	x *= 10;
	x += c - '0';
	c = _read();
	}
	if (s < 0) x = -x;
	return x;
}
 
static inline int _readInt() {
	int c, x, s;
	c = _read();
	while (c <= 32) c = _read();
	x = 0;
	s = 1;
	if (c == '-') {
	s = -1;
	c = _read();
	}
	while (c > 32) {
	x *= 10;
	x += c - '0';
	c = _read();
	}
	if (s < 0) x = -x;
	return x;
}

const int INF = 987654321;

int main()
{
	int d[101][101];
	int N = _readInt(), M = _readInt();

	for(int i=1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
			d[i][j] = INF;
		d[i][i] = 0;
	}

	for(int i=0; i < M; i++)
	{
		int y = _readInt(), x = _readInt(), w = _readInt();
		d[y][x] = min(d[y][x], w);
	}

	for(int k=1; k <= N; k++)
		for(int i=1; i <= N; i++)
			for(int j=1; j <= N; j++)
				if(d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	for(int i=1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
			printf("%d ", d[i][j]);
		puts("");
	}
	return 0;
}