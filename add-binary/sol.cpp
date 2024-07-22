#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) 
    {
        if(b.length() > a.length())
            swap(a,b);
        while(b.length() < a.length())
           b = "0" + b;
        int carry = 0;
        string ans = "";
        
        for(int i = b.length() - 1; i >= 0; i--)
        {
            if(a[i] == '1' && b[i] == '1')
            {
                if(carry == 0)
                    ans = "0" + ans;
                else
                    ans = "1" + ans;

                carry = 1;
            }
            else if(a[i] == '0' && b[i] == '0')
            {
                if(carry == 0)
                    ans = "0" + ans;
                else
                {
                    ans = "1" + ans;
                    carry = 0;
                }
            }
            //01 or 10 condition
            else if((b[i] =='0' && a[i] == '1') || (b[i] == '1' && a[i] == '0'))
            {
                 
                if(carry == 0) 
                    ans = "1" + ans;
                 
                else 
                    ans = "0" + ans;
                 
            }
        }

        if(carry == 1) 
            ans = "1" + ans;
        
        return ans;
    }
};