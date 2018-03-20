#pragma once


// CTipLogPassword 对话框

class CTipLogPassword : public CDialogEx
{
	DECLARE_DYNAMIC(CTipLogPassword)

public:
	CTipLogPassword(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTipLogPassword();

// 对话框数据
	enum { IDD = IDD_TipLogPassword_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
