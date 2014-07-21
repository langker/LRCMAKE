#if !defined(AFX_ABOUT_H__4FF783C8_CF51_4F06_AB78_F5E8735BFFC7__INCLUDED_)
#define AFX_ABOUT_H__4FF783C8_CF51_4F06_AB78_F5E8735BFFC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// about.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// about dialog

class about : public CDialog
{
// Construction
public:
	about(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(about)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(about)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(about)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ABOUT_H__4FF783C8_CF51_4F06_AB78_F5E8735BFFC7__INCLUDED_)
