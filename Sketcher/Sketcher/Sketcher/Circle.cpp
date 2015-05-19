#include "stdafx.h"
#include "Circle.h"
#include <cmath>


CCircle::CCircle()
{
}

//圆实际使用的构造函数
CCircle::CCircle(const CPoint& start, const CPoint& end, COLORREF color) :CElement(start, color)
{
	//使用浮点值计算半径因为这是sqrt()函数的要求(在cmath中)
	long radius = static_cast<long>(sqrt(static_cast<double>((end.x - start.x)*(end.x - start.x) + (end.y - start.y)*(end.y - start.y))));

	if (radius < 1L)radius = 1L;//圆的半径必须大于等于1

	//为MM_TEXT模式定义left-top和right-bottom点
	m_StartPoint = CPoint(start.x - radius, start.y - radius);
	m_BottomRight = CPoint(start.x + radius, start.y + radius);

	//定义环绕矩形
	m_EnclosingRect = CRect(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);
}

CCircle::~CCircle()
{
}

//画圆的函数
void CCircle::Draw(CDC* pDC)
{
	//创建并初始化钢笔对象
	CPen aPen;
	CreatePen(aPen);

	CPen* pOldPen = pDC->SelectObject(&aPen);//选中钢笔

	//选中空画刷
	CBrush* pOldBrush = dynamic_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH));

	//画圆
	pDC->Ellipse(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);

	//还原钢笔和画刷
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}