#pragma once


// TransferFailDlg �Ի���

class TransferFailDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TransferFailDlg)

public:
	TransferFailDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TransferFailDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "HomePage.h"