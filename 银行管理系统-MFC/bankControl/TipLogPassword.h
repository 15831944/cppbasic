#pragma once


// CTipLogPassword �Ի���

class CTipLogPassword : public CDialogEx
{
	DECLARE_DYNAMIC(CTipLogPassword)

public:
	CTipLogPassword(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTipLogPassword();

// �Ի�������
	enum { IDD = IDD_TipLogPassword_Dlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
