/*
//���� ����

//����_���ڿ�_1652��

#include<iostream>

using namespace std;

string s;
int row_cnt, col_cnt, N, cnt;
char a[101][101];

int main(){
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		cnt = 0; //������� ��

		//���� ���� �ڸ� ã�� loop��
		for (int j = 0; j < s.size(); j++) {
			//��켱������ ���������� s[j]����
			a[i][j] = s[j];

			if (a[i][j] == '.') {
				cnt++;
			}
			else {
				//�� ���� ������ ��, 
				if (cnt >= 2) {
					//���� �����鼭 �����ڸ��� 2ĭ�̻��� ��,
					col_cnt++; //���� �ڸ� ã�Ҵ� !
					cnt = 0; //������� �ʱ�ȭ
				}
			}
		}

		//���� ������ �ʰ� ���� ������ 2ĭ�̻� �� ��, �� ���� ������ ��
		if (cnt >= 2) { col_cnt++; }
	}
	//���� ���� �ڸ� ã�� loop��
	for (int i = 0; i < N; i++) {
		cnt = 0;
		for (int j = 0; j < N; j++) {
			//�� �켱 ������ ������ s[j]����
			if (a[j][i] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2) {
					row_cnt++;
					cnt = 0;
				}
			}
		}

		//���� ������ �ʰ� ���� ������ 2ĭ�̻� �� ��, �� ���� ������ ��
		if (cnt >= 2) { col_cnt++; }

	}
	
	cout << col_cnt << " " << row_cnt;

}

*/