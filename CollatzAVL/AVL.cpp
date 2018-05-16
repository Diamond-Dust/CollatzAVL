#pragma once
#include "AVL.h"


Node* AVL::LeftRotate(Node * upperPlace, Node* place) {
	Node* swapper = place->LeftChild;
	upperPlace->RightChild = swapper;
	if(swapper != nullptr)
		swapper->Parent = upperPlace;
	place->LeftChild = upperPlace;
	place->Parent = upperPlace->Parent;
	upperPlace->Parent = place;
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
	Node* swapper = place->RightChild;
	upperPlace->LeftChild = swapper;
	if (swapper != nullptr)
		swapper->Parent = upperPlace;
	place->RightChild = upperPlace;
	place->Parent = upperPlace->Parent;
	upperPlace->Parent = place;
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
	Node* lowerPlace = place->LeftChild;
	Node* rightLowerPlace = lowerPlace->RightChild;
	place->LeftChild = rightLowerPlace;
	if (rightLowerPlace != nullptr)
		rightLowerPlace->Parent = place;
	lowerPlace->RightChild = place;
	place->Parent = lowerPlace;
	Node* leftLowerPlace = lowerPlace->LeftChild;
	upperPlace->RightChild = leftLowerPlace;
	if (leftLowerPlace != nullptr)
		leftLowerPlace->Parent = upperPlace;
	lowerPlace->LeftChild = upperPlace;
	lowerPlace->Parent = upperPlace->Parent;
	if (lowerPlace->Parent == nullptr)
		ROOT = lowerPlace;
	upperPlace->Parent = lowerPlace;

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
	Node* lowerPlace = place->RightChild;
	Node* leftLowerPlace = lowerPlace->LeftChild;
	place->RightChild = leftLowerPlace;
	if (leftLowerPlace != nullptr)
		leftLowerPlace->Parent = place;
	lowerPlace->LeftChild = place;
	place->Parent = lowerPlace;
	Node* rightLowerPlace = lowerPlace->RightChild;
	upperPlace->LeftChild = rightLowerPlace;
	if (rightLowerPlace != nullptr)
		rightLowerPlace->Parent = upperPlace;
	lowerPlace->RightChild = upperPlace;
	lowerPlace->Parent = upperPlace->Parent;
	if (lowerPlace->Parent == nullptr)
		ROOT = lowerPlace;
	upperPlace->Parent = lowerPlace;

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
	for (Node* currentParent = currentNode->Parent; currentParent != nullptr; currentParent = currentNode->Parent)
	{
		if (currentNode == currentParent->RightChild)
		{
			if (currentParent->GetBalance() > 0)
			{
				grandParent = currentParent->Parent;
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
				grandParent = currentParent->Parent;
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

		changedNode->Parent = grandParent;
		if (grandParent != nullptr)
		{
			if (currentParent == grandParent->LeftChild)
				grandParent->LeftChild = changedNode;
			else
				grandParent->RightChild = changedNode;
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
	for (Node* currentParent = place->Parent; currentParent != nullptr; currentParent = grandParent)
	{
		grandParent = currentParent->Parent;
		if (place == currentParent->LeftChild)
		{
			if (currentParent->GetBalance() > 0)
			{
				sibling = currentParent->RightChild;
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
				sibling = currentParent->LeftChild;
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

		place->Parent = grandParent;
		if (grandParent != nullptr)
		{
			if (currentParent == grandParent->LeftChild)
				grandParent->LeftChild = place;
			else
				grandParent->RightChild = place;
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
				if (currentNode->RightChild != nullptr)
					currentNode = currentNode->RightChild;
				else
				{
					addedNode->Parent = currentNode;
					currentNode->RightChild = addedNode;
					this->BalanceAdding(addedNode);
					break;
				}
			}
			else if (*currentNode > *addedNode)
			{
				if (currentNode->LeftChild != nullptr)
					currentNode = currentNode->LeftChild;
				else
				{
					currentNode->LeftChild = addedNode;
					addedNode->Parent = currentNode;
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

bool AVL::Is() {
	return (ROOT == nullptr) ? false : true;
}

unsigned int AVL::GetMax() {
	Node* currentNode = ROOT;
	if (currentNode == nullptr)
		return 0;
	else
	{
		while (currentNode->RightChild != nullptr)
			currentNode = currentNode->RightChild;
		return currentNode->GetValue();
	}
}

unsigned int AVL::GetMin() {
	Node* currentNode = ROOT;
	if (currentNode == nullptr)
		return 0;
	else
	{
		while (currentNode->LeftChild != nullptr)
			currentNode = currentNode->LeftChild;
		return currentNode->GetValue();
	}
}

unsigned int AVL::PopMax() {
	Node* currentNode = ROOT;
	Node* leftChildNode;
	unsigned int index;
	while (currentNode->RightChild != nullptr)
		currentNode = currentNode->RightChild;
	if (currentNode->GetSize() < 2)
	{
		this->BalanceRemoving(currentNode);
		leftChildNode = currentNode->LeftChild;
		if (currentNode == ROOT)
		{
			ROOT = leftChildNode;
			if (leftChildNode != nullptr)
				leftChildNode->Parent = nullptr;
		}
		else
		{
			if (leftChildNode != nullptr)
				leftChildNode->Parent = currentNode->Parent;
			currentNode->Parent->RightChild = leftChildNode;
		}
		index = currentNode->Pop();
		delete currentNode;
	}
	else
		index = currentNode->Pop();
	return index;
}

unsigned int AVL::PopMin() {
	Node* currentNode = ROOT;
	Node* rightChildNode;
	unsigned int index;
	while (currentNode->LeftChild != nullptr)
		currentNode = currentNode->LeftChild;
	if (currentNode->GetSize() < 2)
	{
		this->BalanceRemoving(currentNode);
		rightChildNode = currentNode->RightChild;
		if (currentNode == ROOT)
		{
			ROOT = rightChildNode;
			if (rightChildNode != nullptr)
				rightChildNode->Parent = nullptr;
		}
		else
		{
			if (rightChildNode != nullptr)
				rightChildNode->Parent = currentNode->Parent;
			currentNode->Parent->LeftChild = rightChildNode;
		}
		index = currentNode->Pop();
		delete currentNode;
	}
	else
		index = currentNode->Pop();
	return index;
}

AVL::~AVL() {
}
