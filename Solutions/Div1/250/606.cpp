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

class EllysNumberGuessing{
    int inf = 1e9;
    bool satisfy(long long num, int guess, int answer){
        if(num > inf || num < 1){
            return false;
        }
        int g1 = 1LL * guess + answer;
        int g2 = 1LL * guess - answer;
        return (int) num == g1 || (int) num == g2;
    }
public:
    int getNumber(vector<int> guesses, vector<int> answers){
        set<int> candidates;
        for(int i=0; i<guesses.size(); i++){
            long long p1 = guesses[i] + answers[i];
            long long p2 = guesses[i] - answers[i];
            if(p1 <= inf){
                candidates.insert((int)p1);
            }
            if(p2 > 0){
                candidates.insert((int)p2);
            }
        }
        set<int> res;
        for(set<int>::iterator itr = candidates.begin(); itr != candidates.end(); itr++){
            bool can_res = true;
            for(int i=0; i<guesses.size(); i++){
                can_res&=satisfy(*itr, guesses[i], answers[i]);
            }
            if(can_res){
                res.insert(*itr);
            }
        }
        if(res.size() == 0){
            return -2;
        }
        if(res.size() > 1){
            return -1;
        }
        return *res.begin();
    }
};
