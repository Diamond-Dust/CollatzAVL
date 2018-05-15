//Based on the Wikipedia article on AVL trees.
#pragma once
#include "Node.h"

class AVL{
	private:
		Node* ROOT;

		Node* LeftRotate(Node * upperPlace, Node* place);
		Node* RightRotate(Node * upperPlace, Node* place);
		Node* RightLeftRotate(Node * upperPlace, Node* place);
		Node* LeftRightRotate(Node * upperPlace, Node* place);
		void BalanceAdding(Node* place);
		void BalanceRemoving(Node* place);
	public:
		AVL();
		void Add(unsigned int num, unsigned int index);
		unsigned int GetMax();
		unsigned int GetMin();
		unsigned int PopMax();
		unsigned int PopMin();
		~AVL();
};