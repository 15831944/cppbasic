#pragma once


// QueryDlg �Ի���

class QueryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QueryDlg)

public:
	QueryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~QueryDlg();

// �Ի�������
	enum { IDD = IDD_Query_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString message;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#include "QuerySucessDlg.h"
#include "HomePage.h"
