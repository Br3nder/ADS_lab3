#include "list.h"
#include "element.h"

ostream& operator << (ostream& stream, const List* list)
{
	Element* element = list->firstElement;
	while (element != NULL)
	{
		stream << "id: " << element->getId() << "\nName: " << element->getName() << endl;
		element = element->getNext();
	}
	return stream;
};

void List::pushBack(int idOfMan, string nameOfMan)
{
	if (this->getSize() != 0)
	{
		Element* cur = this->getElement();
		while (cur->getNext() != NULL)
			cur = cur->getNext();
		cur->setNext(new Element(idOfMan, nameOfMan, nullptr));
	}
	else
		this->setElement(new Element(idOfMan, nameOfMan));
}

void List::pushFront(int idOfMan, string nameOfMan)
{
	if (this->getSize() != 0)
	{
		Element* tmp = this->getElement(), * newElement = new Element(idOfMan, nameOfMan, nullptr);
		this->setElement(newElement);
		newElement->setNext(tmp);
	}
	else
		this->setElement(new Element(idOfMan, nameOfMan));
}

void List::popBack()
{
	if (this->getSize() > 1)
	{
		Element* cur = this->getElement(), * prev = NULL;
		while (cur->getNext() != NULL)
		{
			prev = cur;
			cur = cur->getNext();
		}
		delete cur;
		prev->setNext(NULL);
	}
}

void List::popFront()
{
	Element* cur = this->getElement();
	this->setElement(cur->getNext());
	delete cur;
}

void List::insert(int idOfMan, string nameOfMan, int position)
{
	Element* newMan = new Element(idOfMan, nameOfMan, nullptr);
	if (position == 1) pushFront(newMan->getId(), newMan->getName());
	else
	{
		Element* cur = this->getElement();
		for (int i = 0; i < position - 1; i++)
			cur = cur->getNext();
		newMan->setNext(cur->getNext());
		cur->setNext(newMan);
	}

}

void List::insert(List* list, int position)
{
	Element* first = list->getElement(), * last;
	while (first->getNext() != NULL)
		first = first->getNext();
	last = first;
	first = list->getElement();
	Element* cur = this->getElement();
	for (int i = 0; i < position - 1; i++)
		cur = cur->getNext();
	last->setNext(cur->getNext());
	cur->setNext(first);
}

Element* List::at(int position)
{
	Element* cur = this->getElement();
	for (int i = 1; i < position; i++)
		cur = cur->getNext();
	return cur;
}

void List::remove(int position)
{
	if (position == 1) popFront();
	else
	{
		Element* cur = this->getElement();
		for (int i = 0; i < position - 2; i++) //get prev element. next element will deleted
			cur = cur->getNext();
		Element* tmp = cur->getNext();
		cur->setNext(tmp->getNext());
		delete tmp;
	}
}

int List::getSize()
{
	Element* cur = this->getElement();
	int len = 1;
	while (cur->getNext() != NULL)
	{
		cur = cur->getNext();
		len++;
	}
	return len;
}

void List::clear()
{
	Element* cur = this->getElement(), *next = cur->getNext();
	this->setElement(NULL);
	while (cur != NULL && next != NULL)
	{
		delete cur;
		cur = next;
		next = next->getNext();
	}
	delete cur;
}

void List::set(int idOfMan, string nameOfMan, int position)
{
	if (position == 1)
	{
		popFront();
		pushFront(idOfMan, nameOfMan);
	}
	else
	{
		Element* cur = this->getElement(), *tmp, *newMan = new Element(idOfMan, nameOfMan);
		for (int i = 0; i < position-1; i++)
			cur = cur->getNext();
		newMan->setNext(cur->getNext()->getNext());
		tmp = cur->getNext();
		cur->setNext(newMan);
		delete tmp;
	}

}

bool List::isEmpty()
{
	if (this->getElement()) return false;
	return true;
}

Element::~Element()
{
	delete this;
}

//void showAllList(Element* e1)
//{
//	Element* e2 = e1;
//	while (e2 != nullptr)
//	{
//		cout << e2;
//		e2 = e2->getNext();
//	}
//}
