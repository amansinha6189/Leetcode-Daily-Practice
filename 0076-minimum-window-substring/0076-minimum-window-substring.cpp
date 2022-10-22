class Solution {
public:
    string minWindow(string s, string t) {
		int n = s.length();
		int m = t.length();
		int j=0,f=0,mn=INT_MAX,st=0;
		vector<int> vs(81),vt(81);
		for(int i=0;i<m;i++) vt[t[i]-'A']++;
		for(int i=0;i<n;i++)  {
			vs[s[i]-'A']++;
			while(j<i&&vs[s[j]-'A']>vt[s[j]-'A']) {
				vs[s[j++]-'A']--;
			}
			f=0;
			for(int k=0;k<81;k++) {
				if(vt[k]&&vt[k]>vs[k]) {
					f=1;
					break;
				}
			}
			if(!f) {
				if(mn>i-j+1) {
					mn=i-j+1;
					st=j;
				}
			}
		}
		return mn==INT_MAX?"":s.substr(st,mn);        
    }
};