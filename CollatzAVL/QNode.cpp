#include "QNode.h"

QNode::QNode(unsigned int index) {
	this->Index = index;
	this->next = nullptr;
}

QNode::QNode(const QNode & right) : Index(right.Index) {
	if (right.next != nullptr)
		this->next = right.next;
	else
		this->next = nullptr;
}

QNode & QNode::operator=(const QNode & right) {
	this->Index = right.Index;
	delete this->next;
	if (right.next != nullptr)
		this->next = right.next;
	else
		this->next = nullptr;
	return *this;
}

bool QNode::operator>(const QNode & right) {
	if (this->Index > right.Index)
		return true;
	else
		return false;
}

bool QNode::operator<(const QNode & right) {
	if (this->Index < right.Index)
		return true;
	else
		return false;
}

unsigned int QNode::GetIndex() {
	return this->Index;
}

QNode::~QNode() {
	if (this->next != nullptr)
		delete this->next;
}
