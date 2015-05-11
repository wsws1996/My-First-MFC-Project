#include "stdafx.h"
#include "Line.h"


CLine::CLine()
{
}
CLine::CLine(const CPoint & start, const CPoint &end, COLORREF color):CElement(start,color),m_EndPoint(end)
{
	//定义封闭矩形
	m_EnclosingRect = CRect(start, end);
	m_EnclosingRect.NormalizeRect();
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);

}


CLine::~CLine()
{
}
//画直线
void CLine::Draw(CDC* pDC)
{
	//为该元素创建钢笔并初始化
	CPen aPen;
	CreatePen(aPen);

	CPen* pOldPen = pDC->SelectObject(&aPen);//选中该钢笔

	//画线
	pDC->MoveTo(m_StartPoint);
	pDC->LineTo(m_EndPoint);

	pDC->SelectObject(pOldPen);//还原旧钢笔
}
