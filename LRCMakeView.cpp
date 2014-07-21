// LRCMakeView.cpp : implementation of the CLRCMakeView class
//

#include "stdafx.h"
#include "LRCMake.h"

#include "LRCMakeDoc.h"
#include "LRCMakeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeView

IMPLEMENT_DYNCREATE(CLRCMakeView, CView)

BEGIN_MESSAGE_MAP(CLRCMakeView, CView)
	//{{AFX_MSG_MAP(CLRCMakeView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeView construction/destruction

CLRCMakeView::CLRCMakeView()
{
	// TODO: add construction code here

}

CLRCMakeView::~CLRCMakeView()
{
}

BOOL CLRCMakeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeView drawing

void CLRCMakeView::OnDraw(CDC* pDC)
{
	CLRCMakeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeView printing

BOOL CLRCMakeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLRCMakeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLRCMakeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeView diagnostics

#ifdef _DEBUG
void CLRCMakeView::AssertValid() const
{
	CView::AssertValid();
}

void CLRCMakeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLRCMakeDoc* CLRCMakeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLRCMakeDoc)));
	return (CLRCMakeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeView message handlers
