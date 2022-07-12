
// FirstStepDoc.cpp : implementation of the CFirstStepDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FirstStep.h"
#endif

#include "FirstStepDoc.h"

#include <propkey.h>

#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFirstStepDoc

IMPLEMENT_DYNCREATE(CFirstStepDoc, CDocument)

BEGIN_MESSAGE_MAP(CFirstStepDoc, CDocument)
END_MESSAGE_MAP()


// CFirstStepDoc construction/destruction

CFirstStepDoc::CFirstStepDoc() noexcept
{
	// TODO: add one-time construction code here
	m_pGrabber = new DShowLib::Grabber();
	ASSERT(m_pGrabber);

}

CFirstStepDoc::~CFirstStepDoc()
{
	delete m_pGrabber;
}

BOOL CFirstStepDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CFirstStepDoc serialization

void CFirstStepDoc::Serialize(CArchive& ar)
{
	std::cout << "serialize" << std::endl;
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CFirstStepDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void CFirstStepDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CFirstStepDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CFirstStepDoc diagnostics

#ifdef _DEBUG
void CFirstStepDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFirstStepDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFirstStepDoc commands


void CFirstStepDoc::OnCloseDocument()
{
	// TODO: Add your specialized code here and/or call the base class
	// Stop live mode.
	m_pGrabber->stopLive();

	// this call will also succeed if no device is open
	m_pGrabber->closeDev();

	CDocument::OnCloseDocument();
}
