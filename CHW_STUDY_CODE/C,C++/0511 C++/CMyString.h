#pragma once;

class CMyString
{
public:
	CMyString();
	CMyString(CMyString& CpyItem);
	CMyString(const char* pszParam);
	~CMyString();

private:
	// 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
	char* m_pszData;

	// 저장된 문자열의 길이
	int m_nLength;

public:
	int SetString(const char* pszParam);

	// 멤버 읽기만 수행하므로 메서드를 상수화한다.
	const char* GetString() const;

	void Release();

	/////////////////////////////////
	//연산자 오버로딩

public:
	//정적맴버
	static int m_nCount; //객체가 생성된 누적수
	static void ResetCount();

	CMyString& operator=(const CMyString& rhs);
	//CMyString& operator+(const CMyString& rhs);

};