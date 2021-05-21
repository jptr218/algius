#include "Algius.h"

void decompress(FILE* in, FILE* out) {
	string cipher;
	vector<bool> bin;

	int fsz = fsize(in);
	int brd = 0;

	for (int i = 0; i < 8; i++) {
		cipher += fgetc(in);
	}

	while (!feof(in)){
		brd++;
		if (brd % 50 == 0) {
			printPercent(((float)brd / (float)fsz) * 100);
		}

		byte tmp = byte(fgetc(in));

		for (int i = 0; i < 8; i++) {
			bin.push_back(tmp.at(i));
		}
	}

	for (int i = 0; i < bin.size(); i++) {
		if (bin[i]) {
			byte tByte = byte();
			for (int j = 0; j < 8; j++) {
				if (bin.size() > i + 1) {
					bool b = bin.at(i + 1);
					tByte.append(b);
					i++;
				}
				else {
					break;
				}
			}
			tByte.write(out);
		}
		else {
			int cIn = 0;
			bool stop = false;
			while (!stop) {
				if (bin.size() > i + 1) {
					bool b = bin.at(i + 1);
					if (b) {
						stop = true;
					}
					else {
						cIn++;
					}
					i++;
				}
				else {
					break;
				}
			}
			fwrite(cipher.substr(cIn, 1).c_str(), 1, cipher.substr(cIn, 1).length(), out);
		}
	}
}