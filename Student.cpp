// Student.cpp: implementation of the Student class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Management.h"
#include "Student.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Student::Student()
{

}



Student::Student(CString ID, CString Name, double Math,double English ,double Physical )
{
this ->CId=ID;
CName=Name;
CPhysical=Physical;
CMath=Math;
CEnglish=English;
CSum=CPhysical+CEnglish+CMath;
}