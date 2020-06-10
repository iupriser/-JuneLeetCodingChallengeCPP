class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.size()) {
            return true;
        }
        int index = 0;
        for(int i =0; i< t.size(); ++i){
            if(t[i] == s[index]){
                index++;
            }
            if(index >= s.size()){
                return true;
            }
        }
        return false;
    }
};

//follow-UP

// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         unordered_map<char, vector<int>> hash; //chars -> list of indices;
//         for(int i=0; i<t.length();i++) hash[t[i]].push_back(i);
        
//         int prev = -1;
//         for(auto c : s){
//             auto it = hash.find(c);
//             if(it == hash.end()) return false;
//             auto vec = it->second;
//             int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin(); // find the first pos whose value is greater than prev
//             if(pos == vec.size()) return false;
//             prev = vec[pos];
//         }
//         return true;
//     }
// };