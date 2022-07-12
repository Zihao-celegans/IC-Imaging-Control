
// FirstStepView.cpp : implementation of the CFirstStepView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FirstStep.h"
#endif

#include "FirstStepDoc.h"
#include "FirstStepView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFirstStepView

IMPLEMENT_DYNCREATE(CFirstStepView, CView)

BEGIN_MESSAGE_MAP(CFirstStepView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFirstStepView construction/destruction

CFirstStepView::CFirstStepView() noexcept
{
	// TODO: add construction code here

}

CFirstStepView::~CFirstStepView()
{
}

BOOL CFirstStepView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFirstStepView drawing

void CFirstStepView::OnDraw(CDC* /*pDC*/)
{
	CFirstStepDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CFirstStepView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFirstStepView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFirstStepView diagnostics

#ifdef _DEBUG
void CFirstStepView::AssertValid() const
{
	CView::AssertValid();
}

void CFirstStepView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFirstStepDoc* CFirstStepView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFirstStepDoc)));
	return (CFirstStepDoc*)m_pDocument;
}
#endif //_DEBUG


// CFirstStepView message handlers


void CFirstStepView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	 // Get the grabber from the document class.
	DShowLib::Grabber* pGrabber = GetDocument()->m_pGrabber;

	// Show the device page.
	pGrabber->showDevicePage();
	// Check if there is a valid device.
	if (pGrabber->isDevValid())
	{
		// Set the window that should display the live video.
		pGrabber->setHWND(m_hWnd);
		// Start the live video.
		pGrabber->startLive();
	}
	else
	{
		AfxMessageBox(TEXT("No device was selected."));
	}
}
