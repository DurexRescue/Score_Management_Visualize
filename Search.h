#if !defined(AFX_SEARCH_H__FA89D82F_7025_4BF8_8856_1BF207E08375__INCLUDED_)
#define AFX_SEARCH_H__FA89D82F_7025_4BF8_8856_1BF207E08375__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Search.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearch dialog

class CSearch : public CDialog
{
// Construction
public:
	CSearch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearch)
	enum { IDD = IDD_DIALOG2 };
	CString	m_Name;
	CString	m_ID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearch)
	afx_msg void OnSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCH_H__FA89D82F_7025_4BF8_8856_1BF207E08375__INCLUDED_)
