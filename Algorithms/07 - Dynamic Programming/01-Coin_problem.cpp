#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int num = 0;
int required_sum = 32;
vector<int> coins = {1,3,4};
int ready[32] = {};
int value[32];

int solve(int x) {
    if(x < 0) return INF;
    if(x==0) return 0;
    if(ready[x]==1) return value[x];
    num++;
    int best = INF;
    for(int c : coins) {
        best = min(best, solve(x-c) + 1);
    }
    ready[x] = 1;
    value[x] = best;
    return best;
}

int main() {
    int answer = solve(required_sum);
    cout << "Minimum number of coins required is " << answer << "\n";
    cout << "Number of iterations : " << num << "\n";
}
