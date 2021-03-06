
// SketcherView.cpp : CSketcherView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"
#include "SketcherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CView)

BEGIN_MESSAGE_MAP(CSketcherView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSketcherView 构造/析构

CSketcherView::CSketcherView() :m_FirstPoint(CPoint(0,0))
, m_SecondPoint(CPoint(0,0))
{
	// TODO:  在此处添加构造代码

}

CSketcherView::~CSketcherView()
{
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CSketcherView 绘制

void CSketcherView::OnDraw(CDC* pDC)
{
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码

}


// CSketcherView 打印

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CSketcherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CSketcherView 诊断

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG


// CSketcherView 消息处理程序


void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonUp(nFlags, point);
}


void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (nFlags&MK_LBUTTON)
	{
		m_SecondPoint = point;
	}

	//CView::OnMouseMove(nFlags, point);
}


void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_FirstPoint = point;//记录初始点

	//CView::OnLButtonDown(nFlags, point);
}
