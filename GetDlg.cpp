// GetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "GetDlg.h"
#include "afxdialogex.h"
#include "ClientDlg.h"


// CGetDlg 对话框

IMPLEMENT_DYNAMIC(CGetDlg, CDialogEx)

CGetDlg::CGetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetDlg::IDD, pParent)
{

}

CGetDlg::~CGetDlg()
{
}

void CGetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &CGetDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CGetDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CGetDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CGetDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CGetDlg::OnEnChangeEdit2)
END_MESSAGE_MAP()


// CGetDlg 消息处理程序


void CGetDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
	CClientDlg dlg;
	dlg.DoModal();
}


void CGetDlg::OnBnClickedButton3()//取款
{
	// TODO: 在此添加控件通知处理程序代码
	CString user,pwd,money,name,id,date;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	GetDlgItem(IDC_EDIT4)->GetWindowTextA(money);
	GetDlgItem(IDC_EDIT7)->GetWindowTextA(name);
	GetDlgItem(IDC_EDIT8)->GetWindowTextA(id);
	GetDlgItem(IDC_EDIT9)->GetWindowTextA(date);
	if(user==""||pwd==""||money==""||name==""||id==""||date=="")
	{
		MessageBox("取款信息不能为空");
		return;
	}

	//时间比较算法
	CString year = date.Left(4);
	CString day = date.Right(2);
	CString month = date.Mid(4,2);
	int y = atoi(year);
	int m = atoi(month);
	int d = atoi(day);

	getdate(user);

	CString year1 = savedate.Left(4);
	CString day1 = savedate.Right(2);
	CString month1 = savedate.Mid(4,2);
	int y1 = atoi(year1);
	int m1 = atoi(month1);
	int d1 = atoi(day1);


	CString str;
	str.Format("%d",(y-y1)*365+(m-m1)*30+(d-d1));//计算时间

	str.Format("%d",saveday);//设置时间

	if((y-y1)*365+(m-m1)*30+(d-d1)<saveday)
	{
		MessageBox("该账号尚未当期,将按照活期利息进行提款");
	}


	//更改余额
	int num = read();
	ofstream file;
	file.open("user.txt",ios::ate);
	for(int i=0;i<num;i++)
	{
		if(strcmp(user,person[i].id)==0)
		{
			if(atoi(money)>person[i].money)
			{
				MessageBox("账户余额不足");
				return;
			}
			else
			{
				person[i].money = person[i].money - atoi(money);
			}
		}
		{
			file<<person[i].id<<"    "<<person[i].name<<"    "<<person[i].pwd<<"    "<<person[i].address<<"    "<<person[i].pid<<"    "<<person[i].date<<"    "<<person[i].money<<"    "<<person[i].status<<endl;
	
		}
	}
	file.close();
	MessageBox("取款成功");
	//记录取款记录
	ofstream file1;
	file1.open("get.txt",ios::app);
	file1<<user<<"   "<<pwd<<"   "<<money<<"    "<<date<<endl;
	file1.close();
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
}


void CGetDlg::OnBnClickedButton1()//账号验证
{
	// TODO: 在此添加控件通知处理程序代码
	CString user,pwd;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	if(user==""||pwd=="")
	{
		MessageBox("账号信息不能为空");
		return;
	}
	for(int i =0 ;i<read();i++)
	{
		if(strcmp(user,person[i].id)==0&&strcmp(person[i].pwd,pwd)==0&&person[i].status==0)
		{
			MessageBox("验证成功");
			GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);//启用编辑框
			return;
		}
	}
	MessageBox("验证失败");
}

int CGetDlg::read()//读取全部数据到类数组
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
	return i;
}


BOOL CGetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);//编辑框禁用

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

CString CGetDlg::getdate(CString id)//获取存款日期
{
	int i=0;
	ifstream file;
	file.open("save.txt",ios::in);
	while(!file.eof())
	{
		file>>save[i].id>>save[i].pwd>>save[i].money>>save[i].date>>save[i].days;
		if(strcmp(save[i].id,id)==0)
		{

			savedate.Format("%s",save[i].date);

			saveday = save[i].days;

		}
		i++;
	}
	i--;
	file.close();
	return "";
}


void CGetDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CGetDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
