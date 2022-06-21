#include <forward_list> // std::forward_list�� ���� ���� ���
#include <iostream>
#include "FowardList.h"
#include "List.h"
int main()
{
    std::forward_list<int> flist;
    ForwardList mylist;
    ForwardList::iterator myiter;

    List list;
    list.push_front(1);
    list.push_front(3);
    list.push_front(5);

    for (List::iterator listiter = list.begin(); listiter != list.end(); ++listiter)
    {
        std::cout << *listiter << "\n";
    }



    // ����
    mylist.push_front(3);
    mylist.push_front(2);
    mylist.push_front(1);
   



	for (myiter = mylist.begin(); myiter != mylist.end(); ++myiter)
	{
		std::cout << *myiter << "\n";
	}


    flist.push_front(1); // push_front() : �� �տ� �����Ѵ�.
    if (flist.front() == mylist.front())
    {
        std::cout << "����";
    }
    ForwardList mylist2 = mylist;

    // flist{ 1 }
    flist.insert_after(flist.begin(), 2); // insert_after(pos, value) : pos �ڿ� value�� �����Ѵ�.
    // flist{ 1, 2 }
    flist.push_front(3); // flist { 3, 1, 2 }

    // �ݺ���
    std::forward_list<int>::iterator iter;
    iter = flist.before_begin();
    // [ ]->[3]->[1]->[2]->[ ]
    //  ��
    iter = flist.begin();
    // [ ]->[3]->[1]->[2]->[ ]
    //       ��
    iter = flist.end();
    // [ ]->[3]->[1]->[2]->[ ]
    //                      ��

    // ����
    flist.pop_front(); // pop_front() : ù ��° ���Ҹ� �����Ѵ�.
    // flist{ 1, 2 };
    flist.erase_after(flist.begin()); // erase_after(pos) : pos ���� ���Ҹ� �����Ѵ�.
    // flist{ 1 }
    flist.clear(); // clear() : �����̳ʸ� ���� ����.
    // flist{ }

    // ũ��
    if (flist.empty()) // empty() : ������� Ȯ���Ѵ�.
    {
        std::cout << "flist�� �����.\n";
    }
    // ����! �ٸ� �����̳ʿ� �ٸ��� size()�� ����

    // �Ʒ�ó�� �ʱ�ȭ ����
    std::forward_list<int> flist2 = { 1, 2, 3, 4, 5 };

    // �б�
    std::cout << "flist2.front() : " << flist2.front() << "\n"; // front() : ù ��° ���Ҹ� ��ȯ�Ѵ�.

    // �� : �ٸ� �����̳ʿ� ���������� == / != / > / >= / < / <= ����
    flist = flist2;
    if (flist == flist2)
    {
        std::cout << "flist�� flist2�� ����.\n";
    }

    // C++17���ʹ� ���� Ÿ���� ���� �ʾƵ� �˾Ƽ� �߷��Ѵ�.
    std::forward_list flist3 = { 1, 2, 3, 4, 5 };

    return 0;
}
