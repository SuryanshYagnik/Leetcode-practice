class Solution {
public:
    void helper(string str,int k,string &maxi){
        if(str>maxi){
            maxi=str;
            return;
        }
        if(k==0){
            return;
        }
        
        for(int i=0;i<str.size()-1;i++){
            for(int j=i+1;j<str.size();j++){
                if(str[i]<str[j]){
                    swap(str[i],str[j]);
                    helper(str,k-1,maxi);
                    swap(str[i],str[j]);
                }
            }
        }
    }
    int maximumSwap(int num) {
        string n=to_string(num);
      string maxi=to_string(num);
        helper(n,1,maxi);
        int ans=stoi(maxi);
        return ans;
    }
};