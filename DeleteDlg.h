#pragma once
#include "Person.h"

// CDeleteDlg �Ի���

class CDeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteDlg)

public:
	CPerson person[20];
	CDeleteDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeleteDlg();

// �Ի�������
	enum { IDD = IDD_DELEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	int read();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
};
