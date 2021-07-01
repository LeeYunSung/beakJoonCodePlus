#pragma once

#include <iostream>
#include <set>//2609
#include <vector>//9613
#include <cstring>//6588
using namespace std;

namespace bj {

	//�ִ������� �ּҰ����
	int P2609()
	{
		//0ms

		/*
		* iterative�� ���
		*
		A�� ����� 1���� A���� ã�´�.
			ã���� => set�� �߰��Ѵ�.

		B�� ����� B���� 1���� ã�´�.
			ã���� => �� A�� ������� ���տ� ���ԵǾ� �ִ����� ����.
				�ִٸ�, �ش� ����� �ִ� ������̰�, GCD * LCM = A * B�� �̿��� �ּҰ���� ���

		*/
		unsigned int A, B;
		cin >> A >> B;

		//��� �̰�� unordered_set�� ���°� �´�.
		set<unsigned int> divisors;
		for (unsigned int i = 1; i <= A; ++i)
		{
			if (A % i == 0)
				divisors.emplace(i);
		}

		for (unsigned int j = A; j >= 1; --j)
		{
			if (B % j == 0)
			{
				if (divisors.find(j) != divisors.end())
				{
					cout << j;
					cout << endl;
					cout << A * B / j;
					return 0;
				}
			}
		}

		return -1;//���� �� ���� ���
	}

	//�ּҰ����
	//�̰Ŵ� ��Ŭ���� ȣ�������� Ǯ��
	int P1934()
	{
		//44ms

		/*
		��Ŭ���� ȣ����
		�� ���� ���� a, b (a > b)�� ���Ͽ�,
		a == bq + r(0 �� r <b)�� �ϸ�,
		a, b�� �ִ������� b, r�� �ִ������� ����. ��,

					gcd(a, b) == gcd(b, r)

		r == 0�̶��, a, b�� �ִ������� b�� �ȴ�.
		*/

		unsigned int T;
		cin >> T;

		while (T--)
		{
			unsigned int A, B;
			cin >> A >> B;

			const unsigned int multiplied = A * B;

			if (A < B)
				swap(A, B);

			while (true)
			{
				auto r = A % B;
				if (r == 0)
				{
					cout << multiplied / B << endl;
					break;
				}
				else
				{
					A = B;
					B = r;
				}
			}

		}

		return 0;
	}

	//������ ��� pair�� GCD��
	int P9613()
	{
		//0ms

		/*
			1 �� T �� 100
			1 < caseSize �� 100

			=> ��(pair)�� ã�°Ŵϱ� �׳� ���� for��
		*/
		unsigned int T;
		cin >> T;
		while (T--)
		{
			unsigned int caseSize;
			cin >> caseSize;

			vector<unsigned int> inputs(caseSize);
			for (auto& input : inputs)
				cin >> input;

			//;;;
			unsigned long long answer = 0;

			for (unsigned int i = 0; i < caseSize; ++i)
			{
				for (unsigned int j = i + 1; j < caseSize; ++j)
				{
					unsigned int A = inputs[i], B = inputs[j];

					if (A < B)
						swap(A, B);

					while (true)
					{
						auto r = A % B;
						if (r == 0)
						{
							answer += B;
							break;
						}
						else
						{
							A = B;
							B = r;
						}
					}
				}
			}

			cout << answer << endl;
		}

		return 0;
	}

	int P6588()
	{
		/*
		* �������� ����
		*
		* 4���� ū ��� ¦���� �� Ȧ�� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
		*
		*
		* �����佺�׳׽��� ü

		  1. 2���� N���� ��� ������ ���´�.
		  2. ���� ������ ���� �� �� ���� ���� ���� ã�´�. �̰��� P��� �ϰ�, �� ���� �Ҽ��̴�.
		  3. P�� �����, ���� ������ ���� P�� ����� ũ�� ������� �����.
		  4. ���� ��� ���� ������ �ʾҴٸ�, �ٽ� 2�� �ܰ�� ����.

		*/

		//vector<bool> filter(1000001); vector<bool> !�Ⱦ���!

		constexpr size_t MAX_SIZE = 1000001;
		auto filter = new bool[MAX_SIZE];
		memset(filter, true, MAX_SIZE * sizeof(bool));

		//index�� number�� �ٷ� ����ʹ�. filter[0], filter[1] => continue;
		for (size_t number = 2; number < MAX_SIZE; ++number)
		{
			if (filter[number])
			{
				//cout << number << "\n";
				for (size_t multiplier = 2; multiplier * number < MAX_SIZE; ++multiplier)
					filter[multiplier * number] = false;
			}
		}

		while (true)
		{
			unsigned int testCase;

			cin >> testCase;
			if (testCase < 6)
				break;

			for (size_t number = 2; number < MAX_SIZE; ++number)
			{
				if (filter[number] && filter[testCase - number])
				{
					cout << testCase << " = " << number << " + " << testCase - number << "\n";
					break;
				}
			}
		}

		return 0;
	}
}