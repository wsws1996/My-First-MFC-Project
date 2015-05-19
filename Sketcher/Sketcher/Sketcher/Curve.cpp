#include "stdafx.h"
#include "Curve.h"
#include <algorithm>

CCurve::CCurve()
{
}
//������ʵ��Ӧ�õĹ��캯��
CCurve::CCurve(const CPoint& first, const CPoint& second, COLORREF color) :CElement(first, color)
{
	//��vector�д洢�ڶ�����
	m_Points.push_back(second);
	m_EnclosingRect = CRect((std::min)(first.x, second.x), (std::min)(first.y, second.y), (std::max)(first.x, second.x), (std::max)(first.y, second.y));
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);
}


CCurve::~CCurve()
{
}

//��������
void CCurve::Draw(CDC* pDC)
{
	//��������ʼ���ֱʶ���
	CPen aPen;
	CreatePen(aPen);

	CPen* pOldPen = pDC->SelectObject(&aPen);//ѡ�иֱ�

	//������
	pDC->MoveTo(m_StartPoint);
	for (auto&point : m_Points)
		pDC->LineTo(point);

	pDC->SelectObject(pOldPen);//��ԭ�ɸֱ�
}

//���������������
void CCurve::AddSegment(const CPoint& point)
{
	m_Points.push_back(point);//������ӵ�����ĩβ

	//Ϊ�µ��޸İ�Χ����
	m_EnclosingRect.DeflateRect(m_PenWidth, m_PenWidth);
	m_EnclosingRect = CRect((std::min)(point.x, m_EnclosingRect.left), (std::min)(point.y, m_EnclosingRect.top), (std::max)(point.x, m_EnclosingRect.right), (std::max)(point.y, m_EnclosingRect.bottom));
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);
}