#include "stdafx.h"
#include "Rectangle.h"
#include<algorithm>

CRectangle::CRectangle()
{
}
CRectangle::CRectangle(const CPoint& start, const CPoint& end, COLORREF color) :CElement(start, color)
{
	//���ε�Ķ���
	m_StartPoint = CPoint((std::min)(start.x, end.x), (std::min)(start.y, end.y));
	m_BottomRight = CPoint((std::max)(start.x, end.x), (std::max)(start.y, end.y));

	//ȷ�����θ���֮��ľ���������2
	if ((m_BottomRight.x - m_StartPoint.x) < 2)
		m_BottomRight.x += 2;
	if ((m_BottomRight.y - m_StartPoint.y) < 2)
		m_BottomRight.y += 2;

	//�������
	m_EnclosingRect = CRect(m_StartPoint, m_BottomRight);
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);

}

CRectangle::~CRectangle()
{
}
//������
void CRectangle::Draw(CDC* pDC)
{
	//�����ֱ�
	CPen aPen;
	CreatePen(aPen);

	//ѡ�иøֱʺͿջ�ˢ
	CPen* pOldPen = pDC->SelectObject(&aPen);
	CBrush*pOldBrush = dynamic_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH));
	
	//������
	pDC->Rectangle(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);

	//��ԭ�ɸֱʺͻ�ˢ
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
}