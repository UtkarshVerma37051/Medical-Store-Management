#ifndef PURCHASED_DATA_H_INCLUDED
#define PURCHASED_DATA_H_INCLUDED
#include"customer.h"
class Customer_Purchase_Record
{
    customer c;
    vector<cart>med_purchased;
    vector<float> profit;
public :
    int read_from_file(long long int);
    void view_data();
};


#endif // PURCHASED_DATA_H_INCLUDED
