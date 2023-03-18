#include <iostream>
#include <string>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
struct patient{
 char name[20];
 char fname[20];
 double cardNO;
 char sex[7];
 int age;
 double phone;
 char bloodtype[3];
 patient *right;
 patient *left;
};
 ofstream myfile;


void Print(patient * root, int num);
int insertData(int amount){
    patient *InsertNode= new patient;
    for(int i=0; i<amount; i++){

 cout<<endl<<"Enter first name of the patient"<<endl;
	  cin>>InsertNode->name;
 cout<<endl<<"Enter Father name of the patient"<<endl;
	  cin>>InsertNode->fname;
 cout<<endl<<"Enter sex of patient"<<endl;
	  cin>>InsertNode->sex;
	   a:
 cout<<endl<<"Enter AGE of patient"<<endl;
	  cin>>InsertNode->age;
 if (cin.fail() || InsertNode->age<0 || InsertNode->age>200){
 cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto a;
    }
     b:
 cout<<endl<<"Enter phone number"<<endl;
	  cin>>InsertNode->phone;
	  if (cin.fail()){
        cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto b;
    }
    c:
 cout<<endl<<"Enter card number of the patient(5-digit)"<<endl;
	  cin>>InsertNode->cardNO;
	  	  if (cin.fail()){
 cout<<endl<<"Invalid Input"<<endl;
        cin.clear();
        cin.ignore();
        goto c;
    }
cout<<endl<<"Enter Blood type of the patient"<<endl;
	  cin>>InsertNode->bloodtype;
     InsertNode->left=NULL;
     InsertNode->right=NULL;
      if(root==NULL){
        root=InsertNode;
        InsertNode->left=NULL;
        InsertNode->right=NULL;
      }
      else{
       patient *temp=root;
       int inserted=0;
       while(inserted==0){
        if(temp->cardNO > InsertNode->cardNO){
            if(temp->left==NULL){
                temp->left=InsertNode;
                InsertNode->left=NULL;
                InsertNode->right=NULL;
                inserted=1;
            }
            else{
                temp=temp->left;
            }
        }
        else{
            if(temp->right==NULL){
                temp->right=InsertNode;
                InsertNode->left=NULL;
                InsertNode->right=NULL;
                inserted=1;
            }
            else{
                temp=temp->right;
            }
        }
       }
      }
      system("cls");
      cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSaved ... ";
       Sleep(700);
        system("cls");

    }

    int num=1;
     myfile.open("store_file.txt", ios::out );
     myfile << "\n\n\t\t\t\t\t\t\t ********** Display patient records ********** \n";
     myfile<<left<<setw(5)<<"N0"<<left<<setw(27)<<"Personal Information"<<left<<setw(15)<<"value";
     myfile << "\n--------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;

     Print(root, num);
      myfile.close();

 return 0;
}
   void Print( struct patient * root, int num){
    if(root != NULL){


             myfile<<left<<setw(5)<<num<<left<<setw(27)<< "First name:"<<left<<setw(15)<<root->name<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Father name:"<<left<<setw(15)<<root->fname<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Card number:"<<left<<setw(15)<<root->cardNO<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Age:"<<root->age<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Gender:"<<left<<setw(15)<<root->sex<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Phone Number:"<<left<<setw(15)<<root->phone<<endl;
             myfile<<setw(5)<<" "<<setw(27)<<"Blood Type:"<<left<<setw(15)<<root->bloodtype<<endl;
                num++;
             //Print(root->left, num);
             //Print(root->right, num);





       }

}
void searchbyName()
{


}
