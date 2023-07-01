/* C++ program for finding the longest increading subsequence using Bottom-Up approach */
#include <stdio.h>

int longestSubsequence(int arr[], int n){
// declaring the dp
// vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
int dp[n+1][n+1];
for(int curr=n-1;curr>=0;curr--){
	for(int prev=curr-1;prev>=-1;prev--){
	
	// including the element
	int take=0;
	// element is included if arr[curr]> arr[prev]
	if(prev==-1 || arr[curr]>arr[prev]){
		take = 1 + dp[curr+1][curr+1];
	}
	
	// excluding the element
	int notTake = dp[curr+1][prev+1];
	
	dp[curr][prev+1] = max(take, notTake);
	}
}
	
return dp[0][0];
}

// Driver Code
int main() {

	int arr[] = { 3, 10, 2, 5, 20 };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Length of LIS is "<<longestSubsequence(arr, n);
	return 0;
}

// This code is contributed by 525tamannacse11
