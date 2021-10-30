// Student.h: interface for the Student class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STUDENT_H__DB721C1A_E8F0_4F2A_A625_7F8C68EAD761__INCLUDED_)
#define AFX_STUDENT_H__DB721C1A_E8F0_4F2A_A625_7F8C68EAD761__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Student  
{
public:
//	double sum;
//	double CSum;
	Student(CString ID,CString Name,double Math,double Physical,double English);
	Student();
//	virtual ~Student();
	double CEnglish;
	double CMath;
	double CPhysical;
	double CSum;
	CString CName;
	CString CId;
};

#endif // !defined(AFX_STUDENT_H__DB721C1A_E8F0_4F2A_A625_7F8C68EAD761__INCLUDED_)
