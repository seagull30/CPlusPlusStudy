#pragma once
#include <stddef.h>

#pragma region ���������غ���
/*
class SingleLinkedList
{
public:
    struct Node
    {
        Node(int data = 0, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data = 0;
        Node* Next = nullptr;
    };

public:
    // �⺻ ������
    SingleLinkedList()
    {
        _head->Next = _end;
    }

    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    explicit SingleLinkedList(size_t count)
    {
        _head->Next = _end;
        for (size_t i = 0; i < count; ++i)
        {
            push_front(0);
        }

    }

    // ���� ������.
    SingleLinkedList(const SingleLinkedList& other);

    // �Ҵ� ������
    SingleLinkedList& operator=(const SingleLinkedList& rhs);

    // �Ҹ���
    ~SingleLinkedList()
    {
        clear();
        delete _head;
        _head = nullptr;
        delete _end;
        _end = nullptr;
    }

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front()
    {
        return begin()->Data;
    }
    const int& front() const
    {
        return begin()->Data;
    }

    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* before_begin()
    {
        return _head;
    }
    const Node* before_begin() const
    {
        return _head;
    }

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* begin()
    {
        return _head->Next;
    }
    const Node* begin() const
    {
        return _head->Next;
    }

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* end()
    {
        return _end;
    }
    const Node* end() const
    {
        return _end;
    }

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* insert_after(Node* pos, int value)
    {
        Node* newNode = new Node();
        Node* where = pos;

        newNode->Next = where->Next;
        where->Next = newNode;
        newNode->Data = value;
        
        return newNode;
    }

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    Node* erase_after(Node* pos)
    {
        Node* where = pos;
        Node* removed = pos->Next;
        where->Next = removed->Next;
        removed->Next = nullptr;
        return removed;
    }

    // ���� ��ҿ� value�� �����Ѵ�.
    void            push_front(int value)
    {
        insert_after(before_begin(), value);
    }

    // ���� ��Ҹ� �����Ѵ�.
    void            pop_front()
    {
        erase_after(before_begin());
    }
    
    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool            empty() const
    {
        if (_head->Next == _end)
            return true;
        else
            return false;
    }

    // �����̳ʸ� ���������.
    void            clear()
    {
        while (empty())
        {
            pop_front();
        }
    }

    bool            contains(int value) const
    {
        Node* node = _head;
        while (node == _end)
        {
            node = node->Next;
            if (node->Data == value)
                return true;
        }
        return false;
    }
private:
    Node* _head = new Node();
    Node* _end = new Node();
};

*/
#pragma endregion

class ForwardList
{
    // ���� ����Ʈ���� �����͸� �����ϱ� ���� Ÿ��
    // ��, ���� ����Ʈ�� �����͸� ���������� �ٷ�� ���� �ƴ϶� 
    // Node��� ������ �ٷ�ϴ�.
    struct Node
    {
        Node(int data = 0, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data = 0;
        Node* Next = nullptr;
    };

public:
    // �����͸� ������ �� ���� �ݺ���.
    class const_iterator
    {
    public:
        const_iterator(Node* p = nullptr);
        ~const_iterator();

        const int&          operator*() const;  // ������
        const int*          operator->() const; // �ɹ� ����
        const_iterator&     operator++();       // ���� ���� ������
        const_iterator      operator++(int);    // ���� ���� ������
        bool                operator==(const const_iterator& rhs) const;
        bool                operator!=(const const_iterator& rhs) const;
        bool                operator==(nullptr_t p) const;
        bool                operator!=(nullptr_t p) const;

    public:
        Node* _p = nullptr;
    };

    // �����͸� ������ ������ �ݺ���.
    class iterator : public const_iterator
    {
    public:
        //using const_iterator::const_iterator;
        iterator(Node* p = nullptr);

        int& operator*() const;
        int* operator->() const;
        iterator& operator++();
        iterator        operator++(int);
    };

    // �⺻ ������
    ForwardList();
    

    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    explicit ForwardList(size_t count);
    

    // ���� ������.
    ForwardList(const ForwardList& other);

    // �Ҵ� ������
    ForwardList& operator=(const ForwardList& rhs);

    // �Ҹ���
    ~ForwardList();

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front();
    
    const int& front() const;
    

    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            before_begin();
   
    const_iterator      before_begin() const;
   

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            begin();
  
    const_iterator      begin() const;
   
    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            end();
   
    const_iterator      end() const;
    
    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator            insert_after(const_iterator pos, int value);
    

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    iterator            erase_after(const_iterator pos);
    

    // ���� ��ҿ� value�� �����Ѵ�.
    void                push_front(int value);
    

    // ���� ��Ҹ� �����Ѵ�.
    void                pop_front();
   

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool                empty() const;


    // �����̳ʸ� ���������.
    void                clear();
	

    // value�� �ִ��� �˻��Ѵ�.
    bool                contains(int value) const;
    
private:
    // ���� ��� : ���� �����͸� ���� ����. ������ ������ ���Ǽ��� ���ؼ� ����
    Node* _head = new Node();   // before_begin()
    // ���̳��
    Node* _end = new Node();    // end()
};
