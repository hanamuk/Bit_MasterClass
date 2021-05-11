#define _CRT_SECURE_NO_WARNINGS
#include"CMyString.h"
#include<string.h>
#include<iostream>
using namespace std;

void AddCount()
{

	CMyString::m_nCount++;
	cout << "현재누적수 : " << CMyString::m_nCount << endl;
}

CMyString::CMyString()
{
	AddCount();
	m_pszData = NULL;
	m_nLength = 0;

}

CMyString::CMyString(CMyString& CpyItem)
{
	AddCount();
	m_nLength = CpyItem.m_nLength;
	this->m_pszData = new char[strlen(CpyItem.m_pszData)+ 1];
	strcpy(this->m_pszData, CpyItem.m_pszData);
	
}

CMyString::CMyString(const char* pszParam)
{
	AddCount();
	this->m_nLength = strlen(pszParam);
	this->m_pszData = new char[m_nLength + 1];
	strcpy(this->m_pszData, pszParam);
}

CMyString::~CMyString()
{
	this->m_nCount--;
	cout << "현재 카운터 : " << m_nCount << endl;
	Release();
	

}

int CMyString::SetString(const char* pszParam)
{
	Release();

	int nSize = strlen(pszParam);
	this->m_pszData = new char[nSize+1];

	strcpy(this->m_pszData, pszParam);
	this->m_nLength = nSize;
	return nSize;
}


const char* CMyString::GetString()const
{
	 return this->m_pszData;


}

void CMyString::Release()
{

	delete[] m_pszData;
	m_pszData = NULL;
	m_nLength = 0;
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
	AddCount();
	if (this != &rhs)
		this->SetString(rhs.GetString());
	
	return *this;
}


void CMyString::ResetCount()
{
	m_nCount = 0;
}

