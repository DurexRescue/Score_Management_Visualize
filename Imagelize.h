#if !defined(AFX_IMAGELIZE_H__44B214A4_4DAB_4134_A205_2CDBF1665454__INCLUDED_)
#define AFX_IMAGELIZE_H__44B214A4_4DAB_4134_A205_2CDBF1665454__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Imagelize.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CImagelize dialog

class CImagelize : public CDialog
{
// Construction
public:
	CImagelize(CWnd* pParent = NULL);   // standard constructor
	CImageList m_imageList;

// Dialog Data
	//{{AFX_DATA(CImagelize)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImagelize)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:


	// Generated message map functions
	//{{AFX_MSG(CImagelize)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGELIZE_H__44B214A4_4DAB_4134_A205_2CDBF1665454__INCLUDED_)
