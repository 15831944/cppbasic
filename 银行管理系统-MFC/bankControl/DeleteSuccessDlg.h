#pragma once


// DeleteSuccessDlg �Ի���

class DeleteSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteSuccessDlg)

public:
	DeleteSuccessDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DeleteSuccessDlg();

// �Ի�������
	enum { IDD = IDD_DeleteSuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "bankControlDlg.h"