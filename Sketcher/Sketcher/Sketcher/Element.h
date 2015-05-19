#pragma once

// CElement 命令目标

class CElement : public CObject
{
protected:
	CPoint m_StartPoint;//开始位置
	int m_PenWidth;//线条宽度
	COLORREF m_Color;//线条颜色
	CRect m_EnclosingRect;//包围元素的矩形
public:
	virtual ~CElement();
	virtual void Draw(CDC* pDC){}
	const CRect& GetEnclosingRect()const{ return m_EnclosingRect; }
protected:
	CElement();
	CElement(const CPoint& start, COLORREF color, int penWidth = 1);
	//创建钢笔
	void CreatePen(CPen& aPen)
	{
		if (!aPen.CreatePen(PS_SOLID, m_PenWidth, m_Color))
		{
			//钢笔创建失败
			AfxMessageBox(_T("钢笔创建失败"), MB_OK);
			AfxAbort();
		}
	}
};


