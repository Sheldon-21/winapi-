
// winapi创建窗口View.cpp: Cwinapi创建窗口View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "winapi创建窗口.h"
#endif

#include "winapi创建窗口Doc.h"
#include "winapi创建窗口View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cwinapi创建窗口View

IMPLEMENT_DYNCREATE(Cwinapi创建窗口View, CView)

BEGIN_MESSAGE_MAP(Cwinapi创建窗口View, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cwinapi创建窗口View 构造/析构

Cwinapi创建窗口View::Cwinapi创建窗口View() noexcept
{
	// TODO: 在此处添加构造代码

}

Cwinapi创建窗口View::~Cwinapi创建窗口View()
{
}

BOOL Cwinapi创建窗口View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cwinapi创建窗口View 绘图

void Cwinapi创建窗口View::OnDraw(CDC* /*pDC*/)
{
	Cwinapi创建窗口Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void Cwinapi创建窗口View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cwinapi创建窗口View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cwinapi创建窗口View 诊断

#ifdef _DEBUG
void Cwinapi创建窗口View::AssertValid() const
{
	CView::AssertValid();
}

void Cwinapi创建窗口View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cwinapi创建窗口Doc* Cwinapi创建窗口View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cwinapi创建窗口Doc)));
	return (Cwinapi创建窗口Doc*)m_pDocument;
}
#endif //_DEBUG


// Cwinapi创建窗口View 消息处理程序
