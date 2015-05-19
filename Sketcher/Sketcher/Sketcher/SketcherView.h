
// SketcherView.h : CSketcherView ��Ľӿ�
//

#pragma once
#include "atltypes.h"
#include<memory>
#include"Element.h"


class CSketcherView : public CView
{
protected: // �������л�����
	CSketcherView();
	DECLARE_DYNCREATE(CSketcherView)

// ����
public:
	CSketcherDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CSketcherView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
protected:
	CPoint m_FirstPoint;
	CPoint m_SecondPoint;
	std::shared_ptr<CElement> m_pTempElement;
	CElement* CreateElement(void)const;	//
};

#ifndef _DEBUG  // SketcherView.cpp �еĵ��԰汾
inline CSketcherDoc* CSketcherView::GetDocument() const
   { return reinterpret_cast<CSketcherDoc*>(m_pDocument); }
#endif

