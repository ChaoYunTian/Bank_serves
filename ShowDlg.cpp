// ShowDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "ShowDlg.h"
#include "afxdialogex.h"
#include "ServerDlg.h"


// CShowDlg �Ի���

IMPLEMENT_DYNAMIC(CShowDlg, CDialogEx)

CShowDlg::CShowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowDlg::IDD, pParent)
{

}

CShowDlg::~CShowDlg()
{
}

void CShowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CShowDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CShowDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CShowDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CShowDlg ��Ϣ�������


BOOL CShowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_list.InsertColumn(0,"�˺�",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"���",LVCFMT_CENTER,100);
	m_list.InsertColumn(2,"���ʱ��",LVCFMT_CENTER,120);
	m_list.InsertColumn(3,"����",LVCFMT_CENTER,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	showall();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

int CShowDlg::read()
{
	int i=0;
	ifstream file;
	file.open("save.txt",ios::in);
	while(!file.eof())
	{
		file>>save[i].id>>save[i].pwd>>save[i].money>>save[i].date>>save[i].days;
		i++;
	}
	i--;
	file.close();
	return i;
}

void CShowDlg::showall()
{
	for(int i =0;i<read();i++)
	{
		m_list.InsertItem(i,0);
		m_list.SetItemText(i,0,save[i].id);
		CString str;
		str.Format("%f",save[i].money);
		m_list.SetItemText(i,1,str);
		m_list.SetItemText(i,2,save[i].date);
		str.Format("%d",save[i].days);
		m_list.SetItemText(i,3,str);
	}
}


void CShowDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	CServerDlg dlg;
	dlg.DoModal();
}


void CShowDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	CServerDlg dlg;
	dlg.DoModal();
}
