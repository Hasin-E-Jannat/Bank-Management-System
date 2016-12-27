#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
//void new_account();
void welcome_msg(){

cout<<"\n\n\n\tWELCOME TO XYZ BANK LMD.\n\n\n\n\n"<<endl;
cout<<"\n\tDeveloped by Dora"<<endl;
cout<<"\n\tAll rights reserved 2016\n\n"<<endl;
cin.get();
}
class Account{
    char name[50];
    int acc_no;
    char mobile[50];
    int deposit;
    int flag;

public:

        void new_account();
        void display(int);
        void write_account();
        int retacc_no();
        const void show_account();
        void depo(int,int);
        int retdepo(int);
        void with(int,int);
        int retwith(int);
         int retcurdepo();
         void report();
};

int Account::retacc_no()
 {
 return acc_no;
 }
 void Account::new_account(){
    while(1){
cout<<"\n\n\tEnter your name: ";
int i;
cin.ignore();
 cin.getline(name,50);
for(i=0;i<strlen(name);i++){
if(isalpha(name[i])){
    continue;

    }
else {
cout<<"\tError try again with only letters";
break;
}
}
 if(i==strlen(name))
        break;
    }

 while(1){
cout<<"\n\n\tEnter your mobile no: ";
int i;
cin.ignore();
cin.getline(mobile,50);
if(strlen(mobile)+1==10){
for(i=0;i<strlen(mobile);i++){
if(isdigit(mobile[i])){
    continue;

    }
else {
cout<<"\tError.Try again with only numbers";
break;
}
}
    }
  else{cout<<"\tError.Try again exactly 10 digits";
        continue;
  }

if(i==strlen(mobile))
        break;
 }
    while(1){
    cout<<"\n\n\tEnter initial deposit more than 500: ";
    cin>>deposit;
    if(deposit<500)
        cout<<"\tTry again"<<endl;
    else break;
    }
    ifstream inFile;
    inFile.open("account.dat",ios::binary);
    inFile.seekg(0, ios::end);
system("cls");
Account ac;
int acc_temp;
    cout<<"\n\n\tACCOUNT CREATED\n\n";
   if (inFile.tellg() == 0){
    acc_no = rand() % 1000 + 10;
    acc_no += rand() % 1000;
    }
    else{
    inFile.clear();
    inFile.seekg(0, ios::beg);
    while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
       acc_temp = ac.retacc_no();
    }
}
acc_no = acc_temp + 1;
cout<<acc_no<<endl;
 cout<<"\n\n\tYour account number is:"<<acc_no<<endl;
    cout<<"\n\n\tBalance:"<<deposit<<endl;
 cin.get();
 }



 const void Account::show_account ()
 {
 cout<<"\n\n\n\n\tACCOUNT NUMBER: "<<acc_no<<endl;
 cin.ignore();
 cout<<"\n\tNAME: "<<name<<endl;
  cout<<"\n\tMOBILE: "<<mobile<<endl;
 cout<<"\n\tBALANCE: "<<deposit<<endl;
 }
 void Account::display(int n)
 {
Account ac;
ifstream inFile;
flag=0;
inFile.open("account.dat",ios::binary);
if(!inFile){
    cout<<"\tFail to open the file. Press any key......";
    return;
}
while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
    if(ac.retacc_no()==n){
       ac.show_account();
       flag=1;
    }

}
inFile.close();
if(flag==0)
cout<<"\tACCOUNT NUMBER DOES NOT EXIST";
 }
 void Account::write_account(){
 Account ac;
 ofstream outFile;
 outFile.open("account.dat",ios::binary|ios::app);
 ac.new_account();
 outFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
 outFile.close();
 }

 int Account::retdepo(int amount)
 {
     deposit += amount;
 return deposit;
 }
 void Account::depo(int n,int amount)
 {
 Account ac;
fstream File;
flag=0;
File.open("account.dat",ios::binary|ios::in|ios::out);
if(!File){
    cout<<"\tFail to open the file. Press any key......";
    return;
}
while(!File.eof()&&flag==0){
        File.read(reinterpret_cast<char*>(&ac),sizeof(Account));
    if(ac.retacc_no()==n){
       ac.retdepo(amount);
       //cout<<deposit;
       int pos=(-1)*static_cast<int>(sizeof(ac));// can't understand
			File.seekp(pos,ios::cur);
       File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout<<"\n\n\t RECORD UPDATED";
			//found=true;
       flag=1;
    }

}

File.close();
if(flag==0)
cout<<"\tRECORD DOES NOT EXIST";
cin.get();
 }

 int Account::retcurdepo()
{
    return deposit;
    }
int Account::retwith(int amount)
{
    deposit -= amount;
    return deposit;
    }
void Account::with(int n,int amount)
 {
 Account ac;
fstream File;
flag=0;
File.open("account.dat",ios::binary|ios::in|ios::out);
if(!File){
    cout<<"\tFail to open the file. Press any key......";
    return;
}
while(!File.eof()&&flag==0){
        File.read(reinterpret_cast<char*>(&ac),sizeof(Account));
    if(ac.retacc_no()==n){
         if(ac.retcurdepo() < 500){
            cout<<"\n\n\n\tINSUFFICIENT BALANCE";
         }
         else{
       ac.retwith(amount);
         }
       //cout<<deposit;
       int pos=(-1)*static_cast<int>(sizeof(ac));// can't understand
			File.seekp(pos,ios::cur);
       File.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout<<"\n\n\t RECORD UPDATED";
			//found=true;
       flag=1;
    }

}

File.close();
if(flag==0)
cout<<"\tRECORD DOES NOT EXIST";
cin.get();
 }
void check_balance(){
    Account ac;
    int n,flag;
cout<<"\n\n\n\n\tEnter account number: ";
cin>>n;
system("cls");
ifstream inFile;
flag=0;
inFile.open("account.dat",ios::binary);
if(!inFile){
    cout<<"\tFail to open the file. Press any key......";
    return;
}
while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
    if(ac.retacc_no()==n){
      int balance = ac.retcurdepo();
cout<<"\n\n\n\tYOUR BALANCE IS: "<<balance<<endl;
       flag=1;
    }

}
inFile.close();
if(flag==0)
cout<<"\tACCOUNT NUMBER DOES NOT EXIST";
cin.get();
}

void search(){
Account ac;
int n;
cout<<"\n\n\n\tSEARCH:"<<endl;
cout<<"\n\tSearch account number: ";
cin>>n;
system("cls");
ac.display(n);
}

void transfer(){
int amt,to,from;
Account ac;
cout<<"\n\n\n\tAMOUNT TO TRANSFER: ";
cin>>amt;
cout<<"\n\n\n\tFROM WHICH ACCOUNT: ";
cin>>from;
cout<<"\n\n\n\tTO WHICH ACCOUNT: ";
cin>>to;
ac.depo(to,amt);
ac.with(from,amt);
}
void close(){
    int n;
    Account ac;
    cout<<"\n\n\n\n\tENTER ACCOUNT NUMBER TO CLOSE: ";
    cin>>n;
    ifstream inFile;
    ofstream outFile;
    inFile.open("account.dat",ios::binary);
    if(!inFile){
    cout<<"\tFail to open the file. Press any key......";
    return;
}
  outFile.open("Temp.dat",ios::binary|ios::out);
  inFile.seekg(0,ios::beg);
        while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
    if(ac.retacc_no()!=n){
            outFile.write(reinterpret_cast<char*>(&ac),sizeof(Account));
    }
        }
    inFile.close();
	outFile.close();
remove("account.dat");
rename("Temp.dat","account.dat");
cout<<"\n\n\n\tRECORD DELETED";
cin.get();
}

void Account::report(){

cout<<"\n"<<acc_no<<"\t"<< name<<"\t"<<mobile<<"\t"<<deposit<<"\n"<<endl;

}


void display_all(){
Account ac;
ifstream inFile;
inFile.open("account.dat",ios::binary);
cout<<"\n\n---------------------------------------------";
cout<<"\nACC.NO.\tNAME\tMOBILE NO.\tBALANCE\n";
cout<<"---------------------------------------------\n";
while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(Account))){
    ac.report();
}
cin.get();
}



int main(){
    char ch;
welcome_msg();
Account acc;
do{
        system("cls");
cout<<"\n\n\n\t1: NEW ACCOUNT"<<endl;
cout<<"\t2: DSIPLAY ACCOUNT INFORMATION"<<endl;
cout<<"\t3: DEPOSIT"<<endl;
cout<<"\t4: WITHDRAW"<<endl;
cout<<"\t5: CHECK BALANCE"<<endl;
cout<<"\t6: CLOSE ACCOUNT"<<endl;
cout<<"\t7: DISPLAY ALL ACCOUNT"<<endl;
cout<<"\t8: SEARCH"<<endl;
cout<<"\t9: TRANSFER AMOUNT\n\n"<<endl;
cout<<"\tE/e: EXIT\n\n"<<endl;
cout<<"Select a option (0-9) or E/e for exit\n\n"<<endl;
cin>>ch;
int acc_count=0;
int n,amount;
system("cls");
switch(ch){
case '1':
    acc.write_account();
    //acc.new_account(acc_count);

    break;
case '2':
    cout<<"\n\n\n\n\tEnter account number: ";
    cin>>n;
    acc.display(n);
    break;
case '3':
    cout<<"\n\n\n\n\tEnter account number: ";
    cin>>n;
    cout<<"\n\n\n\n\tEnter amount to deposit: ";
    cin>>amount;
    acc.depo(n,amount);
    break;
case '4':
    cout<<"\n\n\n\n\tEnter account number: ";
    cin>>n;
    cout<<"\n\n\n\n\tEnter amount to withdraw: ";
    cin>>amount;
    acc.with(n,amount);
    break;
case '5':
    check_balance();
    break;
case '6':
    close();
    break;
 case '7':
    display_all();
    break;
case '8':
    search();
    break;
case '9':
    transfer();
    break;
case 'E':
case 'e':
    cout<<"\n\n\n\n\tTHANK YOU FOR STOPING BY!!!!\n\n\n\n";
    return 0;
    break;
}
cin.ignore();
}while(ch!='E'||ch != 'e');

return 0;
}
