#include "Algius.h"

void compress(FILE* in, FILE* out, string cipher) {
	byte cByte;
	int brd = 0;
	int fsz = fsize(in);

	fwrite(cipher.c_str(), 1, 8, out);
	while (!feof(in)) {
		if (brd % 50 == 0) {
			printPercent(((float)brd / (float)fsz) * 100);
		}
		brd++;

		char tmp = fgetc(in);
		auto cInd = find(cipher.begin(), cipher.end(), tmp);
		if (cInd != cipher.end()) {
			if (cByte.append(0)) {
				cByte.write(out);
			}
			for (int i = 0; i < cInd - cipher.begin(); i++) {
				if (cByte.append(0)) {
					cByte.write(out);
				}
			}
			if (cByte.append(1)) {
				cByte.write(out);
			}
		}
		else {
			byte tmpB(tmp);
			if (cByte.append(1)) {
				cByte.write(out);
			}
			for (int i = 0; i < 8; i++) {
				if (cByte.append(tmpB.at(i))) {
					cByte.write(out);
				}
			}
		}
	}
	cByte.write(out);
}