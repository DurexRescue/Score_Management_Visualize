#if !defined(AFX_LB_H__5D5CCE64_609D_42FA_8E58_9C8E7A416667__INCLUDED_)
#define AFX_LB_H__5D5CCE64_609D_42FA_8E58_9C8E7A416667__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LB.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLB dialog

class CLB : public CDialog
{
// Construction
public:
	CLB(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLB)
	enum { IDD = IDD_DIALOG1 };
	CString	m_ID;
	CString	m_name;
	double	m_math;
	double	m_physics;
	double	m_english;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLB)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLB)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LB_H__5D5CCE64_609D_42FA_8E58_9C8E7A416667__INCLUDED_)
