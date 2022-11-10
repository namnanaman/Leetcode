//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool static compare(pair<int,int> a,pair<int,int> b){
        if(a.second == b.second) return a.first < b.first;
        
        return a.second < b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        
        vector<pair<int,int>> ans(n);
        for(int i = 0 ; i < n;i++){
            ans[i].first = start[i];
            ans[i].second = end[i];
        }
        
        
        
        sort(ans.begin(),ans.end(),compare);
        
        int i = 0;
        int j = 1;
        int cnt = 1;
        while(j < n){
            if(ans[i].second  < ans[j].first){
                cnt++;
                i = j;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends