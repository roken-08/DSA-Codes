#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        int maxv = 0;
        int maxc = 0;
        for(char c : s){
            mpp[c]++;
        }
        for(int i = 0; i < (int)s.length(); i++){
            char a = s[i];
            if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
                maxv = max(maxv , mpp[a]);
            } else {
                maxc = max(maxc, mpp[a]);
            }
        }
        return maxc + maxv;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    Solution obj;
    int result = obj.maxFreqSum(s);
    cout << result << endl;
    return 0;
}
