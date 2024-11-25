#pragma once
#include <iostream>
#include "LinkList.h"
class Polynomial
{
private:
	LinkList<PolyItem> TermList;
public:
	Polynomial();
	Polynomial(const LinkList<PolyItem>& TermList);
	Polynomial(const Polynomial& poly);
	~Polynomial();
	int Length() const;												//获取多项式项数
	void Show() const;												//打印多项式至屏幕
	void Insert(const PolyItem& item);								//插入一项，若有同类项则合并
	Polynomial Differentiate(const Polynomial& poly);						//对多项式求导
	bool IsEqual(const Polynomial& poly) const;						// 判断两个多项式是否相等
	Polynomial operator +(const Polynomial& poly) const;			//加法运算符重载
	Polynomial operator -(const Polynomial& poly) const;			//减法运算符重载
	Polynomial operator *(const Polynomial& poly) const;			//乘法运算符重载
	Polynomial operator =(const Polynomial& poly) const;			//赋值语句重载

};

Polynomial Polynomial::Differentiate(const Polynomial& poly) {

}