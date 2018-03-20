// bankUser.h : CbankUser 类的实现



// CbankUser 实现

// 代码生成在 2017年5月29日, 17:15

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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
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
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
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
// CbankUser 诊断

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


