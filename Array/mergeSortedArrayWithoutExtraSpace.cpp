#include <iostream>
#include <utility>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,i,j;
		scanf("%d %d",&n,&m);
		int arr1[n],arr2[m];
		for(i = 0; i < n; i++) scanf("%d",&arr1[i]);
		for(i = 0; i < m; i++) scanf("%d",&arr2[i]);
		int gap = m+n;
		while(gap > 0){
			if(gap != 1) gap = gap/2 + gap%2;
			for(i = 0; i+gap < n; i++) if(arr1[i] > arr1[i+gap]) swap(arr1[i],arr1[i+gap]);
			for(j = gap-n+i;i<n && j<m;i++,j++) if(arr1[i] > arr2[j]) swap(arr1[i],arr2[j]);
			for(j = 0; j+gap < m; j++) if(arr2[j] > arr2[j+gap]) swap(arr2[j],arr2[j+gap]);
			if(gap == 1) gap = 0;
		}
		for(i = 0; i < n; i++) printf("%d ",arr1[i]);
		for(i = 0; i < m; i++) printf("%d ",arr2[i]);
		printf("\n");
	}
}
