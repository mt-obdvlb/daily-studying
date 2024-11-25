#include<iostream>
#include<vector>
#include<deque>
#include<set>
#include<queue>

using namespace std;



class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(),ret = 0;
        queue<int> q;
        deque<int> dMin;
        deque<int> dMax;
        for(int i = 0;i<n;i++){
            while(!dMin.empty()&&dMin.back()>nums[i]){
                dMin.pop_back();
            }
            dMin.push_back(nums[i]);
			while(!dMax.empty()&&dMax.back()<nums[i]){
                dMax.pop_back();
            }
            dMax.push_back(nums[i]);
            while(!q.empty()&&(abs(dMin.front()-nums[i])>limit||
				abs(dMax.front()-nums[i])>limit)){
                if(dMin.front()==q.front()){
                    dMin.pop_front();
                }
                if(dMax.front()==q.front()){
                	dMax.pop_front();
				}
                q.pop();
            }
            q.push(nums[i]);
            ret = max(ret,(int)q.size());
        }
        return ret;
    }
};

int main(){
	Solution s;	
	vector<int> v(4);
	int arr[10] ={8,2,4,7};
	for(int i  =0;i<4;i++){
		v[i] = arr[i];
	}
	cout<<s.longestSubarray(v,4);
	return 0;	
} 

