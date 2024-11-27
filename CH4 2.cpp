#include <iostream>
#include <string>
using namespace std;

int main () {
	string a;
	cin >> a;
	int C_Num = 0, H_Num = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		if (a[i] == 'C') {
			C_Num++;
		}
		if (a[i] == 'H') {
			H_Num++;
		}
	}
	int CH4_Num;
	H_Num /= 4;
	if (C_Num >= H_Num) {
		CH4_Num = H_Num;
	} else {
		CH4_Num = C_Num;
	}
	for (int i = CH4_Num; i > 0; i--) {
		cout << "CHHHH";
	}
	return 0;
}
