#pragma once
#include "Element.h"
class CCircle :
	public CElement
{
public:
	virtual ~CCircle();
	virtual void Draw(CDC* pDC)override;//��Բ�ĺ���

	//Բ�Ĺ��캯��
	CCircle(const CPoint& start, const CPoint& end, COLORREF color);

protected:
	CPoint m_BottomRight;//����������ε��ҵ׵�
	CCircle();//Ĭ�Ϲ��캯��-��Ӧ�ñ�ʹ��
};

