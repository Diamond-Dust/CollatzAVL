#pragma once

class QNode {
	public:
		QNode* next;
		unsigned int Index;
		QNode(unsigned int index);
		QNode(const QNode& right);
		QNode& operator=(const QNode& right);
		bool operator>(const QNode& right);
		bool operator<(const QNode& right);
		unsigned int GetIndex();
		~QNode();
};