#pragma once

typedef struct Module {
	char value;
	Module* next;
	Module* prev;
}Node;

class DLL {
	private:
		int size;
		Module *head, *tail;

	public:
		DLL() {
			head = nullptr;
			tail = nullptr;
			size = 0;
		}

		int GetSize() {
			return size;
		}

		void AddFront(const char& newM) {
			Module* NewM = new Module;
			NewM->value = newM;
			if (size == 0)
				tail = NewM;
			else
			{
				head->next = NewM;
				NewM->prev = head;
			}
			head = NewM;
			size++;

		}

		void AddBack(const char& newM) {
			Module* NewM = new Module;
			NewM->value = newM;
			if (size == 0)
				head = NewM;
			else
			{
				tail->prev = NewM;
				NewM->next = tail;
			}
			tail = NewM;
			size++;
		}

		char PopFront() {
			if (size == 0)
				return 0;
			char popped = head->value;
			if (size > 1)
			{
				head = head->prev;
				delete head->next;
			}
			else
			{
				head = nullptr;
				tail = nullptr;
			}
			size--;
			return popped;
		}

		char PopBack() {
			if (size == 0)
				return 0;
			char popped = tail->value;
			if (size > 1)
			{
				tail = tail->next;
				delete tail->prev;
			}
			else
			{
				tail = nullptr;
				head = nullptr;
			}
			size--;
			return popped;
		}

		void Dissolve() {
			char popped = this->PopFront();
			if (popped == 0)
				putchar('#');
			while (popped)
			{
				putchar(popped);
				popped = this->PopFront();
			}
		}

		~DLL() {
			delete head;
			delete tail;
		}
};