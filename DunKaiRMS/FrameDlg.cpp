// FrameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DunKaiRMS.h"
#include "FrameDlg.h"
#include "afxdialogex.h"


// CFrameDlg �Ի���

IMPLEMENT_DYNAMIC(CFrameDlg, CDialogEx)

CFrameDlg::CFrameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFrameDlg::IDD, pParent)
{

}

CFrameDlg::~CFrameDlg()
{
}

void CFrameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_list);
}


BEGIN_MESSAGE_MAP(CFrameDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFrameDlg::OnBnClickedOk)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CFrameDlg ��Ϣ�������


void CFrameDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


BOOL CFrameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, L"����", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"����", LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, L"�Ա�", LVCFMT_LEFT, 80);
	m_list.InsertColumn(3, L"����", LVCFMT_LEFT, 80);
	m_list.InsertColumn(4, L"��Ȥ����", LVCFMT_LEFT, 150);
	m_list.InsertColumn(5, L"����", LVCFMT_LEFT, 120);
	m_list.InsertColumn(6, L"ְλ", LVCFMT_LEFT, 120);
	m_list.InsertColumn(7, L"����н��", LVCFMT_LEFT, 80);
	m_list.InsertColumn(8, L"ת��н��", LVCFMT_LEFT, 80);
	m_list.InsertColumn(9, L"��ְʱ��", LVCFMT_LEFT, 120);
	m_list.InsertColumn(10, L"ת��ʱ��", LVCFMT_LEFT, 120);
	m_list.InsertColumn(11, L"��ְʱ��", LVCFMT_LEFT, 120);
	m_list.InsertColumn(12, L"��ϵ�绰", LVCFMT_LEFT, 100);
	m_list.InsertColumn(13, L"��ͥסַ", LVCFMT_LEFT, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CFrameDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_list.GetSafeHwnd())
	{
		m_list.MoveWindow(0, 0, cx, cy);
	}
}
