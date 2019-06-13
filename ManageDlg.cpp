// ManageDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "ManageDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"
#include "ServerDlg.h"

// CManageDlg �Ի���

IMPLEMENT_DYNAMIC(CManageDlg, CDialogEx)

CManageDlg::CManageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManageDlg::IDD, pParent)
{

}

CManageDlg::~CManageDlg()
{
}

void CManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CManageDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CManageDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CManageDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CManageDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CManageDlg ��Ϣ�������


void CManageDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(TRUE);
}


void CManageDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CManageDlg::OnCancel();
	CClientDlg dlg;
	dlg.DoModal();
}


void CManageDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CManageDlg::OnCancel();
	CServerDlg dlg;
	dlg.DoModal();
}
