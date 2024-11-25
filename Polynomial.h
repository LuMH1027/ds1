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
	int Length() const;												//��ȡ����ʽ����
	void Show() const;												//��ӡ����ʽ����Ļ
	void Insert(const PolyItem& item);								//����һ�����ͬ������ϲ�
	Polynomial Differentiate(const Polynomial& poly);						//�Զ���ʽ��
	bool IsEqual(const Polynomial& poly) const;						// �ж���������ʽ�Ƿ����
	Polynomial operator +(const Polynomial& poly) const;			//�ӷ����������
	Polynomial operator -(const Polynomial& poly) const;			//�������������
	Polynomial operator *(const Polynomial& poly) const;			//�˷����������
	Polynomial operator =(const Polynomial& poly) const;			//��ֵ�������

};

Polynomial Polynomial::Differentiate(const Polynomial& poly) {

}