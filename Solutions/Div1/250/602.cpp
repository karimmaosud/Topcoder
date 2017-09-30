#include <set>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


class TypoCoderDiv1{
    int mem[55][2500];
public:
    int getmax(vector <int> D, int X){
        memset(mem, 0, sizeof(mem));
        for(int i = (int) D.size() - 1; i>=0; i--){
            for(int r = 0; r < 2200; r++){
                if(r + D[i] >= 2200){
                    if(i + 1 == D.size()){
                        mem[i][r] = 1;
                    }else{
                        if(max(0, r + D[i] - D[i+1]) < 2200){
                            mem[i][r] = 2 + mem[i+2][max(0, r + D[i] - D[i+1])];
                        }
                    }
                }else{
                    mem[i][r] = mem[i+1][r + D[i]];
                }
                mem[i][r] = max(mem[i][r], mem[i+1][max(0, r - D[i])]);
            }
        }
        return mem[0][X];
    }
};

