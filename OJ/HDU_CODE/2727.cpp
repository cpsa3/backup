////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-07-05 23:01:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2727
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:432KB
//////////////////System Comment End//////////////////
//Memory Time
//340K    0MS

#include<iostream>
using namespace std;

const int size=23;
const int num=251;
int n;  //chess size
int m;  //move steps
int lastx,lasty;
int map[size][size];  //������Ϊ(x,y)�����ӱ��
bool link[num][num];  //���ĳ������ŵ������Ƿ�������

int posx[]={0,-1,-2,-2,-1,1,2,2,1};   //��Ӧ��(x,y)�İ˸���λ
int posy[]={0,2,1,-1,-2,-2,-1,1,2};

typedef class chess
{
 public:
	 int color;   //����:1 ����:0
	 int r,c;
	 int connet[8];  //��¼�뵱ǰ����ֱ�����������ӱ��
	 int pc;  //connet��ָ��
	 
	 chess()
	 {
		 color=-1;
		 pc=0;
	 }
}PEG;

void LinePeg(PEG* peg,int i);  //������peg[i]���������ڵİ˸���λ��ͬɫ��������
bool CheckWin(PEG* peg);  //BFS,�������(����)�Ƿ������������һ��(Ӯ��)

int main(void)
{
	//freopen("2706.in","r",stdin);
	//freopen("2.out","w",stdout);
	while(cin>>n>>m)
	{
		if(!n && !m)
			break;
		memset(map,0,sizeof(map));
		memset(link,false,sizeof(link));
		PEG* peg=new PEG[m+1];
		
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			map[x][y]=i;  //��ż�¼
			peg[i].r=x;
			peg[i].c=y;
			
			if(i%2)
				peg[i].color=1;  //����
			else
				peg[i].color=0;  //����
			
			LinePeg(peg,i);  //�������µ��������丽����ͬɫ��������
		}
		if(CheckWin(peg))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}

/*������(x,y)���������ڵİ˸���λ��ͬɫ��������*/
void LinePeg(PEG* peg,int i)
{
	int color=peg[i].color;
	for(int k=1;k<=8;k++)
	{
		int r=peg[i].r+posx[k];
		int c=peg[i].c+posy[k];
		
		if(r>=0 && r<=n && c>=0 && c<=n)  //���߽�
		{
			if(map[r][c] && peg[ map[r][c] ].color==color)  //�����ɫ
			{
				switch(k)  //"��"�ֶԽ�����
				{
				case 1:  //30�ȷ�λ
					{
						if(link[ map[r][c-2] ][ map[r+1][c] ])
							break;
						if(c-3>=0 && link[ map[r][c-3] ][ map[r+1][c-1] ])
							break;
						if(c+1<=n && link[ map[r][c-1] ][ map[r+1][c+1] ])
							break;
						if(r-1>=0)
						{
							if(link[ map[r-1][c-2] ][ map[r+1][c-1] ])
								break;
							if(link[ map[r-1][c-1] ][ map[r+1][c] ])
								break;
							if(link[ map[r-1][c] ][ map[r+1][c-1] ])
								break;
						}
						if(r+2<=n)
						{
							if(link[ map[r+2][c-2] ][ map[r][c-1] ])
								break;
							if(link[ map[r+2][c-1] ][ map[r][c-2] ])
								break;
							if(link[ map[r+2][c] ][ map[r][c-1] ])
								break;
						}
						
						int a=map[peg[i].r][peg[i].c];
						int b=map[r][c];
						peg[a].connet[peg[a].pc++]=b;
						peg[b].connet[peg[b].pc++]=a;
						link[a][b]=link[b][a]=true;
						break;
					}
				case 2:  //60�ȷ�λ
					{
						if(link[ map[r][c-1] ][ map[r+2][c] ])
							break;
						if(r-1>=0 && link[ map[r-1][c-1] ][ map[r+1][c] ])
							break;
						if(r+3<=n && link[ map[r+1][c-1] ][ map[r+3][c] ])
							break;
						if(c-2>=0)
						{
							if(link[ map[r][c-2] ][ map[r+1][c] ])
								break;
							if(link[ map[r+1][c-2] ][ map[r+2][c] ])
								break;
							if(link[ map[r+2][c-2] ][ map[r+1][c] ])
								break;
						}
						if(c+1<=n)
						{
							if(link[ map[r][c-1] ][ map[r+1][c+1] ])
								break;
							if(link[ map[r+1][c-1] ][ map[r][c+1] ])
								break;
							if(link[ map[r+1][c-1] ][ map[r+2][c+1] ])
								break;
						}
						
						int a=map[peg[i].r][peg[i].c];
						int b=map[r][c];
						peg[a].connet[peg[a].pc++]=b;
						peg[b].connet[peg[b].pc++]=a;
						link[a][b]=link[b][a]=true;
						break;
					}
				case 3:  //120�ȷ�λ
					{
						if(link[ map[r][c+1] ][ map[r+2][c] ])
							break;
						if(r-1>=0 && link[ map[r-1][c+1] ][ map[r+1][c] ])
							break;
						if(r+3<=n && link[ map[r+1][c+1] ][ map[r+3][c] ])
							break;
						if(c-1>=0)
						{
							if(link[ map[r][c-1] ][ map[r+1][c+1] ])
								break;
							if(link[ map[r+1][c-1] ][ map[r][c+1] ])
								break;
							if(link[ map[r+2][c-1] ][ map[r+1][c+1] ])
								break;
						}
						if(c+2<=n)
						{
							if(link[ map[r+1][c] ][ map[r][c+2] ])
								break;
							if(link[ map[r+2][c] ][ map[r+1][c+2] ])
								break;
							if(link[ map[r+1][c] ][ map[r+2][c+2] ])
								break;
						}
						
						int a=map[peg[i].r][peg[i].c];
						int b=map[r][c];
						peg[a].connet[peg[a].pc++]=b;
						peg[b].connet[peg[b].pc++]=a;
						link[a][b]=link[b][a]=true;
						break;
					}
				case 4:  //150�ȷ�λ
					{
						if(link[ map[r][c+2] ][ map[r+1][c] ])
							break;
						if(c-1>=0 && link[ map[r+1][c-1] ][ map[r][c+1] ])
							break;
						if(c+3<=n && link[ map[r+1][c+1] ][ map[r][c+3] ])
							break;
						if(r-1>=0)
						{
							if(link[ map[r-1][c] ][ map[r+1][c+1] ])
								break;
							if(link[ map[r-1][c+1] ][ map[r+1][c] ])
								break;
							if(link[ map[r-1][c+2] ][ map[r+1][c+1] ])
								break;
						}
						if(r+2<=n)
						{
							if(link[ map[r][c+1] ][ map[r+2][c] ])
								break;
							if(link[ map[r][c+1] ][ map[r+2][c+2] ])
								break;
							if(link[ map[r][c+2] ][ map[r+2][c+1] ])
								break;
						}
						
						int a=map[peg[i].r][peg[i].c];
						int b=map[r][c];
						peg[a].connet[peg[a].pc++]=b;
						peg[b].connet[peg[b].pc++]=a;
						link[a][b]=link[b][a]=true;
						break;
					}
				case 5:  //210�ȷ�λ
					{
						if(link[ map[r-1][c] ][ map[r][c+2] ])
							break;
						if(c-1>=0 && link[ map[r-1][c-1] ][ map[r][c+1] ])
							break;
						if(c+3<=n && link[ map[r-1][c+1] ][ map[r][c+3] ])
							break;
						if(r-2>=0)
						{
							if(link[ map[r-2][c] ][ map[r][c+1] ])
								break;
							if(link[ map[r-2][c+1] ][ map[r][c+2] ])
								break;
							if(link[ map[r-2][c+2] ][ map[r][c+1] ])
								break;
						}
						if(r+1<=n)
						{
							if(link[ map[r][c] ][ map[r-1][c+1] ])
								break;
							if(link[ map[r+1][c+1] ][ map[r-1][c] ])
								break;
							if(link[ map[r+1][c+2] ][ map[r-1][c+1] ])
								break;
						}
						
						int a=map[peg[i].r][peg[i].c];
						int b=map[r][c];
						peg[a].connet[peg[a].pc++]=b;
						peg[b].connet[peg[b].pc++]=a;
						link[a][b]=link[b][a]=true;
						break;
					}
				case 6:  //240�ȷ�λ
					{
						if(link[ map[r-2][c] ][ map[r][c+1] ])
							break;
						if(r-3>=0 && link[ map[r-3][c] ][ map[r-1][c+1] ])
							break;
						if(r+1<=n && link[ map[r-1][c] ][ map[r+1][c+1] ])
							break;
						if(c-1>=0)
						{
							if(link[ map[r-2][c-1] ][ map[r-1][c+1] ])
								break;
							if(link[ map[r-1][c-1] ][ map[r][c+1] ])
								break;
							if(link[ map[r][c-1] ][ map[r-1][c+1] ])
								break;
						}
						if(c+2<=n)
						{
							if(link[ map[r-1][c] ][ map[r-2][c+2] ])
								break;
							if(link[ map[r-2][c] ][ map[r-1][c+2] ])
								break;
							if(link[ map[r-1][c] ][ map[r][c+2] ])
								break;
						}
						
						int a=map[peg[i].r][peg[i].c];
						int b=map[r][c];
						peg[a].connet[peg[a].pc++]=b;
						peg[b].connet[peg[b].pc++]=a;
						link[a][b]=link[b][a]=true;
						break;
					}
				case 7:  //300�ȷ�λ
					{
						if(link[ map[r-2][c] ][ map[r][c-1] ])
							break;
						if(r-3>=0 && link[ map[r-3][c] ][ map[r-1][c-1] ])
							break;
						if(r+1<=n && link[ map[r-1][c] ][ map[r+1][c-1] ])
							break;
						
						if(c-2>=0)
						{
							if(link[ map[r-2][c-2] ][ map[r-1][c] ])
								break;
							if(link[ map[r-1][c-2] ][ map[r-2][c] ])
								break;
							if(link[ map[r][c-2] ][ map[r-1][c] ])
								break;
						}
						if(c+1<=n)
						{
							if(link[ map[r-1][c-1] ][ map[r-2][c+1] ])
								break;
							if(link[ map[r][c-1] ][ map[r-1][c+1] ])
								break;
							if(link[ map[r-1][c-1] ][ map[r][c+1] ])
								break;
						}
						
						int a=map[peg[i].r][peg[i].c];
						int b=map[r][c];
						peg[a].connet[peg[a].pc++]=b;
						peg[b].connet[peg[b].pc++]=a;
						link[a][b]=link[b][a]=true;
						break;
					}
				case 8:  //330�ȷ�λ
					{
						if(link[ map[r][c-2] ][ map[r-1][c] ])
							break;
						if(c-3>=0 && link[ map[r][c-3] ][ map[r-1][c-1] ])
							break;
						if(c+1<=n && link[ map[r][c-1] ][ map[r-1][c+1] ])
							break;
						if(r-2>=0)
						{
							if(link[ map[r-2][c-2] ][ map[r][c-1] ])
								break;
							if(link[ map[r-2][c-1] ][ map[r][c-2] ])
								break;
							if(link[ map[r-2][c] ][ map[r][c-1] ])
								break;
						}
						if(r+1<=n)
						{
							if(link[ map[r-1][c-1] ][ map[r+1][c-2] ])
								break;
							if(link[ map[r-1][c-1] ][ map[r+1][c] ])
								break;
							if(link[ map[r-1][c] ][ map[r+1][c-1] ])
								break;
						}
						
						int a=map[peg[i].r][peg[i].c];
						int b=map[r][c];
						peg[a].connet[peg[a].pc++]=b;
						peg[b].connet[peg[b].pc++]=a;
						link[a][b]=link[b][a]=true;
						break;
					}
    }
   }
  }
 }
 return;
}

/*BFS,�������(����)�Ƿ������������һ��(Ӯ��)*/
bool CheckWin(PEG* peg)
{
	for(int k=0;k<=n;k++)
	{
		int p=map[0][k];
		if(p && peg[p].color==1)
		{
			int queue[num];
			bool vist[num]={false};
			int head=0;
			int tail=0;
			queue[tail++]=p;
			vist[p]=true;
			
			while(head<tail)
			{
				int s=queue[head++];
				if(peg[s].r==n)
					return true;
				
				for(int i=0;i<peg[s].pc;i++)
				{
					int x=peg[s].connet[i];
					if(!vist[x])
					{
						vist[x]=true;
						queue[tail++]=x;
					}
				}
			}
		}
	}
	return false;
}