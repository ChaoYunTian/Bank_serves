#pragma once

#include "Person.h"
// CSaveDlg �Ի���

class CSaveDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSaveDlg)

public:
	CPerson person[20];
	CSaveDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSaveDlg();

// �Ի�������
	enum { IDD = IDD_SAVEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();

public:
	int read();
	bool check(CString id,CString pwd);

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit6();
};
