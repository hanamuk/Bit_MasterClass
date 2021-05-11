#pragma once

class CMyString
{
public:
	////////////////////////////////////
	// ������ �����ε�
	CMyString& operator=(const CMyString& rhs);
	//CMyString& operator+(const CMyString& rhs);
	//CMyString& operator-(const CMyString& rhs);

public:
	////////////////////////////////////
	// �Լ� �����ε�
	CMyString();
	CMyString(const CMyString& rhs);// ���� ������
	CMyString(const char* pszParam);// ��ȯ ������
	
	~CMyString();

private:
	// ���ڿ��� �����ϱ� ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ��� ����
	int m_nLength;

public:
	int SetString(const char* pszParam);

	// ��� �б⸸ �����ϹǷ� �޼��带 ���ȭ�Ѵ�.
	const char* GetString() const;

	void Release();

	
};
