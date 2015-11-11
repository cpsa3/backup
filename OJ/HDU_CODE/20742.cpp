////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2013-06-07 22:27:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2074
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
char map[80][80];
char n,a,b,c;
void Draw(int x){
	int i;
	int y = n-1-x;
	for(i=x;i<=y;i++){
		map[x][i] = map[y][i] =	map[i][x] = map[i][y] = a;
	}
}
void Print(){
	map[0][0] = map[0][n-1] = map[n-1][0] = map[n-1][n-1] = ' ';
	for(int i=0;i<n;i++){
		printf("%s\n",map[i]);
	}
}
int main(){
	bool flag = true;
	int i,j;
	while(scanf("%d %c %c",&n,&a,&b) != EOF){
		getchar();
		if(flag == false){
			printf("\n");
		}
		flag = false;
		if(n==1){
			printf("%c\n",a);
			continue;
		}
		if((n-1)%4 != 0){
			c=a;a=b;b=c;
		}
		memset(map,b,sizeof(map));
		for(i=0;i<n;i++){
			map[i][n] = '\0';
		}
		for(i=0;i<=n/2;i+=2){
			Draw(i);
		}
		Print();
	}
	return 0;
}