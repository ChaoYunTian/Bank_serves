// PwdDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "PwdDlg.h"
#include "afxdialogex.h"


// CPwdDlg �Ի���

IMPLEMENT_DYNAMIC(CPwdDlg, CDialogEx)

CPwdDlg::CPwdDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPwdDlg::IDD, pParent)
{

}

CPwdDlg::~CPwdDlg()
{
}

void CPwdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPwdDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CPwdDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CPwdDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPwdDlg ��Ϣ�������


void CPwdDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(TRUE);
}


void CPwdDlg::OnBnClickedButton1()//�޸�����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString pwd;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(pwd);
	if(pwd=="")
	{
		MessageBox("�������µ�����");
		return;
	}
	int i=0;
	ifstream file;
	file.open("admin.txt",ios::in);
	char id[10];
	char pp[10];
	while(!file.eof())
	{
		file>>id>>pp;
	
	}
	file.close();
	strcpy(pp,pwd);
	ofstream file1;
	file1.open("admin.txt",ios::ate);
	file1<<id<<"    "<<pwd<<endl;
	file1.close();
	MessageBox("�����޸ĳɹ�");
}
