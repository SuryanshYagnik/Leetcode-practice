class Solution {
public:
   string removeKdigits(string num, int k) {
    stack<char> st;

    for(int i = 0; i < num.size(); i++) {
        while(!st.empty() && k > 0 && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while(k > 0) {
        st.pop();
        k--;
    }

    string result = "";
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());
    int start = 0;
    while(start < result.size() && result[start] == '0') {
        start++;
    }

    result = result.substr(start);

    return result.empty() ? "0" : result;
}

};