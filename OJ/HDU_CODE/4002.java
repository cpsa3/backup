////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: 096040179JY
////Nickname: ___ºÚ—‘
////Run ID: 
////Submit time: 2011-09-04 19:23:04
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 4002
////Problem Title: 
////Run result: Accept
////Run time:1734MS
////Run memory:4296KB
//////////////////System Comment End//////////////////
import java.util.*;
import java.math.*;
public class Main {
	static int MAXN=40000;
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
		// TODO Auto-generated method stub
		get_prime();
		//System.out.println(prime[0]+prime[1]);
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
				//if(ans.compareTo(N)==1) break;
				if(ans.multiply(BigInteger.valueOf(prime[j])).compareTo(N)==1) break;
				ans=ans.multiply(BigInteger.valueOf(prime[j]));
			}
			System.out.println(ans);
			//ans=ans.divide(BigInteger.valueOf(prime[j]));
			//System.out.println(ans);
		}
	}
}












