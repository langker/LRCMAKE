; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLRCMakeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "LRCMake.h"

ClassCount=3
Class1=CLRCMakeApp
Class2=CLRCMakeDlg

ResourceCount=3
Resource2=IDD_LRCMAKE_DIALOG
Resource1=IDR_MAINFRAME
Class3=about
Resource3=IDD_DIALOG1

[CLS:CLRCMakeApp]
Type=0
HeaderFile=LRCMake.h
ImplementationFile=LRCMake.cpp
Filter=N

[CLS:CLRCMakeDlg]
Type=0
HeaderFile=LRCMakeDlg.h
ImplementationFile=LRCMakeDlg.cpp
Filter=D
LastObject=IDC_SLIDER1
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_LRCMAKE_DIALOG]
Type=1
Class=CLRCMakeDlg
ControlCount=18
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_LIULAN,button,1342242816
Control3=IDC_SLIDER1,msctls_trackbar32,1342242840
Control4=IDC_PLAYTIME,static,1342308865
Control5=IDC_BOFANG,button,1342242816
Control6=IDC_ZHANTING,button,1342242816
Control7=IDC_TINGZHI,button,1342242816
Control8=IDC_LIST1,listbox,1353778434
Control9=IDC_EDIT3,edit,1350631552
Control10=IDC_LIULAN2,button,1342242816
Control11=IDC_STATIC,static,1342308865
Control12=IDC_BUTTON5,button,1342242816
Control13=IDC_BUTTON6,button,1342251008
Control14=IDC_BUTTON7,button,1342242816
Control15=IDC_BUTTON3,button,1342242816
Control16=IDC_EDIT5,edit,1353781252
Control17=IDC_BUTTON1,button,1342242816
Control18=IDC_STATIC,static,1342308353

[DLG:IDD_DIALOG1]
Type=1
Class=about
ControlCount=3
Control1=IDC_STATIC,static,1342308352
Control2=IDC_BUTTON1,button,1342242816
Control3=IDC_BUTTON2,button,1342242816

[CLS:about]
Type=0
HeaderFile=about.h
ImplementationFile=about.cpp
BaseClass=CDialog
Filter=D
LastObject=about
VirtualFilter=dWC

