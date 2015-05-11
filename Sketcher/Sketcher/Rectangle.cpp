#include "stdafx.h"
#include "Rectangle.h"
#include<algorithm>

CRectangle::CRectangle()
{
}
CRectangle::CRectangle(const CPoint& start, const CPoint& end, COLORREF color) :CElement(start, color)
{
	//矩形点的定义
	m_StartPoint = CPoint((std::min)(start.x, end.x), (std::min)(start.y, end.y));
	m_BottomRight = CPoint((std::max)(start.x, end.x), (std::max)(start.y, end.y));

	//确保矩形各点之间的距离至少是2
	if ((m_BottomRight.x - m_StartPoint.x) < 2)
		m_BottomRight.x += 2;
	if ((m_BottomRight.y - m_StartPoint.y) < 2)
		m_BottomRight.y += 2;

	//定义矩形
	m_EnclosingRect = CRect(m_StartPoint, m_BottomRight);
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);

}

CRectangle::~CRectangle()
{
}
//画矩形
void CRectangle::Draw(CDC* pDC)
{
	//创建钢笔
	CPen aPen;
	CreatePen(aPen);

	//选中该钢笔和空画刷
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush*pOldBrush = dynamic_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH));
	
	//画矩形
	pDC->Rectangle(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);

	//还原旧钢笔和画刷
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}