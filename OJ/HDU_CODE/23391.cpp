////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2010-10-26 15:10:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2339
////Problem Title: 
////Run result: Accept
////Run time:750MS
////Run memory:7160KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int dir[4][2]={1,0,-1,0,0,1,0,-1};
struct px
{
	int x,y,high;
};

bool cmp(px a,px b)
{
	return a.high<b.high;
}
queue<px>Q;
int mark[501][501];//��¼�ĵ��Ƿ��Ѵ���
int hight[501][501]={0};
int main ()
{
	int T,h,w,d,i,j;
	struct px temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&h,&w,&d);
		memset(hight,0,sizeof(hight));
		vector<px>S;
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
			{
				scanf("%d",&hight[i][j]);
				temp.x=i;temp.y=j;temp.high=hight[i][j];
				S.push_back(temp);
			}
			sort(S.begin(),S.end(),cmp);
			int res=0;//��¼�ܷ���
			//int mark[501][501];//��¼�ĵ��Ƿ��Ѵ���
			for(i=0;i<501;i++)
				for(j=0;j<501;j++)
					mark[i][j]=-1;
			for(i=h*w-1;i>=0;i--)//�ȴ�����ߵ�
			{
				int dx=S[i].x;
				int dy=S[i].y;
				if(mark[dx][dy]!=-1)//�ѱ�������Ͳ����ٴ���
					continue;
				int flag=1;//��Ǹõ��Ƿ�Ϊ��
				int sum=0;//�͸õ�ȸ߶ȵ���Ŀ
				//queue<px>Q;
				while(!Q.empty())
					Q.pop();
				Q.push(S[i]);
				while(!Q.empty())
				{
					struct px temp1=Q.front();
					Q.pop();
					if(mark[temp1.x][temp1.y]!=-1)
						continue;
					mark[temp1.x][temp1.y]=i;//��¼�¸߶�
					if(hight[temp1.x][temp1.y]==hight[dx][dy])
						sum++;//�͸õ�ȸ߶ȵ���Ŀ
					for(j=0;j<4;j++)
					{ 
						int nx=temp1.x+dir[j][0];
						int ny=temp1.y+dir[j][1];
						if(nx<0||nx>=h||ny<0||ny>=w) continue;
						if(hight[nx][ny]<=hight[dx][dy]-d) continue;
						if(mark[nx][ny]>i) flag=0;//����������ǰ�������������ߵĵ㣬˵���õ㲻�Ƿ�
						if(mark[nx][ny]==-1)
						{
							struct px temp2;
							temp2.x=nx;temp2.y=ny;temp2.high=hight[nx][ny];
							Q.push(temp2);
						}
					}
				}
				if(flag) res+=sum;
			}
			printf("%d\n",res);
	}
return 0;
}