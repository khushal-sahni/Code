#include <bits/stdc++.h>
using namespace std;

unordered_set<int> S;
// Returns length of the longest contiguous subsequence
int findLongestConseqSubseq(int arr[], int n)
{
    S.clear();
    int ans = 0;

    // Hash all the array elements
    for (int i = 0; i < n; i++)
        S.insert(arr[i]);

    // check each possible sequence from the start
    // then update optimal length
    for (int i=0; i<n; i++)
    {
        // if current element is the starting
        // element of a sequence
        if (S.find(arr[i]-1) == S.end())
        {
            // Then check for next elements in the
            // sequence
            int j = arr[i];
            while (S.find(j) != S.end())
                j++;

            // update  optimal length if this length
            // is more
            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}

// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }

    return 0;
}

// *****************THE BELOW SOLUTION TIMES OUT FOR SOME FUCKING REASON******************
// #include <iostream>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;
//
// int main(){
//   int t;
//   cin >> t;
//   while(t--){
//     int n,i,k;
//     scanf("%d",&n);
//     int arr[n];
//     for(i = 0; i < n; i++) scanf("%d",&arr[i] );
//
//     int maxLength = 0;
//     unordered_map <int,int> m;
//     for(i = 0; i < n; i++){
//       int preLength = 0,postLength = 0,length = 0;
//       if(m.find(arr[i]) == m.end()){
//         if(m.find(arr[i]-1) != m.end()) preLength += m[arr[i]-1];
//         if(m.find(arr[i]+1) != m.end()) postLength += m[arr[i]+1];
//         length = preLength + postLength + 1;
//         if(length > maxLength) maxLength = length;
//         m.insert(pair <int,int> (arr[i],length));
//         m[arr[i]-preLength] = length;
//         m[arr[i]+postLength] = length;
//       }
//     }
//     cout << maxLength << "\n";
//   }
// }
