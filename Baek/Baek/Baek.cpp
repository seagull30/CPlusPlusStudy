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

#pragma region 백준_1966_프린터큐_X
/*
#include <iostream>
#include <queue>

int main()
{
	int loopCount;
	std::cin >> loopCount;
	std::queue<int> importance;
	for (int i = 0; i < loopCount; ++i)
	{
		int numberOfDocument;
		int findDocumentNumber;
		std::cin >> numberOfDocument >> findDocumentNumber;
		for (int j = 0; j < numberOfDocument; ++j)
		{
			int input;
			std::cin >> input;
			importance.push(input);
		}





		while (!importance.empty())
			importance.pop();
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

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v[100000];
bool isVisited[100000] = {};

int N, M, R;
void def()
{

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

bool arr[25][25] = {};
int complex[123456789] = {};
int count = 0;

void countComplex(int n)
{
	
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (arr[i][j])
			{
				countComplex();
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
int main()
{

}
*/
#pragma endregion