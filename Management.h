// Management.h : main header file for the MANAGEMENT application
//

#if !defined(AFX_MANAGEMENT_H__CAD8E6C6_D615_499F_BAA5_C43EDCD30EF2__INCLUDED_)
#define AFX_MANAGEMENT_H__CAD8E6C6_D615_499F_BAA5_C43EDCD30EF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CManagementApp:
// See Management.cpp for the implementation of this class
//

class CManagementApp : public CWinApp
{
public:
	CManagementApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManagementApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CManagementApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGEMENT_H__CAD8E6C6_D615_499F_BAA5_C43EDCD30EF2__INCLUDED_)
