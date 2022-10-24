class Solution {
public:
    int len = 0;
    void func(vector<string> &arr, string ans, int index, map<char, bool> &mpp){
        if(index == arr.size()){
            int n = ans.size();
            cout<<ans<<" ";
            len = max(len, n);
            return;
        }
        int N = arr[index].size();
        
        bool flag = true;
        
        sort(arr[index].begin(), arr[index].end());
        for(int i = 1; i<N; i++){
            if(arr[index][i] == arr[index][i-1]){
                flag = false;
            }
        }
        for(int i = 0; i<N; i++){
            if(mpp[arr[index][i]] == true){
                flag = false;
                break;
            }
        }
        
        if(flag){
            ans += arr[index];
            for(int i = 0; i<N; i++){
                mpp[arr[index][i]] = true;
            }

            func(arr,ans,index + 1, mpp);
            
            for(int i = 0; i<N; i++){
                ans.pop_back();
                mpp[arr[index][i]] = false;
            }
            func(arr,ans,index + 1, mpp);

        }else{
            func(arr,ans,index + 1, mpp);
        }
        
        
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        map<char, bool> mpp;
        
        for(auto str: arr){
            for(auto ch : str){
                mpp[ch] = false;
            }
        }
        
        string ans = "";
        func(arr, ans, 0, mpp);
        
        cout<<ans;
        return len;
    }
};

// string i 