/*
//1008��
#inlcude<iostream>
using namespace std;

int main() {
	int A, B;
	double C;
	cin >> A >> B;
	C = (double)A/(double)B;
	cout.precision(10); //(�ڸ���)���е�, �ݿø����༭ ���е� ����, cout�� precision�� default���� 6�̴�
	cout.fixed; //�Ҽ��� �ڸ��� ���е� ǥ!��! 
	cout << C << endl;
	return 0;
}


//10818��
#include<iostream>
using namespace std;

int main() {
	int min=0, max=0;
	int N;
	//N >= 1 && N < 10000;
	cin >> N;
	int num[10000];

	for (int i = 0; i < N; i++) {
		scanf_s("%d",&num[i]);
	}
	for (int i = 0; i < N; i++) {
		printf("%d ",num[i]);
	}
	max = num[0]; //max�� �迭 ù ��ҷ� �ʱ�ȭ
	for (int i = 1; i < N - 1; i++) {
		if (max < num[i])
		{
			max = num[i];
		}
	}
	min = num[0]; //min�� �迭 ù ��ҷ� �ʱ�ȭ
	for (int i = 1; i < N - 1; i++) {
		if (min > num[i]) {
			min = num[i];
		}
	}
	cout << endl << max << " " << min;
}

//4344��
#include<iostream>
using namespace std;
int main() {
	int C, sum = 0, count = 0;
	float avr, answer;
	cin >> C;
	int num[1000];
	for (int i = 0; i < C; i++) {
		cin >> num[i];
		sum = sum + num[i];
	}
	avr = (float)sum / C;
	printf("���: %f", avr);

	for (int i = 0; i < C; i++) {
		if (num[i] > avr) {
			count++;
		}
	}

	cout << endl << "��� ���� ��� ��: " << count<< endl;
	answer = ((float)count / C);
	cout.precision(5);
	cout.fixed;
	cout << answer*100 << "%";
}


//10179��
#include<iostream>
using namespace std;
int main() {
	int C;
	float num[10];
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> num[i];
		num[i] = num[i] * 0.8;
	}
	for (int i = 0; i < C; i++) {
		cout.precision(4);
		cout.fixed;
		cout << "$" << num[i] << endl;
	}
}


//10250�� 
//ACMȣ�� ����
#include<iostream>
using namespace std;

int main() {
	int C, H, W, N; //���̽�, ��, ��, n��° �մ�
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> H >> W >> N;
		//ȣ���� YYXX, YXX�� �� �ڸ����� x,y,z;
		int x, y;
		x = N % H; //��
		if (x == 0) { x = H; }
		y = int(N / H) + 1;
		cout << x;
		cout << y << endl; //y�� ���ڸ� ���� ���;��ϴµ�? ���� ��� 2ȣ�� �ƴ� 02ȣ
	}
}
*/

#include<iostream>
using namespace std;
int main() {
	int N, count;
	//N >= 3 && N <= 5000;
	cin >> N;
	for (int i = 0; i < 1000; i++) {
		if ((N % (5 * i))== 0) { //���Ը� 5�� ����� ���� �������� 0�̶��
			count = i;
		}
		if ((N % (5 * i)) % 3 == 0) { //���Ը� 5�� ���� ���� 3�� ������ 
			count = i + ((N - (5 * i)) / 3);
		}
		/*
		if ((N % (3 * i)) == 0) { //���Ը� 3�� ����� ���� �������� 0�̶��
			count = i;
		}
		if ((N % (5 * i)) % 3 == 0) { //���Ը� 5�� ���� ���� 3�� ������ 
			count = i + ((N - (5 * i)) / 3);
		}
		*/

		else
		{
			count = -1;
		}
	}
	cout << count << endl;
}





