#include <stdio.h>
#include <algorithm>

using namespace std;

static char _buffer[8192*64];
static int _currentChar = 0;
static int _charsNumber = 0;
 
static inline char _read() {
	if (_currentChar == _charsNumber) {
		_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
		_currentChar = 0;
	}
	return _buffer[_currentChar++];
}

static inline int _readRInt() {
	int c, x;
	c = _read();
	x = 0;
	while (c & 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}
	return x;
}

int main()
{
	int N = _readRInt();
	printf("%d\n", N);
	long long sum = 0;
	while(N--)
		sum += _readRInt();

	printf("%lld", sum);
	return 0;
}