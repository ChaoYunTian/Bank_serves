// GetInfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Bank.h"
#include "GetInfoDlg.h"
#include "afxdialogex.h"
#include "ServerDlg.h"


// CGetInfoDlg �Ի���

IMPLEMENT_DYNAMIC(CGetInfoDlg, CDialogEx)

CGetInfoDlg::CGetInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGetInfoDlg::IDD, pParent)
{

}

CGetInfoDlg::~CGetInfoDlg()
{
}

void CGetInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CGetInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CGetInfoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CGetInfoDlg ��Ϣ�������


void CGetInfoDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(TRUE);
	CServerDlg dlg;
	dlg.DoModal();
}


BOOL CGetInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//��ʼ���б�

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_list.InsertColumn(0,"�˺�",LVCFMT_CENTER,100);
	m_list.InsertColumn(1,"���",LVCFMT_CENTER,100);
	m_list.InsertColumn(2,"ȡ��ʱ��",LVCFMT_CENTER,120);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	//��ʾȫ��ȡ����Ϣ
	showall();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

int CGetInfoDlg::read()//��ȡȡ����Ϣ��������
{
	int i=0;
	ifstream file;
	file.open("get.txt",ios::in);
	while(!file.eof())
	{
		file>>mm[i].id>>mm[i].pwd>>mm[i].money>>mm[i].date;
		i++;
	}
	i--;
	file.close();
	return i;
}

void CGetInfoDlg::showall()//��ʾ�����������
{
	for(int i =0;i<read();i++)
	{
		m_list.InsertItem(i,0);
		m_list.SetItemText(i,0,mm[i].id);
		CString str;
		str.Format("%f",mm[i].money);
		m_list.SetItemText(i,1,str);
		m_list.SetItemText(i,2,mm[i].date);
	}
}
