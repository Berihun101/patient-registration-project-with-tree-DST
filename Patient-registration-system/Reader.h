#include <iostream>
#include <string>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<iomanip>

using namespace std;

int read(){


      ifstream myfile;
             myfile.open("store_file.txt",ios::in);
             if(myfile.is_open())
             {
               string line;
               while(getline(myfile,line)){
               cout<< line<<endl;
               }
              myfile.close();
            }
            else{
              cout<<"OPPS!An error occured while opening a file";
            }
        getch();
       return 0;












}
