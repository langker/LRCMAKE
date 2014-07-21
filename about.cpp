// about.cpp : implementation file
//

#include "stdafx.h"
#include "LRCMake.h"
#include "about.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// about dialog


about::about(CWnd* pParent /*=NULL*/)
	: CDialog(about::IDD, pParent)
{
	//{{AFX_DATA_INIT(about)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void about::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(about)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(about, CDialog)
	//{{AFX_MSG_MAP(about)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// about message handlers

void about::OnButton1() 
{
MessageBox("ÄÇÊÇ£¡");
CDialog::OnOK();	
}

void about::OnButton2() 
{
ShellExecute(GetParent()->GetSafeHwnd(), _T("open"), 
(CString)"http://hi.baidu.com/Ð¦Ì¾ºì³¾ÆÆ", NULL, NULL, SW_SHOW); 	
}
