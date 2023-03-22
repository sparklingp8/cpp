#include<iostream>
#include<string>
using namespace std;
int main(){
   struct students{
      int roll;
      string name;
   };
   
   students s1,*s2;
   s2=&s1;
   s1.roll=12;   
   s1.name="bbbd";
   cout<<s1.name<<s1.roll<<&s1<<&s2<<endl;
   s2->name="cccd";
   cout<<s1.name<<s1.roll<<&s1<<&s2<<endl;



}