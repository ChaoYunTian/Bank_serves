#pragma once


// CPwdDlg �Ի���

class CPwdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPwdDlg)

public:
	CPwdDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPwdDlg();

// �Ի�������
	enum { IDD = IDD_CHANGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
