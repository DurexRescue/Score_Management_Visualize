// Image.cpp : implementation file
//

#include "stdafx.h"
#include "Management.h"
#include "Image.h"
#include <cmath>
#include "Student.h"
#include<Afxtempl.h>

#include"resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Image dialog


Image::Image(CWnd* pParent /*=NULL*/)
	: CDialog(Image::IDD, pParent)
{
	//{{AFX_DATA_INIT(Image)
	m_3 = 0.0;
	m_4 = 0.0;
	m_5 = 0.0;
	m_1 = 0;
	m_2 = 0;
	//}}AFX_DATA_INIT
}


void Image::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Image)
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Text(pDX, IDC_EDIT3, m_3);
	DDX_Text(pDX, IDC_EDIT4, m_4);
	DDX_Text(pDX, IDC_EDIT5, m_5);
	DDX_Text(pDX, IDC_EDIT1, m_1);
	DDX_Text(pDX, IDC_EDIT2, m_2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Image, CDialog)
	//{{AFX_MSG_MAP(Image)
	ON_WM_PAINT()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnSelchangedTree1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Image message handlers

void Image::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
    int Range_0_60=0;
	int Range_60_70=0;
	int Range_70_80=0;
	int Range_80_90=0;
	int Range_90_100=0;



	for(int j=0;j<m_stuArr.GetSize();j++){
	    Student stu=m_stuArr.GetAt(j);
		if((stu.CMath>=0)&&(stu.CMath<60)){
		    Range_0_60++;
		}
	    if((stu.CMath>=60)&&(stu.CMath<70)){
		    Range_60_70++;
		}
		if((stu.CMath>=70)&&(stu.CMath<80)){
		    Range_70_80++;
		}
		if((stu.CMath>=80)&&(stu.CMath<90)){
		    Range_80_90++;
		}
		if((stu.CMath>=90)&&(stu.CMath<=100)){
		    Range_90_100++;
		}
	}

	CString st0,st1,st2,st3,st4;
	st0.Format("%d",Range_0_60);
	st1.Format("%d",Range_60_70);
	st2.Format("%d",Range_70_80);
	st3.Format("%d",Range_80_90);
	st4.Format("%d",Range_90_100);

	


	SetDlgItemText(IDC_EDIT1, st0);
	SetDlgItemText(IDC_EDIT2, st1);
	SetDlgItemText(IDC_EDIT3, st2);
	SetDlgItemText(IDC_EDIT4, st3);
	SetDlgItemText(IDC_EDIT5, st4);
	
    double Angle_0_60=(Range_0_60)/double(m_stuArr.GetSize());
    double Angle_60_70=(Range_60_70)/double(m_stuArr.GetSize());
	double Angle_70_80=(Range_70_80)/double(m_stuArr.GetSize());
	double Angle_80_90=(Range_80_90)/double(m_stuArr.GetSize());
	double Angle_90_100=(Range_90_100)/double(m_stuArr.GetSize());

	
    CBrush br1(RGB(253,51,67));
	CBrush br2(RGB(250,164,51));
	CBrush br3(RGB(139,197,51));
	CBrush br4(RGB(3,141,216));
	CBrush br5(RGB(255,255,255));
    

	// TODO: Add your message handler code here
	CPen pen(PS_SOLID,1,RGB(0,0,0));         
    dc.SelectObject(&pen); 



    //�߼�����
    
    dc.SetMapMode(MM_TWIPS);//0.1����
   
	if(Draw_ZZT){
    //������
		SetViewportOrgEx(dc,700,450,NULL);
    dc.MoveTo(0,0);
    dc.LineTo(0,1400);//��1000
    dc.MoveTo(10,1380);
    dc.LineTo(0,1400);
    dc.LineTo(-10,1380);
	//������
    CString str;
    int i;
    for(i=1;i<=10;i++)
    {   str.Format("%d",i*3);
    
        dc.TextOut(-70,i*120,str);
    }
    
	//������
    dc.MoveTo(0,0);
    dc.LineTo(1300,0);
	//��С��ͷ
    dc.LineTo(1280,10);
    dc.MoveTo(1300,0);
    dc.LineTo(1280,-10);
	dc.TextOut(1200,-30,"Score Range");
	dc.TextOut(-40,1500,"Count");

    
    int h=40;

	
    
	//ÿ250һ��10 ��Ҫ��ʾ25 ��Ҫ250*2+125=625 ÿ250һ��3 ��Ҫ��ʾ18 ��Ҫ6*250=1500 ÿ120һ��3 ��Ҫ��ʾ20 ��Ҫ120*6.7=600
    
    //30:1200
    
    //������
 
    
    CRect r1(100,(Range_0_60)*h,200,0);
    dc.FillRect(r1,&br1);
    dc.TextOut(80,-10,"0-60");//�������˵������
    dc.TextOut(130,(Range_0_60)*h+80,st0);

    CRect r2(300,(Range_60_70)*h,400,0);
    dc.FillRect(r2,&br2);
    dc.TextOut(280,-10,"60-70");
	dc.TextOut(330,(Range_60_70)*h+80,st1);

    CRect r3(500,(Range_70_80)*h,600,0);
    dc.FillRect(r3,&br3);
    dc.TextOut(480,-10,"70-80");
	dc.TextOut(530,(Range_70_80)*h+80,st2);

    CRect r4(700,(Range_80_90)*h,800,0);
    dc.FillRect(r4,&br4);
    dc.TextOut(680,-10,"80-90");
	dc.TextOut(730,(Range_80_90)*h+80,st3);

	CRect r5(900,(Range_90_100)*h,1000,0);
    dc.FillRect(r5,&br5);
    dc.TextOut(880,-10,"90-100");
	dc.TextOut(930,(Range_90_100)*h+80,st4);
    }
    //����ͼ������cos��sin�������㶥��ֵ����ɫ����֮ǰ�Ѿ������˵�brush
	if(Draw_BT){
		SetViewportOrgEx(dc,500,500,NULL);
	int x1,y1,x2,y2,y3,x3,x4,y4;
	CString stx0,stx1,stx2,stx3,stx4;
	int r=400;
    dc.SelectObject(&br1);
    x1=int(r*cos(Angle_0_60*3.14*2))+1400;
    y1=int(r*sin(Angle_0_60*3.14*2)+400);
    dc.Pie(1000,800,1800,0,1800,400,x1,y1);
//BOOL Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    dc.SelectObject(&br2);
    x2=int(r*cos((Angle_0_60+Angle_60_70)*3.14*2))+1400;
    y2=int(r*sin((Angle_0_60+Angle_60_70)*3.14*2))+400;
    dc.Pie(1000,800,1800,0,x1,y1,x2,y2);

    dc.SelectObject(&br3);
    x3=int(r*cos((Angle_0_60+Angle_60_70+Angle_70_80)*3.14*2))+1400;
    y3=int(r*sin((Angle_0_60+Angle_60_70+Angle_70_80)*3.14*2))+400;
    dc.Pie(1000,800,1800,0,x2,y2,x3,y3);

	/*dc.SelectObject(&br5);
    x4=int(r*cos((Angle_0_60+Angle_60_70+Angle_70_80+Angle_80_90)*3.14*2))+1400;
    y4=int(r*sin((Angle_0_60+Angle_60_70+Angle_70_80+Angle_80_90)*3.14*2))+400;
    dc.Pie(1000,800,1800,0,x3,y3,x4,y4);*/

    CBrush   br9(RGB(125,30,227));
    dc.SelectObject(&br9);
    
	x4=int(r*cos((Angle_0_60+Angle_60_70+Angle_70_80+Angle_80_90)*3.14*2))+1400;
    y4=int(r*sin((Angle_0_60+Angle_60_70+Angle_70_80+Angle_80_90)*3.14*2))+400;
    dc.Pie(1000,800,1800,0,x3,y3,x4,y4);


    dc.SelectObject(&br4);
    dc.Pie(1000,800,1800,0,x4,y4,1800,400); 

    //��԰�����Ͻǻ�ͼ��������˵������
	stx0=" "+st0;
    stx1=" "+st1;
	stx2=" "+st2;
    stx3=" "+st3;
	stx4=" "+st4;

    CRect r5(2000,1000,2080,1060);
    dc.FillRect(r5,&br1);
    dc.TextOut(2100,1040,"0-60"+stx0);

    CRect r6(2000,900,2080,960);
    dc.FillRect(r6,&br2);
    dc.TextOut(2100,940,"60-70"+stx1);

    CRect r7(2000,800,2080,860);
    dc.FillRect(r7,&br3);
    dc.TextOut(2100,840,"70-80"+stx2);

    CRect r8(2000,700,2080,760);
    dc.FillRect(r8,&br9);
    dc.TextOut(2100,740,"80-90"+stx3);
	

	CRect r9(2000,600,2080,660);
    dc.FillRect(r9,&br4);
    dc.TextOut(2100,640,"90-100"+stx4);

}

	if(Draw_ZXT){
	
		SetViewportOrgEx(dc,700,450,NULL);
    dc.MoveTo(0,0);
    dc.LineTo(0,1400);//��1000
    
	dc.MoveTo(10,1380);
    dc.LineTo(0,1400);
    dc.LineTo(-10,1380);
	//������
    CString str;
    int i;
    for(i=1;i<=10;i++)
    {   str.Format("%d",i*3);
    
        dc.TextOut(-70,i*120+30,str);
		CPen pen(PS_DASH,1,RGB(0,0,0));         
        dc.SelectObject(&pen); 
		dc.MoveTo(0,i*120);
		dc.LineTo(1300,i*120);
    }
    


	CPen pen(PS_SOLID,1,RGB(0,0,0));         
    dc.SelectObject(&pen); 
	//������
    dc.MoveTo(0,0);
    dc.LineTo(1300,0);
	//��С��ͷ
   dc.LineTo(1280,10);
    dc.MoveTo(1300,0);
    dc.LineTo(1280,-10);
	dc.TextOut(1200,-30,"Score Range");
	dc.TextOut(-40,1500,"Count");

    
    int h=40;

	
    
	//ÿ250һ��10 ��Ҫ��ʾ25 ��Ҫ250*2+125=625 ÿ250һ��3 ��Ҫ��ʾ18 ��Ҫ6*250=1500 ÿ120һ��3 ��Ҫ��ʾ20 ��Ҫ120*6.7=600
    
    //30:1200
    
    //������
 
    
    //CRect r1(100,(Range_60_70)*h,200,0);
    //dc.FillRect(r1,&br1);
    //�������˵������  +50
    //dc.TextOut(130,(Range_60_70)*h+80,st1);
    
	dc.MoveTo(130,(Range_0_60)*h);
	dc.TextOut(80,-10,"0-60");
	dc.TextOut(280,-10,"60-70");
	dc.TextOut(480,-10,"70-80");
    dc.TextOut(680,-10,"80-90");
	dc.TextOut(880,-10,"90-100");
    
	dc.LineTo(330,(Range_60_70)*h);
	dc.LineTo(530,(Range_70_80)*h);
	dc.LineTo(730,(Range_80_90)*h);
	dc.LineTo(930,(Range_90_100)*h);

	dc.MoveTo(130,(Range_0_60)*h);
	dc.LineTo(0,(Range_0_60)*h);
	
	dc.MoveTo(330,(Range_60_70)*h);
    dc.LineTo(0,(Range_60_70)*h);


	dc.MoveTo(530,(Range_70_80)*h);
	dc.LineTo(0,(Range_70_80)*h);

	dc.MoveTo(730,(Range_80_90)*h);
    dc.LineTo(0,(Range_80_90)*h);

	dc.MoveTo(930,(Range_90_100)*h);
    dc.LineTo(0,(Range_90_100)*h);

    //CRect r2(300,(Range_70_80)*h,400,0);
    //dc.FillRect(r2,&br2);
    
	//dc.TextOut(330,(Range_70_80)*h+80,st2);

    //CRect r3(500,(Range_80_90)*h,600,0);
    //dc.FillRect(r3,&br3);
    
	//dc.TextOut(530,(Range_80_90)*h+80,st3);

    //CRect r4(700,(Range_90_100)*h,800,0);
    //dc.FillRect(r4,&br4);
    
	//dc.TextOut(730,(Range_90_100)*h+80,st4);

    //CRect r5(900,(Range_90_100)*h,1000,0);
    //dc.FillRect(r5,&br4);
    
	//dc.TextOut(930,(Range_90_100)*h+80,st4);
	}

	m_1=Range_0_60;
	m_2=Range_60_70;
	m_3=Range_70_80;
    m_4=Range_80_90;
	m_5=Range_90_100;
	// Do not call CDialog::OnPaint() for painting messages
}

void Image::Transfer(CArray<Student,Student&>& Temp_Arr){
	for(int i=0;i<Temp_Arr.GetSize();i++){
		Student temp;
		temp.CEnglish=Temp_Arr[i].CEnglish;
		temp.CMath=Temp_Arr[i].CMath;
		temp.CPhysical=Temp_Arr[i].CPhysical;
		temp.CName=Temp_Arr[i].CName;
		temp.CId=Temp_Arr[i].CId;
		temp.CSum=Temp_Arr[i].CSum;
		m_stuArr.Add(temp);
	}
}

BOOL Image::OnInitDialog() 
{
	CDialog::OnInitDialog();
	Draw_ZZT=false;
	Draw_BT=false;
	Draw_ZXT=false;
	// TODO: Add extra initialization here
	HTREEITEM hRoot;     // ���ĸ��ڵ�ľ��           ��һ������������ţ
	HTREEITEM hCataItem; // �ɱ�ʾ��һ����ڵ�ľ��   �ڶ������ٶȡ���Ѷ������Ͱ�
//	HTREEITEM hArtItem;  // �ɱ�ʾ��һ���½ڵ�ľ��   ���������ֻ��ٶȡ��ٶȵ�ͼ��QQ��΢��...
	
	// ������ڵ�   
	hRoot = m_tree.InsertItem(_T("����ͼ��"), 0, 0); 
 
/*  ����ԭ�ͣ�
    HTREEITEM InsertItem(LPCTSTR lpszItem, int nImage, int nSelectedImage,
		HTREEITEM hParent = TVI_ROOT, HTREEITEM hInsertAfter = TVI_LAST);
*/

	hCataItem = m_tree.InsertItem(_T("��״ͼ"), 1, 1, hRoot, TVI_LAST); 
	
	
	
	hCataItem = m_tree.InsertItem(_T("��ͼ"), 1, 1, hRoot, TVI_LAST);  
	
 
	hCataItem = m_tree.InsertItem(_T("����ͼ"), 1, 1, hRoot, TVI_LAST);  
	

	OnMENUITEMexpandtree();//չ�����нص�
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Image::OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here

	CString strText; // ���ڵ�ı�ǩ�ı��ַ���     
  
    // ��ȡ��ǰѡ�нڵ�ľ��     
    HTREEITEM hItem = m_tree.GetSelectedItem();  
    // ��ȡѡ�нڵ�ı�ǩ�ı��ַ���     
    strText = m_tree.GetItemText(hItem);  
    // ���ַ�����ʾ���༭����     
    //SetDlgItemText(IDC_EDIT_SELECT, strText); 
	

    SetDlgItemText(IDC_STATIC1, strText); 

	if(strText=="��״ͼ"){
	
		Draw_ZZT=true;
		Draw_BT=false;
		Draw_ZXT=false;
	}
	if(strText=="��ͼ"){

		Draw_BT=true;
		Draw_ZZT=false;
		Draw_ZXT=false;
	
	}
	if(strText=="����ͼ"){
	    Draw_ZXT=true;
		Draw_BT=false;
		Draw_ZZT=false;
	}
	
	Invalidate();
	*pResult = 0;
}

void Image::OnMENUITEMexpandtree() //�������������� չ���������нڵ�
{
    // TODO: Add your command handler code here
     MyExpandTree(m_tree.GetRootItem()); 
}
 
void Image::MyExpandTree(HTREEITEM hTreeItem)
{
    if(!m_tree.ItemHasChildren(hTreeItem))
    {
        return;
    }
    HTREEITEM hNextItem = m_tree.GetChildItem(hTreeItem);
    while (hNextItem != NULL)
    {
        MyExpandTree(hNextItem);
        hNextItem = m_tree.GetNextItem(hNextItem, TVGN_NEXT);
    }
    m_tree.Expand(hTreeItem,TVE_EXPAND);
}
