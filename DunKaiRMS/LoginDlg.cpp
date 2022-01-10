// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DunKaiRMS.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 对话框

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


// CLoginDlg 消息处理程序

//什么时候添加数值型关联变量，什么时候添加控件型关联变量？
//回答：如果你想要的获取控件中的数值的时候，可以使用数值型关联变量
//如果你想获取控件窗口的时候，可以使用控件型关联变量
//有控件型关联变量可以获取数值（GetWindowText, GetDlgItemText），
//但是有数值型关联变量，我们不可以获取控件型关联变量
//一个控件可以同时拥有数值型关联变量和控件型关联变量


void CLoginDlg::OnBnClickedBtnLogin()
{
	UpdateData(TRUE);

	if (m_strUsername.IsEmpty() || m_strPassword.IsEmpty())
	{
		MessageBox(L"用户名或者密码为空.", L"温馨提示", MB_ICONWARNING);
		return;
	}


	if (m_strUsername == L"admin" && m_strPassword == L"123456")
	{
		//成功
		EndDialog(IDOK);
	}
	else
	{
		//失败
		MessageBox(L"您输入的用户名或密码错误.", L"温馨提示", MB_ICONERROR);
		return;
	}
}
