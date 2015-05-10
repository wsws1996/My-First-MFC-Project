#pragma once

// CElement ����Ŀ��

class CElement : public CObject
{
protected:
	CPoint m_StartPoint;//��ʼλ��
	int m_PenWidth;//�������
	COLORREF m_Color;//������ɫ
	CRect m_EnclosingRect;//��ΧԪ�صľ���
public:
	virtual ~CElement();
	virtual void Draw(CDC* pDC){}
	const CRect& GetEnclosingRect()const{ return m_EnclosingRect; }
protected:
	CElement();
	CElement(const CPoint& start, COLORREF color, int penWidth = 1);
};


