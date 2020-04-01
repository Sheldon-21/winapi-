
// winapi创建窗口View.h: Cwinapi创建窗口View 类的接口
//

#pragma once


class Cwinapi创建窗口View : public CView
{
protected: // 仅从序列化创建
	Cwinapi创建窗口View() noexcept;
	DECLARE_DYNCREATE(Cwinapi创建窗口View)

// 特性
public:
	Cwinapi创建窗口Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~Cwinapi创建窗口View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // winapi创建窗口View.cpp 中的调试版本
inline Cwinapi创建窗口Doc* Cwinapi创建窗口View::GetDocument() const
   { return reinterpret_cast<Cwinapi创建窗口Doc*>(m_pDocument); }
#endif

