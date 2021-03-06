////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___����
////Run ID: 
////Submit time: 2011-09-04 19:24:46
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 4002
////Problem Title: 
////Run result: Accept
////Run time:1718MS
////Run memory:4132KB
//////////////////System Comment End//////////////////
import java.util.*;
import java.math.*;
public class Main {
	static int MAXN=10000;
	static int pn;
	static int prime[] = new int [MAXN];
	static boolean unprime[] = new boolean [MAXN];
	static void get_prime()
	{
		int i,j,ilim = MAXN/2;
		pn = 0;
		for(i=2;i<=ilim;i++)
		{
			if(unprime[i]) continue;
			prime[pn++]=i;
			for(j=i*i;j<MAXN;j+=i) unprime[j]=true;
		}
		for(;i<MAXN;i++)
		{
			if(!unprime[i]) prime[pn++]=i;
		}
	}
	public static void main(String[] args) 
	{
		get_prime();
		Scanner in =new Scanner(System.in);
		int T,i,j;
		BigInteger N,ans;
		T=in.nextInt();
		for(i=1;i<=T;i++)
		{
			N=in.nextBigInteger();
			ans=BigInteger.valueOf(1);
			for(j=0;;j++)
			{
				if(ans.multiply(BigInteger.valueOf(prime[j])).compareTo(N)==1) break;
				ans=ans.multiply(BigInteger.valueOf(prime[j]));
			}
			System.out.println(ans);
		}
	}
}












