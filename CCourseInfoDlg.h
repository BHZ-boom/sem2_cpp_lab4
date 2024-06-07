#pragma once
#include "afxdialogex.h"


// CCourseInfoDlg 对话框

class CCourseInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCourseInfoDlg)

public:
	CCourseInfoDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCourseInfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSE_INFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnCbnSelchangeComboMajor();
};
