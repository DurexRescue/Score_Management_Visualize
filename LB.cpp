// LB.cpp : implementation file
//

#include "stdafx.h"
#include "Management.h"
#include "LB.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLB dialog


CLB::CLB(CWnd* pParent /*=NULL*/)
	: CDialog(CLB::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLB)
	m_ID = _T("");
	m_name = _T("");
	m_math = 0.0;
	m_physics = 0.0;
	m_english = 0.0;
	//}}AFX_DATA_INIT
}


void CLB::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLB)
	DDX_Text(pDX, IDC_ID, m_ID);
	DDX_Text(pDX, IDC_NAME1, m_name);
	DDX_Text(pDX, IDC_EMATH, m_math);
	DDX_Text(pDX, IDC_EPHYSICS, m_physics);
	DDX_Text(pDX, IDC_EENGLISH, m_english);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLB, CDialog)
	//{{AFX_MSG_MAP(CLB)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLB message handlers
