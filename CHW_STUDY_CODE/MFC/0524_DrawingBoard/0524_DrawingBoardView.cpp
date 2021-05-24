
// 0524_DrawingBoardView.cpp: CMy0524DrawingBoardView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "0524_DrawingBoard.h"
#endif

#include "0524_DrawingBoardDoc.h"
#include "0524_DrawingBoardView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0524DrawingBoardView

IMPLEMENT_DYNCREATE(CMy0524DrawingBoardView, CView)

BEGIN_MESSAGE_MAP(CMy0524DrawingBoardView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_LINE, &CMy0524DrawingBoardView::OnLine)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CMy0524DrawingBoardView::OnUpdateLine)
	ON_COMMAND(ID_RECTANGEL, &CMy0524DrawingBoardView::OnRectangel)
	ON_UPDATE_COMMAND_UI(ID_RECTANGEL, &CMy0524DrawingBoardView::OnUpdateRectangel)
	ON_COMMAND(ID_CERCLE, &CMy0524DrawingBoardView::OnCercle)
	ON_UPDATE_COMMAND_UI(ID_CERCLE, &CMy0524DrawingBoardView::OnUpdateCercle)
	ON_COMMAND(ID_FILL, &CMy0524DrawingBoardView::OnFill)
	ON_UPDATE_COMMAND_UI(ID_FILL, &CMy0524DrawingBoardView::OnUpdateFill)
END_MESSAGE_MAP()

// CMy0524DrawingBoardView 생성/소멸

CMy0524DrawingBoardView::CMy0524DrawingBoardView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_ptStart.x = 0;
	m_ptStart.y = 0;
	m_ptEnd.x = 0;
	m_ptEnd.y = 0;
	m_bDrag = FALSE;

	m_nShape = 0;
	m_bFill  = FALSE;

	m_Color = RGB(0, 0, 0);
}

CMy0524DrawingBoardView::~CMy0524DrawingBoardView()
{
}

BOOL CMy0524DrawingBoardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy0524DrawingBoardView 그리기

void CMy0524DrawingBoardView::OnDraw(CDC* /*pDC*/)
{
	CMy0524DrawingBoardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy0524DrawingBoardView 인쇄

BOOL CMy0524DrawingBoardView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy0524DrawingBoardView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy0524DrawingBoardView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy0524DrawingBoardView 진단

#ifdef _DEBUG
void CMy0524DrawingBoardView::AssertValid() const
{
	CView::AssertValid();
}

void CMy0524DrawingBoardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0524DrawingBoardDoc* CMy0524DrawingBoardView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0524DrawingBoardDoc)));
	return (CMy0524DrawingBoardDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy0524DrawingBoardView 메시지 처리기





void CMy0524DrawingBoardView::OnLButtonDown(UINT nFlags, CPoint point)
{

	m_bDrag = TRUE;//드래그 시작함
	m_ptStart = point;

	CView::OnLButtonDown(nFlags, point);
}

void CMy0524DrawingBoardView::OnMouseMove(UINT nFlags, CPoint point)
{
	
/*	if (m_bDrag == TRUE)//지금 드래그 중이니?
	{
		m_ptEnd.x = point.x;
		m_ptEnd.y = point.y;
		RedrawWindow();//WM_PAINT발생
	}
*/
	if (m_bDrag)
	{
		//m_bDrag = FALSE;
		m_ptEnd.x = point.x;
		m_ptEnd.y = point.y;
		RedrawWindow();
	}
	CView::OnMouseMove(nFlags, point);
}

void CMy0524DrawingBoardView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag)
	{
		m_bDrag = FALSE;
		m_ptEnd.x = point.x;
		m_ptEnd.y = point.y;
		RedrawWindow();
	}
	
	CView::OnLButtonUp(nFlags, point);
}


void CMy0524DrawingBoardView::OnPaint()
{
	CPaintDC dc(this); 
	CBrush myBr(m_Color);
	CBrush* pOldBr = NULL;

	if (m_bFill)//채움
		pOldBr = dc.SelectObject(&myBr);	

	switch (m_nShape)
	{
		case 0://선
		{
			dc.MoveTo(m_ptStart);
			dc.LineTo(m_ptEnd);
		}
		break;
		case 1: //사각형
			dc.Rectangle(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
		break;
		case 2:	//원
			dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptEnd.x, m_ptEnd.y);
		break;
	}

	if (m_bFill)//채움
		dc.SelectObject(pOldBr);
}

//직선
void CMy0524DrawingBoardView::OnLine()
{
	m_nShape = 0;
}
void CMy0524DrawingBoardView::OnUpdateLine(CCmdUI* pCmdUI)
{
	if(m_nShape == 0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

//사각형
void CMy0524DrawingBoardView::OnRectangel()
{
	m_nShape = 1;
}
void CMy0524DrawingBoardView::OnUpdateRectangel(CCmdUI* pCmdUI)
{
	if (m_nShape == 1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

//원
void CMy0524DrawingBoardView::OnCercle()
{
	m_nShape = 2;
}

void CMy0524DrawingBoardView::OnUpdateCercle(CCmdUI* pCmdUI)
{
	if (m_nShape == 2)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

//채우기
void CMy0524DrawingBoardView::OnFill()
{
	m_bFill = !m_bFill;
	if (m_bFill)
	{
		CColorDialog ColorDlg;
		ColorDlg.DoModal();
		m_Color = ColorDlg.GetColor();
	}
	
}

void CMy0524DrawingBoardView::OnUpdateFill(CCmdUI* pCmdUI)
{

	if (m_bFill)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);

}
