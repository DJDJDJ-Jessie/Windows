// FrameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DunKaiRMS.h"
#include "FrameDlg.h"
#include "afxdialogex.h"


// CFrameDlg 对话框

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


// CFrameDlg 消息处理程序


void CFrameDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


BOOL CFrameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, L"工号", LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, L"姓名", LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, L"性别", LVCFMT_LEFT, 80);
	m_list.InsertColumn(3, L"年龄", LVCFMT_LEFT, 80);
	m_list.InsertColumn(4, L"兴趣爱好", LVCFMT_LEFT, 150);
	m_list.InsertColumn(5, L"部门", LVCFMT_LEFT, 120);
	m_list.InsertColumn(6, L"职位", LVCFMT_LEFT, 120);
	m_list.InsertColumn(7, L"试用薪资", LVCFMT_LEFT, 80);
	m_list.InsertColumn(8, L"转正薪资", LVCFMT_LEFT, 80);
	m_list.InsertColumn(9, L"入职时间", LVCFMT_LEFT, 120);
	m_list.InsertColumn(10, L"转正时间", LVCFMT_LEFT, 120);
	m_list.InsertColumn(11, L"离职时间", LVCFMT_LEFT, 120);
	m_list.InsertColumn(12, L"联系电话", LVCFMT_LEFT, 100);
	m_list.InsertColumn(13, L"家庭住址", LVCFMT_LEFT, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CFrameDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_list.GetSafeHwnd())
	{
		m_list.MoveWindow(0, 0, cx, cy);
	}
}
