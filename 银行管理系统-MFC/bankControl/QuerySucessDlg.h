#pragma once


// QuerySucessDlg �Ի���

class QuerySucessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(QuerySucessDlg)

public:
	QuerySucessDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~QuerySucessDlg();

// �Ի�������
	enum { IDD = IDD_QuerySuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "HomePage.h"
