#pragma once
#include "QNode.h"

class PQ {
private:
	int size;
	int First;
	QNode* head;
public:
	PQ();
	PQ(const PQ& right);
	void Add(QNode* node);
	void Add(unsigned int index);
	int GetSize();
	unsigned int Pop();
	PQ& operator=(const PQ& right);
	~PQ();
};