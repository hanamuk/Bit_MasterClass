#pragma once;

class CMyString
{
public:
	CMyString();
	CMyString(CMyString& CpyItem);
	CMyString(const char* pszParam);
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

	/////////////////////////////////
	//������ �����ε�

public:
	//�����ɹ�
	static int m_nCount; //��ü�� ������ ������
	static void ResetCount();

	CMyString& operator=(const CMyString& rhs);
	//CMyString& operator+(const CMyString& rhs);

};