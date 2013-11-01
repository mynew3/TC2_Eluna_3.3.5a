#ifndef TOUTF8_H

#define TOUTF8_H


/*
1.utf8字符串转std::string
*/
//--
std::string UTF8_To_string(const std::string & str) 
{ 
int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0); 

wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
memset(pwBuf, 0, nwLen * 2 + 2); 

MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen); 

int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL); 

char * pBuf = new char[nLen + 1]; 
memset(pBuf, 0, nLen + 1); 

WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL); 

std::string retStr = pBuf; 

delete []pBuf; 
delete []pwBuf; 

pBuf = NULL; 
pwBuf = NULL; 

return retStr; 
} 
////////////////////////////////////////////////////////////////////////// 


////////////////////////////////////////////////////////////////////////// 
//  [8/19/2009 Leezhm] 
//  translate ascii characters to utf-8 characters
/*
2.std::string转utf8字符串
转换过程：与1过程相反 
*/
//------------------------------------------------------------------------ 
std::string string_To_UTF8(const std::string & str) 
{ 
int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0); 

wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴 
ZeroMemory(pwBuf, nwLen * 2 + 2); 

::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen); 

int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL); 

char * pBuf = new char[nLen + 1]; 
ZeroMemory(pBuf, nLen + 1); 

::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL); 

std::string retStr(pBuf); 

delete []pwBuf; 
delete []pBuf; 

pwBuf = NULL; 
pBuf  = NULL; 

return retStr; 
} 

#endif
//////////////////////////////////////////////////////////////////////////