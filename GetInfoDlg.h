#pragma once
#include "afxcmn.h"
#include "GetMoney.h"

// CGetInfoDlg �Ի���

class CGetInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGetInfoDlg)

public:
	CGetMoney mm[20];
	CGetInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGetInfoDlg();

// �Ի�������
	enum { IDD = IDD_GETINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	int read();
	void showall();
};
