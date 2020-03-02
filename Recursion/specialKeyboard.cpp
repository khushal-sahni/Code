#include<bits/stdc++.h>
using namespace std;

unsigned long long int findoptimal(unsigned long long int N)
{
    if (N <= 6)
        return N;

   unsigned long long int screen[N];

   unsigned long long int b;
    unsigned long long int n;
    for (n=1; n<=6; n++)
        screen[n-1] = n;

    for (n=7; n<=N; n++)
    {
        screen[n-1] = 0;

        for (b=n-3; b>=1; b--)
        {
            unsigned long long int curr = (n-b-1)*screen[b-1];
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
