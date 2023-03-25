#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

// Here is the prototypes of all functions

// Header Functions
void topHeader();
void welcomeMenu();
string signInterface();

// SignUp and SignIn Fuctions
void signup(string userName,string password,string role);
string signin(string userName,string password);

// Validation Functions
bool isValidUserName(string userName); 
bool isValidName(string userName);
bool isValidPassword(string);
bool isValidRole(string);
bool isValidChoice(string);
bool isValidPrice(string);
bool isValidDeal(string);
bool dishvalidation(string dish);
bool coldDrinkvalidation(string);

// Data storing function in files
void storeUsersInFile(string userName,string password,string role);
void storeDishesInFile();
void storeDealsInFile();
void storeColdDrinksInFile();
void storeCommentsInFile(string);

// Data reading functions from files
void arrayFillingForUsers();
void arrayFillingForDishes();
void arrayFillingForDeals();
void arrayFillingForComments();
void arrayFillingForColdDrinks();

// Manager Functionalety Functions
string managerInterface();
void addDish(string , int);
void updatePrice(string,int);
void deleteDish(string dish);
void addDeal(string , int);
void updateDealPrice(int , int);
void deleteDeal(int);
void addColdDrink(string,int);
void updateColdDrinkPrice(string,int);
void viewComents();

// Customer Functionalety Functions
string customerInterface();
void dishesMenu();
void giveOrder(string ,int);
void viewDeals();
void orderDeal(string,int);
void colddrinkMenu();
void orderColdDrink(string , int);
int viewbill();
void feedback(string);

// Helping Functions
void pressAnyKey();
void SuccessMessage(string);
void message(string);
void optionMenu(string);
void fillDishesGap();
string userInput(string);
string userInputWithSpaces(string);
int priceInput(string);

// Global Variables for Arrays Control
int userCount = 0;
int dishCount = 0;
int dealCount = 0;
int orderitems = 0;
int commentCount = 0;
int coldDrinkCount = 0;

int noOfDishes = 10;

// Global Arrays for Storing different data
string names[10] = {};
string passwords[10] = {};
string roles[10] = {};

string dishes[10] = {""};
int prices[10]; 
string deals[10] = {};
int dealPrices[10] = {};
string coldDrinks[10] = {};
int coldDrinkPrices[10] = {};
string comments[10] = {};
string order[10];
int quantities[10] = {0};

// Main Function
main()
{

    system("cls");                              // Clearing Screen

    arrayFillingForUsers();
    arrayFillingForDishes();
    arrayFillingForComments();                 // Array filling from files
    arrayFillingForColdDrinks();
    arrayFillingForDeals();
    welcomeMenu();
    topHeader();                               // Top Header 

    int choice = 0;
    while(choice !=3)
    {
        string tempChoice = signInterface();
        if(isValidChoice(tempChoice))
        {
            choice = stoi(tempChoice);
        }
        else
        {
            message("Invalid choice!");
            pressAnyKey();
        }
        if(choice == 1)
        {
            optionMenu("Signup");
            string name = userInput("your name");
            if(isValidUserName(name))
            {
                if(isValidName(name))
                {
                    string password = userInput("your password");
                    if(isValidPassword(password))
                    {
                        string role = userInput("your role");
                        if(isValidRole(role))
                        {
                            signup(name,password,role);
                            storeUsersInFile(name,password,role);
                            SuccessMessage("Signed Up");
                        }
                        else
                        {
                            message("Role can only be Manager or Customer.");

                        } 
                    }
                    else
                    {
                        message("The password must contain atleast 5 digits");
                        message("Password must contain 1 small & 1 capital letter");
                    }
                }
                else
                {
                    message("User name must be like gmail or facebook");
                    message("Samples : name@gmail.com \t name@facebook.com");
                } 
            }
            else
            {
                message("UserName already exists");
            }
            pressAnyKey();
        }
        else if(choice == 2)
        {

            optionMenu("Signin");
            string name = userInput("your name");
            string password = userInput("your password");
            string role = signin(name,password);
            if(role == "Manager" || role == "manager")
            {
                int mchoice = 0;
                while(mchoice != 11)
                {
                    mchoice = 0;     ///  If this is not done it will continue opening particualr option that is opened once
                    string tempmChoice = managerInterface();
                    if(isValidChoice(tempmChoice))
                    {
                        mchoice = stoi(tempmChoice);
                    }
                    else
                    {
                        message("Invalid choice!");
                        pressAnyKey();
                    }
                    if(mchoice == 1)
                    {
                        optionMenu("Add dish");
                        string newdish = userInput("new dish");
                        string tempPrice = userInput("price of new dish");
                        if(isValidPrice(tempPrice))
                        {
                            int price = stoi(tempPrice);
                            addDish(newdish,price);
                            SuccessMessage("Dish Added");
                        }
                        else
                        {
                            message("Invalid Price");
                        }
                        pressAnyKey();
                    }
                    else if(mchoice == 2)
                    {
                        optionMenu("Delete dish");
                        string dish = userInput("dish name");
                        if(dishvalidation(dish))
                        {
                            deleteDish(dish);
                            fillDishesGap();
                            SuccessMessage("Dish Deleted");
                        }
                        else
                        {
                           message("Invalid dish!");
                        }
                        pressAnyKey();
                    }
                    else if(mchoice == 3)
                    {
                        optionMenu("Update Price");
                        string dish = userInput("the dish");
                        if(dishvalidation(dish))
                        {
                            string tempPrice = userInput("the new price");
                            if(isValidPrice(tempPrice))
                            {
                                int price = stoi(tempPrice);
                                updatePrice(dish,price);
                                SuccessMessage("Price Updated");
                            }
                            else
                            {
                                message("Invalid Price");
                            }
                        }
                        else
                        {
                            message("Invalid dish!");
                        }
                        pressAnyKey();
                        
                    }
                    else if(mchoice == 4)
                    {
                        optionMenu("Add deal");
                        string newdeal = userInputWithSpaces("new deal");
                        string tempPrice = userInput("the price of deal");
                        if(isValidPrice(tempPrice))
                        {
                            int price = stoi(tempPrice);
                            addDeal(newdeal , price);
                            SuccessMessage("Deal Added");
                        }
                        else
                        {
                            message("Invalid Price");
                        } 
                        pressAnyKey();
                    }
                    else if(mchoice == 5)
                    {
                        string tempdealno = userInput("the deal number");
                        if(isValidDeal(tempdealno))
                        {
                            int dealno = stoi(tempdealno);
                            string tempPrice = userInput("the updated price of deal");
                            if(isValidPrice(tempPrice))
                            {
                                int price = stoi(tempPrice);
                                updateDealPrice(dealno,price);
                                SuccessMessage("Deal Updated");
                            }
                            else
                            {
                                message("Invalid Price");
                            }   
                        }
                        else
                        {
                            message("Invalid deal!");
                        }
                        pressAnyKey();
                    }
                    else if(mchoice == 6)
                    {
                        string tempdealno = userInput("deal number");
                        if(isValidDeal(tempdealno))
                        {
                            int dealno = stoi(tempdealno);
                            deleteDeal(dealno);
                            SuccessMessage("Deal Deleted");
                        }
                        else
                        {
                            message("Invalid deal!");
                        }
                        pressAnyKey();
                    }
                    else if(mchoice == 7)
                    {
                        optionMenu("Add cold drink");
                        string newColdDrink = userInput("new cold drink");
                        string tempPrice = userInput("the price of new cold drink");
                        if(isValidPrice(tempPrice))
                        {
                            int price = stoi(tempPrice);
                            addColdDrink(newColdDrink,price);
                            SuccessMessage("Cold Drink Added");

                        }
                        else
                        {
                            message("Invalid Price");
                        }
                        pressAnyKey();
                    }
                    else if(mchoice == 8)
                    {
                        optionMenu("Update cold drink price");
                        string coldDrink = userInput("cold drink");
                        if(coldDrinkvalidation(coldDrink))
                        {
                            string tempPrice = userInput("the new price cold drink");
                            if(isValidPrice(tempPrice))
                            {
                                int price = stoi(tempPrice);
                                updateColdDrinkPrice(coldDrink,price);
                                SuccessMessage("Price Updated");
                            }
                            else
                            {
                                message("Invalid Price");
                            }
                        }
                        else
                        {
                            message("Invalid cold drink!");
                        }
                        pressAnyKey();
                        
                    }
                    else if(mchoice == 9)
                    {
                        message("  -----------Comments-------------  " );
                        viewComents();
                        pressAnyKey();
                    }
                    else if(mchoice == 10)
                    {
                        cout << "The bill of current customer : " <<  viewbill() << endl;
                        pressAnyKey();
                    }
                    storeDishesInFile();             
                    storeColdDrinksInFile();
                    storeDealsInFile();
                }
            }
            else if(role == "Customer" || role == "customer")
            {
                int cchoice = 0;
                while(cchoice != 9)
                {
                    cchoice = 0;
                    string tempcChoice = customerInterface();
                    if(isValidChoice(tempcChoice))
                    {
                        cchoice = stoi(tempcChoice);
                    }
                    else
                    {
                        message("Invalid Choice !");
                        pressAnyKey();
                    }
                    if(cchoice == 1)
                    {
                        message("  Dishes        Prices  " );
                        dishesMenu();
                        pressAnyKey();
                    }
                    else if(cchoice == 2)
                    {
                        string option = "y";
                        while(option == "y")
                        {  
                            string dish = userInput("dish you wanna order");
                            if(dishvalidation(dish))
                            {
                                string tempQuantity = userInput("the quantity");
                                if(isValidPrice(tempQuantity))
                                {
                                    int quantity = stoi(tempQuantity);
                                    message("Press y to add more dish or press any key to go back.");
                                    option  = getch();
                                    giveOrder(dish,quantity);
                                }
                                else
                                {
                                    message("Invalid Quantity");
                                }
                            }
                            else
                            {
                                message("You have ordered an invalid dish.");
                            }
                        }
                        SuccessMessage("Order given");
                        pressAnyKey();
                    }
                    else if(cchoice == 3)
                    {
                        viewDeals();
                        pressAnyKey();
                    }
                    else if(cchoice == 4)
                    {
                        string dealno = userInput("deal number to order");
                        if(isValidDeal(dealno))
                        {
                            string tempQuantity = userInput("the quantity");
                            if(isValidPrice(tempQuantity))
                            {
                                int quantity = stoi(tempQuantity);
                                orderDeal(dealno,quantity);
                                SuccessMessage("Deal Ordered");
                            }
                            else
                            {
                                message("Invalid Quantity");
                            } 
                        }
                        else
                        {
                            message("You have ordered an invalid deal.");
                        }
                        pressAnyKey();
                    }
                    else if(cchoice == 5)
                    {
                        message("  Colddrinks      Prices  ");
                        colddrinkMenu();
                        pressAnyKey();
                    }
                    else if(cchoice == 6)
                    {
                        string colddrink = userInput("cold drink");
                        if(coldDrinkvalidation(colddrink))
                        {
                            string tempQuantity = userInput("the quantity");
                            if(isValidPrice(tempQuantity))
                            {
                                int quantity = stoi(tempQuantity);
                                orderColdDrink(colddrink,quantity);
                                SuccessMessage("Cold Drink Ordered");
                            }
                            else
                            {
                                message("Invalid Quantity");
                            } 
                        }
                        else
                        {
                            message("You have ordered an invalid cold drink.");
                        }
                        pressAnyKey();
                    }
                    else if(cchoice == 7)
                    {
                        message("  Items          Quantity       Price  ");     
                        cout << "Total bill : " <<  viewbill() << endl;
                        pressAnyKey();
                    }
                    else if(cchoice == 8)
                    {
                        string comment = userInputWithSpaces("comment");
                        feedback(comment);
                        storeCommentsInFile(comment);
                        message("Thanks for your feedback");
                        pressAnyKey();
                    }
                }
            }
            else
            {
                cout << "You have entered wrong username or password!" << endl;
                pressAnyKey();
            }
        }
    }
    
    

}


void topHeader()
{
    cout << "##########################################" << endl;
    cout << "####                                  ####" << endl;
    cout << "####    RESTAURANT MANAGMENT SYSTEM   ####" << endl;
    cout << "####                                  ####" << endl;
    cout << "##########################################" << endl;
}

void welcomeMenu()
{
    
    cout << "  $$\\      $$\\           $$\\                   "<< endl;                          
    cout << "  $$ | $\\  $$ |          $$ |                     "<< endl;                       
    cout << "  $$ |$$$\\ $$ | $$$$$$\\  $$ | $$$$$$$\\  $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  "<< endl;
    cout << "  $$ $$ $$\\$$ |$$  __$$\\ $$ |$$  _____|$$  __$$\\ $$  _$$  _$$\\ $$  __$$\\ "<< endl;
    cout << "  $$$$  _$$$$ |$$$$$$$$ |$$ |$$ /      $$ /  $$ |$$ / $$ / $$ |$$$$$$$$ | "<< endl;
    cout << "  $$$  / \\$$$ |$$   ____|$$ |$$ |      $$ |  $$ |$$ | $$ | $$ |$$   ____| "<< endl;
    cout << "  $$  /   \\$$ |\\$$$$$$$\\ $$ |\\$$$$$$$\\ \\$$$$$$  |$$ | $$ | $$ |\\$$$$$$$\\  "<< endl;
    cout << "  \\__/     \\__| \\_______|\\__| \\_______| \\______/ \\__| \\__| \\__| \\_______| "<< endl;
    cout << endl << endl;
    cout << "Press any key to Continue  ";
    getch();
                                                                                                                                             

}

string signInterface()
{
    system("cls");
    topHeader();
    string choice;
    cout << "1-       Signup" << endl ;
    cout << "2-       Signin" << endl; 
    cout << "3-       Exit" << endl;
    cout << "Enter your choice >>  ";
    cin >> choice;
    return choice;

}


string managerInterface()
{
    system("cls");
    topHeader();
    string choice;
    cout << "   Manager Interface  " << endl << "-----------------------"<< endl;
    cout << "1-       Add new dish" << endl ;
    cout << "2-       Delete dish" << endl; 
    cout << "3-       Update price" << endl;
    cout << "4-       Add deal" << endl ;
    cout << "5-       Update deal price" << endl; 
    cout << "6-       Delete deal" << endl;
    cout << "7-       Add cold drink" << endl ;
    cout << "8-       Update cold drink price" << endl; 
    cout << "9-       View comments" << endl;
    cout << "10-      View bill" << endl ;
    cout << "11-      Back" << endl; 
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

string customerInterface()
{
    system("cls");
    topHeader();
    string choice;
    cout << "   Customer Interface  " << endl << "-----------------------"<< endl;
    cout << "1-       View Menu" << endl ;
    cout << "2-       Give order" << endl; 
    cout << "3-       View deals" << endl;
    cout << "4-       Order deals" << endl ;
    cout << "5-       View cold drinks" << endl; 
    cout << "6-       Order cold drink" << endl; 
    cout << "7-       View bill" << endl;
    cout << "8-       Feedback" << endl;
    cout << "9-       Back" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

void addDish(string newdish,int price)
{

    dishes[dishCount] = newdish;
    prices[dishCount] = price;
    dishCount++;
}


void searchDish()
{
    string nm;
    cout << "Enter the name : ";
    cin >> nm;
    for (int i = 0 ; i < 10 ; i++)
    {
        if(nm == dishes[i])
        {
            cout << "     " << dishes[i] << "    " << "\t\t" << prices[i] << endl;
        }
    }
}



void updatePrice(string dish,int price)
{
    for (int i = 0 ; i < dishCount ; i++)
    {
        if(dish == dishes[i])
        {
            prices[i] = price;
        }
    }
}

void deleteDish(string dish)
{
    for (int i = 0 ; i < dishCount ; i++)
    {
        if(dish == dishes[i])
        {
            dishes[i] = "";
            prices[i] = 0;
        }
    }
}

void fillDishesGap()
{
    for(int i = 0; i < dishCount; i++)
    {
        if(dishes[i]=="")
        {
            string temp = dishes[i];
            dishes[i] = dishes[i+1];
            prices[i] = prices[i+1];
            dishes[i+1] = temp;
        }
    }
    dishCount--;
}

void addDeal(string newdeal,int price)
{
    deals[dealCount] = newdeal;
    dealPrices[dealCount] = price;
    dealCount++;
}

void updateDealPrice(int dealno,int price)
{
    dealPrices[dealno-1] = price;

}


void deleteDeal(int dealno)
{
    deals[dealno-1] = "";
    dealPrices[dealno-1] = 0;
}


void addColdDrink(string newColdDrink,int price)
{

    coldDrinks[coldDrinkCount] = newColdDrink;
    coldDrinkPrices[coldDrinkCount] = price;
    coldDrinkCount++;

}

void updateColdDrinkPrice(string coldDrink,int price)
{
    for (int i = 0 ; i < coldDrinkCount ; i++)
    {
        if(coldDrink == coldDrinks[i])
        {
            coldDrinkPrices[i] = price;
        }
    }
}

void viewComents()
{
    for(int i = 0; i < 10 ; i++)
    {
        if(comments[i] == "")
            cout <<"";
        else
            cout << "  " << comments[i] << endl;
    }
}


void dishesMenu()
{
    for(int i = 0; i < dishCount ; i++)
    {
        cout << "  " << dishes[i] << "    " << "\t" << prices[i] << endl;
    }

}

void giveOrder(string dish,int quantity)
{
    order[orderitems] = dish;
    quantities[orderitems] = quantity;
    orderitems++;
}

void viewDeals()
{
    for(int i = 0 ; i < dealCount ; i++)
    {
        if(deals[i] != "")
        {
            cout << "Deal   " << i+1 << endl;
            cout << deals[i] << endl;
            cout << "Price : "<< dealPrices[i] << endl;
        }  
    }
}

void orderDeal(string dealno,int quantity)
{
    order[orderitems] = dealno;
    quantities[orderitems] = quantity;
    orderitems++;
}

void colddrinkMenu()
{
    for(int i = 0; i < coldDrinkCount ; i++)
    {
        cout << "   " << coldDrinks[i] << "      " << "\t" << coldDrinkPrices[i] << endl;
    }
}

void orderColdDrink(string colddrink,int quantity)
{
    order[orderitems] = colddrink;
    quantities[orderitems] = quantity;
    orderitems++;
}

int viewbill()
{
    int bill = 0;
    int traverse = 0;
    for(int i = 0;i < orderitems;i++)
    {
        int orderLength = order[i].length();
        for (int k = 0 ; k < dishCount ; k++)
        {
            if(order[i]==dishes[k])
            {
                cout << "  " << order[i] << "    " << "\t" << quantities[i]<< "      " << "\t" << prices[k] << endl;
                int pro = 1;
                pro = prices[k]*quantities[i];
                bill = bill + pro;
                traverse++;
                break; 

            }
        }
        for (int k = 0 ; k < coldDrinkCount ; k++)
        {
            if(order[i]==coldDrinks[k])
            {
                cout << "  " << order[i] << "    " << "\t" << quantities[i]<< "      " << "\t" << coldDrinkPrices[k] << endl;
                int pro = 1;
                pro = coldDrinkPrices[k]*quantities[i];
                bill = bill + pro;
                traverse++;
                break;

            }

        }
        if(orderLength == 1)
        {
            for (int k = 0 ; k < 10 ; k++)
            {
                int deal = stoi(order[traverse]);
                if(deal==k)
                {
                    cout << "  Deal " << k << "    " << "\t" << quantities[traverse]<< "       " << "\t" << dealPrices[k-1] << endl;
                    int pro = 1;
                    pro = dealPrices[k-1]*quantities[traverse];
                    bill = bill + pro;

                }

            }
        }
    }
    

    return bill;

}

void feedback(string comment)
{
    comments[commentCount] = comment;
    commentCount++;
}


bool dishvalidation(string dish)
{
    for (int j = 0 ; j < 10 ; j++)
    {
        if(dish == dishes[j])
        {
            return true;
        }
            
    }
    return false;
        
}

bool coldDrinkvalidation(string coldDrink)
{
    for (int j = 0 ; j < 10 ; j++)
    {
        if(coldDrink == coldDrinks[j])
        {
            return true;
        }
            
    }
    return false;
        
}


void signup(string userName,string password,string role)
{
    names[userCount]=userName;
    passwords[userCount] = password;
    roles[userCount] = role;
    userCount++;
}

void storeUsersInFile(string userName,string password,string role)
{
    fstream files;
    files.open("Users.txt",ios::app);
    files << userName << endl; 
    files << password << endl; 
    files << role << endl; 
    files.close();

}

void storeDishesInFile()
{
    fstream files;
    files.open("Dishes.txt",ios::out);
    for (int k = 0 ; k < dishCount ; k++)
    {
        files << dishes[k] << endl; 
        files << prices[k] << endl; 
    }
    files.close();
}

void storeColdDrinksInFile()
{
    fstream files;
    files.open("Colddrinks.txt",ios::out);
    for (int k = 0 ; k < coldDrinkCount ; k++)
    {
        files << coldDrinks[k] << endl; 
        files << coldDrinkPrices[k] << endl; 
    }
    files.close();
}

void storeDealsInFile()
{
    fstream files;
    files.open("Deals.txt",ios::out);
    for (int k = 0 ; k < dealCount ; k++)
    {
        files << deals[k] << endl; 
        files << dealPrices[k] << endl; 
    }
    files.close();
}

void storeCommentsInFile(string comment)
{
    fstream files;
    files.open("Comments.txt",ios::app);
    files << comment << endl; 
    files.close();

}


string signin(string userName,string password)
{
    string role;
    for(int i = 0; i < userCount; i++)
    {
        if(userName == names[i] && password == passwords[i])
        {
            role = roles[i];
        }
    }
    return role;
}

void allUsers()
{
    for(int i = 0; i < userCount; i++)
    {
        cout << names[i] << "\t" << passwords[i] << endl;
    }
}

bool isValidUserName(string userName)
{
    bool flag = true;
    for(int i = 0; i < userCount; i++)
    {
        if(userName == names[i])
        {
            flag = false;
        }
    }
    return flag;

}
bool isValidName(string name)
{
    bool flag = false;
    int len = name.length();
    string app;
    string ext;
    int i = 0;
    while(name[i] != '@' && i < len)
    {
        i++;
    }
    while(name[i] != '.' && i < len)
    {
        app = app + name[i];
        i++;
    }
    for(i; i < len; i++)
    {
        ext = ext + name[i];
    }
    if((app == "@gmail" || app == "@facebook" || app == "@hotmail" || app == "@yahoo") && ext == ".com")
    {
        flag = true;
    }
    return flag;

}

bool isValidPassword(string password)
{
    bool flag = false;
    int len = password.length();
    int countS = 0;
    int countL = 0;
    if(len >= 5)
    {
        for(int i = 0; i < len; i++)
        {
            if(password[i] >= 97 && password[i]<=122)
            {
                countS++;
            }
            else if(password[i] >= 65 && password[i]<=90)
            {
                countL++;
            }
        }
        if(countS >= 1 && countL >= 1)
        {
            flag = true;
        }
    }
    return flag;

}

bool isValidChoice(string choice)
{
    bool flag = false;
    int len = choice.length();
    int count = 0;
    if(len = 1)
    {
        for(int i = 0; i < len; i++)
        {
            if(choice[i] >= 48 && choice[i]<=57)
            {
                count++;
            }
        }
        if(count >= 1)
        {
            flag = true;
        }
    }
    return flag;
}

bool isValidPrice(string price)
{
    bool flag = false;
    int len = price.length();
    int count = 0;
    if(len <= 9)
    {
        for(int i = 0; i < len; i++)
        {
            if(price[i] >= 48 && price[i]<=57)
            {
                count++;
            }
        }
        if(count == len)
        {
            flag = true;
        }
    }
    return flag;
}

bool isValidDeal(string deal)
{
    bool flag = false;
    int len = deal.length();
    int count = 0;
    if(len == 1 && deal[0] >= 48 && deal[0]<=57)
    {
        flag = true;
    }
    return flag;

}
bool isValidRole(string role)
{
    bool flag = false;
    if(role == "Manager" || role == "manager" || role == "Customer" || role == "customer")
    {
        flag = true;
    }
    return flag;

}

void pressAnyKey()
{
    cout << "Enter any key to go back >> ";
    getch();
}

void SuccessMessage(string message)
{
    cout << message << " Sucessfully!" << endl;
}

void message(string message)
{
    cout << message << endl;
}

string userInput(string message)
{
    string store;
    cout << "Enter " << message << " : ";
    cin >> store;
    return store;

}

string userInputWithSpaces(string message)
{
    string store;
    cout << "Enter the " << message << " : ";
    cin.ignore();
    getline(cin,store);
    return store;

}

void optionMenu(string message)
{
    cout << "---------------------------------------"<< endl;
    cout << "        " << message << " Menu" << endl;
    cout << "---------------------------------------"<< endl;
}

int priceInput(string message)
{
    int store;
    cout << "Enter the " << message << " : ";
    cin >> store;
    return store;

}

void arrayFillingForUsers()
{
    int i = 0;
    fstream files;
    files.open("Users.txt",ios::in);
    while(!files.eof())
    {
        string name,password,role;
        getline(files,name);
        getline(files,password);
        getline(files,role);
        names[i] = name;
        passwords[i] = password;
        roles[i] = role;
        i++;
        userCount = i;
            
    }
}

void arrayFillingForDishes()
{
    int i = 0;
    fstream files;
    files.open("Dishes.txt",ios::in);
    while(!files.eof())
    {
        string dish = "",price = "";
        int pri;
        getline(files,dish);
        if (dish == "") break;
        getline(files,price);
        pri = stoi(price);
        dishes[i] = dish;
        prices[i] = pri;
        i++;
        dishCount = i;
            
    }

}

void arrayFillingForComments()
{
    fstream files;
    files.open("Comments.txt",ios::in);
    while(!files.eof())
    {
        string comment;
        getline(files,comment);
        comments[commentCount] = comment;
        commentCount++; 
    }
}

void arrayFillingForColdDrinks()
{
    fstream files;
    files.open("Colddrinks.txt",ios::in);
    while(!files.eof())
    {
        string colddrink,price;
        getline(files,colddrink);
        if (colddrink == "") break;
        getline(files,price);
        coldDrinks[coldDrinkCount] = colddrink;
        coldDrinkPrices[coldDrinkCount] = stoi(price);
        coldDrinkCount++; 
    }
}

void arrayFillingForDeals()
{
    fstream files;
    files.open("Deals.txt",ios::in);
    while(!files.eof())
    {
        string deal,price;
        getline(files,deal);
        if (deal == "") break;
        getline(files,price);
        deals[dealCount] = deal;
        dealPrices[dealCount] = stoi(price);
        dealCount++; 
    }
}
