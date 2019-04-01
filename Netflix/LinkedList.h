#pragma once
#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <iostream>
using namespace std;

template<class T>
class LinkedList {
private:
	template<class T>
	class Node {
		friend class LinkedList;
	private:
		T data;
		Node<T>* next;
	public:
		Node<T>(const T& data) : data(data), next(nullptr) {}
	};
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();
	LinkedList(const LinkedList& other) = delete;
	~LinkedList();
	void insert(const T data);
	void remove(const T data);
	void print();
};

template<class T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr)
{

}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* current = this->head;
	Node<T>* temp = nullptr;
	while (current)
	{
		temp = current->next;
		delete current;
		current = temp;
	}
}

template<class T>
void LinkedList<T>::insert(const T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (this->tail == nullptr)
	{
		newNode->next = nullptr;
		this->tail = newNode;
		this->head = newNode;
		return;
	}
	this->tail->next = newNode;
	this->tail = this->tail->next;
}

template<class T>
void LinkedList<T>::print()
{
	Node<T>* current = this->head;
	while (current)
	{
		cout << "\n" << *(current->data) << endl;
		current = current->next;
	}
}

template<class T>
void LinkedList<T>::remove(const T data)
{
	Node<T>* current = this->head->next;
	Node<T>* previous = this->head;
	if (previous->data == data)
	{
		this->head = this->head->next;
		delete previous;
		return;
	}
	while (current != nullptr && current->data != data)
	{
		previous = current;
		current = current->next;
	}
	if (current != nullptr)
	{
		previous->next = current->next;
		delete current;
	}
}

#endif //_LINKED_LIST_H


