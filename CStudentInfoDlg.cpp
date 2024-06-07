// CStudentInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "lab4.h"
#include "afxdialogex.h"
#include "CStudentInfoDlg.h"
#include "lab4Dlg.h"


// CStudentInfoDlg 对话框

IMPLEMENT_DYNAMIC(CStudentInfoDlg, CDialogEx)

CStudentInfoDlg::CStudentInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_INFO_DIALOG, pParent)
{

}

CStudentInfoDlg::~CStudentInfoDlg()
{
}

void CStudentInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStudentInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStudentInfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CStudentInfoDlg 消息处理程序
BOOL CStudentInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//为Combe Box添加选项
	CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_DATE);
	if (pComboBox != nullptr)
	{
		// 添加选项到ComboBox
		pComboBox->AddString(_T("2005-6-1"));
		pComboBox->AddString(_T("2005-3-1"));
		pComboBox->AddString(_T("2005-9-9"));
		// 设置默认选中第一个选项
		pComboBox->SetCurSel(0);
	}

	CComboBox* pComboBox2 = (CComboBox*)GetDlgItem(IDC_COMBO_MAJ);
	if (pComboBox != nullptr)
	{
		pComboBox2->AddString(_T("软件工程"));
		pComboBox2->AddString(_T("自动化"));
		pComboBox2->AddString(_T("工业工程"));
		pComboBox2->SetCurSel(0);
	}
	
	return TRUE;  // 返回TRUE 除非你将焦点设置到控件
}



void CStudentInfoDlg::OnBnClickedOk()
{
	CString name, id, sex, birth, major;
	// 获取课程信息

	CString s1(_T("姓名："));
	CString s2(_T("学号："));
	CString s3(_T("出生年月："));
	CString s4(_T("所学专业："));
	
	GetDlgItemText(IDC_EDIT_NA, name);
	GetDlgItemText(IDC_EDIT_ID, id);
	GetDlgItemText(IDC_COMBO_MAJ, major);
	GetDlgItemText(IDC_COMBO_DATE, birth);
	
	Clab4Dlg* pParentDlg = (Clab4Dlg*)GetParent();
	
	pParentDlg->AddCourseInfo(s4 + major);
	pParentDlg->AddCourseInfo(s1 + name);
	pParentDlg->AddCourseInfo(s2 + id);
	pParentDlg->AddCourseInfo(s3 + birth);
	CButton* pCheck = (CButton*)GetDlgItem(IDC_RADIO1);
	if (pCheck->GetCheck() == BST_CHECKED)
	{
		CString str(_T("性别：男"));
		pParentDlg->AddCourseInfo(str);
	}
	if (pCheck->GetCheck() == BST_CHECKED)
	{
		CString str(_T("性别：女"));
		pParentDlg->AddCourseInfo(str);
	}
	
	CDialogEx::OnOK();
}
