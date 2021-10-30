// Imagelize.cpp : implementation file
//

#include "stdafx.h"
#include "Management.h"
#include "Imagelize.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImagelize dialog


CImagelize::CImagelize(CWnd* pParent /*=NULL*/)
	: CDialog(CImagelize::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImagelize)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CImagelize::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImagelize)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImagelize, CDialog)
	//{{AFX_MSG_MAP(CImagelize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImagelize message handlers

BOOL CImagelize::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	HICON hIcon[8];
	int n;
	
    // tree structure common values

    CTreeCtrl* pTree = (CTreeCtrl*) GetDlgItem(IDC_TREE1);
	
  
	TV_INSERTSTRUCT tvinsert;
	tvinsert.hParent = NULL;
	tvinsert.hInsertAfter = TVI_LAST;
	tvinsert.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE |
						 TVIF_TEXT;
	tvinsert.item.hItem = NULL; 
	tvinsert.item.state = 0;
	tvinsert.item.stateMask = 0;
	tvinsert.item.cchTextMax = 6;
	tvinsert.item.iSelectedImage = 1;
	tvinsert.item.cChildren = 0;
	tvinsert.item.lParam = 0;
	//top level
	tvinsert.item.pszText = "数学";
	HTREEITEM Math_Second = pTree->InsertItem(&tvinsert);

	tvinsert.item.pszText = "物理";
	HTREEITEM Physics_Second = pTree->InsertItem(&tvinsert);

	tvinsert.item.pszText = "英语";
	HTREEITEM English_Second = pTree->InsertItem(&tvinsert);
	

//--------------------------------------------------//

	tvinsert.hParent = Math_Second;
	tvinsert.item.pszText = "60-70";

	pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "70-80";
	pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "80-90";
	pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "90以上";
	pTree->InsertItem(&tvinsert);
	
//--------------------------------------------------//

	tvinsert.hParent = Physics_Second;
	tvinsert.item.pszText = "60-70";
	HTREEITEM Physics_Range_Sixty_Seventy = pTree->InsertItem(&tvinsert);

	tvinsert.item.pszText = "70-80";
	HTREEITEM Physics_Range_Seventy_Eighty = pTree->InsertItem(&tvinsert);

	tvinsert.item.pszText = "80-90";
    HTREEITEM Physics_Range_Eighty_Ninety = pTree->InsertItem(&tvinsert);

	
	tvinsert.item.pszText = "90以上";
	HTREEITEM Physics_Beyond_Ninety = pTree->InsertItem(&tvinsert);

	tvinsert.hParent = Physics_Beyond_Ninety;
	tvinsert.item.pszText = "Dogbert";
	pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "Ratbert";
	pTree->InsertItem(&tvinsert);
	
//--------------------------------------------------//

	tvinsert.hParent = English_Second;
	tvinsert.item.pszText = "60-70";
	HTREEITEM English_Range_Sixty_Seventy = pTree->InsertItem(&tvinsert);

	tvinsert.item.pszText = "70-80";
	HTREEITEM English_Range_Seventy_Eighty = pTree->InsertItem(&tvinsert);

	tvinsert.item.pszText = "80-90";
    HTREEITEM English_Range_Eighty_Ninety = pTree->InsertItem(&tvinsert);

	
	tvinsert.item.pszText = "90以上";
	HTREEITEM English_Beyond_Ninety = pTree->InsertItem(&tvinsert);

	tvinsert.hParent = English_Beyond_Ninety;
	tvinsert.item.pszText = "Dogbert";
	pTree->InsertItem(&tvinsert);
	tvinsert.item.pszText = "Ratbert";
	pTree->InsertItem(&tvinsert);

//--------------------------------------------------//
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
