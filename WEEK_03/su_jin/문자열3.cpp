/*

//����_���ڿ�_1264��

#include<iostream>
#include<string>

using namespace std;
int main() {
	char s[256]; //�� �� �ִ� 255����
	int cnt = 0;
	while (1) {
		cin.getline(s, 256);
		//�Է��� ���� ���ٿ� #�� �Է¹��� �� �Է�����
		if (s[0] == '#') { return 0; }

		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == 'a' || s[i] == 'A') { cnt++; }
			if (s[i] == 'e' || s[i] == 'E') { cnt++; }
			if (s[i] == 'i' || s[i] == 'I') { cnt++; }
			if (s[i] == 'o' || s[i] == 'O') { cnt++; }
			if (s[i] == 'u' || s[i] == 'U') { cnt++; }
		}
		cout << cnt << "\n";
		cnt = 0;
	}
}
*/