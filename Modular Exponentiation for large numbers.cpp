class Solution
{
	public:
	    typedef long long int ll;
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    ll ans = 1;
		    while(n>0){
		        if(n%2 != 0){
		            ans = (ans*x)%M;
		            n = n-1;
		        }
		        else{
		            x = (x*x)%M;
		            n = n/2;
		        }
		    }

		   return ans%M;
		}
};
