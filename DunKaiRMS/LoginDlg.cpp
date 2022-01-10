// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DunKaiRMS.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginDlg::IDD, pParent)
	, m_strUsername(_T("admin"))
	, m_strPassword(_T("123456"))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERNAME, m_strUsername);
	DDX_Text(pDX, IDC_PASSWORD, m_strPassword);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_LOGIN, &CLoginDlg::OnBnClickedBtnLogin)
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������

//ʲôʱ�������ֵ�͹���������ʲôʱ����ӿؼ��͹���������
//�ش��������Ҫ�Ļ�ȡ�ؼ��е���ֵ��ʱ�򣬿���ʹ����ֵ�͹�������
//��������ȡ�ؼ����ڵ�ʱ�򣬿���ʹ�ÿؼ��͹�������
//�пؼ��͹����������Ի�ȡ��ֵ��GetWindowText, GetDlgItemText����
//��������ֵ�͹������������ǲ����Ի�ȡ�ؼ��͹�������
//һ���ؼ�����ͬʱӵ����ֵ�͹��������Ϳؼ��͹�������


void CLoginDlg::OnBnClickedBtnLogin()
{
	UpdateData(TRUE);

	if (m_strUsername.IsEmpty() || m_strPassword.IsEmpty())
	{
		MessageBox(L"�û�����������Ϊ��.", L"��ܰ��ʾ", MB_ICONWARNING);
		return;
	}


	if (m_strUsername == L"admin" && m_strPassword == L"123456")
	{
		//�ɹ�
		EndDialog(IDOK);
	}
	else
	{
		//ʧ��
		MessageBox(L"��������û������������.", L"��ܰ��ʾ", MB_ICONERROR);
		return;
	}
}
