#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//ü���� �ٽ� ĥ�ϱ�
int arr[55][55]; //�������ϰ� 0,1�� ġȯ�� �迭
int board1[8][8], board2[8][8]; 
int ans; //�ּҰ�, min����

//������ ü���� ���� 2���� ���
//board1�� 1��1���� 0(White)�� ���۵Ǵ� ü���� 
//board2�� 1��1���� 1(Black)���� ���۵Ǵ� ü����


void compare(int a, int b) {
	int count1 = 0, count2 = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board1[i][j] != arr[a + i][b + j]) { count1++; }
			if (board2[i][j] != arr[a + i][b + j]) { count2++; }

		}
	}
	ans = min(count1, count2);
}
 
int main() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); //�ð��ʰ��Ȱɸ��� ����
	int N, M;
	string s;
	
	cin >> N >> M;
	//white->0, black->1
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'B') { arr[i][j] == 1; }
			else arr[i][j] = 0;
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//board1�� 0���� ����~
			if ((i + j) % 2 == 0) { board1[i][j] == 0; }
			else board1[i][j] == 1;
			//board2�� 1���� ����~
			if ((i + j) % 2 == 1) { board2[i][j] == 1; }
			else board2[i][j] == 0;
		}
	}
	for (int i = 0; i + 8 < N; i++) {
		for (int j = 0; i + 8 < M; j++) { //�ε�ȣ
			compare(i, j); // �Լ�ȣ��
		}
	}

	cout << ans;
	return 0;
}




