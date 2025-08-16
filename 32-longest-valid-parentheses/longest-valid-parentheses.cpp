class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n=s.size();
        vector<int>temp(n,0);
        for(int i=0; i<n; i++){
            if(st.empty()){
                if(s[i]=='(')
                    st.push(i);
            }
            else if(s[i]==')' && !st.empty()){
                temp[i]=1;
                temp[st.top()]=1;
                st.pop();
            }
            else st.push(i);
        }
        int cur=0;
        int maxi=0;
        for(int i=0; i<n; i++){
            if(temp[i]==1){
                cur++;
                maxi=max(maxi,cur);}
            else{
                
                cur=0;
            }
            

        }
        return maxi;
    }
};