#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string title = "";
        int rem;
        while(columnNumber)
        {
            columnNumber--;
            rem = columnNumber % 26;
            columnNumber /= 26;

            title = char('A' + rem) + title;
        }
        return title;
    }
};