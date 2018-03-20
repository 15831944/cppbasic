#pragma once


// DeleteSuccessDlg 对话框

class DeleteSuccessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteSuccessDlg)

public:
	DeleteSuccessDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DeleteSuccessDlg();

// 对话框数据
	enum { IDD = IDD_DeleteSuccess_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#include "bankControlDlg.h"