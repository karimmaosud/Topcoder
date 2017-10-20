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

class PowerOfThree{
    string convert_to_balanced_ternary(int num){
        if(num == 2){
            return "T+";
        }
        string ret = "";
        while(num){
            int rem = num%3;
            num/=3;
            if(rem == 1){
                ret += '+';
            }else if(rem == 2){
                ret += 'T';
                num++;
            }else{
                ret += '0';
            }
        }
        return ret;
    }
    
    void negate_num(string & ternary_num){
        map<char, char> mp;
        mp['0'] = '0';
        mp['T'] = '+';
        mp['+'] = 'T';
        for(int i=0; i<ternary_num.length(); i++){
            ternary_num[i] = mp[ternary_num[i]];
        }
    }
    
public:
    string ableToGet(int x, int y){
        string balanced_ternary_x = convert_to_balanced_ternary(abs(x));
        string balanced_ternary_y = convert_to_balanced_ternary(abs(y));
        if(x < 0){
            negate_num(balanced_ternary_x);
        }
        if(y < 0){
            negate_num(balanced_ternary_y);
        }
        
        if(balanced_ternary_x.length() < balanced_ternary_y.length()){
            swap(balanced_ternary_x, balanced_ternary_y);
        }
        
        for(int i=0; i<balanced_ternary_y.length(); i++){
            if((balanced_ternary_y[i] == '0' && balanced_ternary_x[i] == '0') || (balanced_ternary_y[i] != '0' && balanced_ternary_x[i] != '0')){
                return "Impossible";
            }
        }
        for(int i = (int)balanced_ternary_y.length(); i < balanced_ternary_x.length(); i++){
            if(balanced_ternary_x[i] == '0'){
                return "Impossible";
            }
        }
        return "Possible";
        
    }
};

