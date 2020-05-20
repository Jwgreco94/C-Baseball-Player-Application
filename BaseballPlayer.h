/*
This assignment uses the linked list provided for the discussion and the class you created for the discussion.
Overload the[] operator in the linked list so that it behaves like an array.
If 0 is provided it gets the first element(data stored in list) in the list, if 1 is provided then it returns the second element in the list.

Create a class called BaseballPlayer which maintains the player’s stats and name.

The class will have data members for the following stats

Number of hits
Number of home runs
Number of walks
Number of strike outs
Provide methods

Constructor with four parameters
Accessors and mutators for the data members
Overload any operators that are needed
The driver class will create several players and put them into an instance of the derived linked list class.The program will tell the user which player has the best stats based the scoring below and which player is the worst.

A hit is worth 1 point
A homerun is worth 4 points
A walk is worth 1 point
A strike out is worth - 1 points
The total of the points will determine who has the higher and lower stats.

*/

//*******************************************************************************
// Jonathan Greco																*
// Professor Specioso															*
// Programming III																*
// 17 Novemeber 2018															*
// Template file for the Baseball Player class									*
//*******************************************************************************
#ifndef BaseballPlayer_H
#define BaseballPlayer_H
#include "LinkedList.h"
#include <iostream>
using namespace std;

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

#endif	// !BaseballPlayer_H
