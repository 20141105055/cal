
// CALDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CAL.h"
#include "CALDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCALDlg �Ի���




CCALDlg::CCALDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCALDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_str = _T("");
	m_str1 = _T("");
	m_str2 = _T("");
}

void CCALDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
	DDX_Text(pDX, IDC_EDIT2, m_str1);
	DDX_Text(pDX, IDC_EDIT3, m_str2);
}

BEGIN_MESSAGE_MAP(CCALDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, &CCALDlg::OnClicked0)
	ON_BN_CLICKED(IDC_1, &CCALDlg::OnClicked1)
	ON_BN_CLICKED(IDC_2, &CCALDlg::OnClicked2)
	ON_BN_CLICKED(IDC_3, &CCALDlg::OnClicked3)
	ON_BN_CLICKED(IDC_4, &CCALDlg::OnClicked4)
	ON_BN_CLICKED(IDC_5, &CCALDlg::OnClicked5)
	ON_BN_CLICKED(IDC_6, &CCALDlg::OnClicked6)
	ON_BN_CLICKED(IDC_7, &CCALDlg::OnClicked7)
	ON_BN_CLICKED(IDC_8, &CCALDlg::OnClicked8)
	ON_BN_CLICKED(IDC_9, &CCALDlg::OnClicked9)
	ON_BN_CLICKED(IDC_Add, &CCALDlg::OnClickedAdd)
	ON_BN_CLICKED(IDC_Cut, &CCALDlg::OnClickedCut)
	ON_BN_CLICKED(IDC_Ride, &CCALDlg::OnClickedRide)
	ON_BN_CLICKED(IDC_Divide, &CCALDlg::OnClickedDivide)
	ON_BN_CLICKED(IDC_Equal, &CCALDlg::OnClickedEqual)
	ON_BN_CLICKED(IDC_Dot, &CCALDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_Percent, &CCALDlg::OnBnClickedPercent)
	ON_BN_CLICKED(IDC_1Dividex, &CCALDlg::OnBnClicked1dividex)
	ON_BN_CLICKED(IDC_C, &CCALDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_Backspace, &CCALDlg::OnBnClickedBackspace)
	ON_BN_CLICKED(IDC_CE, &CCALDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_Sqart, &CCALDlg::OnBnClickedSqart)
	ON_BN_CLICKED(IDC_Madd, &CCALDlg::OnBnClickedMadd)
	ON_BN_CLICKED(IDC_MR, &CCALDlg::OnBnClickedMr)
	ON_BN_CLICKED(IDC_MC, &CCALDlg::OnBnClickedMc)
END_MESSAGE_MAP()


// CCALDlg ��Ϣ�������

BOOL CCALDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCALDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCALDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCALDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCALDlg::OnClicked0()
{
	
	UpdateData(true);
	m_str = m_str+L"0";
	m_str1 = m_str1+L"0";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked1()
{
	UpdateData(true);
	m_str = m_str+L"1";
	m_str1 = m_str1+L"1";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked2()
{
	UpdateData(true);
	m_str = m_str+L"2";
	m_str1 = m_str1+L"2";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked3()
{
	UpdateData(true);
	m_str = m_str1+L"3";
	m_str1 = m_str+L"3";
	UpdateData(false);
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked4()
{
	UpdateData(true);
	m_str = m_str+L"4";	
	m_str1 = m_str1+L"4";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked5()
{
	UpdateData(true);
	m_str = m_str+L"5";
	m_str1 = m_str1+L"5";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked6()
{
	UpdateData(true);
	m_str = m_str+L"6";
	m_str1 = m_str1+L"6";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked7()
{
	UpdateData(true);
	m_str = m_str+L"7";
	m_str1 = m_str1+L"7";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked8()
{
	UpdateData(true);
	m_str = m_str+L"8";
	m_str1 = m_str1+L"8";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClicked9()
{
	UpdateData(true);
	m_str = m_str+L"9";
	m_str1 = m_str1+L"9";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClickedAdd()
{
	UpdateData(true);
	
	UpdateData(false);
	UpdateData(true);
	flag=1;
	temp = _ttof(m_str);
	m_str="";
	temp=_ttof(m_str1);
	m_str1=m_str1+L"+";
	UpdateData(false);// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClickedCut()
{
	
	UpdateData(true);
	flag=2;
	temp = _ttof(m_str);
	m_str="";
	temp=_ttof(m_str1);
	m_str1=m_str1+L"-";
	UpdateData(false);// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClickedRide()
{
	UpdateData(true);
	flag=3;
	temp = _ttof(m_str);
	m_str="";
	temp = _ttof(m_str1);
	m_str1=m_str1+L"*";
	UpdateData(false);// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClickedDivide()
{
	UpdateData(true);
	flag=4;
	temp = _ttof(m_str);
	m_str="";
	temp=_ttof(m_str1);
	m_str1=m_str1+L"/";
	UpdateData(false);

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnClickedEqual()
{
	
	if(flag==1)
	{
		UpdateData(true);
		temp = temp+_ttof(m_str);
	}	
	if(flag==2)
	{
		UpdateData(true);
		temp = temp- _ttof(m_str);
	}
	if(flag==3)
	{
		UpdateData(true);
		temp = temp*_ttof(m_str);
	}
	if(flag==4)
	{
		UpdateData(true);
		if( _ttof(m_str)==0)
		{
			m_str="error";
		}
		else
		{
			temp =temp / _ttof(m_str);
		}
	}
	if(flag==5)
	{
	    UpdateData(true);
		temp=temp/100;
	}
	if(flag==6)
	{
	    UpdateData(true);
		temp=1/temp;
	}
	if(flag==7)
	{
		UpdateData(true);
		temp=sqrt(temp);
	}
	if(flag==8)
	{
		UpdateData(true);
		mermory=0;
		mermory=mermory+temp;
	}
	if(flag==9)
	{
        UpdateData(true);
		temp=mermory;
	}
	while(m_str.Right(1)=="0")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	    UpdateData(false);	
    }
	m_str.Format(L"%lf",temp);
	check(m_str);
	UpdateData(false);// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CCALDlg::check(CString &s)
{
	while(s.Right(1)=="0")
		s.Delete(s.GetLength()-1,1);
}


void CCALDlg::OnBnClickedDot()
{
	UpdateData(true);
	if(m_str.Find(L".")==-1)
		m_str=m_str+L".";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnBnClickedPercent()
{
	UpdateData(true);
	flag=5;
	temp=_ttof(m_str);
	m_str= "";
	temp = _ttof(m_str1);
	m_str1 =m_str1+L"%";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}





void CCALDlg::OnBnClicked1dividex()
{
	UpdateData(true);
	flag=6;
	temp = _ttof(m_str);
	m_str="";
	UpdateData(false);// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnBnClickedC()
{
	UpdateData(true);
	m_str="0.";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnBnClickedBackspace()
{
	m_str.Delete(m_str.GetLength()-1,1);
    UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnBnClickedCe()
{
	UpdateData(true);
	m_str="";
	m_str1="";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnBnClickedSqart()
{
	flag=7;
	UpdateData(true);
	temp = _ttof(m_str);
	m_str ="";
	temp = _ttof(m_str1);
	m_str1 =m_str1+L"sqrt";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnBnClickedMadd()
{
	UpdateData(true);
	flag=8;
	//m_str2=m_str;
	temp = _ttof(m_str1);
	x=0;
	x++;
	if(x=1)
	{
		m_str2="";
		m_str2 = m_str2+L"M+";
	}
	m_str1="";
	m_str="";
	UpdateData(false);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCALDlg::OnBnClickedMr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	flag=9;
	m_str1="";
	check(m_str);
	UpdateData(true);
	m_str.Format(L"%lf",temp);
}


void CCALDlg::OnBnClickedMc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_str2="";
	UpdateData(false);
}
