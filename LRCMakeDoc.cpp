// LRCMakeDoc.cpp : implementation of the CLRCMakeDoc class
//

#include "stdafx.h"
#include "LRCMake.h"

#include "LRCMakeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeDoc

IMPLEMENT_DYNCREATE(CLRCMakeDoc, CDocument)

BEGIN_MESSAGE_MAP(CLRCMakeDoc, CDocument)
	//{{AFX_MSG_MAP(CLRCMakeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeDoc construction/destruction

CLRCMakeDoc::CLRCMakeDoc()
{
	// TODO: add one-time construction code here

}

CLRCMakeDoc::~CLRCMakeDoc()
{
}

BOOL CLRCMakeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLRCMakeDoc serialization

void CLRCMakeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeDoc diagnostics

#ifdef _DEBUG
void CLRCMakeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLRCMakeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeDoc commands
