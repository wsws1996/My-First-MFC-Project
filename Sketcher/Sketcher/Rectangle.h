#pragma once
#include "Element.h"
class CRectangle :
	public CElement
{
public:
	virtual ~CRectangle();
	virtual void Draw(CDC* pDC) override;//�����εĺ���

	//������Ĺ��캯��
	CRectangle(const CPoint& start, const CPoint& end, COLORREF color);

protected:
	CRectangle();//Ĭ�Ϲ��캯��-��Ӧ�ñ�ʹ��
	CPoint m_BottomRight;
};

