#include <iostream>
#include <windows.h>
#include <fstream>
#include <unistd.h>
#include <iomanip>
#include <time.h>
#include <vector>
#include <string>// this will check if string contains specific word
using namespace std; 
void customer();  // customer part 
bool exist(string email, char ch); // checking if the email is already exist before making new account 
void showAllBookings(); // Show reversations made by customers 
void newUser(); // add new customer
void admin(); // admin login 
bool is_digits(const std::string &str); // check if the input consist only on numbers 
void loginCustomer(); // login the customer 
void adminAccess(); // admin functions 
void addItem(); // add item in menu
vector<string> showMenu(); // book item from menu

void printSpace(int a, string text);
void billGen(vector<string>, string);
string UserData(string id, char ch);
void center(string text);
void lines(int num, string ch);
void emptyspace(int num, bool ,bool);
void printHeader();
void Add_a_Table(); 
void startReverstation(int userid);

 bool check(string Visit_Time,string place, int Date,int Month,int Tableno, string Floor);
 void Reserving_a_Table (int id, string place, string Floor);
 vector<string> calcutBill( vector<string> items, string userId, string place, int date, int month, string visit_time, int tableNo, string floor); 
 bool validateCard(string cardNumber); 
 void showClientsBookings(string id);
 void showMyDetails(string id); 
 void customerPanel(string userId);
 
int main(){
  // showMyDetails("3");
// showClientsBookings("3");
  //  cout<<check("BR", "In Door", 5, 8, 1, "VIP");
  	// cout<<"\n The chec is: "<<check("BR", "In Door", 4, 5, 4, "2nd");

  //  vector<string>  selectMenu =   showMenu(); 
  //    vector<string> ab =    calcutBill(selectMenu);

    //  for (int i = 0; i < ab.size(); i++)
    //  {
    //   cout<<ab[i]<<" ";
    //  }
     
    // customer();
    // newUser();
  //  loginCustomer();
  // cout<<"\n The chec is: "<<check("DI", "In Door", 3, 3, 4, "VIP");
  // system("pause");
  // startReverstation(3);
  //  vector<string>  selectMenu =   showMenu(); 
    //  calcutBill(selectMenu); 
   
        //  billGen(selectMenu, "3"); 
  // admin();
  // adminAccess();
  // addItem();
  //  showMenu();
  //  vector<string> items = showMenu();
  // cout<<UserData("1", 'p');
  //  vector<string> a = {"1", "4"};
  //  billGen(a, "1");
   
  // showAllBookings();
    system("cls"); 
    
    lines(150, "="); 
    emptyspace(20, false, false);
    center("Welcome to Resturant Management System"); 
    lines(150, "="); 
    cout<<"\n \n";
    cout<<" Who are you ?";
    cout<<"\n 1) Admin \n 2) Customer";
    cout<<"\n \n Enter Choice: ";
    int role=0;
    cin>>role;
    if(role == 1){
    //     // for admin  
         admin();
    } else if(role == 2){
       customer();
    } else {
         cout<<"Try Again\n";
        cout<<"Invalid Input \n"; 
         system("pause");
        system("cls");
        main();

    }
} 

void printHeader(){
   system("cls"); 
    lines(150, "="); 
    emptyspace(20, false, false);
    center("Welcome to Resturant Management System"); 
    lines(150, "="); 
    cout<<"\n \n";
}
void customer(){
     cout<<"\n ----------Customer Panel---------- -";
     cout<<"\n 1) Login \n 2) New User \n Enter Your Choice:";
    int dec=0;
    cin>>dec;
    if(dec == 1){
        
        // Login
        loginCustomer();

    } else if(dec == 2){
        newUser();
    //    customer();
    } else {
        cout<<"Invalid Input "; 
        Sleep(6);
        system("cls");
         customer();

    }

}

// for new account 
 void newUser(){
   printHeader();
  cout<<"       Create A New Account";
  lines(35, "-");
   

    string name="zhair", email="ahmadzhair2003@gamil.com", passwrod="abdcdef", phone="03444390"; int a=0, userId=0 ; 
    cout<<"Enter Name: ";
    cin>>name;


do{
if(a>0){ cout<<"\n The Phone Number you Entered is Aleady Exist ! try other one \n";}
    cout<<"Enter Phone Number: ";
    cin>>phone;
    while ((!is_digits(phone))  || (phone.length()!=11))
    {
      cout<<"\n You Entered the invalid phone number \n";
      cout<<"Enter Phone Number: ";
      cin>>phone;
    }
    a++;
  

}
while (exist(phone, 'p'));


// checking email is valid and already not in used my other account
a=0;
do
{    
    // int a=0; 
      if(a>0){
        cout<<"\n The Email you Entered is Aleady Exist ! try other one \n";
    }
    cout<<"Enter Email : ";
    cin>>email;
    while (email.length() < 12 || email.find('@') >= 25) // checking email is valid?
    {
      cout<<"\n----Invalid Email----\n";
      cout<<"Enter Email : ";
      cin>>email;
    }
    
   a++; 
} while (exist(email, 'e'));

    
    cout<<"Enter Password: ";
    cin>>passwrod;

    ifstream  user("./database/users.txt", ios::out);
    string id=""; 
    while (user.good())
    {

      getline(user, id);
      id = id.substr(id.find('#')+1, id.find('|')-id.find('#')-2);
    }
    userId= stoi(id); // getting the user id of last account;
    userId++; // this will be user id fo new account 
    user.close();

    //Entering the data into users.txt file 
     ofstream users("./database/users.txt", ios::app);
    users<<"\n"<<" #"<<userId<<" | "<<name<<" ^ "<<email<<" & "<<phone<<" % "<<passwrod<<" ]";
    users.close();
   
   cout<<"\n-------- Account Created SuccessFully! -----\n";
   char choice='y'; 
   cout<<"1. Book Table \n2. Return to First Menu \nEnter Choice(Y/N): ";
   cin>>choice;  
   switch (choice)
   {
   case 'y':
   case 'Y': 
    startReverstation(userId);
    break;
   default:
    main();
    break;
   }
  
  
 }

 bool exist(string id, char ch){
    ifstream user("./database/users.txt", ios::out); 
     string line; 
   char _1sign, _2sign;
   switch (ch)
   {
   case 'e':
    _1sign='^';
    _2sign='&';
    break;
   case 'p':
   _1sign='&';
   _2sign = '%';
   break;
   default:
    break;
   }
    int found=0;

    while (user.good())
    {
          getline(user, line, '\n');
        int first = line.find(_1sign)+2;
    string result=line.substr(first, line.find(_2sign)-first-1);
    found = id.compare(result);
    if(found==0){
      // user.close();
     return true; 
    } 
    // else if(found ==-1) {user.close();return false;}
    }
    user.close();
  return 0;
 }
 bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}


void loginCustomer(){
  printHeader();
  string email="ahmadzhair2003@gmail.com", password="1122"; bool match= false;
    
    
    cout<<"           Login Panel ";
    lines(30, "-");
    cout<<"Email: ";
    cin>>email;
     while (email.length() < 12 || email.find('@') >= 25) // checking email is valid?
    {
      cout<<"\n----Invalid Email----\n";
      cout<<"Enter Email : ";
      cin>>email;
    }
    if (exist(email, 'e'))
    {
         cout<<"\nPassword: ";
         cin>>password;
    } else {
      cout<<exist(email, 'e');
      cout<<"\n ---This user does not exist---\n ";
       cout<<"Email: ";
    cin>>email;
     while (email.length() < 12 || email.find('@') >= 25) // checking email is valid?
    {
      cout<<"\n----Invalid Email----\n";
      cout<<"Enter Email : ";
      cin>>email;
    }


    }
    

 
    string line="", emailM="", passwordM="", userId;
    // matching the password 
    ifstream user("./database/users.txt", ios::out);
    while (user.good())
    {
          getline(user, line, '\n');
        int first = line.find('^')+2;
    emailM=line.substr(first, line.find('&')-first-1);
    
     int second= line.find('%')+2;
    passwordM=line.substr(second, line.find(']')-second-1);
    if (password.compare(passwordM)==0 && email.compare(emailM)==0)
    { 
      userId = line.substr(line.find('#')+1, line.find('|')-line.find('#')-2);
      match= true;
      break;
    }
    }
    user.close();

    if (match==true)
    {

      // logged in successfully as customer 
      system("cls");
      cout<<"\n----- You Logged in Successfully ---\n\n";
       customerPanel(userId); 
      


    } else {
     cout<<"Password was Wrong\n ";
      cout<<"1) Try again  \n2) Register New Account";
      int choice = 1; 
       cout<<"\nEnter Choice: ";
       cin>>choice;
       switch (choice)
       {
       case 1:
        loginCustomer();
        break;
       case 2: 
        newUser();
        break;

       default:
       loginCustomer();
        break;
       }

    }
    
}
 void admin(){
  printHeader();
  string namea="", passworda="";

  cout<<"      Admin Login Panel";
    lines(30, "-");
  cout<<"Enter Username: ";
  cin>>namea;
  cout<<"Enter Password: ";
  cin>>passworda;
  string lineA=""; 
 
 ifstream adminFile("./database/admin.txt", ios::out);
 while (adminFile.good())
 {
  getline(adminFile, lineA);
  string name=lineA.substr(lineA.find('!')+2, lineA.find('%')-lineA.find('!')-3);
  string password = lineA.substr(lineA.find('%')+2, lineA.find(']')-lineA.find('%')-3);
  if (namea.compare(name)==0 && passworda.compare(password)==0)
  {
    cout<<"\n-----You logged in successfully-----\n";
    adminAccess();
  } else {
    cout<<"\nYou Entered invalid login details\nScreen will be reset in 3s...";
    sleep(3);
    admin();
  }
  

 }
  adminFile.close();

}
void adminAccess(){
printHeader();
cout<<"     Welcome To Master Panel      ";
lines(30, "-"); 
cout<<"\n1) Add Item In Menu\n2) Show All Bookings\n3) Add New Account\n4) Add Table";
cout<<"\n\nEnter Choice: ";
int choice =4; 
cin>>choice;
switch (choice)
{
case 1:
  // menu funciton 
  addItem();
  break;
case  2: 
   // show all the bookings 
   showAllBookings();
   break;
case 3: 
   // add new account 
   newUser();
   break;
case 4:
  // add  table 
   Add_a_Table();
   break;   
default:
  cout<<"\nYou Entered the wrong Choice\nScreen will be reset in 3s...";
  sleep(3);
  adminAccess(); 
  break;
}

}
void addItem(){
  system("cls");
   ifstream getId("./database/menu.txt", ios::out);
  string menuId; 
  while (getId.good())
  {
    getline(getId, menuId);
   menuId  = menuId.substr(menuId.find('#')+1, menuId.find('!')- menuId.find('#')-2);
  }
  getId.close();
  int id= stoi(menuId);
  id++; // next item will get next id 
  cout<<"      Add Item in Menu";
  lines(30, "-");
 
  cout<<"\n---- Enter Item information ------\n";
  string name,price,timee; 
  cout<<"Name: ";
  cin>>name;
  cout<<"Price in PKR: ";
  cin>>price;

  //  time_t ttime = time(0);
  //  tm *local_time = localtime(&ttime);
  //  cout << "Year: "<< 1900 + local_time->tm_year << endl;cout << "Month: "<< 1 + local_time->tm_mon<< endl;
  //  cout << "Day: "<< local_time->tm_mday << endl;
  //  cout << "Time: "<< 1 + local_time->tm_hour << ":";
  //  cout << 1 + local_time->tm_min << ":";cout << 1 + local_time->tm_sec << endl;
    
    string available;
  cout<<"\nWhen Item Will be Available: \n1. Breakfast\n2. Lunch \n3. Dinner \n4. Breakfast and Luch \n5. Lunch and Dinner \n6. Breakfast and Dinner";
  cout<<"\nSelect Time: ";
  int choice=0; 
  cin>>choice;
  switch (choice)
  {
  case 1:
    available="LU";
    break;
  case 2: 
    available="BR";
    break;
  case 3: 
    available="DI";
    break;
  case 4: 
    available="BRLU";
    break;
  case 5: 
      available= "LUDI";
      break;
  case 6: 
    available = "BRDI";
    break;
  default: 
    cout<<"--------Invalid input-------\n Try again!\n";
    system("pause");
    addItem();
    break;
  } 
  if (choice>6)
  {
    cout<<"\nUnable to add Item\n";
  } else {
  ofstream addMenu("./database/menu.txt", ios::app);
     if(addMenu.good()){ // checking if the file is opened

         addMenu<<"\n"<<" #"<<id<<" ! "<<name<<" $ "<<price<<" % "<<available<<" ]"; // adding data to file
         cout<<"\n----- Item Added Successfully ----- \n";
        
         

  } else { // this file can't be opend 
    cout<<" \n Unable able to open the file or file location is changed ";
  }
  addMenu.close();
  }

  char go='n';
         cout<<"Enter 'y' to add item or exit to main menu 'n' \nEnter Choice: "; 
         cin>>go; 
         if(go=='n' || go=='N'){
          adminAccess();
         } else {
          addItem();
         }
  
  }

  vector<string> showMenu(){
    vector <string>menu; 
   int total =0; 
   cout<<"------ Menu ------\n";
   int a=1; 
   cout<<"\n----Select Time ----\n1. Breakfast \n2. Lunch\n3. Dinner\n Enter Choice: ";
   cin>>a; 

   string time=""; 
   switch (a)
   {
   case 1:
     time = "BR"; 
    break;
   case 2: 
    time = "LU";
    break;
   case 3: 
    time = "DI";
    break;
    default: 
     cout<<"\nInvalid Input\n";
     cout<<"By Default Selected Breakfast\n"; 
     time = "BR";
    break;
   }
   ifstream getId("./database/menu.txt", ios::out);
  string menuLine; 
   string name, price, longTime, menuId; 
   int counter1 =1; 
  while (getId.good())
  { 
   getline(getId, menuLine);
  
   menuId  = menuLine.substr(menuLine.find('#')+1, menuLine.find('!')- menuLine.find('#')-2);
   name  = menuLine.substr(menuLine.find('!')+1, menuLine.find('$')- menuLine.find('!')-2);
   price  = menuLine.substr(menuLine.find('$')+1, menuLine.find('%')- menuLine.find('$')-2);
   longTime = menuLine.substr(menuLine.find('%')+1, menuLine.find(']')- menuLine.find('%')-2);

  
   
    bool found=false;
    int pos = 0; int index;
   while((index = longTime.find(time, pos)) != string::npos) {
      found = true; 
      pos = index + 1;
      break;
   }
   if(found){
     cout<<counter1<<"."+name<<" "+price+" PKR\n";
      menu.push_back(menuId);
     counter1++;
   } 
  }
  getId.close();
int choice2; vector <string>selectedItems;
do
{
   cout<<"Select Items "<<"or Enter -1 to exit: ";
   cin>>choice2; 
   

   if (choice2>0)
   {
    selectedItems.push_back(menu[choice2-1]);
   }   
} while (choice2 >=0);

  return selectedItems; 
} 
void showAllBookings(){

  cout<<"\n                                                 Showing All the Bookings  ";
lines(116, "_");
cout<<"|                         Booking Details             |                         Customer Details                   |";
lines(116, "_");
cout<<"\nSir No | Date     | Table No | Place     | Vist Time | Name           | Phone         | Email                      |\n";

  // the code to show all bookings 
 // get user details by its id; 

int counter_is = 1;  

    
  // checking all reversions; 
 ifstream user("./database/reversedTables.txt", ios::out);
//  cout<<user.good();
    string Detailed,CPlace, CVisit_Time, CDate, CMonth, CTableno, CId;
  while (!user.eof())
    {
    getline(user,Detailed);
    CId =  Detailed.substr(Detailed.find('#')+1, Detailed.find('$')-Detailed.find('#')-2);
    CPlace = Detailed.substr(Detailed.find('$')+2, Detailed.find('@')-Detailed.find('$')-3);
    CDate = Detailed.substr(Detailed.find('@')+2, Detailed.find('&')-Detailed.find('@')-3);
    CMonth = Detailed.substr(Detailed.find('&')+2, Detailed.find('^')-Detailed.find('&')-3);
    CVisit_Time = Detailed.substr(Detailed.find('^')+2, Detailed.find(']')-Detailed.find('^')-3);
    CTableno = Detailed.substr(Detailed.find(']')+2, Detailed.find('}')-Detailed.find(']')-3);

    
    //getting user from it id 
   string userDetails, name, phone, email, idFile; 
   ifstream getUser("./database/users.txt", ios::out);
    while (getUser.good())
    {
        getline(getUser, userDetails);
        idFile = userDetails.substr(userDetails.find('#')+1, userDetails.find('|')-userDetails.find('#')-2);

         if (stoi(idFile)== stoi(CId))
         { 
            name =  userDetails.substr(userDetails.find('|')+1, userDetails.find('^')-userDetails.find('|')-2);
            phone =  userDetails.substr(userDetails.find('&')+1, userDetails.find('%')-userDetails.find('&')-2);
            email =  userDetails.substr(userDetails.find('^')+1, userDetails.find('&')-userDetails.find('^')-2);
            string a = CDate+"/"+CMonth+"/2023";
            cout<<"--------------------------------------------------------------------------------------------------------------------\n";
            printSpace(7, to_string(counter_is));cout<<" ";printSpace(9, a);cout<<" ";printSpace(9, CTableno);cout<<" ";printSpace(10, CPlace);cout<<" ";printSpace(10,CVisit_Time);printSpace(16, name);printSpace(15, phone);printSpace(28,email);cout<<endl;
            break;
         }
        
          
          
    }
     
     counter_is++;
    }

  cout<<endl;
  cout<<"Go to Master panel \n"; 
  system("pause"); 
  adminAccess();
}

// printng space (used for formatting the output)
void printSpace(int a, string text){
  cout<<text;
  int spaceTo = a-text.length();
  for (int i = 0; i < spaceTo; i++)
    {
      cout<<" ";
    }
   cout<<"|";
}
 

void billGen(vector<string>items, string userId){
 


  int total =0; 
  emptyspace(150, true, true);
  lines(150, "-");
  center("BILL"); 
  lines(150, "-");
 


  string nameN, emailE, phoneP; 
   nameN = UserData(userId, 'n');
   phoneP = UserData(userId, 'p');
   emailE = UserData(userId, 'e');
 
  // emptyspace(10, false, false); 
  cout<<"    Name: "<<nameN<<endl; 
  cout<<"    Email: "<<emailE<<endl; 
  cout<<"    Phone: "<<phoneP<<endl; 
   emptyspace(150, true, true);
     emptyspace(20, false, false);
  cout<<"Item Name        | Price         |\n";

 for (int i = 0; i < items.size(); i++)
 {
  
 ifstream getId("./database/menu.txt", ios::out);
  string menuLine; 
   string name, price, longTime, menuId; 
   int counter1 =1; 
  while (getId.good())
  { 
   getline(getId, menuLine);
  
   menuId  = menuLine.substr(menuLine.find('#')+1, menuLine.find('!')- menuLine.find('#')-2);
   name  = menuLine.substr(menuLine.find('!')+1, menuLine.find('$')- menuLine.find('!')-2);
   price  = menuLine.substr(menuLine.find('$')+1, menuLine.find('%')- menuLine.find('$')-2);
   
    bool found=false;

    if(menuId.compare(items[i])==0){
      total += stoi(price);
      emptyspace(20, false, false);
      printSpace(17, name);
      printSpace(15, price);
      cout<<endl; 
    }
   }

   

}
emptyspace(150, true, true);
emptyspace(80, false, false);
 
cout<<"The Total Amount is: "<<total; 
lines(150, "-");
}


 string UserData(string id, char ch){
    ifstream user("./database/users.txt", ios::out); 
     string line, requiredData;  
   char _1sign, _2sign;
   switch (ch)
   {
   case 'e':
    _1sign='^';
    _2sign='&';
    break;
   case 'n':
   _1sign='|';
   _2sign = '^';
   break;
   case 'p':
   _1sign = '&';
   _2sign ='%'; 
   default:
    break;
   }
    int found=0;

    while (user.good())
    {
          getline(user, line, '\n');
        int first = line.find(_1sign)+2;

     string Cid =  line.substr(line.find('#')+1, line.find('|')-line.find('#')-2);
    string result=line.substr(first, line.find(_2sign)-first-1);
    found = id.compare(Cid);
    if(found==0){
      // user.close();
      return result; 
    } 
    // else if(found ==-1) {user.close();return false;}
    }
    user.close();
  return "Unknown User";
 }

 void center( string text){
  int total = 140; 
 for (int i = text.length(); i < total/2; i++)
 {
  text = " "+text; 
 }

  printSpace(150, text);


 }

 void lines(int num, string ch){
  cout<<'\n';
  for(int i=0; i<num; i++){
    cout<<ch; 
  }
  cout<<'\n';
 }

 void emptyspace(int num, bool a, bool b){
 if(a){cout<<"\n";}
  for(int i=0; i<num; i++){
    cout<<" "; 
  }
  if(b){cout<<"\n";}

 } 

// start revesrtaion 

 void startReverstation(int userid){
 string place, Floor;	
  printHeader(); 
	cout<<"\n Where you want to reserve the table? "<<endl;
	cout<<"\n 1. Outdoor "<<endl;
	cout<<" 2. Indoor "<<endl<<endl;
	cout<<" Enter Your Choice : ";
	
	place = "Out Door";
	Floor = "noFloor";
	Reserving_a_Table (userid, place, Floor);
}

// checking the revs is not aleady there 
bool check(string Visit_Time,string place, int Date,int Month,int Tableno, string Floor){
	ifstream  user("./database/reversedTables.txt", ios::out);
    string Detailed,CPlace, CVisit_Time, CDate, CMonth, CTableno, CFloor;
    bool Found;

    while (!user.eof())
    {
     bool BFloor = false, BPlace = false; 
    getline(user,Detailed);
    
    CPlace = Detailed.substr(Detailed.find('$')+2,Detailed.find('@')-Detailed.find('$')-3);
    
	CDate = Detailed.substr(Detailed.find('@')+2, Detailed.find('&')-Detailed.find('@')-3);
    
	CMonth = Detailed.substr(Detailed.find('&')+2, Detailed.find('^')-Detailed.find('&')-3);
    
	CVisit_Time = Detailed.substr(Detailed.find('^')+2, Detailed.find(']')-Detailed.find('^')-3);
     
	CTableno = Detailed.substr(Detailed.find(']')+2, Detailed.find('}')-Detailed.find(']')-3);
    
    CFloor = Detailed.substr(Detailed.find('}')+2, Detailed.find('*')-Detailed.find('}')-3);

	if(CPlace.compare(place)==0){
        BPlace = true; 
		
	}

	  if (CFloor.compare(Floor)==0){
		BFloor = true;
    
      }

    if((CTableno.compare(to_string(Tableno)) == 0) ){
		  if(stoi(CDate)==Date){
			    if(stoi(CMonth)==Month){
					
					if(CVisit_Time.compare(Visit_Time)==0 && BFloor && BPlace){
						Found = true;
						
						  break;
                    
					}
	
				}
			
		  }
	}

    }
     user.close();
	
	return Found;
}

void Reserving_a_Table (int id, string place, string Floor){
	
	int keypress;
	cin>>keypress;
	
	if(keypress == 1){
		place = "Out Door";
		Floor = "no Floor";
		cout<<"\n Enter Table No which you want to select : "<<endl<<endl;
		// string outdoor = " Out 1, Out 2, Out 3, Out 4, Out 5 ";
		// string outdoor_Tables = "\n Press 1 For Table # 1 \n Press 2 For Table # 2 \n Press 3 For Table # 3 \n Press 4 For Table # 4 \n Press 5 For Table # 5 ";
		
		// ofstream out("./database/Outdoor_Tables.txt");
		// out<<outdoor<<endl;
		// out<<outdoor_Tables;

		// out.close();
			string st2;
		ifstream in("./database/Outdoor_Tables.txt");
		
		while(in.good()){
			getline(in, st2);
			cout<<st2;
			cout<<endl;
		}
		
		}else if(keypress == 2){
			
			place = "In Door";
			
			cout<<"\n Please select on which floor you wnt to reserve the table : "<<endl;
			cout<<"\n Press 1 for Ground Floor \n Press 2 for VIP Floor \n Press 3 for 2nd Floor. "<<endl<<endl;
			cout<<" Enter Your Choice : ";
			cin>>keypress;
			
			if(keypress == 1){
				
				Floor = "Ground";
				
				cout<<"\n Enter Table No which you want to select on Ground Floor : "<<endl<<endl;
				// string GroundFloor_Tables = "\n Press 1 For Table # 1 \n Press 2 For Table # 2 \n Press 3 For Table # 3 \n Press 4 For Table # 4 \n Press 5 For Table # 5 \n Press 6 For Table # 6 \n Press 7 For Table # 7 ";
				
				// ofstream Ground("./database/GroundFloor_Tables.txt");
				// Ground<<GroundFloor_Tables;
			
				// Ground.close();
			
				ifstream in("./database/GroundFloor_Tables.txt");
					string Gr;
				while(in.good()){
				
				getline(in, Gr);
				cout<<Gr;
				cout<<endl;
				}	
				}else if(keypress == 2){
			
				Floor = "VIP";
		
			
				// cout<<"\n Enter Table No which you want to select on VIP Floor : "<<endl<<endl;
				// string VIPFloor = "\n Press 1 For Table # 1 \n Press 2 For Table # 2 \n Press 3 For Table # 3 \n Press 4 For Table # 4 \n Press 5 For Table # 5 ";
				// ofstream VIP("./database/VIPFloor.txt");
				// VIP<<VIPFloor;
				
				// VIP.close();
			string Vi;
				ifstream in("./database/VIPFloor.txt");
				
				while(in.good()){
				
				getline(in, Vi);
				cout<<Vi;
				cout<<endl;
				}
				
				}else if(keypress == 3){
					
					Floor = "2nd";
					
				// cout<<"\n Enter Table No which you want to select on 2nd Floor : "<<endl<<endl;
				// string SecondFloor = "\n S1, S2, S3, S4 \n\n Press 1 For Table # 1 \n Press 2 For Table # 2 \n Press 3 For Table # 3 \n Press 4 For Table # 4 ";
				// ofstream Sec("./database/SecondFloor.txt");
				// Sec<<SecondFloor;
				// string Se;
				// Sec.close();
			
				ifstream in("./database/SecondFloor.txt");
				string Se;
				while(in.good()){
				
				getline(in, Se);
				cout<<Se;
				cout<<endl;
				}
				}else{
				cout<<" Invalid Number. "<<endl;
				}
	}
	else{
		cout<<"\n Invalid Number "<<endl;
		exit(0);
	}
	
	
	cout<<endl;
	cout<<" Enter Your Choice : ";
	int Date, Month, Time, Press;
	cin>>Press;
	string Visit_Time;
	cout<<"\n Enter the Date : ";
	cin>>Date;
	cout<<"\n Enter the Month : ";
	
	cin>>Month;
	cout<<"\n Select the  Time for which You want to Reserve the Table : "<<endl;
	cout<<"\n Press 1 for BreakFast "<<endl<<" Press 2 for Lunch "<<endl<<" Press 3 for Dinner "<<endl<<endl;
	cout<<" Enter Your Choice : ";
	cin>>Time;
	// Time = Press;
	cout<<Time<<" ";
	if(Time == 1){
		Visit_Time = "BR";
	}else if(Time == 2){
		Visit_Time = "LU";
	}else if(Time == 3){
		Visit_Time = "DI";
	}
    cout<<Visit_Time <<" "<< place <<" " <<Date << " "<< Month << " " <<Press << " " <<Floor;
	cout<<"\n The chec is: "<<check("BR", "In Door", 5, 3, 4, "noFloor");

	if(check(Visit_Time, place, Date, Month, Press, Floor)){
		cout<<" This Table is alreday Booked. Please Select Another one. "<<endl;
	}else{
     system("cls"); 
     lines(100, "-"); 
		cout<<"                    Your Reservation Details are : ";
     lines(100, "-"); 
		printSpace(100, "      The Place you have selected is : "+place );cout<<endl;
    printSpace(100, "         Table No is: "+to_string(Press)); cout<<endl;
    printSpace(100, "      Date: "+to_string(Date)+"/"+to_string(Month)+"/2023");cout<<endl;
    printSpace(100, "      Visit Time: "+Visit_Time);cout<<endl;
		// cout<<"\n You have selected the Table # "<<Press<<" for "<<Date<<" / "<<Month<<" / 2023 "<<" for "<<Visit_Time<<"."<<endl;
		// cout<<"\n -------------------- Thank You -------------------- ";
			lines(100, "-"); 

      //

		// ofstream reserved("./database/reversedTables.txt",ios::app) ;
		// reserved<<endl<<"#"<<id<<" $ "<<place<<" @ "<<Date<<" & "<<Month<<" ^ "<<Visit_Time<<" ] "<<Press<<" } "<<Floor<<" *";
		// reserved.close();
     vector<string>  selectMenu;   string itemsList = ""; 
    char choice = 'y'; 
         vector<string>  bill ; 
    cout<<"\nDo You Want to Order Dishes as well? (y/n): "; 
    cin>>choice; 
    lines(50, "-"); 
     switch (choice)
     {
     case 'y':
     case 'Y':
          selectMenu =   showMenu(); 
          
          bill = calcutBill(selectMenu, to_string(id), place, Date, Month, Visit_Time, Press, Floor); 
            // billGen(selectMenu, to_string(id)); 
          for(int j=0; j<selectMenu.size(); j++){

                      itemsList = itemsList+" "+selectMenu[j];
                                        }
       
      break;
     case 'n':
     case 'N': 
     choice = 'n'; 
     itemsList = "NO item added"; 
     bill.push_back("000.00");
     bill.push_back("No Order");
     break;
     default:
     choice='n';
     itemsList = "NO item added"; 
     bill.push_back("000.00");
     bill.push_back("No Order");
     cout<<"invlaid";
      break;
     }
   
     
    ofstream reserved("./database/reversedTables.txt",ios::app) ;
		reserved<<endl<<"#"<<id<<" $ "<<place<<" @ "<<Date<<" & "<<Month<<" ^ "<<Visit_Time<<" ] "<<Press<<" } "<<Floor<<" *"<<choice<<" ["<<itemsList<<" - "<<bill[0]<<" + "<<bill[1]<<" =";
		reserved.close();
	}
	
	cout<<"\n 1. If You want to exist  \n 2. Press 2 for selecting another table . 3. Customer Panel"<<endl;
	cout<<"\n Enter Your Choice : ";
	cin>>Press;
	if(Press == 1){
		exit(0);
	}else if(Press == 2){
		cout<<"\n Where you want to reserve the table? "<<endl;
		cout<<"\n Press 1 for Outdoor "<<endl;
		cout<<"\n Press 2 for Indoor "<<endl<<endl;
		cout<<" Enter Your Choice : ";
		place = "Out Door";
		Floor = "noFloor";
    Reserving_a_Table(id, place, Floor);
		// return(Reserving_a_Table(id, place, Floor));
	} else if(Press==3){
    system("cls");
    customerPanel(to_string(id));
  }
  else{
		cout<<" Invalid Number "<<endl;
	}
	
	}


vector<string> calcutBill( vector<string> items, string userId, string place, int date, int month, string visit_time, int tableNo, string floor){
   vector<string> billIs ; int total =0; 

for (int i = 0; i < items.size(); i++)
 {
  
 ifstream getId("./database/menu.txt", ios::out);
  string menuLine; 
   string name, price, longTime, menuId; 
   int counter1 =1; 
  while (getId.good())
  { 
   getline(getId, menuLine);
  
   menuId  = menuLine.substr(menuLine.find('#')+1, menuLine.find('!')- menuLine.find('#')-2);
   price  = menuLine.substr(menuLine.find('$')+1, menuLine.find('%')- menuLine.find('$')-2);
   
    bool found=false;

    if(menuId.compare(items[i])==0){
      total += stoi(price);
    }
   }
} 
billGen(items, userId); 

billIs.push_back(to_string(total)); 


cout<<"How you Want to Pay: \n1. On Spot \n2. Credit Card \nEnter Choice: "; 
int choice =1; 
  cin>>choice; 
  if (choice ==1)
  {
    billIs.push_back("On Spot"); 
  } else { 

         string cardNumber;
    cout << "Enter a credit card number: ";
    cin >> cardNumber;

     do
     {
      string cardNumber;
      cout << "Enter a credit card number: ";
       cin >> cardNumber;

       if (validateCard(cardNumber))
         billIs.push_back("Paid By Credit Card");
        else {
          cout<<"\nInvalid Card try again !\n";
          // billIs.push_back("Payment Faild"); 
        }
     } while (!validateCard(cardNumber));
    
  }
   
 


  emptyspace(150, true, true);
  lines(150, "-");
  center("Final Receipt"); 
  lines(150, "-");


  string nameN, emailE, phoneP; 
   nameN = UserData(userId, 'n');
   phoneP = UserData(userId, 'p');
   emailE = UserData(userId, 'e');
 
  cout<<"    Name: ";printSpace(81, nameN);                                                  cout<<"Date: "<<date<<"\\"<<month<<"\\2023"<<endl; 
  cout<<"    Email: ";printSpace(80, emailE);                                               cout<<"Place: "<<place<<endl; 
  cout<<"    Phone: ";printSpace(80, phoneP);                                                 cout<<"Visit Time: "<<visit_time<<endl;
  cout<<"                                                                                            |Table No: "<<tableNo<<endl;  
  cout<<"                                                                                            |Floor: "<<floor<<endl<<endl;  
     emptyspace(20, false, false);
  cout<<"Item Name        | Price         |\n";

 for (int i = 0; i < items.size(); i++)
 {
  
 ifstream getId("./database/menu.txt", ios::out);
  string menuLine; 
   string name, price, longTime, menuId; 
   int counter1 =1; 
  while (getId.good())
  { 
   getline(getId, menuLine);
  
   menuId  = menuLine.substr(menuLine.find('#')+1, menuLine.find('!')- menuLine.find('#')-2);
   name  = menuLine.substr(menuLine.find('!')+1, menuLine.find('$')- menuLine.find('!')-2);
   price  = menuLine.substr(menuLine.find('$')+1, menuLine.find('%')- menuLine.find('$')-2);
   
    bool found=false;

    if(menuId.compare(items[i])==0){
      total += stoi(price);
      emptyspace(20, false, false);
      printSpace(17, name);
      printSpace(15, price);
      cout<<endl; 
    }
   }

   

}
emptyspace(150, true, true);
emptyspace(40, false, false);
 
cout<<"The Total Amount is: "<<total<<"                                         Payment Details: "<<billIs[1]; 
lines(150, "-");


    

    return billIs; 
  }


bool validateCard(string cardNumber)
{
    int sum = 0;
    bool isSecond = false;
    for (int i = cardNumber.length() - 1; i >= 0; i--)
    {
        int digit = cardNumber[i] - '0';
        if (isSecond == true)
            digit = digit * 2;
        sum += digit / 10;
        sum += digit % 10;

        isSecond = !isSecond;
    }
    return sum % 10 == 0;
}
void showClientsBookings(string id){

  cout<<"\n                     Showing All the Bookings  ";
  lines(54, "-");
 cout<<"|                    Booking Details                  |";
 lines(54, "_");
 cout<<"\nSir No | Date     | Table No | Place     | Vist Time |";
 int counter_is = 1;  

    
  // checking all reversions; 
 ifstream user("./database/reversedTables.txt", ios::out);
 //  cout<<user.good();
    string Detailed,CPlace, CVisit_Time, CDate, CMonth, CTableno, CId;
  while (!user.eof())
    {
    getline(user,Detailed);
    CId =  Detailed.substr(Detailed.find('#')+1, Detailed.find('$')-Detailed.find('#')-2);
    CPlace = Detailed.substr(Detailed.find('$')+2, Detailed.find('@')-Detailed.find('$')-3);
    CDate = Detailed.substr(Detailed.find('@')+2, Detailed.find('&')-Detailed.find('@')-3);
    CMonth = Detailed.substr(Detailed.find('&')+2, Detailed.find('^')-Detailed.find('&')-3);
    CVisit_Time = Detailed.substr(Detailed.find('^')+2, Detailed.find(']')-Detailed.find('^')-3);
    CTableno = Detailed.substr(Detailed.find(']')+2, Detailed.find('}')-Detailed.find(']')-3);
    // cout<<CId<<" "<<id; 
       if (stoi(CId)== stoi(id))
         { 
            string a = CDate+"/"+CMonth+"/2023";
            cout<<"\n-----------------------------------------------------\n";
            printSpace(7, to_string(counter_is));cout<<" ";printSpace(9, a);cout<<" ";printSpace(9, CTableno);cout<<" ";printSpace(10, CPlace);cout<<" ";printSpace(10,CVisit_Time);
           counter_is++;
         }
 
   
    }
    if(counter_is==1){
      cout<<"\n YOu did maked any Booking up till Now"; 
      lines(30, "-");
    }
        cout<<"\n";
 }

 void showMyDetails(string id){
  cout<<endl;
  cout<<" My Details are ";
  lines(30, "-"); 
  cout<<" Name: "<<UserData(id, 'n');
  cout<<"\n Phone: "<<UserData(id, 'p'); 
  cout<<"\n Email: "<<UserData(id, 'e');
  lines(30, "-");
 }
 void customerPanel(string userId){
  cout<<"     Customer Panel    "; 
      lines(30, "-"); 

      cout<<"1. Show My Information\n2. Make Booking \n3. Show My All pervious Bookings \nEnter Choice: "; 
      int dec =1; 
      cin>>dec;
      if(dec==2){startReverstation(stoi(userId));} else if(dec==3){
       showClientsBookings(userId); 
      } else if (dec==1)
      {
        showMyDetails(userId);
      } else {
        cout<<"invlaid Input \n by default Make Booking is Selected"; 
        startReverstation(stoi(userId));
        lines(30, "-");
      }
      system("pause");char a='0'; 
      cout<<"\nReturn to main Menu 'y' or exist 'n' "; 
      cin>>a; 
       if (a=='y' || a=='Y')
       {
        customerPanel(userId);
       } else {
        exit(0);
       }
      
      
       
 }
 
 void Add_a_Table(){
  printHeader(); 
	  string place, Floor; 
	int Enter, AddTable;
	cout<<"\n Where you want to Add the table? ";
	cout<<"\n Press 1 for Outdoor ";
	cout<<"\n Press 2 for Indoor "<<endl;
	cout<<" Enter Your Choice : ";
	cin>>Enter;
	
	if(Enter == 1){

		cout<<"\n Enter the Table # which You want to Add in Outdoor : "<<endl;

		ofstream out("./database/Outdoor_Tables.txt", ios::app);
	   string st2; 
		
		ifstream in(".database/Outdoor_Tables.txt");
		int counter =1; 
		while(in.good()){
			getline(in, st2);
			
			counter++; 
		}
		cout<<"\n Enter your Table no: ";
		cin>>AddTable;	out.close();

	   out<<"\nPress "<<counter<<" For Table no: "<<AddTable; 
		 
     cout<<"\nTable No: "<<AddTable<<"Added successfully";
     lines(50, "-"); 
     cout<<"Go to Master Panel..."; 
     system("pause"); 
     adminAccess();
	}else if(Enter == 2){
		
		cout<<"\n Please Select on which Floor You want to add the Table? "<<endl;
		cout<<"\n Press 1 for Ground Floor \n Press 2 for VIP Floor \n Press 3 for 2nd Floor. "<<endl<<endl;
		cout<<" Enter Your Choice : ";
		cin>>Enter;
	
		if(Enter == 1){
			
			cout<<"\n Enter the Table # which You want to Add in Ground Floor : "<<endl;
			ofstream Ground(".database/GroundFloor_Tables.txt", ios::app);
			string Gr;
			
			ifstream in(".database/GroundFloor_Tables.txt");
				int counter2 = 1; 
			while(in.good()){
				
				getline(in, Gr);
				counter2++; 
				}	
			cout<<"\n Enter Table NO: ";	
			cin>>AddTable;
			Ground<<"\nPress "<<counter2<<" For Table no: "<<AddTable;
		 
     cout<<"\nTable No: "<<AddTable<<"Added successfully";
     lines(50, "-"); 
     cout<<"Go to Master Panel..."; 
     system("pause"); 
     adminAccess();
			
		}else if(Enter == 2){
			
			cout<<"\n Enter the Table # which You want to Add in VIP Floor : "<<endl;			
			ofstream VIP(".database/VIPFloor.txt", ios::app);
			string Vi;
			
			ifstream in(".database/VIPFloor.txt");
		    int		counter3=1;
			
			while(in.good()){
				
				getline(in, Vi);
				counter3++;
			}
			cout<<"\n Enter your Choice : ";
			cin>>AddTable;
			VIP<<"\nPress "<<counter3<<" For Table no: "<<AddTable;
		 
     cout<<"\nTable No: "<<AddTable<<"Added successfully";
     lines(50, "-"); 
     cout<<"Go to Master Panel..."; 
     system("pause"); 
     adminAccess();
		}else if(Enter == 3){	
			cout<<"\n Enter the Table # which You want to Add in 2nd Floor "<<endl;			
			ofstream Sec(".database/SecondFloor.txt", ios::app);
			string Se;
			
			ifstream in(".database/SecondFloor.txt");
		  int counter4 = 1; 		
			while(in.good()){
				
				getline(in, Se);
				counter4++; 
				}
			cout<<"\n Enter Table NO : ";
			cin>>AddTable;
			Sec<<"\nPress "<<counter4<<" For Table no: "<<AddTable;
		 
     cout<<"\nTable No: "<<AddTable<<"Added successfully";
     lines(50, "-"); 
     cout<<"Go to Master Panel..."; 
     system("pause"); 
     adminAccess();
			}else{
				cout<<" Invalid Number "<<endl;
        cout<<"try again! "; 
        system("pause"); 
        Add_a_Table(); 
			}
	}else{
		cout<<" Invalid Number "<<endl;
	}
  cout<<"\n Go to Master Panel \n"; 
   system("pause"); 
   adminAccess();
}
