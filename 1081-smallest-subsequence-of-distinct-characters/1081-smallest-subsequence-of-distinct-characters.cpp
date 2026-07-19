class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }

        string answer = "";
        set<char>st;

        for(int i=0;i<n;i++){    
            if(st.count(s[i])){
                mp[s[i]]--;
                continue;
            }
            answer+=s[i];
            st.insert(s[i]);
            if(answer.size()>=2){
                bool check = false;

                while(!check && answer.size()>=2){
                    if(answer[answer.size()-1] < answer[answer.size()-2] && mp[answer[answer.size()-2]]>=1){
                        st.erase(answer[answer.size()-2]);
                        answer.erase(answer.end()-2);
                    }
                    else {
                        check = true;
                    }
                }
            }
            mp[s[i]]--;
        }
        return answer;
    }
};