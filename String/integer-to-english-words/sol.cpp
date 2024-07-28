#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string helper(int num, vector<string>& units,vector<string>& tens) 
    {
        if (num == 0) 
            return "";

        else if (num < 20) 
            return units[num] + " ";

        else if (num < 100) 
            return tens[num / 10] + " " + helper(num % 10,units,tens);

        else
            return units[num / 100] + " Hundred " + helper(num % 100,units,tens);

    }
    string numberToWords(int num) 
    {
        if(num == 0)
            return "Zero";
        int index = 0;

        vector<string> units = {"","One","Two","Three","Four","Five","Six","Seven","Eight",
                                "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
                                "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        
        vector<string> tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy",
                            "Eighty","Ninety"};
        
        vector<string> thousands = {"","Thousand","Million","Billion"};

        string ans = "";

        while (num > 0) 
        {
            if (num % 1000 != 0) 
                ans = helper(num % 1000,units,tens) + thousands[index] + " " + ans;

            num /= 1000;
            index++;
        }
        ans.erase(ans.find_last_not_of(" ") + 1);

        return ans;
    }
};