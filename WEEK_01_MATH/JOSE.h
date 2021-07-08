#pragma once

#include <iostream>
#include <set>//2609
#include <vector>//9613
#include <cstring>//6588
#include <string>//1676, to_string
#include <iterator>
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

	int P6588()
	{
		//24ms

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

	int P10430()
	{
		int A, B, C;
		std::cin >> A >> B >> C;

		std::cout << (A + B) % C << std::endl;
		std::cout << ((A % C) + (B % C)) % C << std::endl;
		std::cout << (A * B) % C << std::endl;
		std::cout << ((A % C) * (B % C)) % C << std::endl;

		return 0;
	}

	void P1978()
	{
		/*
		* ���� �Ҽ��� �Ǵܵ� ���� ������� �ʴ� ����
		* �Ҽ� �Ǵ��� N���� ���� �Ҽ��� �ƴ� ��� ���� �õ��� ��.
		*/
		int T;
		cin >> T;

		auto isPrime = [](const int N)
		{
			if (N == 1)
				return false;

			int div = N - 1;
			while (div != 1)
			{
				if (N % div-- == 0)
					return false;
			}
			return true;
		};

		int count = 0;
		while (T--)
		{
			int n;
			cin >> n;
			if (isPrime(n))
				count++;
		}

		cout << count;
	}

	int P1929()
	{
		/*
		* ���� �Ҽ��� �Ǵܵ� ���� ����ϴ� ����
		* �Ҽ� �Ǵ��� N���� ���� �Ҽ��� ���� �Ǵ���
		*/

		ios::sync_with_stdio(false);
		cout.tie(nullptr);

		int M, N;
		cin >> M >> N;

		vector<int> primes;
		primes.reserve(1000000);

		for (int i = 2; i <= N; ++i)
		{
			bool isPrime = true;
			for (auto prime : primes)
			{
				if (prime * prime > i)
					break;

				if (i % prime == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime)
			{
				if (M <= i && i <= N)
					cout << i << "\n";
				primes.push_back(i);
			}
		}

		return 0;
	}

	int P10872()
	{
		int N;
		cin >> N;

		long long ret = 1;
		while (N)
		{
			ret *= N--;
		}
		cout << ret;

		return 0;
	}

	int P1676()
	{
		/*N!���� �ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������
		 *0�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
		 */

		int N;
		cin >> N;

		int twoCount = 0, fiveCount = 0;
		while (N)
		{
			auto copyN = N;
			while (copyN)
			{
				if (copyN % 2 == 0)//if(!(N & 1))
					twoCount++;
				else
					break;

				copyN /= 2;
			}

			copyN = N--;
			while (copyN)
			{
				if (copyN % 5 == 0)//if(!(N & 1))
					fiveCount++;
				else
					break;

				copyN /= 5;
			}
		}

		cout << min(twoCount, fiveCount);

		return 0;
	}

	int P2004()
	{
		/*
		* nCr = A * 10^k*�ϋ� k?
		* nCr = n! / r!(n-r)!
		* P1676�� ���� ������� ���������� Time Exceeded
		*/
		typedef long long ll;

		ll n, r;
		cin >> n >> r;

		auto _div2 = [](const ll factorialParam) -> ll
		{
			ll answer = 0;

			for (ll i = 2; i <= factorialParam; i *= 2)
				answer += factorialParam / i;

			return answer;
		};

		auto _div5 = [](const ll factorialParam) -> ll
		{
			ll answer = 0;

			for (ll i = 5; i <= factorialParam; i *= 5)
				answer += factorialParam / i;

			return answer;
		};

		cout << min(_div2(n) - (_div2(r) + _div2(n - r)),
			_div5(n) - (_div5(r) + _div5(n - r)));

		return 0;
	}

	int P9613()
	{
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
						const auto r = A % B;
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

	int P17087()
	{
		/*���� ã��*/
		int brotherCount, crntPos;
		cin >> brotherCount >> crntPos;

		vector<int> brotherPos(brotherCount);

		auto _GCD = [](int A, int B)
		{
			/*
			��Ŭ���� ȣ����
			�� ���� ���� a, b (a > b)�� ���Ͽ�,
			a == bq + r(0 �� r <b)�� �ϸ�,
			a, b�� �ִ������� b, r�� �ִ������� ����. ��,

						gcd(a, b) == gcd(b, r)

			r == 0�̶��, a, b�� �ִ������� b�� �ȴ�.
			*/

			if (A < B)
				swap(A, B);

			int R = A % B;
			while (R != 0)
			{
				A = B;
				B = R;
				R = A % B;
			}

			return B;
		};


		for (auto& pos : brotherPos)
		{
			cin >> pos;
			pos -= crntPos;
			if (pos < 0)
				pos = -pos;
		}

		int GCD = brotherPos[0];
		for (size_t i = 1; i < brotherPos.size(); ++i)
			GCD = _GCD(GCD, brotherPos[i]);

		cout << GCD;

		return 0;
	}

	int P1373()
	{
		//44ms
		/*2���� => 8����*/

		string binary;
		cin >> binary;

		string reversedAnswer;

		for (auto iter = binary.rbegin(); iter != binary.rend();)
		{
			auto advanced = iter;
			int three = 3;
			while (three-- != 0 && advanced != binary.rend())
			{
				advanced++;
			}

			string subStr(advanced.base(), iter.base());
			//string subStr(iter, advanced);

			int temp = 0;
			int pow2 = 1;
			for (int index = subStr.length() - 1; index >= 0; index--)
			{
				temp += (subStr[index] - '0') * pow2;
				pow2 *= 2;

			}
			reversedAnswer.append(1, (char)(temp + '0'));

			iter = advanced;
		}

		cout << string(reversedAnswer.rbegin(), reversedAnswer.rend());

		return 0;
	}

	int P1212()
	{
		/*8���� => 2����*/
		string octal;
		cin >> octal;

		string answer;
		for (auto iter = octal.begin(); iter != octal.end(); ++iter)
		{
			string subStr;
			auto currentDigit = *iter - '0';
			while (currentDigit)
			{
				subStr += (currentDigit % 2 + '0');
				currentDigit /= 2;
			}

			while (subStr.length() < 3)
				subStr += '0';
			answer += string(subStr.rbegin(), subStr.rend());
		}

		if (answer[0] == '0')
			answer.erase(answer.begin());

		if (answer[0] == '0')
			answer.erase(answer.begin());

		cout << answer;

		return 0;
	}

	int P2089()
	{
		/*-2����*/
		long long decimal;
		cin >> decimal;
		if (decimal == 0)
			cout << 0;

		string answer;
		while (decimal != 0)
		{
			int currentDigit = decimal % -2;
			answer += abs(currentDigit) + '0';
			decimal = (int)ceil((double)decimal / -2.0);
		}

		cout << string(answer.rbegin(), answer.rend());

		return 0;
	}

	int P17103()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		//52ms

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
		filter[0] = filter[1] = false;

		//index�� number�� �ٷ� ����ʹ�. filter[0], filter[1] => continue;
		for (size_t number = 2; number < MAX_SIZE; ++number)
		{
			if (filter[number])
			{
				for (size_t multiplier = 2; multiplier * number < MAX_SIZE; ++multiplier)
					filter[multiplier * number] = false;
			}
		}

		unsigned int caseSize;
		cin >> caseSize;
		vector<int> cases(caseSize);
		for (auto& sample : cases)
			cin >> sample;

		for (auto testCase : cases)
		{
			int count = 0;
			for (size_t number = 2; number < MAX_SIZE && 0 < testCase - number; ++number)
			{
				if (number > testCase / 2)
					break;

				if (filter[number] && filter[testCase - number])
					count++;
			}

			cout << count << "\n";
		}

		return 0;
	}
}