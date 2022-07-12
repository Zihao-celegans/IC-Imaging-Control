// FirstStepDoc.h : interface of the CFirstStepDoc class
//
#include <tisudshl.h>
#include <algorithm>

#pragma once


class CFirstStepDoc : public CDocument
{
protected: // create from serialization only
	CFirstStepDoc() noexcept;
	DECLARE_DYNCREATE(CFirstStepDoc)

// Attributes
public:
	DShowLib::Grabber* m_pGrabber;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CFirstStepDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void OnCloseDocument();
};
