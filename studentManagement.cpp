#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
class student{
    int roll_no;
    int class_name;
    char name[20];
    char branch[5];
    char address[30];
    public:
    void getdata(){
        cout<<"Enter Roll No :- ";
        cin>>roll_no;
        cout<<"\nEnter Class :- ";
        cin>>class_name;
        cout<<"\nEnter Name :- ";
        cin.ignore();
        cin.getline(name,20);
        cout<<"\nEnter branch :-";
        //cin.ignore();
        cin.getline(branch,5);
        cout<<"\nAddress :- ";
        //cin.ignore();
        cin.getline(address,30);

    }
    void putdata(){
        cout<<"\nRoll No :- "<<roll_no<<"\nName :- "<<name;
        cout<<"\nClass :- "<<class_name<<"\nBranch :- "<<branch<<"\nAddress :- "<<address<<endl;
    }
    int getrollNo(){
        return roll_no;
    }
};
int main(){
    student s1;
    // Save record in file
    
    // Reading record from file
    int rno , found=0;
    long position;
    int choice;
    char add = 'y';
    fstream file_Obj("Student.dat",ios::app);
    ifstream file_obj("Student.dat");
    cout<<"\n1. Add student : \n2.Search Student : \n3. See All Record : \nEnter Choice :-";
    cin>>choice;
    switch(choice){
    case 1:
    
        while(add=='y' || add=='Y'){
        s1.getdata();
        file_Obj.write((char*)&s1, sizeof(s1));
        cout<<"Recorded added successfully !!";
        cout<<"Do you want to add another record(y/n)";
        cin>>add;
        }
        break;

    case 2:
         cout<<"\nEnter Roll No to find a record ";
         cin>>rno;
         file_obj.seekg(0);
         if(file_obj.is_open()){
         while(!file_obj.eof()){
             position =file_obj.tellg();
         file_obj.read((char*)&s1 , sizeof(s1));
         if(s1.getrollNo()==rno){
            file_obj.seekg(position);
            s1.putdata();
            
            found =1;
            break;
            }
            if(found==0){
        cout<<"\n\tNo record found !!!";
    }   
    file_obj.close();
    }
        }
          
    break;
    case 3:
         if(file_obj.is_open()){
         while(!file_obj.eof()){
         file_obj.read((char*)&s1 , sizeof(s1));
            s1.putdata();
            }
         }
         else{
             cout<<"Error -> To open the file !";
         }
         break;
    default:
    cout<<"Invalid choice";
}
return 0;    
}
