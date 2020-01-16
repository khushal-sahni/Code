
#include<bits/stdc++.h>
using namespace std;

int count(int x, int Y[], int n, int NoOfY[])
{
    if (x == 0) return 0;

    if (x == 1) return NoOfY[0];

    int* idx = upper_bound(Y, Y + n, x);
    int ans = (Y + n) - idx;

    ans += (NoOfY[0] + NoOfY[1]);

    if (x == 2)  ans -= (NoOfY[3] + NoOfY[4]);

    if (x == 3)  ans += NoOfY[2];

    return ans;
}

long long countPairs(int X[], int Y[], int m, int n)
{
    int NoOfY[5] = {0};
    for (int i = 0; i < n; i++)
        if (Y[i] < 5)
            NoOfY[Y[i]]++;

    sort(Y, Y + n);

    long long total_pairs = 0;

    for (int i=0; i<m; i++)
        total_pairs += count(X[i], Y, n, NoOfY);

    return total_pairs;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		int i,a[m],b[n];
		for(i=0;i<m;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		cout<<countPairs(a, b, m, n)<<endl;
	}
}


// ***********************Below code misses one test case for some reason**************************
//
// #include <iostream>
// #include <algorithm>
// using namespace std;
// int main(){
//   int t;
//   scanf("%d",&t);
//   while(t--){
//     int x,y,i,j,count = 0;
//     bool found1 = false,found0 = false;
//     scanf("%d %d",&x,&y);
//     int p[x],q[y];
//     for(i = 0; i < x; i++) scanf("%d",&p[i]);
//     for(i = 0; i < y; i++) scanf("%d",&q[i]);
//     sort(p,p+x);
//     sort(q,q+y);
//     for(i = 0; i < y; i++){
//       if(q[i] == 1){
//         for(j = 0; j < x; j++){
//           if(p[j] > 1) {
//             count += x-j;
//             break;
//           }
//         }
//         found1 = true;
//       }
//       if(q[i] > 1) break;
//     }
//     for(i = 0; i < y; i++){
//       if(q[i] == 0){
//         for(j = 0; j < x; j++){
//           if(p[j] > 0){
//             count += x-j;
//             break;
//           }
//         }
//         found0 = true;
//       }
//     }
//     for(i = 0; i < x; i++){
//
//       if(p[i] == 2){
//         for(j = 0; j < y; j++){
//           if(q[j] > 4){
//             count += y-j;
//             // cout << "\n Adding count " << y-j << " count =" << count;
//             break;
//           }
//         }
//       }
//       else if(p[i] == 3){
//         bool found = false;
//         for(j = 0; j < y; j++){
//           if(q[j] == 3){
//             found = true;
//             break;
//           }
//           if(q[j] > 3) break;
//         }
//         if(found && found1 && found0) count += y-3;
//         else if(found && !found1 && found0) count += y-2;
//         else if(!found && found1 && found0) count += y-2;
//         else if(found && found1 && !found0) count += y-2;
//         else if(!found && !found1 && found0) count += y-1;
//         else if(!found && found1 && !found0) count += y-1;
//         else if(found && !found1 && !found0) count += y-1;
//         else count += y;
//
//         // cout << "\n Adding count " << y-2 << " count =" << count << "found =" << found;
//       }
//       else if(p[i] > 3){
//         int *idx = upper_bound(q,q+y,p[i]);
//         count += ((p + n) - idx);
//       }
//     }
//
//     printf("%d\n",count);
//   }
// }
