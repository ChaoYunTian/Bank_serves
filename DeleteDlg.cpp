// DeleteDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "DeleteDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"

// CDeleteDlg 对话框

IMPLEMENT_DYNAMIC(CDeleteDlg, CDialogEx)

CDeleteDlg::CDeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeleteDlg::IDD, pParent)
{

}

CDeleteDlg::~CDeleteDlg()
{
}

void CDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CDeleteDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleteDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CDeleteDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CDeleteDlg 消息处理程序


void CDeleteDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
	CClientDlg dlg;//返回服务项目选择页
	dlg.DoModal();
}

int CDeleteDlg::read()//读取所有数据到类数组
{
	int i=0;
	ifstream file;
	file.open("user.txt",ios::in);
	while(!file.eof())
	{
		file>>person[i].id>>person[i].name>>person[i].pwd>>person[i].address>>person[i].pid>>person[i].date>>person[i].money>>person[i].status;
		i++;
	}
	i--;
	file.close();
	return i;
}


void CDeleteDlg::OnBnClickedButton2()//挂失之后改变status状态，重写user.txt
{
	// TODO: 在此添加控件通知处理程序代码
	CString id,pwd,pid;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(id);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	GetDlgItem(IDC_EDIT3)->GetWindowTextA(pid);
	if(id==""||pwd==""||pid=="")
	{
		MessageBox("挂失信息不能为空");
		return;
	}
	int num = read();
	bool isexist = false;
	ofstream file;
	file.open("user.txt",ios::ate);
	for(int i=0;i<num;i++)
	{
		if(strcmp(id,person[i].id)==0&&strcmp(pwd,person[i].pwd)==0&&strcmp(pid,person[i].pid)==0)
		{
			isexist = true;
			person[i].status = 1;
		}
		{
			file<<person[i].id<<"    "<<person[i].name<<"    "<<person[i].pwd<<"    "<<person[i].address<<"    "<<person[i].pid<<"    "<<person[i].date<<"    "<<person[i].money<<"    "<<person[i].status<<endl;
		}
	}
	file.close();
	if(isexist)
	{
		MessageBox("挂失成功");
	}
	else
	{
		MessageBox("挂失失败，请明确账号密码身份证号信息");
	}
}




void CDeleteDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
