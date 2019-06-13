
// BankDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Bank.h"
#include "BankDlg.h"
#include "afxdialogex.h"
#include "ManageDlg.h"
#include <fstream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBankDlg 对话框




CBankDlg::CBankDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBankDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBankDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CBankDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CBankDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBankDlg 消息处理程序

BOOL CBankDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBankDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBankDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBankDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBankDlg::OnBnClickedButton2()//退出
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(TRUE);
}


void CBankDlg::OnBnClickedButton1()//登录
{
	// TODO: 在此添加控件通知处理程序代码
	CString user,pwd;
	GetDlgItem(IDC_EDIT1)->GetWindowTextA(user);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(pwd);
	if(user==""||pwd=="")
	{
		MessageBox("账号或密码不能为空");
		return;
	}
	if(CheckUser(user,pwd))
	{
		CManageDlg dlg;
		dlg.DoModal();
	}
	else
	{
		MessageBox("账号或密码错误");
	}
}

bool CBankDlg::CheckUser(CString user,CString pwd)//判断管理员用户名密码
{
	int i=0;
	ifstream file;
	file.open("admin.txt",ios::in);//打开供读取文件
	char id[10];
	char pp[10];
	while(!file.eof())
	{
		file>>id>>pp;
		if(strcmp(user,id)==0&&strcmp(pwd,pp)==0)
		{
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}
