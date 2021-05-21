#include "Algius.h"

struct sort_arr {
	int arr[2][8];
	sort_arr() {
		arr[0][0] = 0;
		arr[0][1] = 0;
		arr[0][2] = 0;
		arr[0][3] = 0;
		arr[0][4] = 0;
		arr[0][5] = 0;
		arr[0][6] = 0;
		arr[0][7] = 0;
		arr[1][0] = 0;
		arr[1][1] = 0;
		arr[1][2] = 0;
		arr[1][3] = 0;
		arr[1][4] = 0;
		arr[1][5] = 0;
		arr[1][6] = 0;
		arr[1][7] = 0;
	}
};

void shiftForward(int in, _In_ int* arr) {
	for (int c = 7; c >= in; c--) {
		if (c != 7) {
			arr[c + 1] = arr[c];
		}
	}
}

sort_arr sortTop(vector<int> vec) {
	sort_arr top;

	int l = 0;
	for (int i : vec) {
		int k = 0;
		for (int j : top.arr[0]) {
			if (i > j) {
				shiftForward(k, top.arr[0]);
				shiftForward(k, top.arr[1]);
				top.arr[0][k] = i;
				top.arr[1][k] = l;
				break;
			}
			k++;
		}
		l++;
	}

	return top;
}

string getCipher(FILE* fs) {
	vector<char> bytes;
	vector<int> freq;

	sort_arr top;
	string topc;

	while (!feof(fs)) {
		char tmp = fgetc(fs);
		auto i = find(bytes.begin(), bytes.end(), tmp);

		if (i != bytes.end()) {
			freq[i - bytes.begin()] += 1;
		}
		else {
			bytes.push_back(tmp);
			freq.push_back(0);
		}
	}
	rewind(fs);

	top = sortTop(freq);

	for (int i = 0; i < 8; i++) {
		topc += bytes[top.arr[1][i]];
	}

	return topc;
}