// Element.cpp : 实现文件
//

#include "stdafx.h"
#include "Sketcher.h"
#include "Element.h"


// CElement

CElement::CElement()
{
}
CElement::CElement(const CPoint&start, COLORREF color, int penWidth) :m_StartPoint(start), m_PenWidth(penWidth), m_Color(color){}

CElement::~CElement()
{
}


// CElement 成员函数
