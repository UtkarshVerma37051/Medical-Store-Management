#include"Customer.h"
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
class Customer_Purchase_Record
{
    customer c;
    vector<cart>med_purchased;
    vector<float> profit;
public :
    int read_from_file(long long int);
    void view_data();
};

int Customer_Purchase_Record ::read_from_file(long long int ph)
{
    string file_name=std::to_string(ph)+".txt";
    ifstream fin(file_name);
    if(!fin)
    {
        return 0;
    }
    c.mob_no=ph;
    getline(fin,c.name);
    getline(fin,c.address);
    int i=0;
    float p=0;
    cart ct;
    while(!fin.eof())
    {
        getline(fin,ct.med_name);
        getline(fin,ct.med_code);
        fin >> ct.quantity;
        fin.get();
        fin >> ct.med_price;
        fin.get();
        fin >> p;
        fin.get();
        med_purchased.push_back(ct);
        profit.push_back(p);
        i++;
        //cout << ct.med_name << "\n" << ct.med_code << "\n" << ct.quantity << " " << ct.med_price << " " << p << endl;
    }
    fin.close();
    return 1;
}
void Customer_Purchase_Record ::view_data()
{
    cout << "Name    : " << c.name << endl;
    cout << "Ph No.  : " << c.mob_no << endl;
    cout << "Address : " << c.address << endl;
    cout << fixed << showpoint;
    cout << setprecision(2);
    float total_profit=0;
    cout << std::left <<  setw(20)  << "Name" << "|" << setw(20) << "Code" << "|" <<  setw(20) << "Quantity" << "|" << setw(20) << "Price (Rs.)" << "|" << setw(20) << "Profit Earned (Rs.)\n"  << endl;
    for(int i=0;i<(int)med_purchased.size();i++)
    {
        total_profit+=profit[i];
        cout << std::left << setw(20) << med_purchased[i].med_name << "|" << setw(20) << med_purchased[i].med_code << "|" << setw(20) << med_purchased[i].quantity << "|" << setw(20) << med_purchased[i].med_price << "|" << setw(20) << profit[i] << endl;
    }
    cout << endl;
    cout << std::left << setw(83) << "Total " << "|" << total_profit << endl;

}
