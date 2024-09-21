class Solution {
public:
    vector<int> lexicalOrder(int n) {
    vector<int> s;
    for(int i = 1; i <= n; i++) {  
        s.push_back(i);
    }

    vector<string> strVec;
    for (int num : s) {
        strVec.push_back(to_string(num));
    }

    sort(strVec.begin(), strVec.end());

    vector<int> result;
    for (const string &str : strVec) {
        result.push_back(stoi(str));
    }

    return result;
}

};