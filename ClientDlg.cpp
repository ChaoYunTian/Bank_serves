// ClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "ClientDlg.h"
#include "afxdialogex.h"
#include "NewDlg.h"
#include "SaveDlg.h"
#include "DeleteDlg.h"
#include "GetDlg.h"
#include "ManageDlg.h"


// CClientDlg �Ի���

IMPLEMENT_DYNAMIC(CClientDlg, CDialogEx)

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientDlg::IDD, pParent)
{

}

CClientDlg::~CClientDlg()
{
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &CClientDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CClientDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CClientDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CClientDlg ��Ϣ�������


void CClientDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(TRUE);
	CManageDlg dlg;//���ط������ѡ��ҳ
	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CClientDlg::OnCancel();
	CNewDlg dlg;//���뿪��ҳ
	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CClientDlg::OnCancel();
	CSaveDlg dlg;//������ҳ
	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CClientDlg::OnCancel();
	CDeleteDlg dlg;
	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CClientDlg::OnCancel();
	CGetDlg dlg;
	dlg.DoModal();

}
