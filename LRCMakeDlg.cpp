// LRCMakeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LRCMake.h"
#include "LRCMakeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeDlg dialog
#define SAFE_RELEASE(x) { if (x) x->Release(); x = NULL; }
void huanyuan(LPVOID pParam);
DWORD WINAPI whileplay(LPVOID pParam);
DWORD WINAPI gengxinjiemian(LPVOID pParam);
CLRCMakeDlg::CLRCMakeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLRCMakeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLRCMakeDlg)
	m_path = _T("");
	m_lrcpath = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    CoInitialize(NULL); 
	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void **)&m_pGraph);
    m_pGraph->QueryInterface(IID_IMediaControl, (void **)&m_pMediaControl); 
	m_pGraph->QueryInterface(IID_IMediaSeeking,   (void **)&m_pMediaSeeking);   
	m_pGraph->QueryInterface(IID_IBasicAudio,   (void **)&m_pBasicAudio);   
	m_pGraph->QueryInterface(IID_IMediaPosition,   (void **)&m_pMediaPosition);   
	isplay=FALSE;
	isplaying=FALSE;
	isfirst=FALSE;
	isliulan=FALSE;
	isbofang=FALSE;
	hGengxinjiemian=NULL;
	hangshu=0;
	islist=FALSE;
	Max=0;
}

void CLRCMakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLRCMakeDlg)
	DDX_Control(pDX, IDC_EDIT5, m_edit);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
	DDX_Control(pDX, IDC_PLAYTIME, m_playtime);
	DDX_Text(pDX, IDC_EDIT1, m_path);
	DDX_Text(pDX, IDC_EDIT3, m_lrcpath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLRCMakeDlg, CDialog)
	//{{AFX_MSG_MAP(CLRCMakeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LIULAN, OnLiulan)
	ON_BN_CLICKED(IDC_BOFANG, OnBofang)
	ON_BN_CLICKED(IDC_ZHANTING, OnZhanting)
	ON_BN_CLICKED(IDC_TINGZHI, OnTingzhi)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_LIULAN2, OnLiulan2)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON5, OnAddTime)
	ON_BN_CLICKED(IDC_BUTTON6, OnSaveFile)
	ON_BN_CLICKED(IDC_BUTTON7, OnAbout)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLRCMakeDlg message handlers

BOOL CLRCMakeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);
	m_slider.SetRange(0, 1000);
	SetWindowPos(NULL,0,0,330,520,SWP_NOMOVE |SWP_NOZORDER);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLRCMakeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLRCMakeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLRCMakeDlg::OnLiulan() 
{
    CFileDialog in(TRUE);
	if(in.DoModal()==IDOK)
        m_path=in.GetPathName();
	UpdateData(FALSE);
	if(isplaying||isfirst)
	{
       DWORD a;
       GetExitCodeThread(hGengxinjiemian,&a);
       isliulan=TRUE;
       TerminateThread(hGengxinjiemian,a);
	   Sleep(100);
	   SAFE_RELEASE(m_pGraph);
	   SAFE_RELEASE(m_pMediaControl);
	   SAFE_RELEASE(m_pMediaSeeking);
	   SAFE_RELEASE(m_pBasicAudio);
	   SAFE_RELEASE(m_pMediaPosition);
	   CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC, IID_IGraphBuilder, (void **)&m_pGraph);
       m_pGraph->QueryInterface(IID_IMediaControl, (void **)&m_pMediaControl); 
	   m_pGraph->QueryInterface(IID_IMediaSeeking,   (void **)&m_pMediaSeeking);   
	   m_pGraph->QueryInterface(IID_IBasicAudio,   (void **)&m_pBasicAudio);   
	   m_pGraph->QueryInterface(IID_IMediaPosition,   (void **)&m_pMediaPosition);   
	}
    USES_CONVERSION;
	CString strTime;
	m_pGraph->RenderFile(A2W(m_path), NULL); 
	DWORD len=(DWORD)GetLength();
	strTime.Format("00:00/0%d:%02d",len/60,len%60); 
	m_playtime.SetWindowText(strTime);
	isfirst=TRUE;
	isliulan=FALSE;
	isbofang=TRUE;
}

void CLRCMakeDlg::OnBofang() 
{
	if(isbofang)
	{
	GetDlgItem(IDC_TINGZHI)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	GetDlgItem(IDC_ZHANTING)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	isplaying=TRUE;
	isplay=TRUE;
	CreateThread(NULL,0,whileplay,this,0,0);
	}
	else
		MessageBox("没文件怎么播放呢？");
}

void CLRCMakeDlg::OnZhanting() 
{
	if(!isbofang)
	{
	isplay=FALSE;
	m_pMediaControl->Pause();
	}
	else
		MessageBox("无法暂停");
}

void CLRCMakeDlg::OnTingzhi() 
{
	if(!isbofang)
	{
	isplaying=FALSE;
	isplay=FALSE;
    m_pMediaControl->Stop();
    SetCurrentPos(0);
	huanyuan();
	}
	else
		MessageBox("无法重播");
}

LONGLONG CLRCMakeDlg::GetLength()
{
    LONGLONG duration;
	if( m_pMediaSeeking->GetDuration(&duration) == S_OK )
		return duration/10000/1000;
	return 0;
}
DWORD WINAPI whileplay(LPVOID pParam)
{
	CLRCMakeDlg *pdlg=(CLRCMakeDlg*)pParam;
	pdlg->m_pMediaControl->Run();
	DWORD len=(DWORD)pdlg->GetLength();
	DWORD i=(DWORD)pdlg->GetCurrentPos();
	pdlg->SetTimer(1,500,NULL);
	while(i!=len)
	{
		if(!pdlg->isliulan)
		{
		    i=(DWORD)pdlg->GetCurrentPos();
			Sleep(500);
		}
		else
			return 0;
	}
	pdlg->huanyuan();
    return 0;
}
DWORD WINAPI gengxinjiemian(LPVOID pParam)
{
	CLRCMakeDlg *pdlg=(CLRCMakeDlg*)pParam;
		if(!pdlg->isliulan&&(!pdlg->islist))
		{
	DWORD len=(DWORD)pdlg->GetLength();
	DWORD lenlen=(DWORD)pdlg->GetCurrentPos();
	CString time;
	pdlg->m_slider.SetPos(lenlen*1000/len);
	time.Format("0%d:%02d/0%d:%02d",lenlen/60,lenlen%60,len/60,len%60);
    pdlg->m_playtime.SetWindowText(time);
		}
	return 0;
}
void CLRCMakeDlg::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent==1)
	{
	    hGengxinjiemian=CreateThread(NULL,0,gengxinjiemian,this,0,0);
		CDialog::OnTimer(nIDEvent);
	}
}

LONGLONG CLRCMakeDlg::GetCurrentPos()
{
	LONGLONG current;
	if( m_pMediaSeeking->GetCurrentPosition(&current) == S_OK )
		return current/10000/1000;
	return 0;
}

void CLRCMakeDlg::SetCurrentPos(LONGLONG pos)
{
	m_pMediaControl->Stop();
	pos *= 10000;   
	LONGLONG stop = GetLength()*10000*1000;
	m_pMediaSeeking->SetPositions(&pos, AM_SEEKING_AbsolutePositioning, &stop,  AM_SEEKING_AbsolutePositioning);
	m_pMediaControl->Run();
}
void CLRCMakeDlg::huanyuan()
{
	m_slider.SetPos(0);
	SetCurrentPos(0);
	GetDlgItem(IDC_TINGZHI)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	GetDlgItem(IDC_ZHANTING)->EnableWindow(TRUE);
}



void CLRCMakeDlg::OnLiulan2() 
{
	Max=0;
	CFileDialog lrc(TRUE);
	if(lrc.DoModal()==IDOK)
        m_lrcpath=lrc.GetPathName();
    UpdateData(FALSE);
	CFile LRCFILE(m_lrcpath,CFile::modeRead); 
	if(LRCFILE.GetLength()<2)
	{
		MessageBox("文件里无内容！");
		return;
	}
	m_edit.SetWindowText("");
	CString LRC;
	char *sRead = new char [LRCFILE.GetLength()];
	memset(sRead,0,sizeof(sRead));
	LRCFILE.Read(sRead,LRCFILE.GetLength());
	LRCFILE.Close();
	LRC.Format("%s",sRead);
	m_edit.SetWindowText(LRC);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
}
void CLRCMakeDlg::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(isplaying)
	{
    islist=FALSE;
	LONGLONG i=m_slider.GetPos()*GetLength();
	SetCurrentPos(i);
	}
	*pResult = 0;
}

void CLRCMakeDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	islist=TRUE;
    DWORD len=(DWORD)GetLength();//文件总长度
	CString time;
	int a=m_slider.GetPos();//当前点数
	time.Format("0%d:%02d/0%d:%02d",a*len/1000/60,a*len/1000%60,len/60,len%60);
    m_playtime.SetWindowText(time);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

int CLRCMakeDlg::AllToSingle(char **single, const char *split, char All[])
{
	int i=0;
	char *p = strtok(All,split);
	while(p!=NULL)
	{
		single[i++] = p;
		p = strtok(NULL,split);
	}
	return i;
}

void CLRCMakeDlg::OnAddTime() 
{
	if(hangshu<Max)
	{
	CString LRC,TOSHOW;
	m_list.GetText(hangshu,LRC);
	DWORD lenlen=(DWORD)GetCurrentPos();
    TOSHOW.Format("[0%d:%02d.00]%s",lenlen/60,lenlen%60,LRC);
	m_list.DeleteString(hangshu);
	m_list.InsertString(hangshu,TOSHOW);
	hangshu++;
	}
	else
		MessageBox("所有时间标签一添加完成！\n请保存文件！");
}

void CLRCMakeDlg::OnSaveFile() 
{
	CFile Save(m_lrcpath,CFile::modeWrite);
	CString LRC;
	int Count=m_list.GetCount();
	for(int i=0;i<Count;i++)
	{
		CString ToAll;
		m_list.GetText(i,ToAll);
		LRC=LRC+ToAll+"\n";
	}
	Save.Write(LRC,LRC.GetLength());
	hangshu=0;
	MessageBox("保存成功！\n现在时间标签指向为0");
	SetWindowPos(NULL,0,0,330,520,SWP_NOMOVE |SWP_NOZORDER);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_LIULAN2)->EnableWindow(TRUE);
}

void CLRCMakeDlg::OnAbout() 
{
	// TODO: Add your control notification handler code here
	about a;
	a.DoModal();
}

void CLRCMakeDlg::OnButton3() 
{
	SetWindowPos(NULL,0,0,650,520,SWP_NOMOVE |SWP_NOZORDER);
	int Count=m_list.GetCount();
	for(int i=0;i<Count;i++)
		m_list.DeleteString(i);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	m_list.ResetContent ();
	CFile LRCFILE(m_lrcpath,CFile::modeRead); 
        char *sRead = new char [LRCFILE.GetLength()];
	memset(sRead,0,sizeof(sRead));
	LRCFILE.Read(sRead,LRCFILE.GetLength());
	char *ToSplit[1000];
	Max=AllToSingle(ToSplit,"\n",sRead);
	for(int p=0;p<Max;p++)
		m_list.InsertString(p,ToSplit[p]);
	LRCFILE.Close();
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_LIULAN2)->EnableWindow(FALSE);
    hangshu=0;
}

void CLRCMakeDlg::OnButton1() 
{
	CFile Save(m_lrcpath,CFile::modeWrite);
	CString LRC;
	m_edit.GetWindowText(LRC);
	Save.Write(LRC,LRC.GetLength());
	MessageBox("保存成功！");
}

BOOL CLRCMakeDlg::PreTranslateMessage(MSG* pMsg) 
{
if(pMsg->message   ==   WM_KEYDOWN   &&   pMsg->wParam   ==   0x1b)   
   return   TRUE;   
if(pMsg->message   ==   WM_KEYDOWN   &&   pMsg->wParam   ==   0x0d   )   
   return   TRUE;  
	
	return CDialog::PreTranslateMessage(pMsg);
}

void CLRCMakeDlg::OnClose() 
{
	m_pMediaControl->Stop();
	DWORD a;
    GetExitCodeThread(hGengxinjiemian,&a);
    TerminateThread(hGengxinjiemian,a);
	CDialog::OnClose();
}
