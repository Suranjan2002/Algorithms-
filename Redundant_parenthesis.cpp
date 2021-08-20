
/* given a valid mathematical expression find whether it have redundant parenthesis or not It conta ins the 
   following operators:- +,-,*,/
    Sample Input: ((a+b))
    Sample Output: 1(Yes)
    Sample Input: (a+(a-b))
    Sample Ouput; 0 (No) */
    //Code
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    int ans= 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            st.push(s[i]);
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.top()=='(')
            {
                ans=1;
            }
            while(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/' )
            {
                st.pop();
            }
            //Now after poping the operators we will pop the opening braces
            st.pop();
        }
       
        
    }
     if(ans==0)
        {
            cout<<"No redundant parenthesis";
        }
        else if(ans=1)
        {
            cout<<"Redundant Parenthesis found";
        }
        //cout<<ans;
}