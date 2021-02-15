//#include<iostream>
////#include<iomanip>
//#include<fstream>
//#include<cstring>
//#include"Validate_Input.cpp"
//
//using namespace std;
//
//class Inventory
//{
//    public :
//    struct Medicine
//    {
//        string name;
//        string code;
//        float CP;
//        float SP;
//        int quantity;
//        struct Medicine *next;
//    };
//    struct Medicine *start=NULL;
//
//public :
//    void add_Inventory();
//    struct Medicine* search_Inventory(string key,int flag);
//    void display_Inventory();
//    void write_to_file();
//    void read_from_file();
//    void modify_inventory();
//    void add_to_inventory();
//    void delete_inventory();
//    void delete_Medicine();
//    void display_specific_medicine(struct Medicine* );
//    void Start();
//};
//Inventory stock;
//void Inventory :: Start()
//{
//    char ch;
//    system("cls");
//    while(1)
//    {
//        cout << "1. Add Medicine       : " << endl;
//        cout << "2. Delete Medicine    : " << endl;
//        cout << "3. Modify Medicine    : " << endl;
//        cout << "4. Search Medicine    : " << endl;
//        cout << "5. List All Medicines : " << endl;
//        cout << "0. Exit               : " << endl;
//        cout << "   Enter your choice  : ";
//        ch=getche();
//        if(ch=='0')
//            break;
//        switch(ch)
//        {
//            case '1' :
//                add_Inventory();
//                system("cls");
//            break;
//
//            case '2' :
//                if(start==NULL)
//                {
//                    system("cls");
//                    cout << "Inventory is Empty!" << endl;
//                    cout << "Press any key to exit : ";
//                    getch();
//                }
//                else
//                    delete_Medicine();
//                system("cls");
//            break;
//
//            case '3' :
//                if(start==NULL)
//                {
//                    system("cls");
//                    cout << "Inventory is Empty!" << endl;
//                    cout << "Press any key to exit : ";
//                    getch();
//                }
//                else
//                    modify_inventory();
//                system("cls");
//            break;
//
//            case '4' :
//                system("cls");
//                if(start==NULL)
//                {
//                    cout << "Inventory is empty." << endl;
//                    cout << "Press any key to exit : ";
//                    getch();
//                }
//                else
//                {
//                    while(1)
//                    {
//                        char op;
//                        cout << "1. Search by Name : " << endl;
//                        cout << "2. Search by Code : " << endl;
//                        cout << "3. Exit           : " << endl;
//                        cout << "Enter your choice : ";
//                        op = getche();
//                        if(op == '3')
//                            break;
//                        else if(op == '1' || op == '2')
//                        {
//                            cout << endl;
//                            Medicine* srch=NULL;
//                            string key;
//                            if(op=='1')
//                                cout << "Enter Name : ";
//                            else
//                                cout << "Enter Code : ";
//                            getline(cin,key);
//
//                            srch=search_Inventory(key,op-48);
//                            if(srch == NULL)
//                                cout << "Medicine not found." << endl;
//                            else
//                            {
//                                system("cls");
//                                display_specific_medicine(srch);
//                            }
//                            cout << "Press any key to exit : ";
//                            getch();
//                            system("cls");
//                        }
//                        else
//                        {
//                            system("cls");
//                            cout << "Invalid Choice!" << endl;
//                        }
//                    }
//                }
//                system("cls");
//            break;
//
//            case '5' :
//                display_Inventory();
//                system("cls");
//            break;
//
//            case '7' :
//                write_to_file();
//            break;
//            default :
//                system("cls");
//                cout << "Invalid Choice!" << endl;
//        }
//    }
//}
//
//void Inventory :: add_Inventory()
//{
//    system("cls");
//    string nm,cd,check;
//    float sp,cp;
//    int quant,found=0;
//    cout << "Enter Medicine Name :";
//    getline(cin,nm);
//    struct Medicine* srch=NULL;
//    srch=search_Inventory(nm,1);
//    if(srch != NULL)
//        goto goto_quant;
//    fflush(stdin);
//    cout << "Enter Medicine Code :";
//    while(1)
//    {
//        getline(cin,cd);
//        srch=search_Inventory(cd,2);
//        if(srch==NULL)
//            break;
//        else
//        {
//            cout << "Medicine already exists." << endl;
//            cout << "Enter a unique Medicine Code : ";
//        }
//    }
//    cout << "Enter Cost Price : ";
//    while(1)
//    {
//        getline(cin,check);
//        cp=check_price(check);
//        if(cp !=0)
//            break;
//        else
//        {
//            cout << "Invalid Input!";
//            cout << "Enter Valid price : ";
//        }
//    }
//    cout << "Enter Selling Price : ";
//    while(1)
//    {
//        getline(cin,check);
//        sp=check_price(check);
//        if(sp !=0)
//            break;
//        else
//        {
//            cout << "Invalid Input!";
//            cout << "Enter Valid price : ";
//        }
//    }
//
//    goto_quant :
//    cout << "Enter Quantity : ";
//    while(1)
//    {
//        getline(cin,check);
//        quant = check_number(check);
//        if(quant !=0)
//            break;
//        else
//            cout << "Invalid Quantity!\nEnter Valid Quantity : ";
//    }
//
//    if(srch==NULL)
//    {
//        Medicine *new_node= new Medicine();
//        new_node->next=NULL;
//        new_node->name=nm;
//        new_node->code=cd;
//        new_node->CP=cp;
//        new_node->SP=sp;
//        new_node->quantity=quant;
//        if(start==NULL)
//            start=new_node;
//        else
//        {
//            struct Medicine *tmp;
//            tmp=start;
//            while(tmp->next!=NULL)
//                tmp=tmp->next;
//            tmp->next=new_node;
//        }
//    }
//    else
//        srch->quantity+=quant;
//    cout << "Medicine Added.\nPress any key to exit.";
//    getch();
//}
//
//
//
//void Inventory :: display_Inventory()
//{
//    system("cls");
//    if(start==NULL)
//    {
//        cout << "Inventory is empty." << endl;
//        cout << "Press any key to exit : ";
//        getch();
//        return ;
//    }
//    else
//    {
//        struct Medicine *tmp;
//        tmp=start;
//        cout << fixed << showpoint;
//        cout << setprecision(2);
//        cout << std::left <<  setw(10)  << "Name" << setw(10) << "Code" << setw(10) << "Quantity" << setw(15) << "Cost Price" << setw(15) << "Selling Price" <<endl << endl;
//        while(tmp!=NULL)
//        {
//            cout << setw(10) << tmp->name << setw(10) << tmp->code << setw(10) << tmp->quantity << setw(15) << tmp->CP << setw(15) << tmp->SP  << endl;
//            tmp=tmp->next;
//        }
//    }
//    cout << "Press any key to exit : ";
//    getch();
//}
//
//Inventory::Medicine* Inventory :: search_Inventory(string key,int flag)
//{
//    struct Medicine *temp;
//    temp=start;
//    if(flag == 1)
//    {
//        while(temp!=NULL)
//        {
//            if(temp->name == key)
//                return temp;
//            temp=temp->next;
//        }
//    }
//    else if(flag == 2)
//    {
//        while(temp!=NULL)
//        {
//            if(temp->code == key)
//            {
//                return temp;
//            }
//            temp=temp->next;
//        }
//    }
//    return NULL;
//}
//
//void Inventory :: write_to_file()
//{
//    if(start==NULL)
//    {
//        remove("Inventory.txt");
//        return;
//    }
//    ofstream fout("Inventory.txt");
//    struct Medicine *temp;
//    temp=start;
//    while(temp!=NULL)
//    {
//        if(temp!=start)
//            fout << '\n';
//        fout << temp->name << endl;
//        fout << temp->code << endl;
//        fout << temp->quantity << endl;
//        fout << temp->CP << endl;
//        fout << temp->SP;
//        temp=temp->next;
//    }
//    fout.close();
//    cout << "Written to file." << endl;
//}
//
//void Inventory :: read_from_file()
//{
//    stock.start=NULL;
//    ifstream fin("Inventory.txt");
//    if(!fin)                                                        //Checking if file exists or not.
//    {
//        start=NULL;
//        fin.close();
//        return;
//    }
//    string nm,cd,q,sp,cp;
//    while(!fin.eof())
//    {
//        Medicine *new_node= new Medicine();
//        new_node->next=NULL;
//        getline(fin,new_node->name);
//        getline(fin,new_node->code);
//        fin >> new_node->quantity;
//        fin.get();
//        fin >> new_node->CP;
//        fin.get();
//        fin >> new_node->SP;
//        fin.get();
//        if(start==NULL)
//            start=new_node;
//        else
//        {
//            struct Medicine *temp;
//            temp=start;
//            while(temp->next!=NULL)
//                temp=temp->next;
//            temp->next=new_node;
//        }
//    }
//    fin.close();
//}
//
//void Inventory :: modify_inventory()
//{
//    char ch;
//    system("cls");
//    while(1)
//    {
//        cout << "1. Add to inventory      : " << endl;
//        cout << "2. Delete from inventory : " << endl;
//        cout << "0. Exit                  : " << endl;
//        cout << "   Enter your choice     : ";
//        ch=getch();
//        if(ch=='0')
//            break;
//        switch(ch)
//        {
//            case '1' :
//                add_to_inventory();
//                system("cls");
//            break;
//
//            case '2' :
//                delete_inventory();
//                system("cls");
//            break;
//
//            default :
//                system("cls");
//                cout << "Invalid Choice!" << endl;
//        }
//    }
//}
//
//void Inventory :: add_to_inventory()
//{
//    char op;
//    system("cls");
//    while(1)
//    {
//        cout << "1. Search by Name : " << endl;
//        cout << "2. Search by Code : " << endl;
//        cout << "3. Exit           : " << endl;
//        cout << "Enter your choice : ";
//        op = getche();
//        if(op == '3')
//            return;
//        else if(op == '1' || op == '2')
//        {
//            Medicine* srch=NULL;
//            string key,quant;
//            int q;
//            cout << endl;
//            if(op=='1')
//                cout << "Enter Name : ";
//            else
//                cout << "Enter Code : ";
//            getline(cin,key);
//            srch=search_Inventory(key,op-48);
//            if(srch == NULL)
//            {
//                cout << "Medicine not found." << endl;
//                cout << "Enter valid Input : " << endl;
//            }
//            else
//            {
//                system("cls");
//                while(1)
//                {
//                    display_specific_medicine(srch);
//                    cout << "Enter the Quantity to delete : ";
//                    getline(cin,quant);
//                    q=check_number(quant);
//                    if(q==0)
//                    {
//                        system("cls");
//                        cout << "Invalid Choice!\n" << endl;
//                        continue;
//                    }
//                    else
//                    {
//                        srch->quantity+=q;
//                        system("cls");
//                        display_specific_medicine(srch);
//                        cout << "Inventory Updated.\n";
//                        cout << "Press any key to exit :" << endl;
//                        getch();
//                        system("cls");
//                        break;
//                    }
//                }
//            }
//        }
//        else
//        {
//            system("cls");
//            cout << "Invalid Choice!" << endl;
//        }
//    }
//}
//
//void Inventory :: delete_inventory()
//{
//    char op;
//    system("cls");
//    while(1)
//    {
//        cout << "1. Search by Name : " << endl;
//        cout << "2. Search by Code : " << endl;
//        cout << "3. Exit           : " << endl;
//        cout << "Enter your choice : ";
//        op = getche();
//        if(op == '3')
//            return;
//        else if(op == '1' || op == '2')
//        {
//            if(start==NULL)
//            {
//                system("cls");
//                cout << "Inventory is empty." << endl;
//                cout << "Press any key to exit : " << endl;
//                continue;
//            }
//            Medicine* srch=NULL;
//            string key,quant;
//            int q;
//            cout << endl;
//            if(op=='1')
//                cout << "Enter Name : ";
//            else
//                cout << "Enter Code : ";
//            getline(cin,key);
//            srch=search_Inventory(key,op-48);
//            if(srch == NULL)
//            {
//                system("cls");
//                cout << "Medicine not found." << endl;
//                cout << "Enter valid Input : " << endl;
//            }
//            else
//            {
//                system("cls");
//                while(1)
//                {
//                    display_specific_medicine(srch);
//                    cout << "Enter the Quantity : ";
//                    getline(cin,quant);
//                    q=check_number(quant);
//                    if(q==0)
//                    {
//                        system("cls");
//                        cout << "Invalid Choice!\n" << endl;
//                        continue;
//                    }
//                    else
//                    {
//                        if(q > srch->quantity)
//                        {
//                            system("cls");
//                            cout << "Entered Quantity is greater than Quantity Present." << endl;
//                            continue;
//                        }
//                        else if(q < srch->quantity)
//                            srch->quantity-=q;
//                        else
//                        {
//                            if(start==NULL)
//                            {
//                                cout << "\nInventory is empty." << endl;
//                                cout << "Press any key to exit : ";
//                                getch();
//                                system("cls");
//                                break;
//                            }
//                            Medicine* temp1=start;
//                            Medicine* temp2=start->next;
//                            if((start->name == key)||(start->code == key))
//                            {
//                                system("cls");
//                                start = start->next;
//                                display_specific_medicine(temp1);
//                                cout << "Medicine deleted." << endl;
//                                cout << "Press any key to exit." << endl;
//                                free(temp1);
//                                getch();
//                                system("cls");
//
//                            }
//                            else
//                            {
//                                while(temp2!=NULL)
//                                {
//                                    if((op == '1' && temp2->name == key)||(op == '2' && temp2->code == key))
//                                    {
//                                        system("cls");
//                                        display_specific_medicine(temp2);
//                                        cout << "Medicine deleted." << endl;
//                                        cout << "Press any key to exit." << endl;
//                                        getch();
//                                        system("cls");
//                                        break;
//                                    }
//                                    temp1=temp1->next;
//                                    temp2=temp2->next;
//                                }
//                                if(temp2 == NULL)
//                                {
//                                    system("cls");
//                                    cout << "Medicine not found." << endl;
//                                }
//                                else
//                                {
//                                    temp1->next=temp2->next;
//                                    free(temp2);
//                                }
//                            }
//                            break;
//                        }
//                        system("cls");
//                        if(srch->quantity!=q)
//                        {
//                            display_specific_medicine(srch);
//                            cout << "Inventory Updated.\n";
//                            cout << "Press any key to exit :" << endl;
//                            getch();
//                            system("cls");
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//        else
//        {
//            system("cls");
//            cout << "Invalid Choice!" << endl;
//        }
//    }
//}
//
//void Inventory :: delete_Medicine()
//{
//    char op;
//    system("cls");
//    while(1)
//    {
//        cout << "1. Search by Name : " << endl;
//        cout << "2. Search by Code : " << endl;
//        cout << "3. Exit           : " << endl;
//        cout << "Enter your choice : ";
//        op = getche();
//        if(op == '3')
//            return;
//        else if(op == '1' || op == '2')
//        {
//            if(start==NULL)
//            {
//                cout << "\nInventory is empty." << endl;
//                cout << "Press any key to exit : ";
//                getch();
//                system("cls");
//                continue;
//            }
//            Medicine* temp1=start;
//            Medicine* temp2=start->next;
//            string key,quant;
//            int q;
//            cout << endl;
//            if(op=='1')
//                cout << "Enter Name : ";
//            else
//                cout << "Enter Code : ";
//            getline(cin,key);
//            if((op == '1' && start->name == key)||(op == '2' && start->code == key))
//            {
//                system("cls");
//                start = start->next;
//                display_specific_medicine(temp1);
//                cout << "Medicine deleted." << endl;
//                cout << "Press any key to exit." << endl;
//                free(temp1);
//                getch();
//                system("cls");
//            }
//            else
//            {
//                while(temp2!=NULL)
//                {
//                    if((op == '1' && temp2->name == key)||(op == '2' && temp2->code == key))
//                    {
//                        system("cls");
//                        display_specific_medicine(temp2);
//                        cout << "Medicine deleted." << endl;
//                        cout << "Press any key to exit." << endl;
//                        getch();
//                        system("cls");
//                        break;
//                    }
//                    temp1=temp1->next;
//                    temp2=temp2->next;
//                }
//                if(temp2 == NULL)
//                {
//                    system("cls");
//                    cout << "Medicine not found." << endl;
//                }
//                else
//                {
//                    temp1->next=temp2->next;
//                    free(temp2);
//                }
//            }
//        }
//        else
//        {
//            system("cls");
//            cout << "Invalid Choice!." << endl << endl;
//        }
//    }
//}
//
//void Inventory :: display_specific_medicine(struct Medicine* temp)
//{
//    cout << fixed << showpoint;
//    cout << setprecision(2);
//    cout << std::left <<  setw(10)  << "Name" << setw(10) << "Code" << setw(10) << "Quantity" << setw(15) << "Cost Price" << setw(10) << "Selling Price" <<endl << endl;
//    cout << setw(10) << temp->name << setw(10) << temp->code << setw(10) << temp->quantity << setw(15) << temp->CP << setw(10) << temp->SP << endl;
//}
