#pragma region 백준_1406번_에디터

#include <iostream>
#include <string>
#include <list>
/*
int main()
{
	std::string str = "";
	int loopcount;
	std::cin >> str >> loopcount;
	std::list<char> ch(str.begin(), str.end());
	std::list<char>::iterator iter = ch.end();
	for (int i = 0; i < loopcount; ++i)
	{
		char input;
		std::cin >> input;
		switch (input)
		{
		case 'L':

			if (ch.empty())
				continue;
			if (iter != ch.begin())
				--iter;
			break;

		case 'D':

			if (ch.empty())
				continue;
			if (iter != ch.end())
				++iter;
			break;

		case 'B':

			if (ch.empty())
				continue;
			if (iter != ch.begin())
			{
				iter=ch.erase(--iter);
			}
			break;

		case 'P':
			std::cin >> input;
			iter = ch.insert(iter, input);
			iter++;
			break;

		default:
			break;
		}

	}
	for (std::list<char>::iterator it = ch.begin(); it != ch.end(); ++it)
	{
		std::cout << *it;
	}

}
*/
#pragma endregion

#pragma region 백준_5397번_키로거
/*
#include <iostream>
#include <list>
#include <string>

int main()
{
	std::list<char> list;
	std::list<char>::iterator iter;
	int testcase;
	std::cin >> testcase;
	std::cin.ignore();

	for (int i = 0; i < testcase; ++i)
	{
		iter = list.begin();
		std::string str;
		std::getline(std::cin, str);
		for (int j = 0; j < str.size(); ++j)
		{
			switch(str[j])
			{
			case '<':
				if (list.empty())
					continue;
				if (iter != list.begin())
					--iter;
				break;

			case '>':
				if (list.empty())
					continue;
				if (iter != list.end())
					++iter;
				break;

			case '-':
				if (list.empty())
					continue;
				if (iter != list.begin())
					iter = list.erase(--iter);
				break;

			default:
				list.insert(iter, str[j]);
				break;
			}
		}

		for (iter = list.begin(); iter != list.end(); ++iter)
		{
			std::cout << *iter;
		}
		std::cout << "\n";
		list.clear();

	}
	return 0;
}
*/
#pragma endregion

#pragma region 백준_2775_부녀회장이될테야
/*
#include <iostream>

int peopleCount(int k, int n)
{
	if (k == 0)
	{
		return n;
	}
	if (n == 1)
	{
		return 1;
	}
	return peopleCount(k - 1, n) + peopleCount(k, n - 1);
}

int main()
{
	int testcase;
	std::cin >> testcase;
	for (int i = 0; i < testcase; ++i)
	{
		int k, n;
		std::cin >> k >> n;
		std::cout << peopleCount(k, n)<<"\n";
	}
}
*/
#pragma endregion

#pragma region 백준_2839_설탕배달
/*
#include <iostream>

int numberOfBags(int weight)
{
	if (weight < 3)
		return -1;

	int five = weight / 5;
	int remainingWeight = weight % 5;

	switch (remainingWeight)
	{
	case 0:
		return five;
		break;

	case 1:
		if (five < 1)
			return -1;
		five-=1;
		return five + (5 + remainingWeight) / 3;
		break;

	case 2:
		if (five < 2)
			return -1;
		five -= 2;
		return five + (5 * 2 + remainingWeight) / 3;
		break;

	case 3:
		return five + 1;
		break;
	case 4:
		if (five < 1)
			return -1;
		five -= 1;
		return five + (5 + remainingWeight) / 3;
	default:
		break;
	}

}

int main()
{
	int sugerWeight;
	std::cin >> sugerWeight;

	std::cout << numberOfBags(sugerWeight);

}
*/
#pragma endregion

#pragma region 백준_10757_큰수A+B_X
/*
#include <iostream>

int main()
{
	unsigned long long num1;
	unsigned long long num2;
	std::cin >> num1 >> num2;

	std::cout << num1 + num2;
	return 0;
}

*/
#pragma endregion

/*
#include <iostream>
#include <string>
int main()
{
	int size = -1;
	int stack[100] = {};
	int loopCount;
	std::cin >> loopCount;
	for (int i = 0; i < loopCount; ++i)
	{
		std::string str;
		std::cin >> str;
		if (str == "push")
		{
			int inputnum;
			std::cin >> inputnum;
			stack[size + 1] = inputnum;
			++size;
		}
		else if (str == "pop")
		{
			if (size == -1)
				std::cout << "-1\n";
			else
			{
				std::cout << stack[size] << "\n";
				--size;
			}
		}
		else if (str == "size")
		{
			std::cout << size + 1 << "\n";
		}
		else if (str == "empty")
		{
			if (size == -1)
				std::cout << "1\n";
			else
				std::cout << "0\n";
		}
		else if (str == "top")
		{
			if (size == -1)
				std::cout << "-1\n";
			else
				std::cout << stack[size] << "\n";
		}
	}
	return 0;
}
*/

#pragma region 백준_17298_오큰수
/*
#include <iostream>
#include <stack>

int q[1000001];
int s[1000001];
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::stack<int> tempNum;

	int loopcount;
	std::cin >> loopcount;
	int input;
	for (int i = 0; i < loopcount; ++i)
	{
		std::cin >> input;
		q[i] = input;
	}

	for (int i = loopcount - 1; i >= 0; --i)
	{
		while (!tempNum.empty() && tempNum.top() <= q[i])
			tempNum.pop();
		if (tempNum.empty())
		{
			s[i] = -1;
		}
		else
			s[i] = tempNum.top();
		tempNum.push(q[i]);
	}
	for (int i = 0; i < loopcount; ++i)
	{
		std::cout << s[i] << " ";
	}
	return 0;
}
*/
#pragma endregion 

#pragma region 백준_1874_스택수열
/*
#include <iostream>
#include <stack>

int q[100001];
char s[200001];

int main()
{
	std::stack<int> st;
	int loopCount;
	std::cin >> loopCount;
	for (int i = 0; i < loopCount; ++i)
	{
		int input;
		std::cin >> input;
		q[i] = input;
	}
	int qcount = 0;
	int scount = 0;
	for (int i = 1; i < loopCount+1; ++i)
	{
		st.push(i);
		s[scount] = '+';
		++scount;

		while (!st.empty() && st.top() == q[qcount])
		{
			st.pop();
			++qcount;
			s[scount] = '-';
			++scount;
		}

	}
	if (st.empty())
	{
		for (int i = 0; i < scount; ++i)
			std::cout << s[i] << "\n";
	}
	else
		std::cout << "NO";



	return 0;
}
*/
#pragma endregion

#pragma region X
/*
#include <iostream>

int main()
{
	int numCount, loopCount;
	std::cin >> numCount >> loopCount;
	int* arr = new int[numCount];
	for (int i = 0; i < numCount; ++i)
	{
		int input;
		std::cin >> input;
		arr[i] = input;
	}
	for (int m = 0; m < loopCount; ++m)
	{
		int i, j;
		std::cin >> i >> j;
		int sum = 0;
		for (int k = i - 1; k < j; ++k)
		{
			sum += arr[k];
		}

		std::cout << sum << "\n";
	}

	delete[] arr;
	return 0;
}
*/
#pragma endregion

#pragma region 백준_15815_천재수학자성필_X
/*
#include <iostream>
#include <string>
#include <stack>
#include <queue>

int main()
{

	std::string q;
	std::stack<int> num;
	std::queue<char> oper;
	std::getline(std::cin, q);

	if (q != "")
	{
		for (int i = 0; i < q.size() / 2 + 1; ++i)
		{
			num.push(q[i] - '0');
		}
		for (int i = q.size() / 2 + 1; i < q.size(); ++i)
		{
			oper.push(q[i]);
		}
	}

	while(!oper.empty())
	{
	int a, b;
		a = num.top();
		num.pop();
		b = num.top();
		num.pop();

		switch (oper.front())
		{
		case '+':
			num.push(a + b);
			break;

		case '-':
			num.push(a - b);
			break;

		case '*':
			num.push(a * b);
			break;

		case '/':
			num.push(a / b);
			break;
		}

		oper.pop();
	}
	std::cout << num.top();
	return 0;
}
*/
#pragma endregion

#pragma region 백준_1264_카드1
/*#include <iostream>
#include <queue>

int main()
{
	int N;
	std::cin >> N;
	std::queue<int> card;
	for (int i = 1; i < N+1; ++i)
		card.push(i);
	int temp;
	while (!card.empty())
	{
		temp = card.front();
		std::cout << temp << " ";
		card.pop();
		if (!card.empty())
		{
		card.push(card.front());
		card.pop();
		}
	}
	return 0;
}
*/

#pragma endregion

#pragma region 백준_1264_카드2
/*
#include <iostream>
#include <queue>

int main()
{
	int N;
	std::cin >> N;
	std::queue<int> card;
	for (int i = 1; i < N+1; ++i)
		card.push(i);
	int temp;
	while (!card.empty())
	{
		temp = card.front();
		card.pop();
		if (!card.empty())
		{
		card.push(card.front());
		card.pop();
		}
	}
	std::cout << temp;
	return 0;
}
*/
#pragma endregion

#pragma region 백준_18258_큐2
/*
#include <iostream>
#include <string>

int arr[2000001];
int size = 0;
int front = 0;
int main()
{
	std::cin.tie(NULL);
	std::cin.sync_with_stdio(false);

	int loopCount;
	std::cin >> loopCount;
	std::cin.ignore();
	for (int i = 0; i < loopCount; ++i)
	{
		std::string str;
		std::cin >> str;
		if (str == "push")
		{
			int input;
			std::cin >> input;
			arr[front + size] = input;
			++size;
		}
		else if (str == "pop")
		{
			if (size == 0)
				std::cout << "-1\n";
			else
			{
				std::cout << arr[front] << "\n";
				++front;
				--size;
			}
		}
		else if (str == "size")
		{
			std::cout << size << "\n";
		}
		else if (str == "empty")
		{
			if (size == 0)
				std::cout << "1\n";
			else
				std::cout << "0\n";
		}
		else if (str == "front")
		{
			if (size == 0)
				std::cout << "-1\n";
			else
				std::cout << arr[front] << "\n";
		}
		else if (str == "back")
		{
			if (size == 0)
				std::cout << "-1\n";
			else
				std::cout << arr[front + size - 1] << "\n";
		}
	}
	return 0;
}
*/
#pragma endregion

#pragma region 백준_11866_요세푸스문제0
/*
#include <iostream>
#include <queue>

int main()
{
	std::queue<int> people;
	int peopleCount, kill;
	std::cin >> peopleCount >> kill;
	for (int i = 1; i <= peopleCount; ++i)
	{
		people.push(i);
	}
	std::cout << "<";
	for(int j=1;j<peopleCount;++j)
	{
		for (int i = 1; i < kill; ++i)
		{
			people.push(people.front());
			people.pop();
		}
		std::cout << people.front() << ", ";
		people.pop();
	}
	std::cout << people.front() << ">";
}
*/
#pragma endregion

#pragma region 백준_10866_덱
/*
#include <iostream>
#include <string>

int deck[20002];

int main()
{
	int front = 10001;
	int size = 0;
	int loopCount;
	std::cin >> loopCount;
	for (int i = 0; i < loopCount; ++i)
	{
		std::string str;
		std::cin >> str;
		if (str == "push_front")
		{
			int input;
			std::cin >> input;
			--front;
			deck[front] = input;
			++size;
		}
		else if (str == "push_back")
		{
			int input;
			std::cin >> input;
			deck[front + size] = input;
			++size;
		}
		else if (str == "pop_front")
		{
			if (size == 0)
				std::cout << "-1\n";
			else
			{
				std::cout << deck[front] << "\n";
				++front;
				--size;
			}
		}
		else if (str == "pop_back")
		{
			if (size == 0)
				std::cout << "-1\n";
			else
			{
				std::cout << deck[front + size-1] << "\n";
				--size;
			}
		}
		else if (str == "size")
		{
			std::cout << size << "\n";
		}
		else if (str == "empty")
		{
			if (size == 0)
				std::cout << "1\n";
			else
				std::cout << "0\n";

		}
		else if (str == "front")
		{
			if (size == 0)
				std::cout << "-1\n";
			else
				std::cout << deck[front] << "\n";
		}
		else if (str == "back")
		{
			if (size == 0)
				std::cout << "-1\n";
			else
				std::cout << deck[front + size-1] << "\n";
		}
	}
	return 0;
}
*/
#pragma endregion

#pragma region 백준_1003_피보나치함수
/*
#include <iostream>

int main()
{
	int loopCount;
	std::cin >> loopCount;
	for (int i = 0; i < loopCount; ++i)
	{
		int input;
		std::cin >> input;
		int prev = 0;
		int next = 1;
		if (input == 0)
		{
			prev = 1;
			next = 0;
		}
		else
		{
			for (int i = 1; i < input; ++i)
			{
				int temp = prev + next;
				prev = next;
				next = temp;
			}
		}
		std::cout << prev << " " << next << "\n";

	}
}
*/
#pragma endregion

#pragma region 백준_1014_컨닝_X
/*
#include <iostream>
#include <string>

int main()
{
	int loopCount;
	std::cin >> loopCount;
	for (int loop = 0; loop < loopCount; ++loop)
	{
		int r, c;
		std::cin >> r >> c;
		char** Class = new char* [r];
		for (int i = 0; i < r; ++i)
			Class[i] = new char[c];
		int oddC = 0;
		int evenC = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				char desk;
				std::cin >> desk;
				Class[i][j] = desk;
				if (desk == '.')
				{
					if (j % 2 == 0)
						++evenC;
					else
						++oddC;
				}
			}
		}
		int noCheatingDesk = 0;

		if (oddC < evenC)
		{
			for (int i = 0; i < r; ++i)
			{
				for (int j = 0; j < c; j += 2)
				{
					if (Class[i - 1][j - 1] == 'X' && Class[i][j - 1] == 'X' && Class[i - 1][j + 1] == 'X' && Class[i][j + 1] == 'X')
						++noCheatingDesk;
				}
			}
			std::cout << evenC + noCheatingDesk << "\n";
		}
		else
		{
			for (int i = 0; i < r; ++i)
			{
				for (int j = 1; j < c; j += 2)
				{
					if (Class[i - 1][j - 1] == 'X' && Class[i][j - 1] == 'X' && Class[i - 1][j + 1] == 'X' && Class[i][j + 1] == 'X')
						++noCheatingDesk;
				}
			}
			std::cout << oddC + noCheatingDesk << "\n";
		}

		for (int i = 0; i < r; ++i)
		{
			delete[] Class[i];
		}

		delete[] Class;
	}
	return 0;
}
*/
#pragma endregion

#pragma region 백준_1966_프린터큐
/*
#include <iostream>
#include <queue>

int main()
{
	int loopCount;
	std::cin >> loopCount;
	std::queue<std::pair<int, int>> q;
	std::priority_queue<int> pq;
	for (int i = 0; i < loopCount; ++i)
	{
		int numberOfDocument;
		int findDocumentNumber;
		std::cin >> numberOfDocument >> findDocumentNumber;
		for (int j = 0; j < numberOfDocument; ++j)
		{
			int input;
			std::cin >> input;
			q.push({ j,input });
			pq.push(input);
		}

		int count = 1;
		while (!q.empty())
		{
			while (pq.top() != q.front().second)
			{
				q.emplace(q.front().first,q.front().second);
				q.pop();
			}
			if (q.front().first == findDocumentNumber)
				std::cout << count << "\n";
			else
				++count;
			q.pop();
			pq.pop();
		}
	}
	return 0;
}
*/
#pragma endregion

#pragma region 백준_1021_회전하는큐
/*
#include <iostream>
#include <deque>

int main()
{
	std::deque<int> dq;
	int size, findNumCount;
	std::cin >> size >> findNumCount;
	for (int i = 1; i <= size; ++i)
	{
		dq.push_back(i);
	}
	int count = 0;
	for (int i = 0; i < findNumCount; ++i)
	{
		int findnum;
		std::cin >> findnum;
		int type = 1;

		int temp=0;
		while (dq[temp] != findnum)
		{
			++temp;
		}
		if (temp >= (float)dq.size() / 2)
			type = 1;
		else
			type = 2;
		while (dq.front() != findnum)
		{
			switch (type)
			{
			case 1:
				dq.push_front(dq.back());
				dq.pop_back();
				++count;
				break;
			case 2:
				dq.push_back(dq.front());
				dq.pop_front();
				++count;
				break;
			}
		}
		dq.pop_front();
	}
	std::cout << count;
}
*/
#pragma endregion

#pragma region 백준_5430_AC
/*
#include <iostream>
#include <deque>
#include <string>


int main()
{
	std::deque<int> dq;
	int loopCount;
	std::cin >> loopCount;
	for (int i = 0; i < loopCount; ++i)
	{
		if (!dq.empty())
			dq.clear();
		std::string str;
		std::cin >> str;
		int inputCount;
		std::cin >> inputCount;

		std::string arr;
		std::cin >> arr;
		std::string temp;

		for (int j = 1; j < arr.size(); ++j)
		{
			if (arr[j] == ',' || (arr[j] == ']' && !temp.empty()))
			{

				dq.push_back(stoi(temp));
				temp.clear();
			}
			else
				temp += arr[j];
		}

		bool dirForward = true;
		bool iserror = false;
		for (int j = 0; j < str.size(); ++j)
		{
			if (str[j] == 'D')
			{
				if (dq.empty())
				{
					iserror = true;
					std::cout << "error\n";
					break;
				}
				else
				{
					if (dirForward)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
			else if (str[j] == 'R')
			{
				dirForward = !dirForward;
			}
		}
		if (!iserror)
		{
			std::cout << "[";
			if (!dq.empty())
			{
				int tempnum = dq.size();
				for (int j = 1; j < tempnum; ++j)
				{
					if (dirForward)
					{
						std::cout << dq.front() << ",";
						dq.pop_front();
					}
					else
					{
						std::cout << dq.back() << ",";
						dq.pop_back();
					}
				}
				std::cout << dq.front();
			}
			std::cout << "]\n";
		}
	}
}
*/
#pragma endregion

#pragma region 백준_1920_수찾기
/*
#include <iostream>
#include <algorithm>
int arr[100000];
int num;
void sort()
{

}

bool bs(int s, int e)
{
	int m = (s + e) / 2;
	if (s < e)
	{
		if (arr[m] == num)
			return true;
		else if (arr[m] > num)
		{
			return bs(s, m);
		}
		else if (arr[m] < num)
		{
			return bs(m + 1, e);
		}

	}
	else
		return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
	}

	std::sort(arr, arr + N);

	int M;
	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		std::cin >> num;
		if (bs(0, N))
			std::cout << "1\n";
		else
			std::cout << "0\n";

	}

}
*/
#pragma endregion

#pragma region 백준_10816_숫자카드2
/*
#include <iostream>
#include <algorithm>

int arr[500001];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int num;
		std::cin >> num;
		arr[i] = num;
	}
	std::sort(arr, arr + N);
	int M;
	std::cin >> M;
	for (int i=0;i<M;++i)
	{
		int input;
		std::cin >> input;
		std::pair<int*, int*> range = std::equal_range(arr, arr + N, input);
		std::cout << range.second - range.first << " ";
	}
}
*/
#pragma endregion

#pragma region 백준_1654_랜선자르기
/*
#include <iostream>
#include <limits.h>

using ll = long long;
using namespace std;

ll K, N, M = 0;
ll lan[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	std::cin >> K >> N;

	for (int i = 0; i < K; ++i)
	{
		cin >> lan[i];
		if (M < lan[i])
			M = lan[i];
	}
	ll s = 1, e = M + 1;
	ll result = 0;
	while (s < e)
	{
		ll m = (s + e) / 2;

		ll count = 0;
		for (int i = 0; i < K; ++i)
			count += lan[i] / m;

		if (count >= N)
		{
			if (result < m)
				result = m;
			s = m + 1;
		}
		else
			e = m;
	}
	std::cout << result;
}
*/
#pragma endregion

#pragma region 백준_2805_나무자르기
/*
#include <iostream>

using ll = long long;
ll N, M, MAX = 0;
ll arr[1000001];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
		if (arr[i] > MAX)
			MAX = arr[i];
	}
	ll s = 1, e = MAX + 1;
	ll result = 0;
	while (s < e)
	{
		ll m = (s + e) / 2;
		ll c = 0;
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] > m)
				c += arr[i] - m;
		}
		if (c >= M)
		{
			if (result < m)
				result = m;
			s = m + 1;
		}
		else
			e = m;
	}

	std::cout << result;
	return 0;
}
*/
#pragma endregion

#pragma region 백준_2110_공유기설치
/*
#include <iostream>
#include <algorithm>
using ll = long long;
ll N, C, max = 0;
ll arr[2000001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	std::sort(arr, arr + N);

	ll s = 1, e = max + 1;
	ll result = 0;
	while (s < e)
	{
		ll m = (s + e) / 2;
		ll count = 1;
		ll temp = 0;
		for (int i = 0; i < N - 1; ++i)
		{
			temp += arr[i + 1] - arr[i];
			if (temp >= m)
			{
				++count;
				temp = 0;
			}
		}
		if (count >= C)
		{
			if (result < m)
				result = m;
			s = m + 1;
		}
		else
			e = m;
	}
	std::cout << result;

	return 0;
}
*/
#pragma endregion

/*
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v[100000];
bool isVisited[100000] = {};

int N, M, R;
void def(int V)
{
	static bool isVisited[100000];

}

int main()
{
	std::cin >> N >> M >> R;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < M; ++i)
		std::sort(v[i].begin(), v[i].end());





}
*/

#pragma region 백준_1260_DFS와BFS
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

std::vector<int> graph[1001];
int N, M, V;

void dfs()
{
	bool isVisited[1001] = {};
	std::stack<int> st;
	st.push(V);

	int node = st.top();
	std::cout << node << " ";
	isVisited[node] = true;

	while (!st.empty())
	{
		node = st.top();
		for (size_t i = 0; i <= graph[node].size() ; ++i)
		{
			if (i == graph[node].size())
			{
				st.pop();
				break;
			}
			int nextNode = graph[node][i];
			if (isVisited[nextNode] == false)
			{
				st.push(nextNode);
				std::cout << nextNode << " ";
				isVisited[nextNode] = true;
				break;
			}

		}
	}
}

void bfs()
{
	bool isVisited[1001] = {};
	std::queue<int> que;
	que.push(V);
	isVisited[V] = true;
	while (!que.empty())
	{
		int node = que.front();
		que.pop();
		std::cout << node << " ";
		for (int nextNode : graph[node])
			if (isVisited[nextNode] == false)
			{
				que.push(nextNode);
				isVisited[nextNode] = true;
			}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M >> V;


	for (int i = 0; i < M; ++i)
	{
		int s, e;
		std::cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for (int i = 1; i <= N; ++i)
		std::sort(graph[i].begin(), graph[i].end());

	dfs();
	std::cout << "\n";
	bfs();
}
*/
#pragma endregion

#pragma region 백준_2606_바이러스
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

std::vector<int> computer[100];
int N, M;

int bfs()
{
	bool isVisit[100] = {};
	std::queue<int> que;
	que.push(1);
	int count = 0;
	isVisit[1] = true;
	while (!que.empty())
	{
		int node = que.front();
		que.pop();
		for (int nextNode : computer[node])
		{
			if (!isVisit[nextNode])
			{
				++count;
				que.push(nextNode);
				isVisit[nextNode] = true;
			}
		}
	}
	return count;
}

int main()
{
	std::cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}
	for (int i = 0; i < N; ++i)
		std::sort(computer[i].begin(), computer[i].end());

	std::cout << bfs();
}
*/
#pragma endregion

#pragma region 백준_2667_단지번호붙이기	
/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
bool arr[25][25] = {};
int complex[312] = {};
int N, count = 0;

void countComplex(int r, int c)
{
	arr[r][c] = false;
	++complex[count];
	if (r < N-1)
		if (arr[r + 1][c])
			countComplex(r + 1, c);
	if (r > 0)
		if (arr[r - 1][c])
			countComplex(r - 1, c);
	if (c < N-1)
		if (arr[r][c + 1])
			countComplex(r, c + 1);
	if (c > 0)
		if (arr[r][c - 1])
			countComplex(r, c - 1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < N; ++j)
		{
			if (str[j] == '1')
				arr[i][j] = true;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[i][j])
			{
				countComplex(i, j);
				++count;
			}
		}
	}

	std::sort(complex, complex + count);
	std::cout << count << "\n";
	for (int i = 0; i < count; ++i)
	{
		std::cout << complex[i] << "\n";
	}
	return 0;
}
*/
#pragma endregion

#pragma region 백준_1012_유기농배추
/*
#include <iostream>

int M, N, K;
bool arr[50][50] = {};

void countBug( int r, int c)
{
	arr[r][c] = false;

	if (r < N - 1)
		if (arr[r + 1][c])
			countBug(r + 1, c);
	if (r > 0)
		if (arr[r - 1][c])
			countBug( r - 1, c);
	if (c < M - 1)
		if (arr[r][c + 1])
			countBug( r, c + 1);
	if (c > 0)
		if (arr[r][c - 1])
			countBug( r, c - 1);
}

int main()
{
	int testCase;
	std::cin >> testCase;
	for (int z = 0; z < testCase; ++z)
	{

		std::cin >> M >> N >> K;

		for (int i = 0; i < K; ++i)
		{
			int a, b;
			std::cin >> a >> b;
			arr[b][a] = true;
		}
		int count=0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (arr[i][j])
				{
					countBug(i, j);
					++count;
				}
			}
		}
		std::cout << count << "\n";
	}
}
*/
#pragma endregion

#pragma region 백준_2178_미로탐색
/*
#include <iostream>
#include <string>
#include <queue>
#include <utility>
bool map[100][100] = {};
short N, M;

//int result = 987654321;
//int count = 0;
//void findExit(int r, int c)
//{
//	map[r][c] = false;
//	++count;
//	if (r == N - 1 && c == M - 1)
//	{
//		if (count < result)
//			result = count;
//	}
//	if (r < N - 1)
//		if (map[r + 1][c])
//			findExit(r + 1, c);
//	if (r > 0)
//		if (map[r - 1][c])
//			findExit(r - 1, c);
//	if (c < M - 1)
//		if (map[r][c + 1])
//			findExit(r, c + 1);
//	if (c > 0)
//		if (map[r][c - 1])
//			findExit(r, c - 1);
//	--count;
//	map[r][c] = true;
//}

int findExit()
{
	std::queue<std::pair<short, short>> path;
	int count = 1;
	path.push({ 0, 0 });
	map[0][0] = false;
	static const int dx[4] = { 1,0,-1,0 };
	static const int dy[4] = { 0,1,0,-1 };
	std::pair<short, short> lastIn = {0,0};
	while (!path.empty())
	{
		int x = path.front().first;
		int y = path.front().second;


		if (x == N - 1 && y == M - 1)
		{
			break;
		}
		for (short i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (map[nx][ny])
			{
				path.push({ nx,ny });
				map[nx][ny] = false;
			}
		}
		if (path.front().first == lastIn.first && path.front().second == lastIn.second)
		{
			++count;
			lastIn = { path.back().first,path.back().second};
		}
		path.pop();
	}
	while (!path.empty())
		path.pop();
	return count;
}

int main()
{
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < M; ++j)
		{
			if (str[j] == '1')
				map[i][j] = true;
		}
	}
	//findExit(0, 0);
	//std::cout << result;

	std::cout << findExit();
	return 0;
}
*/
#pragma endregion

#pragma region 백준_7576_토마토
/*
#include <iostream>
#include <queue>

int box[1000][1000] = {};
std::queue<std::pair<int, int>> tomato;
int M, N;

int time()
{
	static const int dr[4] = { 1,0,-1,0 };
	static const int dc[4] = { 0,1,0,-1 };
	int count = 0;
	int temp = 0;
	std::pair<int, int> last;
	if(!tomato.empty())
		last = { tomato.back().first ,tomato.back().second };
	while (!tomato.empty())
	{
		int r = tomato.front().first;
		int c = tomato.front().second;
		for (int i = 0; i < 4; ++i)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				continue;
			if (box[nr][nc] == 0)
			{
				box[nr][nc] = 1;
				tomato.push({ nr,nc });
				++temp;
			}
		}
		if (last.first == tomato.front().first && last.second == tomato.front().second)
		{
			if (temp != 0)
			{
				++count;
				temp = 0;
			}
			last = { tomato.back().first,tomato.back().second };
		}
		tomato.pop();
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> box[i][j];
			if (box[i][j] == 1)
				tomato.push({ i,j });
		}
	}
	int d = time();

	bool isComplete = true;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (box[i][j] == 0)
			{
				isComplete = false;
				break;
			}
		}
	}
	if (isComplete)
	{
		std::cout << d;
	}
	else
		std::cout << "-1";
}
*/
#pragma endregion

#pragma region 백준_7569_토마토
/*
#include <iostream>
#include <queue>

int box[100][100][100] = {};
std::queue<std::pair<std::pair<int, int>, int>> tomato;
int  N, M, H;

int time()
{
	static const int dx[6] = { 1,0,0,-1,0,0 };
	static const int dy[6] = { 0,1,0,0,-1,0 };
	static const int dz[6] = { 0,0,1,0,0,-1 };
	int count = 0;
	int temp = 0;
	std::pair<std::pair<int, int>, int> last;
	if(!tomato.empty())
		last = { {tomato.back().first.first,tomato.back().first.second},tomato.back().second };
	while (!tomato.empty())
	{
		int x = tomato.front().first.first;
		int y = tomato.front().first.second;
		int z = tomato.front().second;
		for (int i = 0; i < 6; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || nx >= H || ny < 0 || ny >= M || nz < 0 || nz >= N)
				continue;
			if (box[nx][ny][nz] == 0)
			{
				box[nx][ny][nz] = 1;
				tomato.push({ {nx,ny},nz });
				++temp;
			}
		}
		if (last.first.first == tomato.front().first.first&& last.first.second == tomato.front().first.second
			&& last.second == tomato.front().second)
		{
			if (temp != 0)
			{
				++count;
				temp = 0;
			}
			last = { {tomato.back().first.first,tomato.back().first.second},tomato.back().second};
		}
		tomato.pop();
	}
	return count;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M >> H;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				std::cin >> box[i][j][k];
				if (box[i][j][k] == 1)
					tomato.push({ {i,j},k });

			}
		}
	}
	int d = time();

	bool isComplete = true;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				if (box[i][j][k] == 0)
				{
					isComplete = false;
					break;
				}
			}

		}
	}
	if (isComplete)
	{
		std::cout << d;
	}
	else
		std::cout << "-1";
}
*/
#pragma endregion

#pragma region 백준_1697_숨바꼭질
/*
#include <iostream>
#include <queue>

int sp, bp;
bool isVisited[100001] = {};
int bfs()
{
	std::queue<int> q;
	q.push(sp);
	isVisited[sp] = true;
	int last = q.back();
	int count = 0;
	while (!q.empty())
	{
		int pos = q.front();
		if (pos == bp)
			break;
		if (pos > 0)
			if (!isVisited[pos - 1])
			{
			q.push(pos - 1);
			isVisited[pos - 1] = true;
			}
		if (pos < 100000)
			if (!isVisited[pos + 1])
			{
			q.push(pos + 1);
			isVisited[pos + 1] = true;
			}
		if (pos * 2 <= 100000)
			if(!isVisited[pos*2])
		{
			q.push(pos * 2);
			isVisited[pos * 2] = true;
		}

		if (last == q.front())
		{
			last = q.back();
			++count;
		}
		q.pop();
	}
	return count;
}

int main()
{
	std::cin >> sp >> bp;

	std::cout << bfs();
	return 0;
}
*/
#pragma endregion

#pragma region 백준_7562_나이트의이동
/*
#include <iostream>
#include <queue>

int testCase;
short I, px, py, ex, ey;

int bfs()
{
	bool isVisited[300][300] = {};
	static const short dx[8] = { 2,2,-2,-2,1,-1,1,-1 };
	static const short dy[8] = { 1,-1,1,-1,2,2,-2,-2 };
	std::queue<std::pair<short, short>> q;
	q.push({ px,py });
	isVisited[px][py] = true;
	std::pair<short, short> last = { q.back().first,q.back().second };
	int count = 0;
	while (!q.empty())
	{
		short x = q.front().first;
		short y = q.front().second;
		if (x == ex && y == ey)
		{
			break;
		}
		for (int i = 0; i < 8; ++i)
		{
			short nx = x + dx[i];
			short ny = y + dy[i];

			if (nx<0 || nx>=I || ny<0 || ny>=I)
				continue;
			if (isVisited[nx][ny])
				continue;

			q.push({ nx,ny });
			isVisited[nx][ny] = true;

		}
		if (last.first == q.front().first && last.second == q.front().second)
		{
			++count;
			last = { q.back().first,q.back().second };
		}
		q.pop();
	}
	return count;
}

int main()
{
	std::cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		std::cin >> I >> px >> py >> ex >> ey;
		std::cout << bfs() << "\n";
	}
}
*/
#pragma endregion

#pragma region 백준_16928_뱀과사다리게임
/*
#include <iostream>
#include <queue>

std::pair<int, int> ladder[15];
std::pair<int, int> snake[15];
bool isVisited[101];

int N, M;

int bfs()
{
	int count = 1;
	bool isVisited[101] = {};
	std::queue<int> q;
	q.push(1);
	isVisited[1] = true;
	int last = q.back();
	static const int dp[6] = { 1,2,3,4,5,6 };
	while (!q.empty())
	{
		bool isExit = false;
		int pos = q.front();
		for (int i = 0; i < N; ++i)
		{
			if (ladder[i].first == pos)
			{
				pos = ladder[i].second;
			}
		}
		for (int i = 0; i < M; ++i)
		{
			if (snake[i].first == pos)
			{
				pos = snake[i].second;
			}
		}

		for (int i = 0; i < 6; ++i)
		{
			int np = pos + dp[i];
			if (isVisited[np])
				continue;

			if (np == 100)
			{
				isExit = true;
				break;
			}
			isVisited[np] = true;
			q.push(np);
		}
		if (isExit)
			break;
		if (q.front() == last)
		{
			last = q.back();
			++count;
		}
		q.pop();
	}
	return count;
}

int main()
{
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		ladder[i] = { a,b };
	}
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		snake[i] = { a,b };
	}
	std::cout << bfs();
}
*/
#pragma endregion

#pragma region 백준_11725_트리의부모찾기
/*
#include <iostream>
#include <vector>
#include <queue>
std::vector<int> v[100001];
int parent[100001] = {};
void findParent()
{
	bool isVisited[100001] = {};
	std::queue<int> q;
	q.push(1);
	isVisited[1] = true;
	while (!q.empty())
	{
		int node = q.front();
		for (int nextNode : v[node])
		{
			if (isVisited[nextNode] == false)
			{
				q.push(nextNode);
				isVisited[nextNode] = true;
				parent[nextNode] = q.front();
			}
		}
		q.pop();
	}
}

int main()
{
	int non;
	std::cin >> non;
	for (int i = 1; i < non; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	findParent();

	for (int i = 2; i <= non; ++i)
	{
		std::cout << parent[i] << "\n";
	}

}
*/
#pragma endregion

#pragma region 끝이없음_x
/*
#include <iostream>
#include <string>

std::string str1;
std::string str2;
int loopcount;
int min, max;

void string(std::string input, std::string body)
{
	std::string temp;
	for (int i = 0; i < body.size(); ++i)
	{
		if (body[i] == '$')
			temp += input;
		else
			temp += body[i];
	}

	str1 = temp;
}


int main()
{



	std::cin >> str1 >> str2 >> loopcount >> min >> max;

	for (int i = 0; i < loopcount; ++i)
	{
		string(str1, str2);
	}

	for (int i = min - 1; i < max; ++i)
	{
		if (i > str1.size() - 1)
			std::cout << '-';
		else
			std::cout << str1[i];
	}

}
*/

#pragma endregion

/*
#include <iostream>
#include <vector>

struct Graph
{
	std::vector<int> trunk;
	bool isBpartite;
};
Graph graph[20000];


int main()
{
	std::ios::sync_with_stdio()
	int testCase;
	std::cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{

	}
}
*/

#pragma region 백준_4342_유클리드게임_X
/*
#include <iostream>
std::pair<char, int> A;
std::pair<char, int> B;
bool isAWin(std::pair<char, int> big, std::pair<char, int> small)
{
	if (small.second == 0)
	{
		if (small.first == 'A')
			return false;
		else
			return true;
	}

	int temp = big.second - small.second;
	if (temp <= 0)
	{
		big.second = 0;
		return isAWin(small, big);
	}

	if (small.second > temp)
	{
		big.second = temp;
		return isAWin(small, big);
	}
	else
	{
		big.second = temp;
		return isAWin(big, small);
	}

}

int main()
{
	int a, b;
	std::cin >> a >> b;
	while (a != 0 && b != 0)
	{
		A = { 'A',a };
		B = { 'B',b };

		if (a > b ? isAWin(A, B) : isAWin(B, A))
			std::cout << "A wins\n";
		else
			std::cout << "B wins\n";
		std::cin >> a >> b;
	}
	return 0;
}
*/
/*
#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	while (a != 0 && b != 0)
	{
		bool isAWin = true;
		while (a != 0 && b != 0)
		{
			if (a > b)
			{
				if (a % b == 0)
				{
					b = 0;
				}
				else
				{
					if (a / b >= 2)
					{
						if (b % (a % b) == 0)
							a = (a % b) + a;
						else
							a %= b;
					}
					else
						a %= b;

				isAWin = !isAWin;
				}
			}
			else if (a < b)
			{
				if (b % a == 0)
				{
					a = 0;
				}
				else
				{
					if (b / a >= 2)
					{
						if (a % (b % a) == 0)
							b = (b % a) + b;
						else
							b %= a;
					}
					else
						b %= a;

					isAWin = !isAWin;
				}
			}

		}

		if (isAWin)
			std::cout << "A wins\n";
		else
			std::cout << "B wins\n";
		std::cin >> a >> b;
	}
}
*/
#pragma endregion

#pragma region 백준_1978_소수찾기
/*
#include <iostream>

int main()
{
	int testCase;
	std::cin >> testCase;
	int count = testCase;
	for (int i = 0; i < testCase; ++i)
	{
		int num;
		std::cin >> num;
		if (num <= 1)
		{
			--count;
		}
		else
		{
			for (int j = 2; j < num; ++j)
			{
				if (num % j == 0)
				{
					--count;
					break;
				}
			}
		}
	}
	std::cout << count;
}
*/
#pragma endregion

#pragma region 백준_9020_골드바흐의추측
/*
#include <iostream>
#define MAX 10000

bool arr[MAX + 1] = {};

void isDecimal()
{
	arr[0] = true;
	arr[1] = true;
	int check = 2;
	while (check != MAX - 1)
	{
		for (int i = check + 1; i <= MAX; ++i)
		{
			if (!arr[i])
				if (i % check == 0)
					arr[i] = true;
		}

		for (int i = check + 1; i <= MAX; ++i)
		{
			if (!arr[i])
			{
				check = i;
				break;
			}
			if (i == MAX - 1)
				check = i;
		}
	}
}

int main()
{
	isDecimal();
	int testCase;
	std::cin >> testCase;
	for (int i = 0; i < testCase; ++i)
	{
		int num;
		std::cin >> num;
		std::pair<int, int> result = { 0,10000 };

		for (int j = 2; j <= num / 2; ++j)
		{
			if (!arr[j])
			{
				if (!arr[num - j])
				{
					if (num - 2 * j < result.second - result.first)
						result = { j,num - j };
				}
			}
		}

		std::cout << result.first << " " << result.second << "\n";
	}

	return 0;
}
*/
#pragma endregion

#pragma region 백준_골드바흐_X
/*
#include <iostream>

int main() {
	int A, B;
	bool isNDecimal[1000001] = {  };
	isNDecimal[1] = true;
	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = 2; i * j <= 1000000; j++)
			isNDecimal[i * j] = true;
	}

	std::cin >> A;
	for (int k = 0; k < A; k++)
	{
		std::cin >> B;
		int count = 0;
		for (int p = B / 2; p > 0; p--)
		{
			if (!isNDecimal[p] && !isNDecimal[B - p])
			{
				++count;
			}
		}
		std::cout << count << "\n";
	}
	return 0;
}
*/
#pragma endregion

#pragma region 백준_5639_이진검색트리
/*
#include <iostream>

struct Node
{
	int _Value;
	//Node* _Parent;
	Node* _Right;
	Node* _Left;
};

Node node[10000] = { 0, };
int count = 0;

void insert(int value,int count)
{
	if (count == 0)
	{
		node[0]._Value= value;
		return;
	}
	else
	{
		Node* parent = &node[0];
		while (1)
		{
			if (parent->_Value > value)
			{
				if (parent->_Left == nullptr)
				{
					node[count]._Value = value;
					//node[count]._Parent= parent;
					parent->_Left = &node[count];
					return;
				}
				else
				{
					parent = parent->_Left;
				}
			}
			else
			{
				if (parent->_Right == nullptr)
				{
					node[count]._Value = value;
					//node[count]._Parent = parent;
					parent->_Right = &node[count];
					return;
				}
				else
				{
					parent = parent->_Right;
				}
			}
		}
	}
}
void printnode(Node* x) {
	if (x != NULL) {
		printnode(x->_Left);
		printnode(x->_Right);
		std::cout << x->_Value << "\n";
	}
}

//void print_post_order()
//{
//	Node* where = &node[0];
//	bool isprint[10000] = {};
//	while (count != 0)
//	{
//		if (where->_Left != nullptr && !isprint[where->_Left->_Value])
//		{
//			where = where->_Left;
//			continue;
//		}
//		else if (where->_Right != nullptr && !isprint[where->_Right->_Value])
//		{
//			where = where->_Right;
//			continue;
//		}
//		else
//		{
//			std::cout << where->_Value << "\n";
//			isprint[where->_Value] = true;
//			--count;
//			if (where->_Parent != nullptr)
//				where = where->_Parent;
//		}
//
//
//	}
//
//}

int main()
{
	int num;
	while (std::cin>>num)
	{
		if (num == 0)
			break;
		insert(num, count);
		++count;
	}

	printnode(&node[0]);
	//print_post_order();
}
*/
#pragma endregion

#pragma region 백준_1991_트리순회
/*
#include <iostream>
#include <vector>

struct Node
{
	char _data;
	Node* _left;
	Node* _right;
};
Node node[26];

void insert(char pos,char left, char right)
{
	node[pos - 'A']._data = pos;
	if (left != '.')
		node[pos - 'A']._left = &node[left - 'A'];
	if (right != '.')
		node[pos - 'A']._right = &node[right - 'A'];
}


void pre(Node* pos)
{
	if (pos != nullptr)
	{
		std::cout << pos->_data;
		pre(pos->_left);
		pre(pos->_right);
	}
}
void in(Node* pos)
{
	if (pos != nullptr)
	{
		in(pos->_left);
		std::cout << pos->_data;
		in(pos->_right);
	}
}
void post(Node* pos)
{
	if (pos != nullptr)
	{
		post(pos->_left);
		post(pos->_right);
		std::cout << pos->_data;
	}
}

int main()
{
	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char v, l, r;
		std::cin >> v >> l >> r;
		insert(v, l, r);
	}
	pre(&node[0]);
	std::cout << "\n";
	in(&node[0]);
	std::cout << "\n";
	post(&node[0]);
	std::cout << "\n";

	return 0;
}
*/
#pragma endregion

