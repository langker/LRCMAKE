// LRCMakeDlg.h : header file
//

#if !defined(AFX_LRCMAKEDLG_H__9C18A227_EB7C_4A9C_9306_460D04E5263A__INCLUDED_)
#define AFX_LRCMAKEDLG_H__9C18A227_EB7C_4A9C_9306_460D04E5263A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
// CLRCMakeDlg dialog
#include <mmsystem.h>
#include <dsound.h>
#include <ddraw.h>
#include <dshow.h>
#include <streams.h>
#include <afxpriv.h>
#include <Shlwapi.h>
#include "about.h"
#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"Strmiids.lib")

class CLRCMakeDlg : public CDialog
{
// Construction
public:
	int CLRCMakeDlg::AllToSingle(char **single, const char *split, char All[]);
	void huanyuan();
	void SetCurrentPos(LONGLONG pos);
	LONGLONG GetCurrentPos();
	LONGLONG GetLength();
	CLRCMakeDlg(CWnd* pParent = NULL);
	BOOL isplay;
	BOOL isplaying;
	BOOL isfirst;
	int Max;
		// 指向Filter Graph的指针
	IGraphBuilder *m_pGraph;  
	// 指向MediaControl对象的指针  
    IMediaControl *m_pMediaControl; 
	// 指向IMediaSeeking对象的指针  
	IMediaSeeking *m_pMediaSeeking;

	IBasicAudio *m_pBasicAudio;
	IMediaPosition *m_pMediaPosition;
	BOOL isliulan;
	BOOL isbofang;
	HANDLE hGengxinjiemian;
	INT hangshu;
	bool islist;
// Dialog Data
	//{{AFX_DATA(CLRCMakeDlg)
	enum { IDD = IDD_LRCMAKE_DIALOG };
	CEdit	m_edit;
	CListBox	m_list;
	CSliderCtrl	m_slider;
	CStatic	m_playtime;
	CString	m_path;
	CString	m_lrcpath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLRCMakeDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLRCMakeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLiulan();
	afx_msg void OnBofang();
	afx_msg void OnZhanting();
	afx_msg void OnTingzhi();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLiulan2();
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnAddTime();
	afx_msg void OnSaveFile();
	afx_msg void OnAbout();
	afx_msg void OnButton3();
	afx_msg void OnButton1();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LRCMAKEDLG_H__9C18A227_EB7C_4A9C_9306_460D04E5263A__INCLUDED_)
