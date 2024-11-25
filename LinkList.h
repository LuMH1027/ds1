#pragma once
#include <iostream>

struct PolyItem
{
	double coef;
	int exp;
	PolyItem(double c=0, int e=0) :coef(c), exp(e) {};
	bool operator==(const PolyItem& other) const 
	{
		return exp == other.exp && coef == other.coef;
	}
	bool operator<(const PolyItem& other) const 
	{
		return exp < other.exp;
	}
	bool operator>(const PolyItem& other) const
	{
		return exp > other.exp;
	}
};

template <typename T> struct Node
{
	T data;
	Node<T>* next;
	Node(T d, Node<T>* n = nullptr) :data(d), next(n) {};
};

enum class Status
{
	Succeed,
	Failed,
};

template<typename T> class LinkList
{
private:
	Node<T>* head;
	int length;
public:
	LinkList() :head(nullptr), length(0) {};
	LinkList(const LinkList<T>& list);
	~LinkList() { Clear(); };
	void Clear();
	int GetLength() const;
	bool IsEmpty() const;
	Status GetNode(int i, T& t);								//取出第i个结点并将其赋值给t
	Status Insert(int i, const T& t);							//在第i个结点插入
	Status Append(const T& t);									//在表尾插入结点
	LinkList<T>& operator=(const LinkList<T>& list);			//重载赋值运算符
};

