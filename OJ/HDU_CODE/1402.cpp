////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2010-12-16 23:14:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1402
////Problem Title: 
////Run result: Accept
////Run time:828MS
////Run memory:3636KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstring>

#define MAXLEN 100001
#define BASE_DIGIT 9
#define BASE 1000000000
#define IsDigit(c) (('0'<=(c))&&((c)<='9'))
#define PRINTCHAR ("%09d")
using namespace std;

/*!*/
void del0(char *s){
int zero=0,len=strlen(s),i;
for(i=0;i<len-1;i++){
if(s[i]!='0')break;
zero++;
}
for(i=0;i<len-zero;i++)
s[i]=s[i+zero];
s[i]=0;
}
short CMP(const int *a,const int *b){
    if(a[0]<b[0])
        return -1;
    if(a[0]>b[0])
        return 1;
    for(int i=a[0];i>0;i--)
    {
        if(a[i]<b[i])
            return -1;
        if(a[i]>b[i])
            return 1;
    }
    return 0;
}
/*!*/
void ADD(const int *a,const int *b,int *c){
    memset(c,0,sizeof(int)*MAXLEN);
    int la=a[0],lb=b[0],d=0;
    c[0]=(la>lb?la:lb)+1;
    for(int i=1;i<=c[0];i++)
    {
        c[i]= a[i]+b[i]+d;
        d=0;
        if(c[i]>=BASE)
        {
            d=1;
            c[i]-=BASE;
        }
    }
    while(c[0]>1&&c[c[0]]==0)
        
        
        c[0]--;
}
/*!*/
void SUB(const int *a,const int *b,int *c){
    memset(c,0,sizeof(int)*MAXLEN);
    c[0]=a[0];
    int d=0;
    for(int i=1;i<=a[0];i++)
    {
        c[i]=a[i]-b[i]-d;
        d=0;
        if(c[i]<0)
        {
            c[i]+=BASE;
            d++;
        }
    }
    while(c[0]>1&&c[c[0]]==0)
        c[0]--;
    return ;
}
void MUL(const int *a,const int *b,int *c){
    memset(c,0,sizeof(int)*MAXLEN);
    __int64 t=0;
    int l = a[0]+b[0]+1;
    c[0]=l;
    for(int i=1;i<=a[0];i++)
        for(int j=1;j<=b[0];j++)
        {
            t=(__int64)c[i+j-1]+(__int64)a[i]*(__int64)b[j];
            c[i+j-1]=t%BASE;
            c[i+j] += t/BASE;
        }
        while(c[0]>1&&c[c[0]]==0)
            c[0]--;
}
void MUL(const int *a,int b,int *c){
    memset(c,0,sizeof(int)*MAXLEN);
    int l = a[0] + 1 ;
    __int64 t
        
        =0;
    for(int i=1;i<=l;i++)
    {
        t = (__int64)a[i]*b + (__int64)c[i];
        c[i+1] = t/BASE;
        c[i] = (t%BASE);
    }
    while(c[l]==0&&l>1) l--;
    c[0]=l;
}

void DIV(const int *a,const int *b,int *c,int *d)
{
    memset(c,0,sizeof(int)*MAXLEN);memset(d,0,sizeof(int)*MAXLEN);
    int *t1 = new int[MAXLEN],*t2 = new int[MAXLEN];
    int la=a[0],lb=b[0],ld=0,min=0,max=0,mid=0,l = la;
    double tdmin=0,tdmax=0,tbmin=b[lb],tbmax=tbmin+1.0;
    if(lb>1)
    {
        tbmin = tbmin*(double)BASE + (double)b[lb-1];
        tbmax = tbmin+1.0;
    }
    for(int i=l;i>0;i--)
    {
        int j;
        for(j=d[0];j>=1;j--)d[j+1]=d[j];d[1]=a[i];
        if(d[d[0]+1]!=0)d[0]++;
        if(CMP(d,b)<0)
            continue;
        ld = d[0];
        tdmin = d[ld];
        j = 1;
        
        
        while(tdmin<tbmin)
        {
            tdmin = tdmin*BASE + d[ld-j];
            j++;
        }
        tdmax = tdmin+1.0;
        max =(int)(tdmax/tbmin)+1;min =(int)(tdmin/tbmax)-1;
        while(true)
        {
            mid = (min+max)/2;
            MUL(b,mid,t1);
            if(CMP(d,t1)<0){max = mid-1;continue;}
            SUB(d,t1,t2);
            if(CMP(t2,b)>=0){min = mid+1;continue;}
            break;
        }
        c[i]=mid;
        memcpy(d,t2,sizeof(int)*MAXLEN);
    }
    delete []t1;delete []t2;
    while(c[l]==0&&l>1) l--;
    c[0]=l;
}

class HarInt
{/*超长大整数类，支持正负大整数的基本运算*/
private:
    int numb[MAXLEN];//具体数字，第0位表示数字长度，第一位及以后分别表示数字的高位至低位
    bool flag;
    char instr[MAXLEN*BASE_DIGIT+1];
public:
    HarInt(){}/*默认构造函数*/
    ~HarInt(){}/*析构函数*/

    /*!*/
    int Parse(char *s)
    {/*将一个字符串转化为一个长整数*/
        del0(s);//去前导零
        if(s[0]=='0')return 2;
        clear();int l=strlen(s),i=0,nl=1;flag = true;//默认为非负数
        if(s[0]=='-'){i++;flag = false;}//为负数，数值从第2位开始
        for(int j=l-1;j>=i;j-=BASE_DIGIT)
        {//从高位至低位一位一位转
            int n=0,ten=1;
            for(int k=0;(k<BASE_DIGIT&&j-k>=i);k++)
            {
                if(!IsDigit(s[j-k])){clear();return 0;}//含非数字字符，赋值失败
                n+=(s[j-k]-'0')*ten;ten*=10;
            }
            numb[nl++]=n;//从第一位开始给数组numb赋值，第0位预留为数字长
        }
        nl--;while(numb[nl]==0&&nl>1)nl--;//消去前导零
        numb[0]=nl;return 1;//赋值成功
    }

    /*!*/
    void clear(){memset(numb,0,sizeof(int)*MAXLEN);}/*将所有数位置为零*/
    /*!*/
    void Parse(const HarInt hi){memcpy(numb,hi.numb,sizeof(int)*MAXLEN);flag = hi.flag;}/*通过一个复制已知对象赋值*/
    /*!*/
    void value(const int a){int t=a;flag=true;if(t<0){flag=false;t*=-1;}numb[0]=1;numb[1]=t;}/*通过一个较小的整形数赋值*/
    int operator[](int i){return numb[i];}/*重载[]，访问第i位数字*/
    bool Flag(){return flag;}/*获取当前数的符号*/
    bool isZero(){return (numb[0]==1&&numb[1]==0);}
    /*!*/
    int Get(){if(scanf("%s",instr)==EOF)return EOF;return Parse(instr);}
    /*!*/
    void print(char s){if(!flag)putchar('-');printf("%d",numb[numb[0]]);for(int i=numb[0]-1;i>=1;i--)printf(PRINTCHAR,numb[i]);putchar(s);}
    friend short HarIntCmp(HarInt,HarInt);
    /*!*/
    HarInt& operator+=(const HarInt& a){
        int *n = new int[MAXLEN];
        memcpy(n,numb,sizeof(int)*MAXLEN);
        if(flag==a.flag)
            ADD(n,a.numb,numb);
        else{
            int c = CMP(n,a.numb);
            if(c==0){numb[0]=1;numb[1]=0;flag=true;}//|a|==|b|&&a*b<0则a-b=0;
            if(c<0){SUB(a.numb,n,numb);flag=a.flag;}//|a|<|b|
            else SUB(n,a.numb,numb);
        }
        delete []n;n=NULL;
        return *this;
    }
    HarInt& operator-=(const HarInt& a){
        int *n = new int[MAXLEN];
        memcpy(n,numb,sizeof(int)*MAXLEN);
        if(flag!=a.flag)
            ADD(n,a.numb,numb);
        else{
            int c = CMP(n,a.numb);
            if(c==0){numb[0]=1;numb[1]=0;flag=true;}
            if(c<0){SUB(a.numb,n,numb);flag=!flag;}
            else SUB(n,a.numb,numb);
        }
        delete []n;n=NULL;
        return *this;
    }
    HarInt& operator*=(const HarInt& a){
        int *n = new int[MAXLEN];
        memcpy(n,numb,sizeof(int)*MAXLEN);
        MUL(n,a.numb,numb);
        delete []n;n=NULL;
        flag = (flag==a.flag);
        return *this;
    }
    
    HarInt& operator*=(int x){
        int *n = new int[MAXLEN];
        memcpy(n,numb,sizeof(int)*MAXLEN);
        MUL(n,x,numb);
        delete []n;n=NULL;
        flag = (flag==(x>0));
        return *this;
    }
    HarInt& operator/=(const HarInt& a){
        int *n1 = new int[MAXLEN],*n2 = new int[MAXLEN];
        memcpy(n1,numb,sizeof(int)*MAXLEN);
        DIV(n1,a.numb,numb,n2);
        delete []n1;delete []n2;
        flag = (flag==a.flag);
        return *this;
    }
    HarInt& operator%=(const HarInt& a){
        int *n1 = new int[MAXLEN],*n2 = new int[MAXLEN];
        memcpy(n1,numb,sizeof(int)*MAXLEN);
        DIV(n1,a.numb,n2,numb);
        delete []n1;delete []n2;
        flag = (flag==a.flag);
        return *this;
    }
};
short HarIntCmp(HarInt a,HarInt b){
    if(a.Flag()>b.Flag())//正数恒大于负数
        return 1;
    if(a.Flag()<b.Flag())//负数恒小于正数
        return -1;
    if(a[0]<b[0])//数位少的数值小，根据符号判断大小
        return ((!a.Flag())?1:-1);
    if(a[0]>b[0])
        return (a.Flag()?1:-1);
    for(int i=a[0];i>=1;i--)
    {
        if(a[i]<b[i])
            return ((!a.Flag())?1:-1);
        if(a[i]>b[i])
            return (a.Flag()?1:-1);
    }
    return 0;
}

bool operator<(HarInt a,HarInt b){return (HarIntCmp(a,b)<0);}
bool operator>(HarInt a,HarInt b){return (HarIntCmp(a,b)>0);}
bool operator==(HarInt a,HarInt b){return (HarIntCmp(a,b)==0);}
bool operator!=(HarInt a,HarInt b){return (HarIntCmp(a,b)!=0);}
bool operator<=(HarInt a,HarInt b){return (HarIntCmp(a,b)<=0);}
bool operator>=(HarInt a,HarInt b){return (HarIntCmp(a,b)>=0);}

/*!*/
HarInt operator+(const HarInt& a,const HarInt& b){HarInt c=a;c+=b;return c;}
HarInt operator-(const HarInt& a,const HarInt& b){HarInt c=a;c-=b;return c;}
HarInt operator*(const HarInt& a,const HarInt& b){HarInt c=a;c*=b;return c;}
HarInt operator/(const HarInt& a,const HarInt& b){HarInt c=a;c/=b;return c;}
HarInt operator%(const HarInt& a,const HarInt& b){HarInt c=a;c%=b;return c;}

/* -----------------
使用说明：
一、HarInt声明大数对象；
二、Get语句scanf赋值，value语句自行赋小数值；
三、print语句输出数字，形参为后面要跟的单个字符。

  四、除了乘法外，其他运算暂不支持小数，要想支持的话，重载一下复制过来大数形参改int就好
  
    -----------------
*/
HarInt a,b,c;
int main(){
    while(a.Get()!=EOF){
        b.Get();
        c=a;c*=b;
        c.print('\n');
        a.clear();b.clear();c.clear();
        
    }
    return 0;
}