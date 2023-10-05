#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findLarger(vector<int>& vec,vector<bool>& vis, int key){
    for(int i=0;i<vec.size();i++){
        if(!vis[i] && vec[i] > key) return i;
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>vec(n);
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++)    scanf("%d",&vec[i]);

    sort(vec.begin(),vec.end());
    int ans = 0;

    for(int i=0;i<n;i++){
        if(!vis[i]){
            int idx = findLarger(vec,vis,vec[i]);
            if(idx != -1){
                vis[idx] = true;
                ans++;
            }
        }
    }

    cout<<ans;

    return 0;
}