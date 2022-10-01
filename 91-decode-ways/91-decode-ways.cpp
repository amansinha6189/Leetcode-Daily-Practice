class Solution {
    private: 
     int memo[101];
public:
    int numDecodings(string s) {
        memset(memo,-1,sizeof(int)*101);
        return fun(s,0);
    }
    int fun(string s,int index)
    {
        // Base Case
        if(index==s.size())
            return 1;
        
        // Using Memoization
        if(memo[index]!=-1)
            return memo[index];

        int ans=0;
        
        // Recursive Call
           // You have two choices 
                 // 1. Choose one digit
                // 2. Choose two digit
         
        // 1. Choose one digit
            if(s[index]!='0')
                ans+=fun(s,index+1);
        
        // 2. Choose two digit
            if(index+1<s.size())
            if(s[index]!='0')
            {
                int num=s[index]-'0';
                 num*=10;
                num+=s[index+1]-'0';
                if(num<=26)
                    ans+=fun(s,index+2);
            }
        return memo[index]=ans;
    }
};
