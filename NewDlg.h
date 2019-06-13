#pragma once


// CNewDlg 对话框
#include "Person.h"
class CNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNewDlg)

public:
	CPerson person[20];
	
	CNewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewDlg();

// 对话框数据
	enum { IDD = IDD_NEWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();
public:
	int readall();//读取全部账户信息
	bool check(CString id);//判断账号是否已经存在
	afx_msg void OnBnClickedButton7();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
