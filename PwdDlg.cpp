// PwdDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "PwdDlg.h"
#include "afxdialogex.h"


// CPwdDlg 对话框

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


// CPwdDlg 消息处理程序


void CPwdDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
}


void CPwdDlg::OnBnClickedButton1()//修改密码
{
	// TODO: 在此添加控件通知处理程序代码
	CString pwd;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(pwd);
	if(pwd=="")
	{
		MessageBox("请输入新的密码");
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
	MessageBox("密码修改成功");
}
