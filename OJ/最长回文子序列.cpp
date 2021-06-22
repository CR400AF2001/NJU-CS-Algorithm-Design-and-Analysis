#include <iostream> 
#include <vector>
#include <string>

using namespace std;

int main() {
	string input;
	vector<char> inputstring;
	getline(cin, input);
	int inputlen = input.size();
	for (int i = 0; i < inputlen - 1; ++i) {
		if (input[i] != ' ') {
			inputstring.push_back(input[i]);
		}
	}
	int len = inputstring.size();
	short** lengthlist = new short*[len];
	for (int i = len - 1; i >= 0; --i) {
		lengthlist[i] = new short[len];
		lengthlist[i][i] = 1;
		if (i != 0) {
			lengthlist[i][i - 1] = 0;
		}
		for (int j = i + 1; j < len; ++j) {
			if (inputstring[i] == inputstring[j]) {
				lengthlist[i][j] = lengthlist[i + 1][j - 1] + 2;
			}
			else {
				lengthlist[i][j] = lengthlist[i + 1][j] >= lengthlist[i][j - 1] ? lengthlist[i + 1][j] : lengthlist[i][j - 1];
			}
		}
	}
	printf("%s\n", "I have read the rules about plagiarism punishment");

	printf("%d\n", lengthlist[0][len - 1]);
	return 0;
}