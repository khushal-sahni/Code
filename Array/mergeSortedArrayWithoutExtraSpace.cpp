
#include <bits/stdc++.h>
using namespace std;

int arr1[10000000];
int arr2[10000000];

int nextGap(int gap)
{
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

void merge(int n, int m)
{
	int i, j, gap = n + m;
	for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
	{
		for (i = 0; i + gap < n; i++)
			if (arr1[i] > arr1[i + gap])
				swap(arr1[i], arr1[i + gap]);


		for (j = gap > n ? gap-n : 0 ; i < n&&j < m; i++, j++)
			if (arr1[i] > arr2[j])
				swap(arr1[i], arr2[j]);

		if (j < m)
		{

			for (j = 0; j + gap < m; j++)
				if (arr2[j] > arr2[j + gap])
					swap(arr2[j], arr2[j + gap]);
		}
	}
}


int main()
{

	int t;
	cin >> t;

	while(t--){
	    int n, m;
	    cin >> n >> m;

	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }

	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }

	    merge(n, m);

        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);

        // printf("\n");

	    for (int i = 0; i < m; i++)
		    printf("%d ", arr2[i]);

	    printf("\n");
	}

	return 0;
}
