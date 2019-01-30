/*
* revision TASK 4
*
* Author    : Plamen Minev
*/
#include <iostream>

struct Node
{
	int m_Value;
	Node* m_Next;

	Node(int val)
		: m_Value(val)
		, m_Next(nullptr)
	{}
};


Node* CustomReverse(Node* head, int k)
{
	Node* current = head;
	Node* next = nullptr;
	Node* prev = nullptr;
	int count = 0;

	while (current != NULL && count < k)
	{
		next = current->m_Next;
		current->m_Next = prev;
		prev = current;
		current = next;
		count++;
	}

	if (next != NULL)
	{
		head->m_Next = CustomReverse(next, k);
	}

	return prev;
}

int main()
{
	Node* head = new Node(1);
	Node* temp = head;
	for (int i = 2; i < 10; i++)
	{
		temp->m_Next = new Node(i);
		temp = temp->m_Next;
	}

	head = CustomReverse(head, 3);
	return 0;
}