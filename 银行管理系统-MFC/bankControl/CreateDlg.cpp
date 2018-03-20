// CreateDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "CreateDlg.h"
#include "afxdialogex.h"


// CCreateDlg 对话框

IMPLEMENT_DYNAMIC(CCreateDlg, CDialogEx)

CCreateDlg::CCreateDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCreateDlg::IDD, pParent)
	, m_userName(_T(""))
	, m_userSex(_T(""))
	, m_userIDNumber(_T(""))
	, m_userCompany(_T(""))
	, m_userTelphone(0)
	, m_userPassword(_T(""))
{

}

CCreateDlg::~CCreateDlg()
{
}

void CCreateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_userName);
	DDX_Text(pDX, IDC_EDIT2, m_userSex);
	DDX_Text(pDX, IDC_EDIT3, m_userIDNumber);
	DDX_Text(pDX, IDC_EDIT4, m_userCompany);
	DDX_Text(pDX, IDC_EDIT5, m_userTelphone);
	DDX_Text(pDX, IDC_EDIT6, m_userPassword);
}


BEGIN_MESSAGE_MAP(CCreateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCreateDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCreateDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCreateDlg 消息处理程序


void CCreateDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	oneUser.m_sName=m_userName;
	oneUser.m_sSex=m_userSex;
	oneUser.m_sID_number=m_userIDNumber;
	oneUser.m_sCompany=m_userCompany;
	oneUser.m_uTelphone=m_userTelphone;
	oneUser.m_sPassword=m_userPassword;
	
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	CString sql=_T("select max(m_ID) from bankUser ");
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	int m=_ttoi(str);
	oneUser.m_uID=m+1;
	rs.Close();
	db.Close();


	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	str.Format(_T("%d"),oneUser.m_uID);
	sql=_T("insert into bankUser(m_ID,m_name,m_sex,m_IDNumber,m_company,m_telphone,m_password) values('")+str;
	sql+=_T("','")+oneUser.m_sName+_T("','")+oneUser.m_sSex+_T("','")+oneUser.m_sID_number+_T("','")+oneUser.m_sCompany;
	str.Format(_T("%d"),oneUser.m_uTelphone);
	sql+=_T("',")+str+_T(",'")+oneUser.m_sPassword;
	sql+="')";
	
	db.ExecuteSQL(sql);

	rs.Close();
	db.Close();
	
	CreateSuccessDlg myDlg;
	myDlg.DoModal();
}


void CCreateDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
