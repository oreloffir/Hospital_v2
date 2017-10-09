#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template<class T>
class LinkedList
{
private:
	class Node
	{
	public:
		T		data;
		Node*	next;
		Node(T& data, Node* next = nullptr); //Constructor
	};

	int size;
	Node* head;
	Node* tail;
public:
	LinkedList();

	bool isEmpty()	const;
	int getSize()	const;
	void insertToTail(T data);
	bool remove(T data);
	
};
template<class T>
LinkedList<T>::Node::Node(T& data, Node* next) : data(data), next(next) {}

template<class T>
LinkedList<T>::LinkedList() : size(0), head(nullptr), tail(nullptr) {};

template<class T>
bool LinkedList<T>::isEmpty() const
{
	if (size == 0)
		return true;
	return false;
}

template<class T>
int LinkedList<T>::getSize() const
{
	return size;
}

template<class T>
void LinkedList<T>::insertToTail(T data)
{
	Node<T> * newNode = new Node<T>(data);
	if (tail == nullptr)
	{
		newNode->next = tail;
		tail = newNode;
		head = newNode;
		return;
	}
	tail->next = newNode;
	tail = tail->next;
}

template<class T>
bool LinkedList<T>::remove(T data)
{
	Node<T> *prev, *currect;
	for (currect = head; currect != nullptr; prev = currect, currect = currect->next)
		if (currect->value == data) 
			break;

	if (current != nullptr)
	{
		prev->next = currect->next;
		delete currect;
		size--;
		return true;
	}
	return false;
}


#endif