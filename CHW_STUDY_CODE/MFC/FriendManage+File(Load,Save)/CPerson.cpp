#include "pch.h"
#include "CPerson.h"

CPerson::CPerson()
{

	m_nAge = 0;
	m_bGender = 0;
	m_strName = _T("");

}
CPerson::~CPerson() 
{


}

void CPerson::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code

		ar << m_nAge;
		ar << m_bGender;
		ar << m_strName;
	}
	else
	{	// loading code
		ar >> m_nAge;
		ar >> m_bGender;
		ar >> m_strName;
	}
}
