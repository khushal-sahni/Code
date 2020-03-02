#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

ull findoptimal(ull N)
{
    if (N <= 6)
        return N;

   ull screen[N];

   ull b;
    ull n;
    for (n=1; n<=6; n++)
        screen[n-1] = n;

    for (n=7; n<=N; n++)
    {
        screen[n-1] = 0;

        for (b=n-3; b>=1; b--)
        {
            ull curr = (n-b-1)*screen[b-1];
            if (curr > screen[n-1])
                screen[n-1] = curr;
        }
    }
    return screen[N-1];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
                if (n > 75)
                     cout << -1 << endl;
               else
		    cout<<findoptimal(n)<<endl;
	}
	return 0;
}
