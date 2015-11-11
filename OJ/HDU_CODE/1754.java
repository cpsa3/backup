////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___简言
////Run ID: 
////Submit time: 2011-08-14 16:58:31
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:8140MS
////Run memory:17948KB
//////////////////System Comment End//////////////////
/*AC代码：8187ms*/
/*用java写的线段树*/
import java.util.*;
import java.math.*;
public class Main {
	static int MAXN = 200006;
	static class Tree
	{
		int s,e,Max;
		Tree(){s=0;e=0;Max=0;}
	};
	static Tree Tnode [] = new Tree [4*MAXN];
	static int N;
	static int M;
	static int W [] = new int [MAXN];
	public static int lch(int a)
	{
		return 2*a;
	}
	public static int rch(int a)
	{
		return 2*a+1;
	}
	public static int max(int a,int b)
	{
		if(a>b) return a;
		return b;
	}
	public static void Build(int p,int s,int e)
	{
		//System.out.println("&");
		if(Tnode[p]==null)
			Tnode[p]=new Tree();
		Tnode[p].s=s;Tnode[p].e=e;
		if(s==e)
		{
			Tnode[p].Max=W[s];
			return;
		}
		int mid=(s+e)/2;
		Build(lch(p),s,mid);
		Build(rch(p),mid+1,e);
		Tnode[p].Max=max(Tnode[lch(p)].Max,Tnode[rch(p)].Max);
	}
	public static void Update(int p,int k,int num)
	{
		if(Tnode[p].s==Tnode[p].e)
		{
			Tnode[p].Max=num;
			return;
		}
		int mid=(Tnode[p].s+Tnode[p].e)/2;
		if(k<=mid)
			Update(lch(p),k,num);
		else
			Update(rch(p),k,num);
		Tnode[p].Max=max(Tnode[lch(p)].Max,Tnode[rch(p)].Max);
	}
	public static int Query(int p,int s,int e)
	{
		if(Tnode[p].s==s&&Tnode[p].e==e)
			return Tnode[p].Max;
		int mid=(Tnode[p].s+Tnode[p].e)/2;
		if(e<=mid)
			return Query(lch(p),s,e);
		else if(s>mid)
			return Query(rch(p),s,e);
		return max(Query(lch(p),s,mid),Query(rch(p),mid+1,e));
	}
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Scanner in =new Scanner(System.in);
		int i,s,e;
		String kind;
		while(in.hasNext())
		{
			N=in.nextInt();
			M=in.nextInt();
			for(i=1;i<=N;i++)
			{
				W[i]=in.nextInt();
			}
			/*
			for(i=0;i<MAXN;i++)
				Tnode[i]=new Tree();
				*/
			Build(1,1,N);//建树
			for(i=1;i<=M;i++)
			{
				kind=in.next();
				s=in.nextInt();
				e=in.nextInt();
				if(kind.equals("Q"))
				{
					int ans=Query(1,s,e);
					System.out.println(ans);
				}
				else
				{
					Update(1,s,e);
				}
			}
			//System.out.println("*");
		}
	}
}


