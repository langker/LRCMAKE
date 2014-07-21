// LRCMakeView.h : interface of the CLRCMakeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LRCMAKEVIEW_H__5015A561_7F83_4D18_807D_E8D0370F02ED__INCLUDED_)
#define AFX_LRCMAKEVIEW_H__5015A561_7F83_4D18_807D_E8D0370F02ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLRCMakeView : public CView
{
protected: // create from serialization only
	CLRCMakeView();
	DECLARE_DYNCREATE(CLRCMakeView)

// Attributes
public:
	CLRCMakeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLRCMakeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLRCMakeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLRCMakeView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LRCMakeView.cpp
inline CLRCMakeDoc* CLRCMakeView::GetDocument()
   { return (CLRCMakeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LRCMAKEVIEW_H__5015A561_7F83_4D18_807D_E8D0370F02ED__INCLUDED_)
