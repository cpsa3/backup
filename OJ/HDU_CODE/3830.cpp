////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-08-08 23:33:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3830
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*LCA+����*/
/*
����ֳ���������:
(1):�ж�����״̬�Ƿ�ͬ��;
(2):���ͬ���������ǵ������������
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
struct Node
{
    __int64 x,y,z,d;//״̬�����������꼰��״̬���ڵ����
};
struct Node start,end;
void Run(Node &u)
{
    __int64 num[3];
    num[0]=u.x;num[1]=u.y;num[2]=u.z;
    sort(num,num+3);
    u.x=num[0];u.y=num[1];u.z=num[2];
}
inline bool equal(const Node u,const Node v)
{
    if(u.x==v.x&&u.y==v.y&&u.z==v.z)
        return true;
    return false;
}

Node get_root(Node &u)//���ص�ǰ�ڵ����������ĸ��ڵ�
{
    Node t=u;
    __int64 p,q,r;
	p=t.y-t.x;q=t.z-t.y;
	while(p!=q)
	{
		if(q>p)//�ұߴ������ 
		{
			r=(q-1)/p;
			t.x+=r*p;
			t.y+=r*p;  
		}
		else
		{
			r=(p-1)/q;
			t.z-=r*q;
			t.y-=r*q; 
		}
		u.d+=r;
		Run(t);//ע��ÿ��Ҫά��
		p=t.y-t.x;q=t.z-t.y;
	}
	return t;
}
Node get_pre(Node &u,__int64 step)//����u�ڵ�ǰ��step���Ľڵ� 
{
	Node t=u;
	__int64 p,q,r;
	//t.d-=step;
	while(step>0)
	{
		p=t.y-t.x;q=t.z-t.y;
		//printf("*\n");
		if(q>p)//�ұߴ������ 
		{
			r=(q-1)/p;
			if(r>step) r=step;
			t.x+=r*p;
			t.y+=r*p;  
		}
		else
		{
			r=(p-1)/q;
			if(r>step) r=step;
			t.z-=r*q;
			t.y-=r*q; 
		}
		step-=r;
		Run(t);//ע��ÿ��Ҫά��
	}
	return t;
}
int main()
{
    int a,b,c,x,y,z;
	__int64 l,r,mid;
    while(scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z)!=EOF)
    {
        start.x=a;start.y=b;start.z=c;start.d=0;
        end.x=x;end.y=y;end.z=z;end.d=0;

        Run(start);
        Run(end);
		if(!equal(get_root(start),get_root(end)))
		{
			printf("NO\n"); 
		}
		else
		{
			//����ͬһ��
			__int64 len=start.d>end.d?start.d-end.d:end.d-start.d;
			if(start.d>end.d)
				start=get_pre(start,len);
			else
				end=get_pre(end,len);
			//����
			l=0;r=start.d<end.d?start.d:end.d;
			//r=start.d;
			while(l!=r)
			{
				
				mid=(l+r)>>1;
				if(equal(get_pre(start,mid),get_pre(end,mid)))
					r=mid;
				else
					l=mid+1; 
			} 
			printf("YES\n");
			printf("%I64d\n",2*l+len);
		} 
    }
return 0;
}