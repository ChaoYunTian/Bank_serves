#pragma once


// CNewDlg �Ի���
#include "Person.h"
class CNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNewDlg)

public:
	CPerson person[20];
	
	CNewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewDlg();

// �Ի�������
	enum { IDD = IDD_NEWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();
public:
	int readall();//��ȡȫ���˻���Ϣ
	bool check(CString id);//�ж��˺��Ƿ��Ѿ�����
	afx_msg void OnBnClickedButton7();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
