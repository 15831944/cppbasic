#pragma once


// DepositSuccessDlg �Ի���

class DepositSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DepositSuccessDlg)

public:
	DepositSuccessDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DepositSuccessDlg();

// �Ի�������
	enum { IDD = IDD_DepositSuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};


#include "HomePage.h"