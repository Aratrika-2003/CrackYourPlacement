#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // char toRoman(int num)
    // {
    //     if(num == 1)
    //         return 'I';
    //     if(num == 5)
    //         return 'V';
    //     if(num == 10)
    //         return 'X';
    //     if(num == 50)
    //         return 'L';
    //     if(num == 100)
    //         return 'C';
    //     if(num == 500)
    //         return 'D';
    //     if(num == 1000)
    //         return 'M';
        
    //     //return -1;
    // }
    string intToRoman(int num) 
    {
        string unit[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hndrs[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thsnds[] = {"","M","MM","MMM"};

        return thsnds[num/1000] + hndrs[(num%1000)/100] + tens[(num%100)/10] + unit[num%10];
    } 
};