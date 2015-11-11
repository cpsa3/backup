////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-05-03 14:12:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2433
////Problem Title: 
////Run result: Accept
////Run time:1203MS
////Run memory:868KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstring>
#include <queue>
using namespace std; 
#define N 105
#define M 6001 
struct EDGE 
{ 
    short b;//��ǰ��
    short next;//��һ��
    short id;//�ߵı��
};
int G[N];
int sum[N];//s[i]������¼i�㵽�����������·��֮��
int tot;//��¼�ߵ�����
EDGE ET[M];
bool vv[N][M];
void addedge(int a,int b,int id)//��ӱ�
{ 
    EDGE x={b,G[a],id};//��ʼ��,ֱ�Ӹ�ֵ
    ET[tot]=x;//������ǰ��
    G[a]=tot++;//����
} 
void init()//��ʼ��
{ 
    tot=0; 
    memset(G,-1,sizeof(G));
} 
int n, m;
void bfs(int s) 
{ 
    queue<int>Q; 
    bool v[N]; 
    int  x,rp,np,d=0,i,j; 
    memset(v,0,sizeof(v)); 
    memset(vv[s],0,sizeof(vv[s])); 
    Q.push(s);//��ʼ��
    v[s]=1;
    rp=1;
    sum[s]=0; 
    while(!Q.empty()) 
    {  
        np=0;  
        while(rp--) 
        {   
            x=Q.front();   
            Q.pop();  
            sum[s]+=d;
            for(j=G[x];j!=-1;j=ET[j].next) 
            {    
                i=ET[j].b;    
                if(!v[i])//���֮ǰ��û�ѹ��õ�ͷ������
                {     
                    Q.push(i);     
                    v[i]=1;//��ǵ�
                    vv[s][ET[j].id]=1;//��ʾ������sΪԴ�����õ��˱�id
                    np++;
                }
            }
        }
        rp=np;
        d++; 
    }
}
int bfs2(int s,int del) 
{ 
    queue<int>Q; 
    bool v[N]; 
    int x,rp,np,d=0,i,j,ans=0,cnt=1; 
    memset(v,0,sizeof(v)); 
    Q.push(s);
    v[s]=1; 
    rp=1; 
    while(!Q.empty()) 
    {  
        np=0;  
        while(rp--) 
        {   
            x=Q.front();   
            Q.pop();   
            ans+=d;   
            for(j=G[x];j!=-1;j=ET[j].next) 
            {    
                if(ET[j].id==del) continue;//ɾ��������:�������  
                i=ET[j].b;    
                if(!v[i]) 
                {     
                    Q.push(i);     
                    v[i]=1;
                    np++;
                    cnt++;    
                }   
            }   
        }  
        rp=np;
        d++; 
    }
    if(cnt!=n) 
        return -1; 
    return ans;
} 
void solve() 
{ 
    int i,j,a,b; 
    init(); 
    for (i=0;i<m;i++) 
    {  
        scanf("%d%d",&a,&b);  
        addedge(a,b,i);//������ʲô�õ�?????
        addedge(b,a,i); 
    } 
    for(i=1;i<=n;i++)//��ÿ������u��һ�ε�Դ���· 
        bfs(i); 
    for(i=0;i<2*m;i+=2)//��ô���·��
    {  
        int del=i/2,ans=0,t;//ɾ��·��
        for(j=1;j<=n;j++) 
        {   
            if(vv[j][del]==0)//���ɾ���������߲������·���� 
                ans+=sum[j];  
            else 
            {    
                t=bfs2(j,del);//����ɾ��������������һ�ε�Դ���·
                if(t==-1)//������ﲻ��ֱ�ӷ���
                {     
                    ans=-1;     
                    break;    
                }    
                ans+=t;//����������·��  
            }  
        }  
        if(ans==-1) 
            printf("INF\n");  
        else 
            printf("%d\n",ans);
    }
}
int main() 
{ 
    while(scanf("%d%d",&n,&m)!=EOF)  
        solve();
    return 0;
}
