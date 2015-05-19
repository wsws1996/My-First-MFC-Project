#pragma once
#include "Element.h"
class CRectangle :
	public CElement
{
public:
	virtual ~CRectangle();
	virtual void Draw(CDC* pDC) override;//画矩形的函数

	//矩形类的构造函数
	CRectangle(const CPoint& start, const CPoint& end, COLORREF color);

protected:
	CRectangle();//默认构造函数-不应该被使用
	CPoint m_BottomRight;
};

