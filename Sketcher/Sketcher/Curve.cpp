#include "stdafx.h"
#include "Curve.h"
#include <algorithm>

CCurve::CCurve()
{
}
//曲线类实际应用的构造函数
CCurve::CCurve(const CPoint& first, const CPoint& second, COLORREF color) :CElement(first, color)
{
	//在vector中存储第二个点
	m_Points.push_back(second);
	m_EnclosingRect = CRect((std::min)(first.x, second.x), (std::min)(first.y, second.y), (std::max)(first.x, second.x), (std::max)(first.y, second.y));
	m_EnclosingRect.InflateRect(m_PenWidth, m_PenWidth);
}


CCurve::~CCurve()
{
}

//绘制曲线
void CCurve::Draw(CDC* pDC)
{
	//创建并初始化钢笔对象
	CPen aPen;
	CreatePen(aPen);

	CPen* pOldPen = pDC->SelectObject(&aPen);//选中钢笔

	//画曲线
	pDC->MoveTo(m_StartPoint);
	for (auto&point : m_Points)
		pDC->LineTo(point);

	pDC->SelectObject(pOldPen);//还原旧钢笔
}