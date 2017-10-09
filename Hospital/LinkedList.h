#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

template<class T>
class LinkedList
{
private:
	class Node
	{
	public:
		T		data;
		Node*	next;
		Node(T& data, Node* next = nullptr);
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

	template<class T>
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& linkedList);
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
	LinkedList<T>::Node* newNode = new LinkedList<T>::Node(data);
	if (tail == nullptr)
	{
		newNode->next = tail;
		tail = newNode;
		head = newNode;
	}
	else {
		tail->next = newNode;
		tail = tail->next;
	}
	size++;
}

template<class T>
bool LinkedList<T>::remove(T data)
{
	LinkedList<T>::Node* prev = nullptr;
	LinkedList<T>::Node* current;

	for (current = head; current != nullptr; prev = current, current = current->next)
		if (current->data == data)
			break;

	if (current != nullptr)
	{
		prev->next = current->next;
		delete current;
		size--;
		return true;
	}
	return false;
}
template<class T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& linkedList)
{
	for(LinkedList<T>::Node* current = linkedList.head; current != nullptr; current = current->next)
		os << current->data << std::endl;

	return os;
}

#endif