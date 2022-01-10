// ModifyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DunKaiRMS.h"
#include "ModifyDlg.h"
#include "afxdialogex.h"


// CModifyDlg 对话框

IMPLEMENT_DYNAMIC(CModifyDlg, CDialogEx)

CModifyDlg::CModifyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CModifyDlg::IDD, pParent)
	, m_nWorkNum(0)
	, m_strName(_T(""))
	, m_nSex(0)
	, m_nAge(0)
	, m_bPaoniu(FALSE)
	, m_bPashan(FALSE)
	, m_bKsing(FALSE)
	, m_bGame(FALSE)
	, m_bBook(FALSE)
	, m_fTempSalary(0)
	, m_fRegularSalary(0)
	, m_joinTime(COleDateTime::GetCurrentTime())
	, m_officialTime(COleDateTime::GetCurrentTime())
	, m_leaveTime(COleDateTime::GetCurrentTime())
	, m_tel(_T(""))
	, m_strAddress(_T(""))
{

}

CModifyDlg::~CModifyDlg()
{
}

void CModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nWorkNum);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	DDX_Radio(pDX, IDC_RADIO1, m_nSex);
	DDX_Text(pDX, IDC_EDIT3, m_nAge);
	DDX_Check(pDX, IDC_CHECK1, m_bPaoniu);
	DDX_Check(pDX, IDC_CHECK2, m_bPashan);
	DDX_Check(pDX, IDC_CHECK3, m_bKsing);
	DDX_Check(pDX, IDC_CHECK4, m_bGame);
	DDX_Check(pDX, IDC_CHECK5, m_bBook);
	DDX_Control(pDX, IDC_COMBO1, m_department);
	DDX_Control(pDX, IDC_COMBO2, m_position);
	DDX_Text(pDX, IDC_EDIT4, m_fTempSalary);
	DDX_Text(pDX, IDC_EDIT6, m_fRegularSalary);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_joinTime);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER3, m_officialTime);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER2, m_leaveTime);
	DDX_Text(pDX, IDC_EDIT7, m_tel);
	DDX_Text(pDX, IDC_EDIT5, m_strAddress);
}


BEGIN_MESSAGE_MAP(CModifyDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CModifyDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &CModifyDlg::OnBnClickedBtnModify)
END_MESSAGE_MAP()


// CModifyDlg 消息处理程序


void CModifyDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}

//修改
void CModifyDlg::OnBnClickedBtnModify()
{
	//判断工号
	UpdateData(TRUE);
	if (m_nWorkNum == 0 || m_strName.IsEmpty())
	{
		MessageBox(L"请先填写工号或者姓名");
		return;
	}

	CString str;
	m_department.GetWindowText(str);
	m_strDepartment = str;

	m_position.GetWindowText(str);
	m_strPosition = str;

	//关闭窗口
	EndDialog(IDOK);
}


BOOL CModifyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_department.AddString(L"研发部");
	m_department.AddString(L"人事部");
	m_department.AddString(L"行政部");
	m_department.AddString(L"财务部");
	m_department.AddString(L"销售部");
	m_department.SetCurSel(0);

	m_position.AddString(L"C++工程师");
	m_position.AddString(L"Java工程师");
	m_position.AddString(L"Web工程师");
	m_position.AddString(L"大数据工程师");
	m_position.AddString(L"人事专员");
	m_position.AddString(L"行政专员");
	m_position.AddString(L"会计");
	m_position.AddString(L"销售");
	m_position.AddString(L"销售经理");

	//显示部门和职位
	m_department.SetWindowText(m_strDepartment);
	m_position.SetWindowText(m_strPosition);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
