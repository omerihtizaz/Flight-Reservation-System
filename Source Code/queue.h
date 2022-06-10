#pragma once
#include<iostream>
#include"link.h"
#include"edge.h"
template<typename T>
struct Node_q {

	Node_q<T>* next;
	T value;
};
template<typename T>
class Queue
{
private:
	Node_q<T>* end;
	int size;
public:
	Node_q<T>* front;
	Queue() {
		front = end = NULL;
		size = 0;
	}
	T q_front() {
		return front->value;
	}
	int get_size() {
		return size;
	}
	void enqueue(T val) {
		Node_q<T>* newnode = new Node_q<T>();
		newnode->value = val;
		newnode->next = NULL;
		if (isEmpty()) {
			front = newnode;
			end = newnode;
		}
		else {
			end->next = newnode;
			end = newnode;
		}
		size++;
	}
	T dequeue() {
		Node_q<T>* temp = front;
		T num;
		num = front->value;
		temp = front->next;
		delete front;
		front = temp;
		size--;
		return num;
	}
	Queue<Node_l<edge>*> goto_(int index)
	{
		Node_l<T>* temp = front;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp;
	}
	bool isEmpty() {
		if (size == 0)
			return true;
		return false;
	}
	Queue<T>& operator+(const T& val) {
		enqueue(val);
	}
	Queue<T>& operator-() {
		dequeue();
	}
	/*int minIndex(int sortedIndex)
	{
		int min_index = -1;
		int min_val = INT_MAX;
		int n = get_size();
		for (int i = 0; i < n; i++)
		{
			int curr = q_front();
			dequeue();
			if (curr <= min_val && i <= sortedIndex)
			{
				min_index = i;
				min_val = curr;
			}
			enqueue(curr);
		}
		return min_index;
	}
	void insertMinToRear(int min_index)
	{
		int min_val=0;
		int n = get_size();
		for (int i = 0; i < n; i++)
		{
			int curr = q_front();
			dequeue();
			if (i != min_index)
				enqueue(curr);
			else
				min_val = curr;
		}
		enqueue(min_val);
	}

	void sortQueue()
	{
		for (int i = 1; i <=get_size(); i++)
		{
			int min_index = minIndex(get_size() - i);
			insertMinToRear(min_index);
		}
	}*/
	void operator=(Queue q) {
		front = q.front;
		end = q.end;
		size = q.size;
	}
};