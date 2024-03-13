#include<bits/stdc++.h>
using namespace std;
#include<chrono>
using namespace std::chrono;

int lcs(string s1,string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    auto start=high_resolution_clock::now();
    string s1="abcdefg hello world";
    string s2 = "aecgh egov";
    
	
	int ans = lcs(s1,s2);
    cout<<endl<<ans;
    auto stop=high_resolution_clock::now();

    auto duration=duration_cast<microseconds>(stop-start);
    cout<<endl<<duration.count()<<"microseconds"<<endl;
	return 0;
    
}
