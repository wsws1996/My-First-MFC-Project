#pragma once
#include "Element.h"
class CCircle :
	public CElement
{
public:
	virtual ~CCircle();
	virtual void Draw(CDC* pDC)override;//画圆的函数

	//圆的构造函数
	CCircle(const CPoint& start, const CPoint& end, COLORREF color);

protected:
	CPoint m_BottomRight;//用来定义矩形的右底点
	CCircle();//默认构造函数-不应该被使用
};

