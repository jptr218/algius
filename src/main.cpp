#include "Algius.h"

int main(int argc, char* argv[]) {
	if (argc != 4) {
		cout << "Usage:" << endl << "algius [c/d] a.txt b.txt" << endl;
		return 1;
	}

	FILE* fr = fopen(argv[2], "rb");
	
	if (string(argv[1]) == "c") {
		FILE* fw = fopen(argv[3], "wb");
		compress(fr, fw, getCipher(fr));
		fclose(fw);
	}
	else {
		FILE* fw = fopen(argv[3], "w");
		decompress(fr, fw);
		fclose(fw);
	}
	
	cout << "               ";

	fclose(fr);
	
	return 1;
}