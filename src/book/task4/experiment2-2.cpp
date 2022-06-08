#include <stdio.h>
#include "SqString.cpp"					//包含顺序串的基本运算函数
SqString Maxcomstr(SqString s,SqString t)
{	SqString str;
	int midx=0,mlen=0,tlen,i=0,j,k;		//用(midx,mlen)保存最大公共子串
	while (i<s.length)					//用i扫描串s
	{	j=0;							//用j扫描串t
		while (j<t.length)
		{	if (s.data[i]==t.data[j])	//找一子串,在s中下标为i,长度为tlen
			{	tlen=1;
				for (k=1;i+k<s.length && j+k<t.length 
						&& s.data[i+k]==t.data[j+k];k++)
					tlen++;
				if (tlen>mlen)			//将较大长度者赋给midx与mlen
				{	midx=i;
					mlen=tlen;
				}
				j+=tlen;				//继续扫描t中第j+tlen字符之后的字符
			}
			else j++;
		}
		i++;							//继续扫描s中第i字符之后的字符
	}
	for (i=0;i<mlen;i++)				//将最大公共子串复制到str中
		str.data[i]=s.data[midx+i];
	str.length=mlen;
	return str;							//返回最大公共子串
}
int main()
{
	SqString s,t,str;
	Assign(s,"aababcabcdabcde");
	Assign(t,"aabcd");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("求s、t的最大公共子串str\n");
	str=Maxcomstr(s,t);
	printf("str:");DispStr(str);
	DestroyStr(s);
	DestroyStr(t);
	DestroyStr(str);
    return 0;
}

