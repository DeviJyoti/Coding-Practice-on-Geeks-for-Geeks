class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>vec;
        for(string b:bank){
            int count=0;
            for(int i=0;i<b.size();i++){
                if(b[i]=='1') count++;
            }
            if(count>0){
                vec.push_back(count);
            }
        }
        int ans=0;
        for(int i=1;i<vec.size();i++){
            ans+=vec[i]*vec[i-1];
        }
        return ans;
    }
};
