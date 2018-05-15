#pragma once
#include "QNode.h"

class PQ {
private:
	int size;
	QNode* head;
public:
	PQ();
	PQ(const PQ& right);
	void Add(QNode* node);
	int GetSize();
	unsigned int Pop();
	PQ& operator=(const PQ& right);
	~PQ();
};