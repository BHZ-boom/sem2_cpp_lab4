// CCourseInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "lab4.h"
#include "afxdialogex.h"
#include "CCourseInfoDlg.h"
#include "lab4Dlg.h"


// CCourseInfoDlg 对话框

IMPLEMENT_DYNAMIC(CCourseInfoDlg, CDialogEx)

CCourseInfoDlg::CCourseInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COURSE_INFO_DIALOG, pParent)
{

}


BOOL CCourseInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//为Combe Box添加选项
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_TYPE);
	if (pComboBox != nullptr)
	{
		// 添加选项到ComboBox
		pComboBox->AddString(_T("专修"));
		pComboBox->AddString(_T("选修"));
		pComboBox->AddString(_T("不修"));
		// 设置默认选中第一个选项
		pComboBox->SetCurSel(0);
	}

	CComboBox* pComboBox2 = (CComboBox*)GetDlgItem(IDC_COMBO_MAJOR);
	if (pComboBox != nullptr)
	{
		pComboBox2->AddString(_T("软件工程"));
		pComboBox2->AddString(_T("自动化"));
		pComboBox2->AddString(_T("工业工程"));
		pComboBox2->SetCurSel(0);
	}
	//为Spin Control添加范围
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);
	pSpin->SetRange(1, 8);  // 设置数值范围为0到100
	pSpin->SetPos(3);        // 设置初始位置为50


	return TRUE;  // 返回TRUE 除非你将焦点设置到控件
}

CCourseInfoDlg::~CCourseInfoDlg()
{
}

void CCourseInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCourseInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCourseInfoDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_MAJOR, &CCourseInfoDlg::OnCbnSelchangeComboMajor)
END_MESSAGE_MAP()


// CCourseInfoDlg 消息处理程序

void CCourseInfoDlg::OnBnClickedOk()
{
	CString courseInfo, courseNum, major, type, 
	semester, hours, score;
	// 获取课程信息
	CString s1(_T("课程号："));
	CString s2(_T("课程名称："));
	CString s3(_T("所属专业："));
	CString s4(_T("课程类型："));
	CString s5(_T("开课学期："));
	CString s6(_T("课时数："));
	CString s7(_T("学分："));
	GetDlgItemText(IDC_EDIT_NUM, courseInfo);
	GetDlgItemText(IDC_EDIT_NAME, courseNum);
	GetDlgItemText(IDC_COMBO_MAJOR, major);
	GetDlgItemText(IDC_COMBO_TYPE, type);
	GetDlgItemText(IDC_EDIT_SEME, semester);
	GetDlgItemText(IDC_EDIT_HOURS, hours);
	GetDlgItemText(IDC_EDIT_SCORE, score);
	Clab4Dlg* pParentDlg = (Clab4Dlg*)GetParent();
	pParentDlg->AddCourseInfo(s1 + courseInfo);
	pParentDlg->AddCourseInfo(s2 + courseNum);
	pParentDlg->AddCourseInfo(s3 + major);
	pParentDlg->AddCourseInfo(s4 + type);
	pParentDlg->AddCourseInfo(s5 + semester);
	pParentDlg->AddCourseInfo(s6 + hours);
	pParentDlg->AddCourseInfo(s7 + score);
	EndDialog(IDOK);
}

void Clab4Dlg::AddCourseInfo(CString& courseInfo) {
	m_ListBox.AddString(courseInfo);
}















void CCourseInfoDlg::OnCbnSelchangeComboMajor()
{
	// TODO: 在此添加控件通知处理程序代码
}
