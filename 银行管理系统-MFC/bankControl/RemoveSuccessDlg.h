#pragma once


// RemoveSuccessDlg �Ի���

class RemoveSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RemoveSuccessDlg)

public:
	RemoveSuccessDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RemoveSuccessDlg();

// �Ի�������
	enum { IDD = IDD_RemoveSuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	double RemoveSuccess_Balance;
	afx_msg void OnBnClickedButton1();
};

#include "HomePage.h"