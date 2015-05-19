#include "stdafx.h"
#include "Circle.h"
#include <cmath>


CCircle::CCircle()
{
}

//Բʵ��ʹ�õĹ��캯��
CCircle::CCircle(const CPoint& start, const CPoint& end, COLORREF color) :CElement(start, color)
{
	//ʹ�ø���ֵ����뾶��Ϊ����sqrt()������Ҫ��(��cmath��)
	long radius = static_cast<long>(sqrt(static_cast<double>((end.x - start.x)*(end.x - start.x) + (end.y - start.y)*(end.y - start.y))));

	if (radius < 1L)radius = 1L;//Բ�İ뾶������ڵ���1

	//ΪMM_TEXTģʽ����left-top��right-bottom��
	m_StartPoint = CPoint(start.x - radius, start.y - radius);
	m_BottomRight = CPoint(start.x + radius, start.y + radius);

	//���廷�ƾ���
	m_EnclosingRect = CRect(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);
}

CCircle::~CCircle()
{
}

//��Բ�ĺ���
void CCircle::Draw(CDC* pDC)
{
	//��������ʼ���ֱʶ���
	CPen aPen;
	CreatePen(aPen);

	CPen* pOldPen = pDC->SelectObject(&aPen);//ѡ�иֱ�

	//ѡ�пջ�ˢ
	CBrush* pOldBrush = dynamic_cast<CBrush*>(pDC->SelectStockObject(NULL_BRUSH));

	//��Բ
	pDC->Ellipse(m_StartPoint.x, m_StartPoint.y, m_BottomRight.x, m_BottomRight.y);

	//��ԭ�ֱʺͻ�ˢ
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}