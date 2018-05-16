#include "Node.h"

Node::Node(unsigned int value, unsigned int index) {
	this->Parent = nullptr;
	this->LeftChild = nullptr;
	this->RightChild = nullptr;
	this->Balance = 0;
	this->Value = value;
	this->Indexes.Add(index);
}

Node::Node(const Node & right) : Balance(right.Balance), Value(right.Value) {
	this->Indexes = right.Indexes;
	this->Parent = right.Parent;
	this->RightChild = right.RightChild;
	this->LeftChild = right.LeftChild;
}

Node & Node::operator=(const Node & right) {
	this->Balance = right.Balance;
	this->Value = right.Value;
	this->Indexes = right.Indexes;
	delete this->Parent;
	this->Parent = right.Parent;
	delete this->RightChild;
	this->RightChild = right.RightChild;
	delete this->LeftChild;
	this->LeftChild = right.LeftChild;
	return *this;
}

bool Node::operator>(const Node & right) {
	return (this->Value > right.Value);
}

bool Node::operator==(const Node & right)
{
	return (this->Value == right.Value);
}

bool Node::operator<(const Node & right) {
	return (this->Value < right.Value);
}

void Node::SetParent(Node * parent) {
	this->Parent = parent;
}

void Node::SetLeftChild(Node * leftchild) {
	this->LeftChild = leftchild;
}

void Node::SetRightChild(Node * rightchild) {
	this->RightChild = rightchild;
}

void Node::SetBalance(int balance) {
	this->Balance = balance;
}

void Node::AddIndex(unsigned int index) {
	this->Indexes.Add(&QNode(index));
}

Node * Node::GetParent() {
	return this->Parent;
}

Node * Node::GetLeftChild() {
	return this->LeftChild;
}

Node * Node::GetRightChild() {
	return this->RightChild;
}

unsigned int Node::Pop() {
	return this->Indexes.Pop();
}

int Node::GetBalance() {
	return this->Balance;
}

unsigned int Node::GetSize() {
	return this->Indexes.GetSize();
}

unsigned int Node::GetValue() {
	return this->Value;
}

Node::~Node() {

}
