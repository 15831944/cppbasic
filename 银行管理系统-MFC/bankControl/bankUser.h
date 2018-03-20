// bankUser.h : CbankUser ������

#pragma once

// ���������� 2017��5��29��, 17:15

class CbankUser : public CRecordset
{
public:
	CbankUser(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CbankUser)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_m_ID;
	CStringW	m_m_name;
	CStringW	m_m_sex;
	LONGLONG	m_m_balance;
	CStringW	m_m_IDNumber;
	CStringW	m_m_company;
	LONGLONG	m_m_telphone;
	CStringW	m_m_address;
	CStringW	m_m_password;

// ��д

	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


