#include<iostream>
#include<regex>
#include<cstring>
using namespace std;

float check_price(string num)
{

    regex reg("[0-9]*\\.?[0-9]*");
    if(regex_match(num,reg))
        return stof(num);
    else
        return 0;
}

int check_number(string num)
{
    regex reg("[0-9]+");
    if(regex_match(num,reg))
        return stoi(num);
    else
        return 0;
}

long long int check_phone_number(string num)
{
    regex reg("[1-9][0-9]{9}");
    if(regex_match(num,reg))
        return stoll(num);
    else
        return 0;
}
