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

#pragma region 백준_10757_큰수A+B
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
