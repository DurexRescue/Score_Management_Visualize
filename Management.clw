; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Image
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Management.h"

ClassCount=7
Class1=CManagementApp
Class2=CManagementDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG2
Class4=CLB
Resource4=IDD_DIALOG3
Class5=CSearch
Resource5=IDD_DIALOG1
Resource6=IDD_MANAGEMENT_DIALOG
Class6=CImagelize
Resource7=IDD_DIALOG4
Class7=Image
Resource8=IDD_DIALOG5

[CLS:CManagementApp]
Type=0
HeaderFile=Management.h
ImplementationFile=Management.cpp
Filter=N

[CLS:CManagementDlg]
Type=0
HeaderFile=ManagementDlg.h
ImplementationFile=ManagementDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CManagementDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ManagementDlg.h
ImplementationFile=ManagementDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MANAGEMENT_DIALOG]
Type=1
Class=CManagementDlg
ControlCount=20
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425
Control4=IDC_BUTTON_Open,button,1342242816
Control5=IDC_VIEW,button,1342242816
Control6=IDC_VAC,button,1342242816
Control7=IDC_AmbigusSearch,button,1342242816
Control8=IDC_ExplicitSearch,button,1342242816
Control9=IDC_Analyze,button,1342242816
Control10=IDC_Delete,button,1342242816
Control11=IDC_Sort,button,1342242816
Control12=IDC_ExplicitSearchByID,button,1342242816
Control13=IDC_Imagelize,button,1342242816
Control14=IDC_Add,button,1342242816
Control15=IDC_Save,button,1342242816
Control16=IDC_Range_Sixty_And_Seventy,button,1342242816
Control17=IDC_Beyond_Ninety,button,1342242816
Control18=IDC_LIST2,SysListView32,1350631425
Control19=IDC_Reset,button,1342242816
Control20=IDC_Multiple_Delete,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CLB
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDC_STATIC1,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME1,static,1342308352
Control5=IDC_ID,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EMATH,edit,1350631552
Control10=IDC_EENGLISH,edit,1350631552
Control11=IDC_EPHYSICS,edit,1350631552

[CLS:CLB]
Type=0
HeaderFile=LB.h
ImplementationFile=LB.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_NAME1

[DLG:IDD_DIALOG2]
Type=1
Class=CSearch
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_ENAME,edit,1350631552
Control5=IDC_EID,edit,1350631552

[CLS:CSearch]
Type=0
HeaderFile=Search.h
ImplementationFile=Search.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSearch

[DLG:IDD_DIALOG3]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG4]
Type=1
Class=CImagelize
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE1,SysTreeView32,1350631463

[CLS:CImagelize]
Type=0
HeaderFile=Imagelize.h
ImplementationFile=Imagelize.cpp
BaseClass=CDialog
Filter=D
LastObject=CImagelize
VirtualFilter=dWC

[DLG:IDD_DIALOG5]
Type=1
Class=Image
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE1,SysTreeView32,1350631431
Control4=IDC_STATIC1,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT1,edit,1350631552
Control11=IDC_EDIT2,edit,1350631552
Control12=IDC_EDIT3,edit,1350631552
Control13=IDC_EDIT4,edit,1350631552
Control14=IDC_EDIT5,edit,1350631552

[CLS:Image]
Type=0
HeaderFile=Image.h
ImplementationFile=Image.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

