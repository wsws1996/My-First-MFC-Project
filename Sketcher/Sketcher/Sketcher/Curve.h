#pragma once
#include "Element.h"
#include<vector>
class CCurve :
	public CElement
{
public:
	virtual ~CCurve();
	virtual void Draw(CDC* pDC) override;//画曲线的函数

	//曲线类的构造函数
	CCurve(const CPoint& first, const CPoint& second, COLORREF color);

	void AddSegment(const CPoint& point);//对曲线进行延伸

protected:
	std::vector<CPoint> m_Points; //定义曲线的点
	CCurve();//默认构造函数-不应该被使用
};

