////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-10-02 22:58:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
void A(char *s)
{
    int len = strlen(s);
    char *p = s + len - 1;
    if (strchr(s, '.'))//判断这个字符串内是不是有'.';
    while (*p == '0') {*p= '\0';p--;}//让*p='\0',然后p--;
    if (*p == '.') *p = '\0';
}

int main(void)
{
    char *pa, *pb;
    char a[100024], b[100024];

    while (scanf("%s%s", &a, &b) != EOF)
    {
        pa = a; pb = b;
        while (*pa == '0') pa++;
        while (*pb == '0') pb++;
        A(pa); A(pb);
        puts(strcmp(pa, pb) ? "NO" : "YES");
    }

    return 0;
}
//先去掉前面多余的0;
//再去小数点后面多余的0(首先要保证有小数点)。
//如果小数点后面所有的数都去的掉了，还要同时去掉小数点。
			