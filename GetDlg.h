#pragma once
#include "Person.h"
#include "save.h"

// CGetDlg �Ի���

class CGetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGetDlg)

public:
	CSave save[20];
	CPerson person[20];
	CGetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGetDlg();

// �Ի�������
	enum { IDD = IDD_GETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	int read();
	virtual BOOL OnInitDialog();
	CString savedate;
	int saveday;
	CString getdate(CString id);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
