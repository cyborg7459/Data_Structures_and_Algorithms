#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"
#define int long long
#define loop(i,n) for(long long i=0;i<n;i++)
#define print(x) {for(auto t : x)\
                            cout << t << " ";\
                            cout << "\n";}
#define all(x) x.begin(), x.end()
#define o(x) cout << x << "\n"
#define fast ios_base::sync_with_stdio(false);\
                     cin.tie(NULL);
#define INF 1000000007

int findTargetSumWays(vector<int>& nums, int target) {
	map<int, long long> mp;
	if(nums[0] == 0) {
		mp.insert({0, 2});
	}
	else {
		mp.insert({nums[0], 1});
		mp.insert({-1 * nums[0], 1});
	}
	for(int i=1; i<nums.size(); i++) {
		int num = nums[i];
		map<int, long long> temp;
		for(auto it = mp.begin(); it != mp.end(); it++) {
			int t = it->first;
			int ways = it->second;
			int a = t + num;
			int b = t - num;
			if(abs(a) <= 1000000) {
				if(temp.find(a) == temp.end())
					temp.insert({a, ways});
				else
					temp[a] += ways;
			}
			if(abs(b) <= 1000000) {
				if(temp.find(b) == temp.end())
					temp.insert({b, ways});
				else
					temp[b] += ways;
			}
		}
		mp = temp;
	}
	if(mp.find(target) == mp.end()) return 0;
	return mp[target];
}

void solve() {
	vector<int> nums = {0,0,0,0,0,0,0,0,1};
	int target = 0;
	cout << findTargetSumWays(nums, target) << nl;
}

signed main()
{
    fast;
    int q = 1;
    while(q--)
        solve();
}
