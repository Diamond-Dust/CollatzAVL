#pragma once
#include "PQ.h"

PQ::PQ() {
	this->head = nullptr;
	size = 0;
}

PQ::PQ(const PQ & right) {
	QNode* newNode = new QNode(*right.head);
	this->head = newNode;
	while (newNode->next != nullptr)
	{
		newNode = newNode->next;
		this->Add(newNode);
	}
}

void PQ::Add(QNode* node) {
	QNode* newNode = new QNode(*node);
	QNode* tempNode = nullptr;
	if (size > 0)
	{
		newNode->next = this->head;
		if (newNode->next->Index < newNode->Index)
			while ((newNode->next != nullptr) && (newNode->next->Index < newNode->Index))
			{
				if (tempNode != nullptr)
					tempNode->next = newNode->next;
				tempNode = newNode->next;
				newNode->next = tempNode->next;
				tempNode->next = newNode;

			}
		else
			this->head = newNode;
	}
	else
		this->head = newNode;
	size++;
}

int PQ::GetSize() {
	return this->size;
}

unsigned int PQ::Pop() {
	unsigned int index;
	QNode* node = this->head;
	index = node->Index;
	this->head = this->head->next;
	size--;
	return index;
}

PQ & PQ::operator=(const PQ & right) {
	QNode* newNode = new QNode(*right.head);
	this->head = newNode;
	while (newNode->next != nullptr)
	{
		newNode = newNode->next;
		this->Add(newNode);
	}
	return *this;
}

PQ::~PQ() {
	this->head = nullptr;
}