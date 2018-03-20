
// bankControlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "bankControl.h"
#include "bankControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CbankControlDlg 对话框




CbankControlDlg::CbankControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CbankControlDlg::IDD, pParent)
	, m_userID(0)
	, m_userPassword(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbankControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ID_edit, m_userID);
	DDX_Text(pDX, IDC_password_edit, m_userPassword);
}

BEGIN_MESSAGE_MAP(CbankControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_submit_button, &CbankControlDlg::OnBnClickedsubmitbutton)
	ON_BN_CLICKED(IDC_Create_Button, &CbankControlDlg::OnBnClickedCreateButton)
	ON_BN_CLICKED(IDC_Create_Button, &CbankControlDlg::OnBnClickedCreateButton)
	ON_BN_CLICKED(IDC_cancel_button, &CbankControlDlg::OnBnClickedcancelbutton)
END_MESSAGE_MAP()


// CbankControlDlg 消息处理程序

BOOL CbankControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CbankControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CbankControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CbankControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbankControlDlg::OnBnClickedsubmitbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	//unsigned long long int testID;
	UpdateData(TRUE);
	long long count;
	short index=0;
	//用户ID
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	
	str_ID.Format(_T("%d"),m_userID);
	CString sql=_T("select m_ID from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(index,str);	//返回当前记录指定字段的值
	int m=_ttoi(str);	//将字符串转化为数值型
	oneUser.m_uID=m;
	rs.Close();
	db.Close();

	//用户密码
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Password from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	//CString _password=str.Right(str.Find(_T(' ')));
	oneUser.m_sPassword=str;
	rs.Close();
	db.Close();

	//用户姓名
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_name from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	oneUser.m_sName=str;
	rs.Close();
	db.Close();

	//用户性别
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Sex from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	oneUser.m_sSex=str;
	rs.Close();
	db.Close();

	//用户余额
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_balance from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	m=_ttoi(str);	//将字符串转化为数值型
	oneUser.m_sBalance=m;
	rs.Close();
	db.Close();

	//用户身份证号码
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_IDNumber from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	oneUser.m_sID_number=str;
	rs.Close();
	db.Close();

	//用户单位
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Company from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	oneUser.m_sCompany=str;
	rs.Close();
	db.Close();

	//用户电话
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Telphone from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	m=_ttoi(str);	//将字符串转化为数值型
	oneUser.m_uTelphone=m;
	rs.Close();
	db.Close();

	//用户地址
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Address from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//返回当前记录指定字段的值
	oneUser.m_sAddress=str;
	rs.Close();
	db.Close();


	INT_PTR nRes;	//用于保存domodal函数返回值
	if(oneUser.m_uID!=m_userID)
	{
		CTipLogID tipLogID;
		m_userID=oneUser.m_uID;
		UpdateData(FALSE);
		nRes=tipLogID.DoModal();
		if(nRes==IDCANCEL)
			exit(0);
	}
	else 
	{
		m=_ttoi(oneUser.m_sPassword);
		if(m!=m_userPassword)
		{
			CTipLogPassword tipLogPassword;
			nRes=tipLogPassword.DoModal();
			if(nRes==IDCANCEL)
				exit(0);
		}
		else{
			HomePage homePage;
			homePage.DoModal();
		}
	}
}


void CbankControlDlg::OnBnClickedCreateButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CCreateDlg createDlg;
	createDlg.DoModal();
}

void CbankControlDlg::OnBnClickedcancelbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}

