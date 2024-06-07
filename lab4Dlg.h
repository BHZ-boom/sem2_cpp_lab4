
// lab4Dlg.h: 头文件
//

#pragma once


// Clab4Dlg 对话框
class Clab4Dlg : public CDialogEx
{
// 构造
public:
	Clab4Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LAB4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	int m_nRed;
	int m_nGreen;
	int m_nBlue;

	CSliderCtrl m_SliderGreen;
	CSliderCtrl m_SliderBlue;
	CScrollBar m_ScrollRed;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMThemeChangedScrollbarRed(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBnClickedButtonCourse();
	afx_msg void OnBnClickedButtonStudent();
	void AddCourseInfo(CString& courseInfo);
	CListBox m_ListBox;
};
