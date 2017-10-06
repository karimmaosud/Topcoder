#include <set>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#define maxn 1000000
using namespace std;

typedef pair<int, int> ii;
class AlienAndHamburgers{
public:
    
    int getNumber(vector<int> type, vector<int> taste){
        vector<int> vis(110, false);
        vector<ii> nums;
        for(int i=0; i<type.size(); i++){
            nums.push_back({taste[i], type[i]});
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int taken = 0;
        int sum = 0;
        for(int i =0; i<nums.size(); i++){
            int cur_type = nums[i].second;
            int cur_taste = nums[i].first;
            if(vis[cur_type]){
                if(sum + cur_taste > sum){
                    sum+=cur_taste;
                }
            }else{
                if((taken+1) * (sum + cur_taste) > (sum * taken)){
                    vis[cur_type] = true;
                    taken++;
                    sum+=cur_taste;
                }
            }
        }
        return sum * taken;
    }
};

