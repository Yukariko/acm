#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>

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

#define pii pair<int, int>

int L;
int i;
class compare
{
public:
	bool operator() (const pii& p, const pii& q)
	{
		if(p.second <= i && q.second <= i)
			return p.first > q.first;
		return p.first > q.first;
	}
};

int main()
{
	int N;
	N = _readInt();
	L = _readInt();

	priority_queue<pii , vector< pii >, compare> pq;
	for(i=0; i < N; i++)
	{
		int n = _readInt();
		pq.push(make_pair(n, i + L));
		while(pq.top().second <= i)
			pq.pop();
		printf("%d ",pq.top().first);
	}
	return 0;
}