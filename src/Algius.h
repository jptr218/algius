#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct byte {
	uint8_t b;
	int i;

	byte(char c = NULL);
	bool append(bool v);
	bool at(int i);
	void write(FILE* fs);
};

int fsize(FILE* f);
void printPercent(int p);

string getCipher(FILE* fs);

void compress(FILE* in, FILE* out, string cipher);
void decompress(FILE* in, FILE* out);