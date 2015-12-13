#include <stdio.h>

using namespace std;

static char _buffer[8192*4];
static int _currentChar = 0;
static int _charsNumber = 0;
 
static inline char _read() {
	if (_currentChar == _charsNumber) {
		_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
		_currentChar = 0;
	}
	return _buffer[_currentChar++];
}
 
static inline int _readInt() {
	int c, x;
	x = _read();
	c = _read();
	if(c > 32)
	{
		x = x * 10 + c - '0';
		_read();
	}
	return x;
}

static inline int _readRInt() {
	int c, x;
	c = _read();
	x = 0;
	while (c > 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}
	return x;
}

static inline char _readChar()
{
	char a;
	_read();
	a = _read();
	_read();
	while ( _read() > 32);
	return a;
}

int main()
{
	int N = _readRInt();
	char out[4096];
	int outp = 0;
	int b = 0;

	while(N--)
	{
		switch(_readChar())
		{
		case 'd': b |= 1 << _readInt(); break;
		case 'e': b &= ~(1 << _readInt()); break;
		case 'h': out[outp++] = '0' + ((b & (1 << _readInt())) > 0); out[outp++] = 10;
		 if(outp == sizeof(out))
		 {
		 	 fwrite(out, 1, outp, stdout);
		 	 outp = 0;
		 }
		 break;
		case 'o': b ^= 1 << _readInt(); break;
		case 'l': b = 0xFFFFFF; break;
		case 'm': b = 0; break;
		}
	}
	fwrite(out, 1, outp, stdout);
	return 0;
}