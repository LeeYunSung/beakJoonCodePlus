//������
//��Ģ���� ã�� �Ŀ��� �ڵ�¥�µ��� �������� ���������� for���� 7�ڸ����� ��� �������ϳ�? �̷� ���
N = abc + a + b+ c 
N = 100*a + b*10 + c + a+ b+ c = 
#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int a = 0; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				for (int d = 0; d <= 9; d++) {
					for (int e = 0; e <= 9; e++) {
						for (int f = 0; f <= 9; f++) {
							for (int g = 0; g <= 9; g++) {
								while (N == 1000001 * a + 100001 * b + 10001 * c + 1001 * d + 101 * e + 11 * f + 2*g) {
									//if����µ� �ȵǼ� while������ ������
									cout << 1000000 * a + 100000 * b + 10000*c+1000*d+100*e+10*f+g;
									return 0;

								}
							}
						}
					}
				}
			}
		}
	}

	cout << 0;
}
