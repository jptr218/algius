#include "Algius.h"

void printPercent(int p) {
	cout << "[" << p << "%]";

	int pp = p / 10;
	for (int i = 0; i < pp; i++) {
		cout << "*";
	}
	for (int i = pp; i < 10; i++) {
		cout << "%";
	}

	cout << "\r";
}

int fsize(FILE* f) {
	fseek(f, 0L, SEEK_END);
	int o = ftell(f);
	rewind(f);
	return o;
}