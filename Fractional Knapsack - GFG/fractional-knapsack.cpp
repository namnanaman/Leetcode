//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> ans;
        
        for(int i = 0 ; i < n;i++){
            double x = (arr[i].value*1.0)/(arr[i].weight *1.0);
            ans.push_back(make_pair(x,i));
            
        }
        
        sort(ans.begin(),ans.end(),greater<pair<double,int>>());
        int s = 0;
        double final = 0;
        
        for(int i = 0; i < ans.size();i++){
            if(s+arr[ans[i].second].weight <= W){
                s += arr[ans[i].second].weight;
                final+=arr[ans[i].second].value;
                
            }else{
                double f = (W-s)*1.0;
                final += (f*ans[i].first);
                break;
            }
        }
        
        
        return final;
        
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends