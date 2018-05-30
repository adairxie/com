#include <cstring>
#include <cstdio>

class CMyString
{
public:
    CMyString(char* pData = NULL);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator =(const CMyString& str);

private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if(pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str)
{
    m_pData = str.m_pData;
}

CMyString::~CMyString()
{
    delete[] m_pData; 
}

CMyString& CMyString::operator =(const CMyString& str)
{

}

int main(int argc, char** argv)
{
    char *str = "hello";
    CMyString str1(str);
}
