#pragma once
#include "PQ.h"

class Node {
	public:
		Node* Parent;
		Node* LeftChild;
		Node* RightChild;
		int Balance;
		unsigned int Value;
		PQ Indexes;
		Node(unsigned int value, unsigned int index);
		Node(const Node& right);
		Node& operator=(const Node& right);
		bool operator>(const Node& right);
		bool operator==(const Node& right);
		bool operator<(const Node& right);
		void SetParent(Node* parent);
		void SetLeftChild(Node* leftchild);
		void SetRightChild(Node* rightchild);
		void SetBalance(int balance);
		void AddIndex(unsigned int index);
		Node* GetParent();
		Node* GetLeftChild();
		Node* GetRightChild();
		unsigned int Pop();
		int GetBalance();
		unsigned int GetSize();
		unsigned int GetValue();
		~Node();
};