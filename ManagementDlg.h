// ManagementDlg.h : header file
//

#if !defined(AFX_MANAGEMENTDLG_H__98C0F43E_1AD2_4C6A_8B86_837C82248419__INCLUDED_)
#define AFX_MANAGEMENTDLG_H__98C0F43E_1AD2_4C6A_8B86_837C82248419__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Student.h"
#include<Afxtempl.h>

#include"resource.h"
/////////////////////////////////////////////////////////////////////////////
// CManagementDlg dialog

class CManagementDlg : public CDialog
{
// Construction
public:
	CManagementDlg(CWnd* pParent = NULL);	// standard constructor
    BOOL PartitionStringByCompart(const   CString   &sOriginal,char   cDivider,CStringArray   &saField);
    CArray <Student,Student&> m_stuArr;
	CArray <Student,Student&> m_stuArr1;

// Dialog Data
	//{{AFX_DATA(CManagementDlg)
	enum { IDD = IDD_MANAGEMENT_DIALOG };
	CListCtrl	m_TList;
	CListCtrl	m_SList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManagementDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	
	

	// Generated message map functions
	//{{AFX_MSG(CManagementDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONOpen();
	afx_msg void OnView();
	afx_msg void OnButton1();
	afx_msg void OnVac();
	afx_msg void OnDelete();
	afx_msg void OnExplicitSearch();
	afx_msg void OnExplicitSearch2();
	afx_msg void OnExplicitSearchId();
	afx_msg void OnExplicitSearchByID();
	afx_msg void OnAmbigusSearch();
	afx_msg void OnAnalyze();
	afx_msg void OnSort();
	afx_msg void OnAdd();
	afx_msg void OnSave();
	afx_msg void OnImagelize();
	afx_msg void OnRangeSixtyAndSeventy();
	afx_msg void OnBeyondNinety();
	afx_msg void OnReset();
	afx_msg void OnMultipleDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEMENTDLG_H__98C0F43E_1AD2_4C6A_8B86_837C82248419__INCLUDED_)
