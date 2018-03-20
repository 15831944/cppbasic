// bankUser.h : CbankUser ���ʵ��



// CbankUser ʵ��

// ���������� 2017��5��29��, 17:15

#include "stdafx.h"
#include "bankUser.h"
IMPLEMENT_DYNAMIC(CbankUser, CRecordset)

CbankUser::CbankUser(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_m_ID = 0;
	m_m_name = L"";
	m_m_sex = L"";
	m_m_balance = 0;
	m_m_IDNumber = L"";
	m_m_company = L"";
	m_m_telphone = 0;
	m_m_address = L"";
	m_m_password = L"";
	m_nFields = 9;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CbankUser::GetDefaultConnect()
{
	return _T("DRIVER=SQL Server;SERVER=(local);Trusted_Connection=Yes;APP=Microsoft? Visual Studio? 2010;WSID=DESKTOP-3870V9G;DATABASE=bankUser");
}

CString CbankUser::GetDefaultSQL()
{
	return _T("[dbo].[bankUser]");
}

void CbankUser::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[m_ID]"), m_m_ID);
	RFX_Text(pFX, _T("[m_name]"), m_m_name);
	RFX_Text(pFX, _T("[m_sex]"), m_m_sex);
	RFX_BigInt(pFX, _T("[m_balance]"), m_m_balance);
	RFX_Text(pFX, _T("[m_IDNumber]"), m_m_IDNumber);
	RFX_Text(pFX, _T("[m_company]"), m_m_company);
	RFX_BigInt(pFX, _T("[m_telphone]"), m_m_telphone);
	RFX_Text(pFX, _T("[m_address]"), m_m_address);
	RFX_Text(pFX, _T("[m_password]"), m_m_password);

}
/////////////////////////////////////////////////////////////////////////////
// CbankUser ���

#ifdef _DEBUG
void CbankUser::AssertValid() const
{
	CRecordset::AssertValid();
}

void CbankUser::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


