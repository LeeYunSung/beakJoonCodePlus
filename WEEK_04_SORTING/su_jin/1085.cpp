
//���簢������ Ż��
#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	int x, y, w, h;
	int arr[4];
	scanf("%d %d %d %d", &x, &y, &w, &h);
	//h-y : ����, y: �Ʒ���, w-x:������, x: ����
	arr[0] = h-y; arr[1] = y; arr[2] = w-x; arr[3] = x;
	sort(arr, arr + 4);
	printf("%d", arr[0]);
}
