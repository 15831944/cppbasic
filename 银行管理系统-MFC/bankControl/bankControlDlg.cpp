
// bankControlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "bankControl.h"
#include "bankControlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CbankControlDlg �Ի���




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


// CbankControlDlg ��Ϣ�������

BOOL CbankControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CbankControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CbankControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbankControlDlg::OnBnClickedsubmitbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//unsigned long long int testID;
	UpdateData(TRUE);
	long long count;
	short index=0;
	//�û�ID
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	
	str_ID.Format(_T("%d"),m_userID);
	CString sql=_T("select m_ID from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(index,str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	int m=_ttoi(str);	//���ַ���ת��Ϊ��ֵ��
	oneUser.m_uID=m;
	rs.Close();
	db.Close();

	//�û�����
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Password from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	//CString _password=str.Right(str.Find(_T(' ')));
	oneUser.m_sPassword=str;
	rs.Close();
	db.Close();

	//�û�����
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_name from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	oneUser.m_sName=str;
	rs.Close();
	db.Close();

	//�û��Ա�
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Sex from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	oneUser.m_sSex=str;
	rs.Close();
	db.Close();

	//�û����
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_balance from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	m=_ttoi(str);	//���ַ���ת��Ϊ��ֵ��
	oneUser.m_sBalance=m;
	rs.Close();
	db.Close();

	//�û����֤����
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_IDNumber from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	oneUser.m_sID_number=str;
	rs.Close();
	db.Close();

	//�û���λ
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Company from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	oneUser.m_sCompany=str;
	rs.Close();
	db.Close();

	//�û��绰
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Telphone from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	m=_ttoi(str);	//���ַ���ת��Ϊ��ֵ��
	oneUser.m_uTelphone=m;
	rs.Close();
	db.Close();

	//�û���ַ
	db.OpenEx(_T("DSN=bankUser;"),CDatabase::noOdbcDialog);
	rs.m_pDatabase=&db;
	sql=_T("select m_Address from bankUser where m_ID=")+str_ID;
	rs.Open(AFX_DB_USE_DEFAULT_TYPE,sql);
	rs.GetFieldValue(short(0),str);	//���ص�ǰ��¼ָ���ֶε�ֵ
	oneUser.m_sAddress=str;
	rs.Close();
	db.Close();


	INT_PTR nRes;	//���ڱ���domodal��������ֵ
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCreateDlg createDlg;
	createDlg.DoModal();
}

void CbankControlDlg::OnBnClickedcancelbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

