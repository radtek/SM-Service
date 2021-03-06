// LogProcessor.h: interface for the LogProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGPROCESSOR_H__2DAEF671_5EAD_412E_A60B_F1DC5E811B37__INCLUDED_)
#define AFX_LOGPROCESSOR_H__2DAEF671_5EAD_412E_A60B_F1DC5E811B37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class LogProcessor  
{
public:
	LogProcessor();
	LogProcessor(char* path);
	virtual ~LogProcessor();
public:
	//写日志
	BOOL printf(const char* txt,...);
private:
	//创建日志文件
	void MakeFileName(void);

private:
	//日志文件名
	char m_szFileName[512];
	//程序执行路径
	char* exe_path;

};


#endif // !defined(AFX_LOGPROCESSOR_H__2DAEF671_5EAD_412E_A60B_F1DC5E811B37__INCLUDED_)
