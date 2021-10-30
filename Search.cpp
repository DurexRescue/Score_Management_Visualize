// Search.cpp : implementation file
//

#include "stdafx.h"
#include "Management.h"
#include "Search.h"
#include "Student.h"
#include "ManagementDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CSearch dialog


CSearch::CSearch(CWnd* pParent /*=NULL*/)
	: CDialog(CSearch::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearch)
	m_Name = _T("");
	m_ID = _T("");
	//}}AFX_DATA_INIT
}


void CSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearch)
	DDX_Text(pDX, IDC_ENAME, m_Name);
	DDX_Text(pDX, IDC_EID, m_ID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearch, CDialog)
	//{{AFX_MSG_MAP(CSearch)
//	ON_BN_CLICKED(IDC_Search, OnSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearch message handlers

void CSearch::OnSearch() 
{
	// TODO: Add your control notification handler code here
	CManagementDlg dlg;
	CString str1,str2,str3;
	
	str1=m_Name;
	for(int i=0;i<dlg.m_stuArr.GetSize();i++)
	{
		//按姓名查找
		if(str1 == dlg.m_stuArr.GetAt(i).CName)
		{
			str2=dlg.m_stuArr.GetAt(i).CId+' '+dlg.m_stuArr.GetAt(i).CName
				+' ';
			str3.Format("%lf %lf %lf %lf",dlg.m_stuArr.GetAt(i).CPhysical,dlg.m_stuArr.GetAt(i).CMath,
				dlg.m_stuArr.GetAt(i).CEnglish,dlg.m_stuArr.GetAt(i).CPhysical+dlg.m_stuArr.GetAt(i).CMath+dlg.m_stuArr.GetAt(i).CEnglish);
			str2=str2+str3;
			break;
		}
	}
	if(i!=dlg.m_stuArr.GetSize()) MessageBox(str2,"查找成功");
	else   MessageBox("无此人信息!","查找失败");
}

