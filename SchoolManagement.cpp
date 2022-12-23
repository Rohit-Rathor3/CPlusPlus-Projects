#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class classes{
    char class_name[20];
    char class_incharge[20];
    int class_no;
    int total_student;
    public:
    classes(){
        class_name=0;
    }
    void getdata(){
        cout<<"\nEnter class name : ";
        cin.getline(class_name,20);
        cout<<"\nEnter class Room No :-";
        cin>>class_no;
        cout<<"\nEnter Class Incharge Name :- ";
        cin.ignore();
        cin.getline(class_incharge,20);
        cout<<"\nEnter total Student :- ";
        cin>>total_student;
    }

    void showdata(){
        cout<<"\n\tClass : "<<class_name<<"\n\tRoom no :- "<<class_no;
        cout<<"\n\tIncharge :- "<<class_incharge<<"\n\tTotal Student :- "<<total_student<<endl;
    }
    
};

class student{
    int roolNo;
    char student_name[30];
    char phoneNo[10];
    char address[40];
    public:
    void studentData(){
        cout<<"\n\tEnter Stdent Details";
        cout<<"\n\tRool No :- ";
        cin>>roolNo;
        cout<<"\n\tEnter Name :- ";
        cin.ignore();
        cin.getline(student_name,30);
        cout<<"\n\tContact No :- ";
        cin.getline(phoneNo,10);
        cout<<"\n\tAddress :- ";
        cin.getline(address,40);
    }
    void showStudent(){
        cout<<"\nStudent Rool no :- "<<roolNo<<"\nName :-  "<<student_name;
        cout<<"\nContact No :-"<<phoneNo<<"\nAddress :- "<<address<<endl;
    }

};
class first:public classes ,public student{
    
    
};
void saveFile()
    {
        first f;
    ofstream file_obj("School.dat" , ios::binary | ios::app);
    if(file_obj.is_open()){
        file_obj.write((char*)f , sizeof(f));
        file_obj.close();
        cout<<"\nClass Details Saved Successfuly !!";
    }
    else{
        cout<<"\n Error -> To save the file !!";
    }
    }
    void seeFile(){
        first f;
        ifstream file_Obj("school.dat",ios::binary);
        cout<<"Seek "<<file_Obj.seekg();
        if(file_Obj.is_open()){
            //file_Obj.seekg(0);
            while(file_Obj.eof()==0){
            //cout<<"\n\t--------- Class Details -----------";
            file_Obj.read((char*)&f,sizeof(f));
            showdata();
            showStudent();
            }
            file_Obj.close();
    }
    else{
        cout<<"\nError -> To read file !!";
    }
    
    }
  
    
int main(){
    first f1;
    f1.getdata();
    f1.showdata();
    f1.studentData();
    f1.showStudent();
    saveFile();
    seeFile(); 
    
    return 0;
}
