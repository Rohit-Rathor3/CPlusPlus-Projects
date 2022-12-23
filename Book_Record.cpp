#include<iostream>
using namespace std;
class publication{
    float price;
    char title[20];
    public:
    void getdata(){
        cout<<"Enter the book title : ";
        cin>>title;
        cout<<"\n  Enter book price : ";
        cin>>price;

    }
    void putdata(){
        cout<<"The title of biik is : "<<title<<endl;
        cout<<"The price of book is : "<<price<<endl;

    }
};
class sales{
    float s1,s2,s3;
    public:

void getdata(){
    cout<<"Enter the sale of first month : ";
    cin>>s1;
    cout<<"\nEnter the sale of second month : ";
    cin>>s2;
    cout<<"\nEnter the sale of third month : ";
    cin>>s3;
}
void putdata(){
    cout<<"\n Sale of first month : "<<s1;    
    cout<<"\n Sale of second month : "<<s2;
    cout<<"\n Sale of third month : "<<s3;

}
};
class book: private publication , private sales{
    int pages;
    public:
    void getdata(){
        cout<<"\nBook Details : ";
        publication::getdata();
        sales::getdata();
        cout<<"\nEnter the number of pages : ";
        cin>>pages;
    }
        void putdata(){
            cout<<"\nBook Details : ";
            publication::putdata();
            cout<<"Number of pages  : "<<pages<<endl;
            sales::putdata();
        }
        };
    class tape: private publication , private sales{

        float time;
        public:
        void getdata(){
            cout<<"\nTape Details : ";
            publication::getdata();
            sales::getdata();
            cout<<"Enter the time length of tape : ";
            cin>>time;

        }
        void putdata(){
            cout<<"\nTime length : "<<time<<endl;
            sales::putdata();
            
        }
    };
int main(){
    book b;
    tape t;
    b.getdata();
    t.getdata();
    b.putdata();
    t.putdata();
    return 0;
}
