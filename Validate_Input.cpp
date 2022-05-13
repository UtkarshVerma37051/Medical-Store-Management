#include<iostream>
#include<regex>
//#include"Validate_Input.h"
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

int check_mail(string& mail)
{
    regex reg("\\w.+\\w@\\w+\\..+\\w");
    if(regex_match(mail,reg))
        return 1;
    else
        return 0;
}
