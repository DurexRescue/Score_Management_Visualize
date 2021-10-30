#if !defined(AFX_IMAGE_H__0A36AB40_5EC7_45C2_A32C_A68F4D744086__INCLUDED_)
#define AFX_IMAGE_H__0A36AB40_5EC7_45C2_A32C_A68F4D744086__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Image.h : header file
//

#include "Student.h"
#include<Afxtempl.h>

#include"resource.h"

/////////////////////////////////////////////////////////////////////////////
// Image dialog

class Image : public CDialog
{
// Construction
public:
	Image(CWnd* pParent = NULL);   // standard constructor

	CArray <Student,Student&> m_stuArr;

	void Image::Transfer(CArray<Student,Student&>& Temp_Arr);


	void Image::OnMENUITEMexpandtree();

	void Image::MyExpandTree(HTREEITEM hTreeItem);

	BOOL Draw_ZZT;
	BOOL Draw_BT;
	BOOL Draw_ZXT;


// Dialog Data
	//{{AFX_DATA(Image)
	enum { IDD = IDD_DIALOG5 };
	CTreeCtrl	m_tree;
	double	m_3;
	double	m_4;
	double	m_5;
	int		m_1;
	int		m_2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Image)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Image)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGE_H__0A36AB40_5EC7_45C2_A32C_A68F4D744086__INCLUDED_)
