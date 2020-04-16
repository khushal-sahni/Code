#define INT_BITS 32
int maxSubarrayXOR(int A[], int n)
{
	int index = 0;
	// Traverse through all bits of integer starting from the most significant bit (MSB)
	for (int i = INT_BITS-1; i >= 0; i--)
	{
		// Initialize index of maximum element and the maximum element
		int maxInd = index;
		int maxEle = INT_MIN;
		for (int j = index; j < n; j++)
		{
			if ( (A[j] & (1 << i)) != 0 && A[j] > maxEle ) //finding max element whose ith bit is set
			   maxEle = A[j], maxInd = j;
		}
		if (maxEle == INT_MIN) //no number found with ith bit set
		continue;
		swap(A[index], A[maxInd]); // Put that max element at index 'index'

		maxInd = index; // Update maxInd because it was swapped
		// Do XOR of A[maxIndex] with all numbers having i'th bit as A.
		for (int j=0; j<n; j++)
		{
			if (j != maxInd && (A[j] & (1 << i)) != 0)//elements not equal to maxInd and ith bit set
			   A[j] = A[j] ^ A[maxInd];
		}
		index++;
	}
	// Final result is XOR of all elements
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= A[i];
	return res;
}
