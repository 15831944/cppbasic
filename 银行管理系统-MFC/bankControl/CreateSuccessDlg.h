#pragma once


// CreateSuccessDlg �Ի���

class CreateSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CreateSuccessDlg)

public:
	CreateSuccessDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CreateSuccessDlg();

// �Ի�������
	enum { IDD = IDD_CreateSuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int _newID;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#include "bankControlDlg.h"
