#include <iostream>
using namespace std;

/*template <class T>
struct ListNode
{
	T data;
	ListNode* next;
};*/

template <class T>
class ListNode
{
public:
	T data;
	ListNode<T>* next;

	ListNode(T data)
	{
		this->data = data;
		next = nullptr;
	}
};

template <class T>
class LinkedList
{
private:
	ListNode<T>* head;

public:
	LinkedList();
	~LinkedList();
	void AppendNode(T data);
	void InsertNode(T data);
	void DeleteNode(T data);
	void DisplayList();
};


template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode<T>* nextNode = nullptr;
	ListNode<T>* nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}
}

template <class T>
void LinkedList<T>::AppendNode(T data)
{
	ListNode<T>* newNode = nullptr;
	ListNode<T>* nodePtr = nullptr;

	newNode = new ListNode<T>(data);

	if (head == nullptr)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next != nullptr)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

template <class T>
void LinkedList<T>::InsertNode(T data)
{
	ListNode<T>* newNode = nullptr;
	ListNode<T>* currentNode = nullptr;
	ListNode<T>* previousNode = nullptr;

	newNode = new ListNode<T>(data);


	if (head == nullptr)
	{
		head = newNode;
	}
	else if (head->data >= newNode->data)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		currentNode = head;
		previousNode = nullptr;

		while (currentNode != nullptr && currentNode->data < newNode->data)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		previousNode->next = newNode;
		newNode->next = currentNode;
	}
}

template <class T>
void LinkedList<T>::DeleteNode(T data)
{
	ListNode<T>* currentNode = nullptr;
	ListNode<T>* previousNode = nullptr;

	if (head != nullptr)
	{
		if (head->data == data)
		{
			currentNode = head->next;
			delete head;
			head = currentNode;
		}
		else
		{
			currentNode = head;

			while (currentNode != nullptr && currentNode->data != data)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
			}

			if (currentNode != nullptr)
			{
				previousNode->next = currentNode->next;
				delete currentNode;
			}
		}
	}
}

template <class T>
void LinkedList<T>::DisplayList()
{
	ListNode<T> *nodePtr = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr)
	{
		cout << nodePtr->data << endl;
		nodePtr = nodePtr->next;
	}
}