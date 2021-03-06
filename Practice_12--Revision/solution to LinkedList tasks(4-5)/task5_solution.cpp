/*
* revision : TASK 5
*
* Author    : Nikolay Denev
*/

#include <iostream>

struct node {
	node(const std::string& name, node* next = nullptr)
		: name(name)
		, pNext(next)
	{}

	std::string name;
	node* pNext;
};

void sortList(node*& pHead) {
	if (pHead == nullptr) {
		return;
	}

	node** currentNode = &pHead;
	node** minNode = &pHead;
	node** currentStart = &pHead;
	while ((*currentStart) != nullptr) {
		// Find the smallest node in the list after the currentNode.
		while ((*currentNode) != nullptr) {
			if ((*currentNode)->name < (*minNode)->name) {
				minNode = currentNode;
			}
			currentNode = &(*currentNode)->pNext;
		}

		node* tempNode = (*minNode);
		(*minNode) = (*minNode)->pNext;
		tempNode->pNext = (*currentStart);
		(*currentStart) = tempNode;

		currentStart = &tempNode->pNext;
		currentNode = currentStart;
		minNode = currentStart;
	}
}

void printList(node* pHead) {
	if (pHead) {
		std::cout << pHead->name.c_str() << ' ';
		printList(pHead->pNext);
	}
}

int main() {
	node* node5 = new node(std::string("Hektor"));
	node* node4 = new node(std::string("Panterata"), node5);
	node* node3 = new node(std::string("Ceco"), node4);
	node* node2 = new node(std::string("Bezalkoholnoto"), node3);
	node* node1 = new node(std::string("Gosho"), node2);

	sortList(node1);
	printList(node1);

	return 0;
}