#include <bits/stdc++.h>
using namespace std;

void f(vector<vector<int>>S,int i,int j){
	if(i == j) cout << "A" << i;
	else{
		cout << "(";
		f(S, i, S[i][j]);
		f(S, S[i][j] + 1, j);
		cout << ")";
	}
}
int matrixMultiplication(vector<int>& arr, int N) {
    
    vector<vector<int>> dp(N, vector<int>(N, -1));
	vector<vector<int>>S(N,vector<int>(N,0));
    
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

  
    for (int len = 2; len < N; len++) {
        for (int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

           
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
                S[i][j]=k;
            }
        }
    }
     f(S,1,N-1);
    return dp[1][N - 1];
}

int main() {
    vector<int> arr = {3 ,2, 5, 4, 2};
    int n = arr.size();
	int ans=matrixMultiplication(arr, n) ;
    cout << endl<<"The minimum number of operations for matrix multiplication is " << ans<< endl;
	
    return 0;
}
