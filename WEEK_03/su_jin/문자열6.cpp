//백준_문자열_3029

/*
#include<iostream>
using namespace std;

int main() {
	int start[3], finish[3], result[3];

	scanf_s("%02d:%02d:%02d",&start[0],&start[1],&start[2]);
	scanf_s("%02d:%02d:%02d", &finish[0], &finish[1], &finish[2]);

	if (finish[0] >= start[0]) {
		result[0] = finish[0] - start[0];
	}
	else {
		result[0] = (finish[0] + 24) - start[0];
	}

	if (finish[1] >= start[1]) {
		result[1] = finish[1] - start[1];
	}
	else {
		result[1] = (finish[1] + 60) - start[1];
		result[0]--;
	}

	if (finish[2] >= start[2]) {
		result[2] = finish[2] - start[2];
	}
	else {
		result[2] = (finish[2] + 60) - start[2];
		result[1]--;

	}

	if (result[0] == 0 && result[1] == 0 && result[2] == 0) {
		result[0] = 24;
	}

	printf("%02d:%02d:%02d\n", result[0], result[1], result[2]);
	return 0;
}
*/