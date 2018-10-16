#include <iostream>
#include <fstream>
using namespace std;

class student{
    public:
        string studentid;
        string name;
        int age;
        string sex;
        int score;
        string grade;
};

int main(){
cout << "Record entry" "\n\n" <<endl;

student entry[5];
int male=0;
int female=0;
int agesum=0;
float scoresum=0;

for (int i=0;i<5;i++){
    cout << "\n\n" "Enter ID : ";
    cin >> entry[i].studentid;
    if ((entry[i].studentid).length()!=8){
        cout << "Please enter the correct ID (Must be 8 characters)" << endl;
        cin >> entry[i].studentid;
    }
    cout << "Enter Name : ";
    cin >> entry[i].name;
    cout << "Enter Age : ";
    cin >> entry[i].age;
    cout << "Enter Sex 'm/f' : ";
    cin >> entry[i].sex;
    if (!(entry[i].sex == "F" || entry[i].sex == "f" || entry[i].sex == "M" || entry[i].sex == "m")){
        cout << "Please enter the correct sex (M or m or F or f)" << endl;
        cout << "Enter Sex 'm/f' : ";
    }
    cout << "Enter Score 100% : ";
    cin >> entry[i].score;
    if ((entry[i].score) >= 100){
        cout << "Please enter the correct score (less than or equal to 100)" << endl;
        cin >> entry[i].score;
    }
    cout << "Enter Grade : ";
    cin >> entry[i].grade;

    agesum += entry[i].age;scoresum += entry[i].score;
     if (entry[i].sex == "f"){
        female++;
     }
     else{
        male++;
     }
}


//###writing records to Document###
ofstream rec;
rec.open("record.txt");

rec << "ID          Student_Name          Age     Gender   Score   Grade \n";
rec << "*****************************************************************\n";

for (int i=0;i<5;i++){
    rec << entry[i].studentid<< "\t" << entry[i].name << "\t" << entry[i].age << "\t" << entry[i].sex << "\t" << entry[i].score<< "\t" << entry[i].grade <<endl;
};

rec << "\n\n\n***********************************************************\n\n";
rec << "Average score of the students is  : " << scoresum/5 <<endl;
rec << "Average age of the student is  : " << agesum/5 <<endl;
rec << "Total number of females are  : " << female <<endl;
rec << "Total number of males are : "<< male <<endl;

rec.close();

return 0;

};
