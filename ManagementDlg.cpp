// ManagementDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Management.h"
#include "ManagementDlg.h"
#include "LB.h"
#include "Search.h"
#include <cmath>
#include "Imagelize.h"
#include "Image.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManagementDlg dialog

CManagementDlg::CManagementDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManagementDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManagementDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManagementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManagementDlg)
	DDX_Control(pDX, IDC_LIST2, m_TList);
	DDX_Control(pDX, IDC_LIST1, m_SList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CManagementDlg, CDialog)
	//{{AFX_MSG_MAP(CManagementDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Open, OnBUTTONOpen)
	ON_BN_CLICKED(IDC_VIEW, OnView)
	ON_BN_CLICKED(IDC_VAC, OnVac)
	ON_BN_CLICKED(IDC_Delete, OnDelete)
	ON_BN_CLICKED(IDC_ExplicitSearch, OnExplicitSearch)
	ON_BN_CLICKED(IDC_ExplicitSearchByID, OnExplicitSearchByID)
	ON_BN_CLICKED(IDC_AmbigusSearch, OnAmbigusSearch)
	ON_BN_CLICKED(IDC_Analyze, OnAnalyze)
	ON_BN_CLICKED(IDC_Sort, OnSort)
	ON_BN_CLICKED(IDC_Add, OnAdd)
	ON_BN_CLICKED(IDC_Save, OnSave)
	ON_BN_CLICKED(IDC_Imagelize, OnImagelize)
	ON_BN_CLICKED(IDC_Range_Sixty_And_Seventy, OnRangeSixtyAndSeventy)
	ON_BN_CLICKED(IDC_Beyond_Ninety, OnBeyondNinety)
	ON_BN_CLICKED(IDC_Reset, OnReset)
	ON_BN_CLICKED(IDC_Multiple_Delete, OnMultipleDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManagementDlg message handlers

BOOL CManagementDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	DWORD dwStyle = m_SList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;            
    dwStyle |= LVS_EX_GRIDLINES; 
	///////////
    m_SList.SetExtendedStyle(dwStyle);
	m_SList.InsertColumn(0,"学号",LVCFMT_LEFT,100);              //添加列标题！！！！  这里的80,40,90用以设置列的宽度。！！！LVCFMT_LEFT用来设置对齐方式！！！
    m_SList.InsertColumn(1,"姓名",LVCFMT_LEFT,66);
    m_SList.InsertColumn(2,"数学",LVCFMT_LEFT,76);
    m_SList.InsertColumn(3,"物理",LVCFMT_LEFT,76);
	m_SList.InsertColumn(4,"英语",LVCFMT_LEFT,76);
	m_SList.InsertColumn(5,"总分",LVCFMT_LEFT,90);
	

    m_TList.SetExtendedStyle(dwStyle);
	m_TList.InsertColumn(0,"学号",LVCFMT_LEFT,100);              //添加列标题！！！！  这里的80,40,90用以设置列的宽度。！！！LVCFMT_LEFT用来设置对齐方式！！！
    m_TList.InsertColumn(1,"姓名",LVCFMT_LEFT,66);
    m_TList.InsertColumn(2,"数学",LVCFMT_LEFT,76);
    m_TList.InsertColumn(3,"物理",LVCFMT_LEFT,76);
	m_TList.InsertColumn(4,"英语",LVCFMT_LEFT,76);
	m_TList.InsertColumn(5,"总分",LVCFMT_LEFT,90);



	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CManagementDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CManagementDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CManagementDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CManagementDlg::OnBUTTONOpen() 
{
	// TODO: Add your control notification handler code here
	CString FilePathName;
	CFileDialog dlg(TRUE);
	if(dlg.DoModal()==IDOK)
		FilePathName=dlg.GetPathName();
	else
		return;
	CStdioFile file;
	file.Open(FilePathName, CFile::modeRead);
	CString strLine;
		m_stuArr.RemoveAll();
	while(file.ReadString(strLine))
        {
			CStringArray strarray;
			PartitionStringByCompart(strLine,' ',strarray);
            CString id=strarray.GetAt(0);
			CString name=strarray.GetAt(1);
			double math=atof(strarray.GetAt(2));
			double physical=atof(strarray.GetAt(3));
			double English=atof(strarray.GetAt(4));
			Student temp(id,name,math,physical,English);
            m_stuArr.Add(temp);
        }
	file.Close();

	CString str;
	int i;
	m_SList.DeleteAllItems();
    for(i=0;i<m_stuArr.GetSize();i++)
	{
		Student stu=m_stuArr.GetAt(i);
        m_SList.InsertItem(i,"");
 	    m_SList.SetItemText(i,0,stu.CId);
	    m_SList.SetItemText(i,1,stu.CName);

		str.Format("%lf",stu.CMath);
		m_SList.SetItemText(i,2,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_SList.SetItemText(i,3,str);

	    str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_SList.SetItemText(i,4,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical+stu.CMath+stu.CEnglish);
		m_SList.SetItemText(i,5,str);

		str.Empty();
	}



    
}

BOOL CManagementDlg::PartitionStringByCompart
(const CString &sOriginal, char cDivider, CStringArray &saField)
{
	saField.RemoveAll(); 
	int len=sOriginal.GetLength();   //字符串长度 
	CString sTmp(""); 
	for(int i=0;i<len;i++) 
	{ 
		if(sOriginal[i]!=cDivider) 
			sTmp+=sOriginal[i]; 
		else 
		{ 
			saField.Add(sTmp); 
			sTmp=_T(""); 
		}   //end of if() 
	}   //end of for() 
	saField.Add(sTmp); 
	if(saField.GetSize()==1)

		return false; 
	return true; 
}

void CManagementDlg::OnView() 
{
	// TODO: Add your control notification handler code here
	CString str;
    int nId;
	int sum=0;
    //首先得到点击的位置
    POSITION pos=m_SList.GetFirstSelectedItemPosition();
    if(pos==NULL)
	{
       MessageBox("请至少选择一项","提示",MB_ICONEXCLAMATION);
       return;
	}
    //得到行号，通过POSITION转化
    nId=(int)m_SList.GetNextSelectedItem(pos);
    str.Format("%d",nId);
    MessageBox("您选中"+m_SList.GetItemText(nId,1)+"同学，其学号为"+m_SList.GetItemText(nId,0)+"\n"+"物理成绩："+m_SList.GetItemText(nId,2)+" 数学成绩："+m_SList.GetItemText(nId,3)+" 英语成绩："+m_SList.GetItemText(nId,4));
}



void CManagementDlg::OnVac() 
{
	// TODO: Add your control notification handler code here
	int a=m_SList.GetSelectionMark();
	if(a== -1)
	{
		MessageBox("请选中一行信息!","请选中一行信息!");
		return;
	}
	CLB dlg;
	dlg.m_english=m_stuArr[a].CEnglish;
	dlg.m_ID=m_stuArr[a].CId;
	dlg.m_math=m_stuArr[a].CMath;
	dlg.m_name=m_stuArr[a].CName;
	dlg.m_physics=m_stuArr[a].CPhysical;
	m_SList.DeleteItem(a);  //清除列表框中的元素
    m_stuArr.RemoveAt(a);     //清楚数组中的元素
	if(IDOK==dlg.DoModal()){
		Student stu(dlg.m_ID,dlg.m_name,dlg.m_math,dlg.m_english,dlg.m_physics);
		//在合适的位置插入
		m_stuArr.InsertAt(a,stu);
		CString str;
		m_SList.InsertItem(a,"");
		m_SList.SetItemText(a,0,stu.CId);
	    m_SList.SetItemText(a,1,stu.CName);
		str.Format("%lf",stu.CMath);
		m_SList.SetItemText(a,2,str);
		str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_SList.SetItemText(a,3,str);
	    str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_SList.SetItemText(a,4,str);
		str.Empty();
		str.Format("%lf",(stu.CMath+stu.CPhysical+stu.CEnglish));
		m_SList.SetItemText(a,5,str);
		str.Empty();
	}
}

void CManagementDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int a=m_SList.GetSelectionMark();
	if(a== -1)
	{
		MessageBox("请选中一行信息!","请选中一行信息!");
		return;
	}
	m_SList.DeleteItem(a);  //清除列表框中的元素
    m_stuArr.RemoveAt(a);     //清楚数组中的元素
}

void CManagementDlg::OnExplicitSearch() 
{
	// TODO: Add your control notification handler code here
	CSearch dlg;
	BOOL Change=false;
	int k=0;
	if(IDOK==dlg.DoModal()){
       CString str1,str2,str3;
	   UpdateData(TRUE);
	   str1=dlg.m_Name;
	   for(int i=0;i<m_stuArr.GetSize();i++)
	   {
		  //按姓名查找
		  if(str1 == m_stuArr.GetAt(i).CName)
		  {
			k=i;
			Change=true;
			break;
		  }
	   }
	   if(i!=m_stuArr.GetSize()) MessageBox("查找成功");
	   else   MessageBox("无此人信息!","查找失败");
	}
	if(Change){
	CLB dlg1;
    dlg1.m_english=m_stuArr[k].CEnglish;
	dlg1.m_ID=m_stuArr[k].CId;
	dlg1.m_math=m_stuArr[k].CMath;
	dlg1.m_name=m_stuArr[k].CName;
	dlg1.m_physics=m_stuArr[k].CPhysical;
	m_SList.DeleteItem(k);  //清除列表框中的元素
    m_stuArr.RemoveAt(k);     //清楚数组中的元素
	if(IDOK==dlg1.DoModal()){
		Student stu(dlg1.m_ID,dlg1.m_name,dlg1.m_math,dlg1.m_english,dlg1.m_physics);
		//在合适的位置插入
		m_stuArr.InsertAt(k,stu);
		CString str;
		m_SList.InsertItem(k,"");
		m_SList.SetItemText(k,0,stu.CId);
	    m_SList.SetItemText(k,1,stu.CName);
		str.Format("%lf",stu.CMath);
		m_SList.SetItemText(k,2,str);
		str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_SList.SetItemText(k,3,str);
	    str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_SList.SetItemText(k,4,str);
		str.Empty();
		str.Format("%lf",(stu.CMath+stu.CPhysical+stu.CEnglish));
		m_SList.SetItemText(k,5,str);
		str.Empty();
	}
	}
}

void CManagementDlg::OnExplicitSearchByID() 
{
	// TODO: Add your control notification handler code here
	CSearch dlg;
	BOOL Change=false;
	int k=0;
	if(IDOK==dlg.DoModal()){
       CString str1,str2,str3;
	   UpdateData(TRUE);
	   str1=dlg.m_ID;
	   for(int i=0;i<m_stuArr.GetSize();i++)
	   {
		  //按学号查找
		  if(str1 == m_stuArr.GetAt(i).CId)
		  {
			k=i;
			Change=true;
			break;
		  }
	   }
	   if(i!=m_stuArr.GetSize()) MessageBox("查找成功");
	   else   MessageBox("无此人信息!","查找失败");
	}
	if(Change){
	CLB dlg1;
    dlg1.m_english=m_stuArr[k].CEnglish;
	dlg1.m_ID=m_stuArr[k].CId;
	dlg1.m_math=m_stuArr[k].CMath;
	dlg1.m_name=m_stuArr[k].CName;
	dlg1.m_physics=m_stuArr[k].CPhysical;
	m_SList.DeleteItem(k);  //清除列表框中的元素
    m_stuArr.RemoveAt(k);     //清楚数组中的元素
	if(IDOK==dlg1.DoModal()){
		Student stu(dlg1.m_ID,dlg1.m_name,dlg1.m_math,dlg1.m_english,dlg1.m_physics);
		//在合适的位置插入
		m_stuArr.InsertAt(k,stu);
		CString str;
		m_SList.InsertItem(k,"");
		m_SList.SetItemText(k,0,stu.CId);
	    m_SList.SetItemText(k,1,stu.CName);
		str.Format("%lf",stu.CMath);
		m_SList.SetItemText(k,2,str);
		str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_SList.SetItemText(k,3,str);
	    str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_SList.SetItemText(k,4,str);
		str.Empty();
		str.Format("%lf",stu.CSum);
		m_SList.SetItemText(k,5,str);
		str.Empty();
	}
	}
}

void CManagementDlg::OnAmbigusSearch() 
{
	// TODO: Add your control notification handler code here
	
	CSearch dlg;
	BOOL Change=false;
	int k;
	if(IDOK==dlg.DoModal()){
       CString str1,str2,str3;
	   UpdateData(TRUE);
	   str1=dlg.m_Name;
	   for(int i=0;i<m_stuArr.GetSize();i++)
	   {
		  //按姓名查找
		   
		   if(m_stuArr.GetAt(i).CName.Find(str1)!=-1)
		  {
			k=i;
			Change=true;
			break;
		  }
	   }
	   if(i!=m_stuArr.GetSize()) MessageBox("查找成功");
	   else   MessageBox("无此人信息!","查找失败");
	   if(Change){
	      CLB dlg1;
          dlg1.m_english=m_stuArr[k].CEnglish;
	      dlg1.m_ID=m_stuArr[k].CId;
	      dlg1.m_math=m_stuArr[k].CMath;
	      dlg1.m_name=m_stuArr[k].CName;
	     dlg1.m_physics=m_stuArr[k].CPhysical;
	     m_SList.DeleteItem(k);  //清除列表框中的元素
         m_stuArr.RemoveAt(k);     //清楚数组中的元素
	     if(IDOK==dlg1.DoModal()){
		    Student stu(dlg1.m_ID,dlg1.m_name,dlg1.m_math,dlg1.m_english,dlg1.m_physics);
		    //在合适的位置插入
		    m_stuArr.InsertAt(k,stu);
		    CString str;
		    m_SList.InsertItem(k,"");
		    m_SList.SetItemText(k,0,stu.CId);
	        m_SList.SetItemText(k,1,stu.CName);
		    str.Format("%lf",stu.CMath);
		    m_SList.SetItemText(k,2,str);
		    str.Empty();
		    str.Format("%lf",stu.CEnglish);
		    m_SList.SetItemText(k,3,str);
	        str.Empty();
		    str.Format("%lf",stu.CPhysical);
		    m_SList.SetItemText(k,4,str);
		    str.Empty();
		    str.Format("%lf",(stu.CMath+stu.CPhysical+stu.CEnglish));
		    m_SList.SetItemText(k,5,str);
		    str.Empty();
	     }
	   }
	}
	
}

void CManagementDlg::OnAnalyze() 
{
	// TODO: Add your control notification handler code here
	double math_sum=0;double physics_sum=0; double english_sum=0;double all_sum=0;
	double math_ave,physics_ave,english_ave,all_ave;
    for(int i=0;i<m_stuArr.GetSize();i++){
		Student stu=m_stuArr.GetAt(i);
		math_sum=math_sum+stu.CMath;
		physics_sum+=stu.CPhysical;
		english_sum+=stu.CEnglish;
	}
	all_sum=math_sum+physics_sum+english_sum;
    math_ave=math_sum/m_stuArr.GetSize();
    physics_ave=physics_sum/m_stuArr.GetSize();
	english_ave=english_sum/m_stuArr.GetSize();
	all_ave=all_sum/3/m_stuArr.GetSize();
	CString a,b,c,d;
	a.Format("%lf",math_ave);
	b.Format("%lf",physics_ave);
	c.Format("%lf",english_ave);
	d.Format("%lf",all_ave);
	MessageBox("数学平均分："+a+"\n物理平均分："+b+"\n英语平均分："+c+"\n总平均分    ："+d);
	int opm=0;int opp=0;int ope=0;
	double Math_SD;
	for(int k=0;k<m_stuArr.GetSize();k++){
		Student stu=m_stuArr.GetAt(k);
		opm =opm+ pow(stu.CMath - math_ave, 2);
	}
	Math_SD = sqrt(1./m_stuArr.GetSize()*opm);//数学标准差
	CString e;
	e.Format("%lf",Math_SD);

	double Physics_SD;
	for(int l=0;l<m_stuArr.GetSize();l++){
		Student stu=m_stuArr.GetAt(l);
		opm =opm+ pow(stu.CPhysical - physics_ave, 2);
	}
	Physics_SD = sqrt(1./m_stuArr.GetSize()*opm);//数学标准差
	CString f;
	f.Format("%lf",Math_SD);

	double English_SD;
	for(int m=0;m<m_stuArr.GetSize();m++){
		Student stu=m_stuArr.GetAt(m);
		opm =opm+ pow(stu.CEnglish - math_ave, 2);
	}
	English_SD = sqrt(1./m_stuArr.GetSize()*opm);//数学标准差
	CString g;
	g.Format("%lf",English_SD);
	MessageBox("数学标准差："+e+"\n物理标准差："+f+"\n英语标准差："+g);

	double Math_Count=0; double Physics_Count=0; double English_Count=0;
	for(int o=0;o<m_stuArr.GetSize();o++){
		Student stu=m_stuArr.GetAt(o);
		if (stu.CMath>= 60)Math_Count++;
		if (stu.CPhysical>= 60)Physics_Count++;
        if (stu.CEnglish>= 60)English_Count++;
	}
	Math_Count/=m_stuArr.GetSize();
	Physics_Count/=m_stuArr.GetSize();
	English_Count/=m_stuArr.GetSize();
	CString h,hh,hhh;
    h.Format("%lf",Math_Count);
	hh.Format("%lf",Physics_Count);
	hhh.Format("%lf",English_Count);
	MessageBox("数学合格率："+h+"\n物理合格率："+h+"\n英语合格率："+hhh);
}

    



void CManagementDlg::OnSort() 
{
	// TODO: Add your control notification handler code here
	for (int i = 0; i <m_stuArr.GetSize()-1; i++) {
	  
		for (int j = m_stuArr.GetSize() - 1; j >= i+1; j--) {
		    
			if (m_stuArr[j].CSum >= m_stuArr[j-1].CSum||
				((m_stuArr[j].CSum == m_stuArr[j-1].CSum) && (m_stuArr[j].CMath >= m_stuArr[j-1].CMath))||
				((m_stuArr[j].CSum == m_stuArr[j-1].CSum) && (m_stuArr[j].CMath == m_stuArr[j-1].CMath) && (m_stuArr[j].CPhysical >= m_stuArr[j-1].CPhysical))||
                ((m_stuArr[j].CSum == m_stuArr[j-1].CSum) && (m_stuArr[j].CMath == m_stuArr[j-1].CMath) && (m_stuArr[j].CPhysical == m_stuArr[j-1].CPhysical) && (m_stuArr[j].CEnglish >= m_stuArr[j-1].CEnglish))
				
				)
			{
				/*此代码效率低下 造成死机
                //a1=m_stuArr.GetAt(j);
				//a2=m_stuArr.GetAt(j-1);

				//m_stuArr.RemoveAt(j);     //清楚数组中的元素
				//m_stuArr.RemoveAt(j-1);     //清楚数组中的元素
				
	        	//m_stuArr.InsertAt(j,a2);
	        	//m_stuArr.InsertAt(j-1,a1);
				*/
				Student a;
				a=m_stuArr[j];
				m_stuArr[j]=m_stuArr[j-1];
				m_stuArr[j-1]=a;
			}
		}
	}
	/*CString stda=m_stuArr[8].CName;
    CString stdb;
	stdb.Format("%lf",m_stuArr[8].CMath);
	MessageBox(stda+"  "+stdb);*/
	CString str;
	m_SList.DeleteAllItems();
    for(i=0;i<m_stuArr.GetSize();i++)
	{
		Student stu=m_stuArr.GetAt(i);
        m_SList.InsertItem(i,"");
 	    m_SList.SetItemText(i,0,stu.CId);
	    m_SList.SetItemText(i,1,stu.CName);

		str.Format("%lf",stu.CMath);
		m_SList.SetItemText(i,2,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_SList.SetItemText(i,3,str);

	    str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_SList.SetItemText(i,4,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical+stu.CMath+stu.CEnglish);
		m_SList.SetItemText(i,5,str);

		str.Empty();
	}
}

void CManagementDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here

	int i=m_stuArr.GetSize();
	CSearch Dlg;
	CLB Dlg1;
	Student stu;
	if(IDOK==Dlg.DoModal()){
      stu.CName=Dlg.m_Name;
	  stu.CId=Dlg.m_ID;
	}
	Dlg1.m_ID=stu.CId;
		Dlg1.m_name=stu.CName;
	if(IDOK==Dlg1.DoModal()){
		
		stu.CEnglish=Dlg1.m_english;
		stu.CMath=Dlg1.m_math;
		stu.CPhysical=Dlg1.m_physics;
		stu.CSum=stu.CEnglish+stu.CMath+stu.CPhysical;
	}
	
	m_stuArr.Add(stu);
		CString str;
		m_SList.InsertItem(i,"");
		m_SList.SetItemText(i,0,stu.CId);
	    m_SList.SetItemText(i,1,stu.CName);
		str.Format("%lf",stu.CMath);
		m_SList.SetItemText(i,2,str);
		str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_SList.SetItemText(i,3,str);
	    str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_SList.SetItemText(i,4,str);
		str.Empty();
		str.Format("%lf",stu.CSum);
		m_SList.SetItemText(i,5,str);
		str.Empty();
}

void CManagementDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	CString pszFileName;
	CFileDialog dlg(FALSE);
	if(dlg.DoModal()==IDOK)
		pszFileName=dlg.GetPathName();
	else
		return;
	CStdioFile myFile;
	CFileException fileException;
	if(myFile.Open(pszFileName,CFile::typeText|CFile::modeCreate|CFile::modeReadWrite),&fileException)
	{
		for(int i=0;i<m_stuArr.GetSize();i++)
		{
			Student stu=m_stuArr.GetAt(i);
			CString str1,str2;
			str1=m_stuArr.GetAt(i).CId+' '+m_stuArr.GetAt(i).CName
				+' ';
			str2.Format("%lf %lf %lf %lf",m_stuArr.GetAt(i).CPhysical,m_stuArr.GetAt(i).CMath,
				m_stuArr.GetAt(i).CEnglish,m_stuArr.GetAt(i).CPhysical+m_stuArr.GetAt(i).CMath+m_stuArr.GetAt(i).CEnglish);
			str1=str1+str2;
			myFile.WriteString(str1);
		    myFile.WriteString("\n");
		    myFile.SeekToEnd();
		}
		MessageBox("文件写入成功!","提示");
	}
	else
	{
		TRACE("Can't open file %s,error=%u\n",pszFileName,fileException.m_cause);
	}
}

void CManagementDlg::OnImagelize() 
{
	// TODO: Add your control notification handler code here
//	CImagelize Dlg;
	
//    Dlg.DoModal();

	Image Dlg;
	Dlg.Transfer(m_stuArr);
	Dlg.DoModal();
    
    

}

void CManagementDlg::OnRangeSixtyAndSeventy() 
{
	// TODO: Add your control notification handler code here
	int count=0;
	//double math;
	m_stuArr1.RemoveAll();
	for(int j=0;j<m_stuArr.GetSize();j++){
	    Student stu=m_stuArr.GetAt(j);
	    if((stu.CMath>=60)&&(stu.CMath<=70)){
		    //m_stuArr1[count]=m_stuArr[j];
			CString id=stu.CId;
			CString name=stu.CName;
			double math=stu.CMath;
			double physical=stu.CPhysical;
			double English=stu.CEnglish;
			Student temp(id,name,math,physical,English);
			m_stuArr1.Add(temp);
			m_stuArr.RemoveAt(j);
			m_SList.DeleteItem(j);
		}
	}
    CString str;
	int i;
	m_TList.DeleteAllItems();
    for(i=0;i<m_stuArr1.GetSize();i++)
	{
		Student stu=m_stuArr1.GetAt(i);
        m_TList.InsertItem(i,"");
 	    m_TList.SetItemText(i,0,stu.CId);
	    m_TList.SetItemText(i,1,stu.CName);

		str.Format("%lf",stu.CMath);
		m_TList.SetItemText(i,2,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_TList.SetItemText(i,3,str);

	    str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_TList.SetItemText(i,4,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical+stu.CMath+stu.CEnglish);
		m_TList.SetItemText(i,5,str);

		str.Empty();
	}
}

void CManagementDlg::OnBeyondNinety() 
{
	// TODO: Add your control notification handler code here
	m_stuArr1.RemoveAll();
	for(int j=0;j<m_stuArr.GetSize();j++){
	    Student stu=m_stuArr.GetAt(j);
	    if(stu.CMath>=90){
		    //m_stuArr1[count]=m_stuArr[j];
			CString id=stu.CId;
			CString name=stu.CName;
			double math=stu.CMath;
			double physical=stu.CPhysical;
			double English=stu.CEnglish;
			Student temp(id,name,math,physical,English);
			m_stuArr1.Add(temp);
			m_stuArr.RemoveAt(j);
			m_SList.DeleteItem(j);
		}
	}
    CString str;
	int i;
	m_TList.DeleteAllItems();
    for(i=0;i<m_stuArr1.GetSize();i++)
	{
		Student stu=m_stuArr1.GetAt(i);
        m_TList.InsertItem(i,"");
 	    m_TList.SetItemText(i,0,stu.CId);
	    m_TList.SetItemText(i,1,stu.CName);

		str.Format("%lf",stu.CMath);
		m_TList.SetItemText(i,2,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_TList.SetItemText(i,3,str);

	    str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_TList.SetItemText(i,4,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical+stu.CMath+stu.CEnglish);
		m_TList.SetItemText(i,5,str);

		str.Empty();
	}
}

void CManagementDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	for (int iItem = m_TList.GetItemCount() - 1; iItem >= 0; iItem--)
	{
		if (m_TList.GetItemState(iItem, LVIS_SELECTED) == LVIS_SELECTED){
            Student stu=m_stuArr1.GetAt(iItem);
			m_TList.DeleteItem(iItem);
			CString id=stu.CId;
			CString name=stu.CName;
			double math=stu.CMath;
			double physical=stu.CPhysical;
			double English=stu.CEnglish;
			Student temp(id,name,math,physical,English);
			m_stuArr.Add(temp);
	        m_stuArr1.RemoveAt(iItem);
		}

	}
	CString str;
	int i;
	m_SList.DeleteAllItems();
    for(i=0;i<m_stuArr.GetSize();i++)
	{
		Student stu=m_stuArr.GetAt(i);
        m_SList.InsertItem(i,"");
 	    m_SList.SetItemText(i,0,stu.CId);
	    m_SList.SetItemText(i,1,stu.CName);

		str.Format("%lf",stu.CMath);
		m_SList.SetItemText(i,2,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical);
		m_SList.SetItemText(i,3,str);

	    str.Empty();
		str.Format("%lf",stu.CEnglish);
		m_SList.SetItemText(i,4,str);

		str.Empty();
		str.Format("%lf",stu.CPhysical+stu.CMath+stu.CEnglish);
		m_SList.SetItemText(i,5,str);

		str.Empty();
	}
}

void CManagementDlg::OnMultipleDelete() 
{
	// TODO: Add your control notification handler code here


    for (int iItem = m_SList.GetItemCount() - 1; iItem >= 0; iItem--)
	{
       if (m_SList.GetItemState(iItem, LVIS_SELECTED) == LVIS_SELECTED)
          m_SList.DeleteItem(iItem);
	      m_stuArr.RemoveAt(iItem);
    }
}
