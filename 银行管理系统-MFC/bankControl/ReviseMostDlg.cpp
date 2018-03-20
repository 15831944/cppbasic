// ReviseMostDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "ReviseMostDlg.h"
#include "afxdialogex.h"


// ReviseMostDlg 对话框

IMPLEMENT_DYNAMIC(ReviseMostDlg, CDialogEx)

ReviseMostDlg::ReviseMostDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ReviseMostDlg::IDD, pParent)
	, reName(_T(""))
	, reSex(_T(""))
	, reIDNumber(_T(""))
	, reCompany(_T(""))
	, reTelphone(0)
	, reAddress(_T(""))
{

}

ReviseMostDlg::~ReviseMostDlg()
{
}

void ReviseMostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, reName);
	DDX_Text(pDX, IDC_EDIT2, reSex);
	DDX_Text(pDX, IDC_EDIT3, reIDNumber);
	DDX_Text(pDX, IDC_EDIT4, reCompany);
	DDX_Text(pDX, IDC_EDIT5, reTelphone);
	DDX_Text(pDX, IDC_EDIT6, reAddress);
}


BEGIN_MESSAGE_MAP(ReviseMostDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ReviseMostDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ReviseMostDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &ReviseMostDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// ReviseMostDlg 消息处理程序


void ReviseMostDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//确定修改常规信息
	UpdateData(TRUE);
	oneUser.m_sName=reName;
	oneUser.m_sSex=reSex;
	oneUser.m_sID_number=reIDNumber;
	oneUser.m_sCompany=reCompany;
	oneUser.m_uTelphone=reTelphone;
	oneUser.m_sAddress=reAddress;


	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	CString sql=_T("insert into bankUser(m_name,m_sex,m_IDNumber,m_company,m_telphone,m_address) values('")+oneUser.m_sName;
	sql+=_T("','")+oneUser.m_sSex+_T("','")+oneUser.m_sID_number+_T("','")+oneUser.m_sCompany;
	str.Format(_T("%d"),oneUser.m_uTelphone);
	sql+=_T("',")+str+_T(",'")+oneUser.m_sAddress;
	sql+="')";
	db.ExecuteSQL(sql);

	rs.Close();
	db.Close();
	

	ReviseSuccessDlg reviseSuccessDlg;
	reviseSuccessDlg.DoModal();
}


void ReviseMostDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//返回首页
	HomePage homePage;
	homePage.DoModal();
}


void ReviseMostDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//退出程序
	exit(0);
}
