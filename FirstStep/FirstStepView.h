
// FirstStepView.h : interface of the CFirstStepView class
//

#pragma once


class CFirstStepView : public CView
{
protected: // create from serialization only
	CFirstStepView() noexcept;
	DECLARE_DYNCREATE(CFirstStepView)

// Attributes
public:
	CFirstStepDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CFirstStepView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // debug version in FirstStepView.cpp
inline CFirstStepDoc* CFirstStepView::GetDocument() const
   { return reinterpret_cast<CFirstStepDoc*>(m_pDocument); }
#endif

