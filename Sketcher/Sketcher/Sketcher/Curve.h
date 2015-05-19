#pragma once
#include "Element.h"
#include<vector>
class CCurve :
	public CElement
{
public:
	virtual ~CCurve();
	virtual void Draw(CDC* pDC) override;//�����ߵĺ���

	//������Ĺ��캯��
	CCurve(const CPoint& first, const CPoint& second, COLORREF color);

	void AddSegment(const CPoint& point);//�����߽�������

protected:
	std::vector<CPoint> m_Points; //�������ߵĵ�
	CCurve();//Ĭ�Ϲ��캯��-��Ӧ�ñ�ʹ��
};

