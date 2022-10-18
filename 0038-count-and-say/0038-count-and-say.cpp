class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";

        string ans = "11";

        while(n>2)
        {
            string temp = "";
            int count = 1;
            
            for(int i=1;i<ans.size();i++)
            {
                if(ans[i] == ans[i-1])
                    count++;
                else
                {
                    temp += to_string(count);
                    temp += ans[i-1];
                    count = 1;
                }
            }

            int last = ans.size();
            
            if(ans[last-1] == ans[last-2])
                temp += to_string(count);
            else
                temp += "1";

            temp += ans[last-1];


            ans = temp;
            n--;
        }   

        return ans;
    }
};