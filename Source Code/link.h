#pragma once
#include<iostream>
using namespace std;
template<class T>
struct	Node_l
{
public:
	T data;
	Node_l<T>* next;
};
template<typename T>
class List
{
private:
	T e;
	Node_l<T>* current;
public:
	Node_l<T>* head;
	T getdata() {
		return e;
	}
	List() {
		head = NULL;
		current = head;
	}
	~List() {
		this->clear();
	}
	T getHead_data() {
		return head->data;
	}
	Node_l<T>* getHead() {
		return head;
	}
	bool isEmpty() {
		if (head == NULL)
			return true;
		return false;
	}
	void insert(const T& newDataItem) {
		Node_l<T>* temp_1 = new Node_l<T>();
		temp_1->data = newDataItem;
		temp_1->next = NULL;
		if (isEmpty()) {
			current = temp_1;
			head = temp_1;
		}
		else {
			Node_l<T>* temp_2 = head;
			while (temp_2->next != NULL)
			{
				temp_2 = temp_2->next;
			}
			temp_2->next = temp_1;
		}
	}
	void clear() {
		Node_l<T>* currNode_l = head;
		Node_l<T>* nextNode_l = NULL;
		while (currNode_l != NULL)
		{
			nextNode_l = currNode_l->next;
			delete currNode_l;
			currNode_l = nextNode_l;
		}
		head = NULL;
		current = NULL;
	}
	/*Node_l<T>* find(T d) {
		Node_l<T>* temp = head;
		while (head->next != NULL) {
			if (d == data)
				cout << "found" << endl;
				return temp;
		}
	}*/
	bool operator== (List l)
	{
		Node_l<T>* temp = this->head;
		Node_l<T>* temp_l = l.head;
		while (temp && temp_l)
		{
			if (temp != temp_l)
				return false;
		}
		if ((temp && !temp_l) || (temp_l && !temp))
		{
			return false;
		}
		return true;
	}
	int getSize()
	{
		return size;
	}
	void display() {
		if (!isEmpty()) {
			Node_l<T>* temp = head;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};