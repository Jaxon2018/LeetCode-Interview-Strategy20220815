#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxValue(vector<int>& weight, vector<int>& value, int bag_weight)
{
    int weight_length=weight.size();
    if( weight_length==0 )
    {
        return 0;
    }
//     vector<vector<int> > a(x, vector<int>(y, 0));
    vector<vector<int> > dp(weight_length+1, vector<int>(bag_weight+1, 0));
    for(int i=1; i<=weight_length; ++i)
    {
        for(int j=1; j<=bag_weight; ++j)
        {
            int value_with_thingi = ( j-weight[i-1]>=0 ) ? ( value[i-1]+dp[i-1][j-weight[i-1]] ) : 0;
            int value_without_thingi = dp[i-1][j];
            dp[i][j] = max(value_with_thingi, value_without_thingi);
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<=weight_length; ++i)
    {
        for(int j=0; j<=bag_weight; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[weight_length][bag_weight]<<endl;
    return 0;
}

int main() {
    vector<int> weight;
    weight.push_back(1);
    weight.push_back(4);
    weight.push_back(3);
    vector<int> value;
    value.push_back(15);
    value.push_back(30);
    value.push_back(20);
    
    int bag_weight = 4;
    
    MaxValue(weight, value, bag_weight);
    
    
    return 0;
}

15 15 15 15 
15 15 15 30 
15 15 20 35 

0 0 0 0 0 
0 15 15 15 15 
0 15 15 15 30 
0 15 15 20 35 

35