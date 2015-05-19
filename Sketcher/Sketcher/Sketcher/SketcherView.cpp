
// SketcherView.cpp : CSketcherView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"
#include "SketcherView.h"
#include "Curve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CView)

BEGIN_MESSAGE_MAP(CSketcherView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSketcherView ����/����

CSketcherView::CSketcherView() :m_FirstPoint(CPoint(0,0))
, m_SecondPoint(CPoint(0,0))
{
	// TODO:  �ڴ˴���ӹ������

}

CSketcherView::~CSketcherView()
{
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSketcherView ����

void CSketcherView::OnDraw(CDC* pDC)
{
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

}


// CSketcherView ��ӡ

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSketcherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CSketcherView ���

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG


// CSketcherView ��Ϣ�������


void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonUp(nFlags, point);
}


void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//Ϊ����ͼ����һ���豸������
	CClientDC aDC(this);//DC��Ϊ����ͼ׼����
	if (nFlags&MK_LBUTTON)//��֤�������ǰ��µ�
	{
		m_SecondPoint = point;	//���浱ǰ���λ��
		if (m_pTempElement)
		{
			//һ��Ԫ�ر�����
			if (ElementType::CURVE == GetDocument()->GetElementType())	//�ж��Ƿ�������
			{
				//Ҫ�������ߣ���˽���Ƭ����ӵ��Ѵ��ڵ�������
				std::static_pointer_cast<CCurve>(m_pTempElement)->AddSegment(m_SecondPoint);
				m_pTempElement->Draw(&aDC);	//��������
				return;	//���
			}
			else
			{
				//�������������ɾ����Ԫ��
				aDC.SetROP2(R2_NOTXORPEN);	//���û滭ģʽ
				m_pTempElement->Draw(&aDC);	//������Ԫ��
			}
		}
		//����һ����ʱ���󲢻���
		m_pTempElement.reset(CreateElement());
		m_pTempElement->Draw(&aDC);
	}

	//CView::OnMouseMove(nFlags, point);
}


void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_FirstPoint = point;//��¼��ʼ��

	//CView::OnLButtonDown(nFlags, point);
}
