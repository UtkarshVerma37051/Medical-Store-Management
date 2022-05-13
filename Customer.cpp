#include<fstream>
#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
#include<conio.h>
#include"New_Inventory.h"
#include"Validate_Input.h"
using namespace std;
struct customer
{
    string name;
    string address;
    long long int mob_no;
};

struct cart
{
    string med_name;
    string med_code;
    float med_price;
    int quantity;
};

class Customer_Record
{
    vector <customer> cstmr_list;
public :
    friend class Customer_Section;

    int search_in_record(long long int);
    void add_customer_to_record(struct customer);
    void read_from_record();
    void view_all_customer();
    void display_record();
    void add_to_purchased_list();
    void display_specific_record(int);
};

void Customer_Record ::view_all_customer()
{
    if(cstmr_list.empty())
        cout << "\nNo Customer.\n";
    else
    {
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << std::left <<  setw(20)  << "Name" << setw(20) << "Ph. No." << setw(20) << "Address" << endl;
        int size=cstmr_list.size();
        for(int i=0;i<size;i++)
            cout << setw(20) << cstmr_list[i].name << setw(20) << cstmr_list[i].mob_no << setw(20) << cstmr_list[i].address << endl;
    }
}

void Customer_Record ::read_from_record()
{
    ifstream fin("Customer_Record.txt");
    if(!fin)                                                        //Checking if file exists or not.
        return;
    fin.get();
    char ch;
//    int i=0;
    struct customer c;
    while(!fin.eof())
    {
        c.name="";
//        i=0;
        while(1)
        {
            ch=fin.get();
            if(ch == '\t')
                break;
            c.name+=ch;
        }
        fin >> c.mob_no;
        fin.get();
        getline(fin,c.address);
        cstmr_list.push_back(c);
    }
    fin.close();
}

//void Customer_Record::display_record()
//{
//    if(cstmr_list.empty())
//        cout << "\nNo Customer.\n";
//    else
//    {
//    cout << fixed << showpoint;
//    cout << setprecision(2);
//    cout << std::left <<  setw(20)  << "Name" << setw(20) << "Ph. No. " << setw(20) << "Address" << endl;
//    for(int i=0;i<cstmr_list.size();i++)
//        cout << setw(20) << cstmr_list[i].name << setw(20) << cstmr_list[i].mob_no << setw(20) << cstmr_list[i].address << endl;
//
//    }
//}


void Customer_Record :: add_customer_to_record(struct customer cst)
{
    ofstream fout("Customer_Record.txt",ios::app);
    fout << '\n' <<  cst.name << '\t';
    fout << cst.mob_no << '\n';
    fout << cst.address;
    fout.close();
}

int Customer_Record ::search_in_record(long long int ph)
{
    int size=cstmr_list.size();
    if(size == 0)
        return -1;
    for(int i=0;i<size;i++)
    {
        if(cstmr_list[i].mob_no == ph)
            return i;
    }
    return -1;
}

class Customer_Section
{
    friend class Inventory;
    friend class Customer_Record;
    vector<cart>cart_list;
    vector<float>profit;
    struct customer curnt_cstmr;
public :
    void  display_customer_details();
    void  display_cart();
    int   get_customer_data(Customer_Record&);
    void  add_to_cart(Inventory&);
    void  delete_from_cart();
    void  update_inventory(Inventory&);
    int  generate_bill(Inventory&);
    int   search_in_cart(string);
    float price_to_pay();
    void  START(Inventory&,Customer_Record&);
    void add_to_purchased_list(Customer_Record&,struct customer,Inventory&);
};

int Customer_Section ::get_customer_data(Customer_Record& cstmr)
{
    system("cls");
    string nm,adr,mob;
    long long int phn;
    cout << "Enter Customer Details        : " << endl;
    cout << "Enter Phone Number(0 to exit) : ";
    while(1)
    {
        fflush(stdin);
        getline(cin,mob);
        if(mob=="0")
            return 0;
        phn=check_phone_number(mob);
        if(phn != 0)
        {
            int found=cstmr.search_in_record(phn);
            if(found != -1)
            {
                curnt_cstmr.mob_no=phn;
                curnt_cstmr.name=cstmr.cstmr_list[found].name;
                curnt_cstmr.address=cstmr.cstmr_list[found].address;
                return 1;
            }
            curnt_cstmr.mob_no=phn;
            break;
        }
        else
        {
            cout << "\nInvalid Number!\nPlease enter a 10-digit Phone Number : " << endl;
        }
    }

    cout << "Enter Name : ";
    fflush(stdin);
    getline(cin,nm);
    curnt_cstmr.name=nm;
    cout << "Enter address : ";
    fflush(stdin);
    getline(cin,adr);
    curnt_cstmr.address=adr;
    cstmr.add_customer_to_record(curnt_cstmr);
    return 1;
}

void Customer_Section :: add_to_cart(Inventory& st)
{
    system("cls");
    string key,quant;
    int q;
    while(1)
    {
        display_cart();
        int found=-1;
        int cart_search=-1;
        cout << "Enter Medicine name (0 to exit): ";
        while(1)
        {
            fflush(stdin);
            getline(cin,key);
            if(key=="0")
                return;
            found=st.search_Inventory(key,1);
            if(found!=-1)
                break;
            cout << "\nMedicine not found." << endl;
            cout << "Enter valid name (0 to exit): ";
            fflush(stdin);
        }
        int orig_quant=st.inv_list[found].quantity;
        cart_search=search_in_cart(key);
        if(cart_search == -1)
        {
            cout << "Enter Quantity :";
            while(1)
            {
                fflush(stdin);
                getline(cin,quant);

                q=check_number(quant);
                if(q==0)
                    cout << "\nPlease Enter a valid quantity : ";
                else if(q > orig_quant)
                {
                    cout << "\nOut of Stock." << endl;
                    cout << "Press any key to exit :";
                    getch();
                    break;
                }
                else
                {
                    string cd=st.inv_list[found].code;
                    float sp=st.inv_list[found].SP;
                    struct cart t ={key,cd,sp,q};
                    cart_list.push_back(t);
                    break;
                }
            }
        }
        else
        {
            cout << "\n" << cart_list[cart_search].quantity << " Already present." << endl;
            cout << "Enter Quantity :";
            while(1)
            {
                fflush(stdin);
                getline(cin,quant);
                q=check_number(quant);
                if(q==0)
                    cout << "\nPlease Enter a valid quantity : ";
                else if(q + cart_list[cart_search].quantity > orig_quant)
                {
                    cout << "\nOut of Stock." << endl;
                    cout << "Press any key to exit :";
                    getch();
                    break;
                }
                else
                {
                    cart_list[cart_search].quantity+=q;
                    break;
                }
            }
        }
    }
}

void Customer_Section :: display_cart()
{
    system("cls");
    int size=cart_list.size();
    if(size==0)
    {
        cout << "No items in cart.\n" << endl;
        fflush(stdin);
        return;
    }
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << std::left <<  setw(20)  << "Name" << setw(20) << "Code" << setw(20) << "Quantity" << setw(20) << "Price(Rs.)" <<endl << endl;
    for(int i=0;i<size;i++)
        cout << setw(20) << cart_list[i].med_name << setw(20) << cart_list[i].med_code << setw(20) << cart_list[i].quantity << setw(20) << cart_list[i].med_price << endl;
}

void Customer_Record :: display_specific_record(int loc)
{
    cout << "\nName     : " << cstmr_list[loc].name << endl;
    cout << "Mob. No. : " << cstmr_list[loc].mob_no << endl;
    cout << "Address  : " << cstmr_list[loc].address << endl;
}

void Customer_Section :: START(Inventory &st,Customer_Record& cstmr_rec)
{
//    cout << "Displaying :" << endl;
//    cstmr_rec.display_record();
//    getch();
    char ch;
    int flag=0;
    while(1)
    {
        int check=get_customer_data(cstmr_rec);
        if(check==0)
        {
            system("cls");
            return;
        }
        system("cls");
        while(1)
        {
            cout << "1. Add to Cart      : " << endl;
            cout << "2. Delete from Cart : " << endl;
            cout << "3. Display Cart     : " << endl;
            cout << "4. Generate Bill    : " << endl;
            cout << "5. Exit             : " << endl;
            ch=getche();
            if(ch == '5')
            {
                flag=0;
                cart_list.clear();
                break;
            }
            switch(ch)
            {
            case '1' :
                add_to_cart(st);
            break;

            case '2' :
                delete_from_cart();
            break;

            case '3' :
                display_cart();
                cout << "Press any key to exit : ";
                getch();
            break;

            case '4' :
                if(generate_bill(st))
                {
                    update_inventory(st);
                    st.write_to_file();
                    add_to_purchased_list(cstmr_rec,curnt_cstmr,st);
                    cart_list.clear();
                    flag=1;
                    break;
                }
            break;

            default :
                system("cls");
                cout << "Invalid Choice!\n" << endl;
                continue;
            }
            system("cls");
            if(flag==1)
            {
                flag=0;
                break;
            }
        }
    }
}

int Customer_Section ::search_in_cart(string key)
{
    int size=cart_list.size();
    for(int i=0;i<size;i++)
    {
        if(cart_list[i].med_name == key)
            return i;
    }
    return -1;
}

void Customer_Section ::delete_from_cart()
{
    system("cls");
    int cart_search=-1,q=0;
    string key,quant;
    while(1)
    {
        display_cart();
        if(cart_list.empty())
        {
            cout << "Press any key to exit : " << endl;
            getch();
            return;
        }
        cout << "Enter Medicine Name (0 to exit): ";
        fflush(stdin);
        fflush(stdin);
        getline(cin,key);
        if(key == "0")
            break;
        cart_search = search_in_cart(key);
        if(cart_search == -1)
        {
            system("cls");
            display_cart();
            cout << "\nMedicine not in cart.\n" << endl;
            cout << "Press any key to continue : ";
            getch();
            continue;
        }

        int med_quant=cart_list[cart_search].quantity;

        cout << "Enter quantity to Delete (0 to exit) : " << endl;
        fflush(stdin);
        getline(cin,quant);
        if(quant=="0")
            break;
        q=check_number(quant);
        if(q == 0 || q > med_quant)
        {
            system("cls");
            cout << "Invalid Quantity\n" << endl;
            cout << "Press any key : ";
            getch();
        }
        else
        {
            if(q!=med_quant)
            cart_list[cart_search].quantity-=q;
            else
                cart_list.erase(cart_list.begin()+cart_search);
            display_cart();
        }
    }
}

void Customer_Section ::display_customer_details()
{
    cout << "Name    : " << curnt_cstmr.name << endl;
    cout << "Address : " << curnt_cstmr.address << endl;
    cout << "Ph. no. : " << curnt_cstmr.mob_no << endl;
}

float Customer_Section ::price_to_pay()
{
    float pay;
    pay=0;
    int i,sz=cart_list.size();
    for(i=0;i<sz;i++)
        pay = pay +  cart_list[i].med_price * cart_list[i].quantity;
    return pay;
}

int Customer_Section :: generate_bill(Inventory& st)
{
    system("cls");
    if(cart_list.empty())
    {
        cout << "No items in cart.\n" << endl;
        cout << "Press any key to exit : ";
        getch();
        return 0;
    }
    int size = cart_list.size();
    cout << "*********************************************INVOICE**************************************************\n" << endl;
    cout << fixed << showpoint;
    cout << setprecision(2);
    display_customer_details();
    cout << endl;
    cout << std::left <<  setw(20)  << "Name" << "|" << setw(20) << "Code" << "|" <<  setw(20) << "Quantity" << "|" << setw(20) << "Price (Rs.)" <<endl << endl;
    for(int i=0;i<size;i++)
    {
        cout << std::left << setw(20) << cart_list[i].med_name << "|" << setw(20) << cart_list[i].med_code << "|" << setw(20) << cart_list[i].quantity << "|" << setw(20) << cart_list[i].med_price << endl;
    }
    cout << "\nTotal Price to pay  |Rs." << price_to_pay() << endl;
    cout << "\n******************************************************************************************************" << endl;
    cout << "Press any key to exit : " << endl;
    getch();


    for(int j=0;j<(int)profit.size();j++)
    {
        cout << profit[j] << " ";
    }

    system("cls");
    return 1;
}

void Customer_Section::update_inventory(Inventory &st)
{
    int loc,size=cart_list.size();
    string name;
    for(int i=0;i<size;i++)
    {
        loc=-1;
        name=cart_list[i].med_name;
        loc=st.search_Inventory(name,1);

        if(cart_list[i].quantity == st.inv_list[loc].quantity)
            st.inv_list.erase(st.inv_list.begin()+loc);
        else
            st.inv_list[loc].quantity -= cart_list[i].quantity;
    }
}

void Customer_Section ::add_to_purchased_list(Customer_Record& cst,struct customer cstmr,Inventory& stck)
{
    int found=cst.search_in_record(cstmr.mob_no);
    string file_name=std::to_string(cstmr.mob_no) + ".txt";
    ofstream fout(file_name,ios::app);
    if(found == -1)
    {
        fout << cstmr.name << '\n';
        fout << cstmr.address;
    }

    int sz=cart_list.size();
    for(int i=0;i<sz;i++)
    {
        float total_profit=0;
        int srch=stck.search_Inventory(cart_list[i].med_name,1);
        {
            total_profit=(stck.inv_list[srch].SP-stck.inv_list[srch].CP)*cart_list[i].quantity;
            profit.push_back(total_profit);
        }
        fout << '\n' << cart_list[i].med_name << '\n';
        fout << cart_list[i].med_code << '\n';
        fout << cart_list[i].quantity << '\n';
        fout << cart_list[i].med_price << '\n';
        fout << total_profit;
    }
    fout.close();
}
