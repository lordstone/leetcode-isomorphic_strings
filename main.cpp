class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        if(s.length() == 0) return true;
        map<char,int> strmap1, strmap2;
        vector<int> strpat1, strpat2;
        int token = 0;
        for(int i = 0; i < s.length() ; i ++){
            if(strmap1.find(s[i]) == strmap1.end()){
                strmap1.insert(pair<char,int>(s[i],token));
                strpat1.push_back(token);
                if(strmap2.find(t[i]) == strmap2.end()){
                    strmap2.insert(pair<char,int>(t[i],token));
                    strpat2.push_back(token++);
                }else{
                    return false;
                }
            }else{
                int tmp = strmap1[s[i]];
                strpat1.push_back(tmp);
                if(strmap2.find(t[i]) == strmap2.end()) return false;
                if(strmap2[t[i]] == tmp){
                    strpat2.push_back(tmp);
                }else{
                    return false;
                }
            }//end if
        }//end for i
        return true;
    }
};
