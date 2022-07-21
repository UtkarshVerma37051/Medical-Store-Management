#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<vector>
#include"Validate_Input.h"
#include"New_Inventory.h"
#include"Supplier.h"
using namespace std;
//struct Inventory_Struct
//{
//    string name="";
//    string code="";
//    float CP=0;
//    float SP=0;
//    int quantity=0;
//};

//class Inventory
//{
//protected :
//    vector<Inventory_Struct> inv_list;
//public :
//    friend class Customer_Section;
//    friend int Supplier_List::search_supplier(const string);
//    friend void Supplier_List::add_supplier();
//    void add_Inventory();
//    int search_Inventory(string key,int flag);
//    void display_Inventory();
//    void write_to_file();
//    void read_from_file();
//    void modify_inventory();
//    void add_to_inventory();
//    void delete_inventory();
//    void delete_Medicine();
//    void display_specific_medicine(int );
//    void get_data_for_customer();
//    void export_to_excel();
//    void Start();
////    void update_on_purchase()
//};
void Inventory::Start(Supplier_List& sup)
{
    char ch;
    system("cls");
    while(1)
    {
        cout << "1. Add Medicine       : " << endl;
        cout << "2. Delete Medicine    : " << endl;
        cout << "3. Modify Medicine    : " << endl;
        cout << "4. Search Medicine    : " << endl;
        cout << "5. List All Medicines : " << endl;
        cout << "0. Exit               : " << endl;
        cout << "   Enter your choice  : ";
        ch=getche();
        if(ch=='0')
            break;
        switch(ch)
        {
            case '1' :
                add_Inventory(sup);
                write_to_file();
                system("cls");
            break;

            case '2' :
                if(inv_list.empty())
                {
                    system("cls");
                    cout << "Inventory is Empty!" << endl;
                    cout << "Press any key to exit : ";
                    getch();
                    system("cls");
                    break;
                }
                else
                    delete_Medicine();
                write_to_file();
                system("cls");
            break;

            case '3' :
                if(inv_list.empty())
                {
                    system("cls");
                    cout << "Inventory is Empty!" << endl;
                    cout << "Press any key to exit : ";
                    getch();
                }
                else
                    modify_inventory(sup);
                write_to_file();
                system("cls");
            break;

            case '4' :
                system("cls");
                if(inv_list.empty())
                {
                    cout << "Inventory is empty." << endl;
                    cout << "Press any key to exit : ";
                    getch();
                }
                else
                {
                    while(1)
                    {
                        char op;
                        cout << "1. Search by Name : " << endl;
                        cout << "2. Search by Code : " << endl;
                        cout << "3. Exit           : " << endl;
                        cout << "Enter your choice : ";
                        op = getche();
                        if(op == '3')
                            break;
                        else if(op == '1' || op == '2')
                        {
                            cout << endl;
                            string key;
                            if(op=='1')
                                cout << "Enter Name : ";
                            else
                                cout << "Enter Code : ";
                            fflush(stdin);
                            getline(cin,key);
                            int found=-1;
                            found=search_Inventory(key,op-48);
                            if(found==-1)
                                cout << "\nMedicine not found." << endl;
                            else
                            {
                                system("cls");
                                display_specific_medicine(found);
                            }
                            cout << "Press any key to exit : ";
                            getch();
                            system("cls");
                        }
                        else
                        {
                            system("cls");
                            cout << "Invalid Choice!" << endl;
                        }
                    }
                }
                system("cls");
            break;

            case '5' :
                display_Inventory();
                system("cls");
            break;

//            case '7' :
//                write_to_file();
//            break;

            case '8' :
                export_to_excel();
            break;

            default :
                system("cls");
                cout << "Invalid Choice!" << endl;
        }
    }
}

void Inventory::add_Inventory(Supplier_List& sup)
{
    system("cls");
    string nm,cd,check;
    float sp,cp;
    int quant=0,found = -1;
    cout << "Enter Medicine Name (0 to exit) : ";
    while(1)
    {
        fflush(stdin);
        getline(cin,nm);
        if(nm=="0")
            return;
        found = search_Inventory(nm,1);
        if(found == -1)
            break;
        else
        {
            cout << "\nMedicine Already Exists." << endl;
            cout << "Enter a new Medicine name (0 to exit) : ";
            fflush(stdin);
        }
    }
    fflush(stdin);
    cout << "\nEnter Medicine Code (0 to exit) : ";
    while(1)
    {
        fflush(stdin);
        getline(cin,cd);
        if(cd=="0")
            return;
        int found = search_Inventory(cd,2);
        if(found == -1)
            break;
        else
        {
            cout << "\nMedicine Already Exists." << endl;
            cout << "Enter a new Medicine name (0 to exit) : ";
            fflush(stdin);
        }
    }

    cout << "\nEnter Cost Price    : ";
    while(1)
    {
        getline(cin,check);
        cp=check_price(check);
        if(cp !=0)
            break;
        else
        {
            cout << "Invalid Input!" << endl;
            cout << "Enter Valid price : ";
        }
    }
    cout << "\nEnter Selling Price : ";
    while(1)
    {
        fflush(stdin);
        getline(cin,check);
        sp=check_price(check);
        if(sp !=0)
            break;
        else
        {
            cout << "Invalid Input!" << endl;
            cout << "Enter Valid price : ";
        }
    }

    cout << "\nEnter Quantity : ";
    while(1)
    {
        fflush(stdin);
        getline(cin,check);
        quant = check_number(check);
        if(quant !=0)
            break;
        else
            cout << "Invalid Quantity!\nEnter Valid Quantity : ";
    }

    struct Inventory_Struct cst={nm,cd,cp,sp,quant};

    while(1)
    {
        cout << "Enter Supplier Code (0 to exit) : " << endl;
        string s_code;
        fflush(stdin);
        getline(cin,s_code);
        if(s_code=="0")
            return;
        found = sup.search_supplier(s_code);
        if(found==-1)
        {
            cout << "Supplier NOT found.\n";
        }
        else
        {
            inv_list.push_back(cst);
            sup.write_to_supplier_history(cst,s_code);
            cout << "\nMedicine Added.\nPress any key to exit.";
            getch();
            break;
        }
    }
}

void Inventory :: display_Inventory()
{
    system("cls");
    if(inv_list.empty())
    {
        cout << "Inventory is empty." << endl;
        cout << "Press any key to exit : ";
        getch();
        return ;
    }
    else
    {
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << std::left <<  setw(20)  << "Name" << setw(20) << "Code" << setw(20) << "Quantity" << setw(20) << "Cost Price" << setw(20) << "Selling Price" <<endl << endl;
        for(int i=0;i<(int)inv_list.size();i++)
        {
            cout << setw(20) << inv_list[i].name << setw(20) << inv_list[i].code << setw(20) << inv_list[i].quantity << setw(20) << inv_list[i].CP << setw(20) << inv_list[i].SP  << endl;
        }
    }
    cout << "Press any key to exit : ";
    getch();
}

int Inventory :: search_Inventory(string key,int flag)
{
    int size=inv_list.size();
    int i=0;
    if(flag == 1)
    {
        while(i<size)
        {
            if(inv_list[i].name == key)
                return i;
            i++;
        }
    }
    else if(flag == 2)
    {
        while(i<size)
        {
            if(inv_list[i].code == key)
                return i;
            i++;
        }
    }
    return -1;
}

void Inventory :: write_to_file()
{
    if(inv_list.empty())
    {
        remove("Inventory.txt");
        return;
    }
    ofstream fout("Inventory.txt");
    int size=inv_list.size();
    for(int i=0;i<size;i++)
    {
        fout << inv_list[i].name << '\n';
        fout << inv_list[i].code << '\n';
        fout << inv_list[i].quantity << '\n';
        fout << inv_list[i].CP << '\n';
        fout << inv_list[i].SP;
        if(i != size-1)
            fout << '\n';
    }
    fout.close();
}

void Inventory :: read_from_file()
{
    inv_list.clear();
    ifstream fin("Inventory.txt");
    if(!fin)                                                        //Checking if file exists or not.
        return;
    struct Inventory_Struct cst;
    while(!fin.eof())
    {
        getline(fin,cst.name);
        getline(fin,cst.code);
        fin >> cst.quantity;
        fin.get();
        fin >> cst.CP;
        fin.get();
        fin >> cst.SP;
        fin.get();
        inv_list.push_back(cst);
    }
    fin.close();
}

void Inventory :: modify_inventory(Supplier_List& sup)
{
    char ch;
    system("cls");
    while(1)
    {
        cout << "1. Add to inventory      : " << endl;
        cout << "2. Delete from inventory : " << endl;
        cout << "0. Exit                  : " << endl;
        cout << "   Enter your choice     : ";
        ch=getch();
        if(ch=='0')
            break;
        switch(ch)
        {
            case '1' :
                add_to_inventory(sup);
                system("cls");
            break;

            case '2' :
                delete_inventory();
                system("cls");
            break;

            default :
                system("cls");
                cout << "Invalid Choice!" << endl;
        }
    }
}

void Inventory :: add_to_inventory(Supplier_List &sup)                                // Adding to existig medicine
{
    char op;
    system("cls");
    while(1)
    {
        cout << "1. Search by Name : " << endl;
        cout << "2. Search by Code : " << endl;
        cout << "3. Exit           : " << endl;
        cout << "Enter your choice : ";
        op = getche();
        if(op == '3')
            return;
        else if(op == '1' || op == '2')
        {
            string key,quant;
            int q;
            cout << endl;
            if(op=='1')
                cout << "Enter Name : ";
            else
                cout << "Enter Code : ";
            fflush(stdin);
            getline(cin,key);
            int found=-1;
            system("cls");
            found=search_Inventory(key,op-'0');
            if(found==-1)
            {
                cout << "Medicine not found." << endl;
                cout << "Enter valid Input : " << endl;
            }
            else
            {
                system("cls");
                while(1)
                {
                    display_specific_medicine(found);
                    cout << "Enter the Quantity to Add : ";
                    fflush(stdin);
                    getline(cin,quant);
                    q=check_number(quant);
                    if(q==0)
                    {
                        system("cls");
                        cout << "Invalid Choice!\n" << endl;
                        continue;
                    }
                    else
                    {
                        while(1)
                        {
                            cout << "Enter Supplier Code (0 to exit) : " << endl;
                            string s_code;
                            fflush(stdin);
                            getline(cin,s_code);
                            if(s_code=="0")
                                return;
                            found = sup.search_supplier(s_code);
                            if(found==-1)
                            {
                                cout << "Supplier NOT found.\n";
                            }
                            else
                            {
                                struct Inventory_Struct cst={inv_list[found].name,inv_list[found].code,inv_list[found].CP,inv_list[found].SP,q};
                                sup.write_to_supplier_history(cst,s_code);
                                break;
                            }
                        }
                        inv_list[found].quantity+=q;
                        system("cls");
                        display_specific_medicine(found);
                        cout << "Inventory Updated.\n";
                        cout << "Press any key to exit :" << endl;
                        getch();
                        system("cls");
                        break;
                    }
                }
            }
        }
        else
        {
            system("cls");
            cout << "Invalid Choice!" << endl;
        }
    }
}

void Inventory :: delete_inventory()                                // Deletion by Quantity
{
    char op;
    system("cls");
    while(1)
    {
        cout << "1. Search by Name : " << endl;
        cout << "2. Search by Code : " << endl;
        cout << "3. Exit           : " << endl;
        cout << "Enter your choice : ";
        op = getche();
        if(op == '3')
            return;
        else if(op == '1' || op == '2')
        {
            if(inv_list.empty())
            {
                system("cls");
                cout << "Inventory is empty." << endl;
                cout << "Press any key to exit : " << endl;
                continue;
            }
            string key,quant;
            int q;
            cout << endl;
            if(op=='1')
                cout << "Enter Name : ";
            else
                cout << "Enter Code : ";
            fflush(stdin);
            fflush(stdin);
            getline(cin,key);
            int found=-1;
            found=search_Inventory(key,op-'0');
            if(found == -1)
            {
                system("cls");
                cout << "Medicine not found." << endl;
                cout << "Enter valid Input : " << endl;
            }
            else
            {
                system("cls");
                while(1)
                {
                    display_specific_medicine(found);
                    cout << "Enter the Quantity : ";
                    fflush(stdin);
                    getline(cin,quant);
                    q=check_number(quant);
                    if(q==0)
                    {
                        system("cls");
                        cout << "Invalid Choice!\n" << endl;
                        continue;
                    }
                    else
                    {
                        if(q > inv_list[found].quantity)
                        {
                            system("cls");
                            cout << "Entered Quantity is greater than Quantity Present." << endl;
                            continue;
                        }
                        else if(q < inv_list[found].quantity)
                            inv_list[found].quantity-=q;
                        else
                        {
                            if(inv_list.empty())
                            {
                                cout << "\nInventory is empty." << endl;
                                cout << "Press any key to exit : ";
                                getch();
                                system("cls");
                                break;
                            }
                            inv_list.erase(inv_list.begin()+found);
                            cout << "Medicine Deleted.";
                            cout << "Press any key to exit." << endl;
                            getch();
                            system("cls");
                            break;
                        }
                        system("cls");
                        if(inv_list[found].quantity!=q)
                        {
                            display_specific_medicine(found);
                            cout << "Inventory Updated.\n";
                            cout << "Press any key to exit :" << endl;
                            getch();
                            system("cls");
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            system("cls");
            cout << "Invalid Choice!" << endl;
        }
    }
}

void Inventory :: delete_Medicine()                                 // Delete whole Medicine from Inventory
{
    char op;
    system("cls");
    while(1)
    {
        if(inv_list.empty())
        {
            cout << "\nInventory is empty." << endl;
            cout << "Press any key to exit : ";
            getch();
            system("cls");
            return;
        }
        cout << "1. Search by Name : " << endl;
        cout << "2. Search by Code : " << endl;
        cout << "3. Exit           : " << endl;
        cout << "Enter your choice : ";
        op = getche();
        if(op == '3')
            return;
        else if(op == '1' || op == '2')
        {
            string key;
            cout << endl;
            if(op=='1')
                cout << "Enter Name : ";
            else
                cout << "Enter Code : ";
            fflush(stdin);
            getline(cin,key);
            int found=-1;
            found=search_Inventory(key,op-'0');
            if(found == -1)
            {
                system("cls");
                cout << "Medicine not found." << endl;
                continue;
            }
            system("cls");
            display_specific_medicine(found);
            inv_list.erase(inv_list.begin()+found);
            cout << "\nMedicine Deleted." << endl;
            cout << "Press any key to exit : ";
            getch();
            system("cls");
        }
        else
        {
            system("cls");
            cout << "Invalid Choice!." << endl << endl;
        }
    }
}

void Inventory :: display_specific_medicine(int loc)
{
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << std::left <<  setw(20)  << "Name" << setw(20) << "Code" << setw(20) << "Quantity" << setw(20) << "Cost Price" << setw(20) << "Selling Price" <<endl << endl;
    cout << setw(20) << inv_list[loc].name << setw(20) << inv_list[loc].code << setw(20) << inv_list[loc].quantity << setw(20) << inv_list[loc].CP << setw(20) << inv_list[loc].SP << endl;
}

void Inventory ::export_to_excel()
{
    system("cls");
    int size=inv_list.size();
    if(size == 0)
    {
        cout << "Inventory is empty." << endl;
        cout << "No Data to export." << endl;
        cout << "Press any key to exit : ";
        getch();
        return;
    }
    string name;
    cout << "\nEnter the file name : ";
    fflush(stdin);
    getline(cin,name);
    name=name+".csv";
    ofstream fout(name);
    fout << "Name" << "," << "Code" << "," << "Quantity" << "," << "Cost Price" << "," << "Selling Price" << '\n';
    for(int i=0;i<size;i++)
    {
        fout << inv_list[i].name << "," << inv_list[i].code << ',' << inv_list[i].quantity << ',' << inv_list[i].CP << ',' << inv_list[i].SP;
        if(i != size-1)
            fout << '\n';
    }
    fout.close();
    cout << "\nExported to file -> " << name << endl;
    cout << "\nPress any key to exit : ";
    getch();
    system("cls");
}
