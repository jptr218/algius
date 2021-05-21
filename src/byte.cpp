#include "Algius.h"

byte::byte(char c) {
	if (c != NULL) {
		b = c;
	}
	else {
		b = 0;
	}
	i = 0;
}

bool byte::append(bool v) {
	if (v) {
		b += 1 << (7 - i);
	}
	i++;
	return (i >= 8);
}

bool byte::at(int i) {
	uint8_t o = b;
	o = o << i;
	o = o >> 7;
	return o;
}

void byte::write(FILE* fs) {
	const char* s = (char*)&b;
	fwrite(s, 1, 1, fs);
	b = 0;
	i = 0;
}