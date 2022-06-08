#include <stdio.h>
#include "SqString.cpp"					//����˳�򴮵Ļ������㺯��
SqString Maxcomstr(SqString s,SqString t)
{	SqString str;
	int midx=0,mlen=0,tlen,i=0,j,k;		//��(midx,mlen)������󹫹��Ӵ�
	while (i<s.length)					//��iɨ�贮s
	{	j=0;							//��jɨ�贮t
		while (j<t.length)
		{	if (s.data[i]==t.data[j])	//��һ�Ӵ�,��s���±�Ϊi,����Ϊtlen
			{	tlen=1;
				for (k=1;i+k<s.length && j+k<t.length 
						&& s.data[i+k]==t.data[j+k];k++)
					tlen++;
				if (tlen>mlen)			//���ϴ󳤶��߸���midx��mlen
				{	midx=i;
					mlen=tlen;
				}
				j+=tlen;				//����ɨ��t�е�j+tlen�ַ�֮����ַ�
			}
			else j++;
		}
		i++;							//����ɨ��s�е�i�ַ�֮����ַ�
	}
	for (i=0;i<mlen;i++)				//����󹫹��Ӵ����Ƶ�str��
		str.data[i]=s.data[midx+i];
	str.length=mlen;
	return str;							//������󹫹��Ӵ�
}
int main()
{
	SqString s,t,str;
	Assign(s,"aababcabcdabcde");
	Assign(t,"aabcd");
	printf("s:");DispStr(s);
	printf("t:");DispStr(t);
	printf("��s��t����󹫹��Ӵ�str\n");
	str=Maxcomstr(s,t);
	printf("str:");DispStr(str);
	DestroyStr(s);
	DestroyStr(t);
	DestroyStr(str);
    return 0;
}

