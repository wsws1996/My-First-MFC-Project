
// SketcherDoc.cpp : CSketcherDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSketcherDoc

IMPLEMENT_DYNCREATE(CSketcherDoc, CDocument)

BEGIN_MESSAGE_MAP(CSketcherDoc, CDocument)
	ON_COMMAND(ID_COLOR_BLACK, &CSketcherDoc::OnColorBlack)
	ON_COMMAND(ID_COLOR_RED, &CSketcherDoc::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CSketcherDoc::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CSketcherDoc::OnColorBlue)
	ON_COMMAND(ID_ELEMENT_LINE, &CSketcherDoc::OnElementLine)
	ON_COMMAND(ID_ELEMENT_RECTANGLE, &CSketcherDoc::OnElementRectangle)
	ON_COMMAND(ID_ELEMENT_CIRCLE, &CSketcherDoc::OnElementCircle)
	ON_COMMAND(ID_ELEMENT_CURVE, &CSketcherDoc::OnElementCurve)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CSketcherDoc::OnUpdateColorBlack)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CSketcherDoc::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CSketcherDoc::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CSketcherDoc::OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_LINE, &CSketcherDoc::OnUpdateElementLine)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_RECTANGLE, &CSketcherDoc::OnUpdateElementRectangle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CIRCLE, &CSketcherDoc::OnUpdateElementCircle)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_CURVE, &CSketcherDoc::OnUpdateElementCurve)
	ON_COMMAND(ID_ELEMENT_ELLIPSE, &CSketcherDoc::OnElementEllipse)
	ON_UPDATE_COMMAND_UI(ID_ELEMENT_ELLIPSE, &CSketcherDoc::OnUpdateElementEllipse)
END_MESSAGE_MAP()


// CSketcherDoc ����/����

CSketcherDoc::CSketcherDoc() :m_Element(ElementType::LINE), m_Color(ElementColor::BLACK)
{
	// TODO:  �ڴ����һ���Թ������

}

CSketcherDoc::~CSketcherDoc()
{
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CSketcherDoc ���л�

void CSketcherDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CSketcherDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CSketcherDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CSketcherDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSketcherDoc ���

#ifdef _DEBUG
void CSketcherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSketcherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSketcherDoc ����


void CSketcherDoc::OnColorBlack()
{
	// TODO:  �ڴ���������������
	m_Color = ElementColor::BLACK;//�ѻ滭��ɫ��Ϊ��ɫ
}


void CSketcherDoc::OnColorRed()
{
	// TODO:  �ڴ���������������
	m_Color = ElementColor::RED;//�ѻ滭��ɫ��Ϊ��ɫ
}


void CSketcherDoc::OnColorGreen()
{
	// TODO:  �ڴ���������������
	m_Color = ElementColor::GREEN;//�ѻ滭��ɫ��Ϊ��ɫ
}


void CSketcherDoc::OnColorBlue()
{
	// TODO:  �ڴ���������������
	m_Color = ElementColor::BLUE;//�ѻ滭��ɫ��Ϊ��ɫ
}


void CSketcherDoc::OnElementLine()
{
	// TODO:  �ڴ���������������
	m_Element = ElementType::LINE;//��Ԫ�����͸�Ϊֱ��
}


void CSketcherDoc::OnElementRectangle()
{
	// TODO:  �ڴ���������������
	m_Element = ElementType::RECTANGLE;//��Ԫ�����͸�Ϊ������
}


void CSketcherDoc::OnElementCircle()
{
	// TODO:  �ڴ���������������
	m_Element = ElementType::CIRCLE;//��Ԫ�����͸�ΪԲ
}


void CSketcherDoc::OnElementCurve()
{
	// TODO:  �ڴ���������������
	m_Element = ElementType::CURVE;//��Ԫ�����͸�Ϊ����
}


void CSketcherDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰ��ɫ�Ǻ�ɫ������Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Color == ElementColor::BLACK);
}


void CSketcherDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰ��ɫ�Ǻ�ɫ������Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Color == ElementColor::RED);
}


void CSketcherDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰ��ɫ����ɫ������Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Color == ElementColor::GREEN);
}


void CSketcherDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰ��ɫ����ɫ������Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Color == ElementColor::BLUE);
}


void CSketcherDoc::OnUpdateElementLine(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰԪ����ֱ�߽�����Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Element == ElementType::LINE);
}


void CSketcherDoc::OnUpdateElementRectangle(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰԪ���ǳ����ν�����Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Element == ElementType::RECTANGLE);
}


void CSketcherDoc::OnUpdateElementCircle(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰԪ����Բ������Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Element == ElementType::CIRCLE);
}


void CSketcherDoc::OnUpdateElementCurve(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰԪ�������߽�����Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Element == ElementType::CURVE);
}


void CSketcherDoc::OnElementEllipse()
{
	// TODO:  �ڴ���������������
	m_Element = ElementType::ELLIPSE;//��Ԫ�����͸�Ϊ��Բ
}


void CSketcherDoc::OnUpdateElementEllipse(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	//�����ǰԪ������Բ������Ŀ����Ϊѡ��
	pCmdUI->SetCheck(m_Element == ElementType::ELLIPSE);
}
