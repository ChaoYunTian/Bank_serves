#pragma once

#include "Person.h"
#include "Save.h"
// CServerDlg 对话框

class CServerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CServerDlg)

public:
	CPerson person[20];
	CSave save[20];
	CServerDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CServerDlg();

// 对话框数据
	enum { IDD = IDD_SERVERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	int read();
	int readsave();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton8();
};
