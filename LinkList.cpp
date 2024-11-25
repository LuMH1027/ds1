#include "LinkList.h"
template <typename T>
LinkList<T>::LinkList(const LinkList<T>& list)
{

}

template <typename T>
void LinkList<T>::Clear()
{

}

template <typename T>
int LinkList<T>::GetLength() const
{
	return length;
}

template <typename T>
bool LinkList<T>::IsEmpty() const
{
	return nullptr == head;
}

template <typename T>
Status LinkList<T>::GetNode(int i, T& t)
{
	if (i<1 || i>length)
		return Status::Failed;
	Node<T>* p = head->next;
	for (int j = 1; j < i; j++)
	{
		p = p->next;
	}
	t = p->data;
	return Status::Succeed;
}

template <typename T>
Status LinkList<T>::Insert(int i, const T& t)
{
	if (i<1 || i>length)
		return Status::Failed;
	Node<T>* p = head->next,q;
	for (int j = 1; j < i-1; j++)
		p = p->next;
	q = new Node<T>(t, p->next);
	p->next = q;
	length++;
	return Status::Succeed;
}

template <typename T>
Status LinkList<T>::Append(const T& t)
{
	Node<T>* p = head->next;
	Node<T>* q = new Node<T>(t, nullptr);
	for (; p->next != nullptr; p = p->next);
	p->next = q;
	return Status::Succeed;
	
}

template <typename T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& list)
{
	if (this == &list)
		return *this;
	Clear();
	head = new Node<T>(T());
	length = list.length;
	Node<T>* src = list.head->next;							
	Node<T>* temp = nullptr;
	while (src)
	{
		temp = new Node<T>(src->data, head->next);
		head->next = temp;
		src = src->next;                   
	}
	return *this;

}