#include "QNode.h"

QNode::QNode(unsigned int index) {
	this->Index = index;
	this->next = nullptr;
}

QNode::QNode(const QNode & right) : Index(right.Index) {
	this->next = right.next;
}

QNode & QNode::operator=(const QNode & right) {
	this->Index = right.Index;
	delete this->next;
	this->next = right.next;
	return *this;
}

bool QNode::operator>(const QNode & right) {
	return (this->Index > right.Index);
}

bool QNode::operator<(const QNode & right) {
	return (this->Index < right.Index);
}

unsigned int QNode::GetIndex() {
	return this->Index;
}

QNode::~QNode() {
	delete this->next;
}
