#pragma once
#include "AVL.h"


Node* AVL::LeftRotate(Node * upperPlace, Node* place) {
	Node* swapper = place->GetLeftChild();
	upperPlace->SetRightChild(swapper);
	if(swapper != nullptr)
		swapper->SetParent(upperPlace);
	place->SetLeftChild(upperPlace);
	place->SetParent(upperPlace->GetParent());
	upperPlace->SetParent(place);
	if (place->GetBalance() == 0)
	{
		upperPlace->SetBalance(1);
		place->SetBalance(-1);
	}
	else
	{
		upperPlace->SetBalance(0);
		place->SetBalance(0);
	}
	return place;
}

Node* AVL::RightRotate(Node * upperPlace, Node* place) {
	Node* swapper = place->GetRightChild();
	upperPlace->SetLeftChild(swapper);
	if (swapper != nullptr)
		swapper->SetParent(upperPlace);
	place->SetRightChild(upperPlace);
	place->SetParent(upperPlace->GetParent());
	upperPlace->SetParent(place);
	if (place->GetBalance() == 0)
	{
		upperPlace->SetBalance(-1);
		place->SetBalance(1);
	}
	else
	{
		upperPlace->SetBalance(0);
		place->SetBalance(0);
	}
	return place;
}

Node * AVL::RightLeftRotate(Node * upperPlace, Node * place) {
	Node* lowerPlace = place->GetLeftChild();
	Node* rightLowerPlace = lowerPlace->GetRightChild();
	place->SetLeftChild(rightLowerPlace);
	if (rightLowerPlace != nullptr)
		rightLowerPlace->SetParent(place);
	lowerPlace->SetRightChild(place);
	place->SetParent(lowerPlace);
	Node* leftLowerPlace = lowerPlace->GetLeftChild();
	upperPlace->SetRightChild(leftLowerPlace);
	if (leftLowerPlace != nullptr)
		leftLowerPlace->SetParent(upperPlace);
	lowerPlace->SetLeftChild(upperPlace);
	lowerPlace->SetParent(upperPlace->GetParent());
	if (lowerPlace->GetParent() == nullptr)
		ROOT = lowerPlace;
	upperPlace->SetParent(lowerPlace);

	if (lowerPlace->GetBalance() > 0) 
	{ 
		upperPlace->SetBalance(-1);  
		place->SetBalance(0);
	}
	else 
		if (lowerPlace->GetBalance() == 0) 
		{
			upperPlace->SetBalance(0);
			place->SetBalance(0);
		}
		else 
		{ 
			upperPlace->SetBalance(0);
			place->SetBalance(1);
		}
	lowerPlace->SetBalance(0);
	return lowerPlace;
}

Node * AVL::LeftRightRotate(Node * upperPlace, Node* place) {
	Node* lowerPlace = place->GetRightChild();
	Node* leftLowerPlace = lowerPlace->GetLeftChild();
	place->SetRightChild(leftLowerPlace);
	if (leftLowerPlace != nullptr)
		leftLowerPlace->SetParent(place);
	lowerPlace->SetLeftChild(place);
	place->SetParent(lowerPlace);
	Node* rightLowerPlace = lowerPlace->GetRightChild();
	upperPlace->SetLeftChild(rightLowerPlace);
	if (rightLowerPlace != nullptr)
		rightLowerPlace->SetParent(upperPlace);
	lowerPlace->SetRightChild(upperPlace);
	lowerPlace->SetParent(upperPlace->GetParent());
	if (lowerPlace->GetParent() == nullptr)
		ROOT = lowerPlace;
	upperPlace->SetParent(lowerPlace);

	if (lowerPlace->GetBalance() > 0)
	{
		upperPlace->SetBalance(0);
		place->SetBalance(-1);
	}
	else
		if (lowerPlace->GetBalance() == 0)
		{
			upperPlace->SetBalance(0);
			place->SetBalance(0);
		}
		else
		{
			upperPlace->SetBalance(1);
			place->SetBalance(0);
		}
	lowerPlace->SetBalance(0);
	return lowerPlace;
}

void AVL::BalanceAdding(Node* place) {
	Node* grandParent;
	Node* changedNode;
	Node* currentNode = place;
	for (Node* currentParent = currentNode->GetParent(); currentParent != nullptr; currentParent = currentNode->GetParent())
	{
		if (currentNode == currentParent->GetRightChild())
		{
			if (currentParent->GetBalance() > 0)
			{
				grandParent = currentParent->GetParent();
				if (currentNode->GetBalance() < 0)
				{
					changedNode = this->RightLeftRotate(currentParent, currentNode);
				}
				else
				{
					changedNode = this->LeftRotate(currentParent, currentNode);
				}
			}
			else
			{
				if (currentParent->GetBalance() < 0)
				{
					currentParent->SetBalance(0);
					break;
				}
				else
				{
					currentParent->SetBalance(1);
					currentNode = currentParent;
					continue;
				}
			}
		}
		else
		{
			if (currentParent->GetBalance() < 0)
			{
				grandParent = currentParent->GetParent();
				if (currentNode->GetBalance() > 0)
				{
					changedNode = this->LeftRightRotate(currentParent, currentNode);
				}
				else
				{
					changedNode = this->RightRotate(currentParent, currentNode);
				}
			}
			else
			{
				if (currentParent->GetBalance() > 0)
				{
					currentParent->SetBalance(0);
					break;
				}
				else
				{
					currentParent->SetBalance(-1);
					currentNode = currentParent;
					continue;
				}
			}
		}

		changedNode->SetParent(grandParent);
		if (grandParent != nullptr)
		{
			if (currentParent == grandParent->GetLeftChild())
				grandParent->SetLeftChild(changedNode);
			else
				grandParent->SetRightChild(changedNode);
			break;
		}
		else
		{
			ROOT = changedNode;
			break;
		}
	}
}

void AVL::BalanceRemoving(Node * place) {
	int currentBalance;
	Node* grandParent;
	Node* sibling;
	for (Node* currentParent = place->GetParent(); currentParent != nullptr; currentParent = grandParent)
	{
		grandParent = currentParent->GetParent();
		if (place == currentParent->GetLeftChild())
		{
			if (currentParent->GetBalance() > 0)
			{
				sibling = currentParent->GetRightChild();
				currentBalance = sibling->GetBalance();
				if (currentBalance < 0)
					place = RightLeftRotate(currentParent, sibling);
				else
					place = LeftRotate(currentParent, sibling);
			}
			else
			{
				if (currentParent->GetBalance() == 0)
				{
					currentParent->SetBalance(1);
					break;
				}
				else
				{
					place = currentParent;
					place->SetBalance(0);
					continue;
				}
			}
		}
		else
		{
			if (currentParent->GetBalance() < 0)
			{
				sibling = currentParent->GetLeftChild();
				currentBalance = sibling->GetBalance();
				if (currentBalance > 0)
					place = LeftRightRotate(currentParent, sibling);
				else
					place = RightRotate(currentParent, sibling);
			}
			else
			{
				if (currentParent->GetBalance() == 0) {
					currentParent->SetBalance(-1);
					break; 
				}
				else
				{
					place = currentParent;
					place->SetBalance(0);
					continue;
				}
			}
		}

		place->SetParent(grandParent);
		if (grandParent != nullptr)
		{
			if (currentParent == grandParent->GetLeftChild())
				grandParent->SetLeftChild(place);
			else
				grandParent->SetRightChild(place);
			if (currentBalance == 0)
				break;
		}
		else
		{
			ROOT = place;
		}
	}
}

AVL::AVL() {
	ROOT = nullptr;
}

void AVL::Add(unsigned int num, unsigned int index) {
	Node* addedNode = new Node(num, index);
	Node* currentNode = ROOT;
	if (currentNode == nullptr)
		ROOT = addedNode;
	else
	{
		while(true)
			if (*currentNode < *addedNode)
			{
				if (currentNode->GetRightChild() != nullptr)
					currentNode = currentNode->GetRightChild();
				else
				{
					addedNode->SetParent(currentNode);
					currentNode->SetRightChild(addedNode);
					this->BalanceAdding(addedNode);
					break;
				}
			}
			else if (*currentNode > *addedNode)
			{
				if (currentNode->GetLeftChild() != nullptr)
					currentNode = currentNode->GetLeftChild();
				else
				{
					currentNode->SetLeftChild(addedNode);
					addedNode->SetParent(currentNode);
					this->BalanceAdding(addedNode);
					break;
				}
			}
			else
			{
				currentNode->AddIndex(index);
				break;
			}
	}
}

unsigned int AVL::GetMax() {
	Node* currentNode = ROOT;
	if (currentNode == nullptr)
		return 0;
	else
	{
		while (currentNode->GetRightChild() != nullptr)
			currentNode = currentNode->GetRightChild();
		return currentNode->GetValue();
	}
}

unsigned int AVL::GetMin() {
	Node* currentNode = ROOT;
	if (currentNode == nullptr)
		return 0;
	else
	{
		while (currentNode->GetLeftChild() != nullptr)
			currentNode = currentNode->GetLeftChild();
		return currentNode->GetValue();
	}
}

unsigned int AVL::PopMax() {
	Node* currentNode = ROOT;
	Node* leftChildNode;
	unsigned int index;
	while (currentNode->GetRightChild() != nullptr)
		currentNode = currentNode->GetRightChild();
	if (currentNode->GetSize() < 2)
	{
		if (currentNode == ROOT)
			this->BalanceRemoving(currentNode);
		else
		{
			this->BalanceRemoving(currentNode);
			leftChildNode = currentNode->GetLeftChild();
			if (leftChildNode != nullptr)
				leftChildNode->SetParent(currentNode->GetParent());
			currentNode->GetParent()->SetRightChild(leftChildNode);
		}
		index = currentNode->Pop();
		//delete currentNode;
	}
	else
		index = currentNode->Pop();
	return index;
}

unsigned int AVL::PopMin() {
	Node* currentNode = ROOT;
	Node* rightChildNode;
	unsigned int index;
	while (currentNode->GetLeftChild() != nullptr)
		currentNode = currentNode->GetLeftChild();
	if (currentNode->GetSize() < 2)
	{
		if (currentNode == ROOT)
			this->BalanceRemoving(currentNode);
		else
		{
			this->BalanceRemoving(currentNode);
			rightChildNode = currentNode->GetRightChild();
			if(rightChildNode != nullptr)
				rightChildNode->SetParent(currentNode->GetParent());
			currentNode->GetParent()->SetLeftChild(rightChildNode);
		}
		index = currentNode->Pop();
		//delete currentNode;
	}
	else
		index = currentNode->Pop();
	return index;
}

AVL::~AVL() {
}
