
                    // there is a composition relationship between class FCIStudent and FCIIdentity

#include <iostream>

using namespace std;
class FCIIdentity
{
private:             // 2 private member variables  the id of the student and its FCI mail
    string id,FciMail;
public:
    FCIIdentity()       // a default constructor which set string id and FCI mail to be an empty
    {
        id="i have no id";
        FciMail="i have no mail";
    }
    FCIIdentity(string id,string mail)       // a parameterized constructor which take 2 arguments id and mail
    {
        this->id=id;        // set the value of the parameter id and set it to the private member variable id
        FciMail=mail;       //set the value of the parameter mail and set it to the private member variable FCI mail

    }

    // setters and getters to the 2 private member variables

    void setid(string iD){id=iD;}

    void setmail(string fcimail){FciMail=fcimail;}

    string getid() const{return id;}

    string getmaiL() const{return FciMail;}

};
class FCIStudent
{
private:                // 3 private member variables the name of student and its age and an object from the class FCIIdentity
    string name;
    int age;
    FCIIdentity *fciID; // a default constructor which we made of FCI Identity is used here by the combiler
public:
    FCIStudent()      // a default constructor
    {
        name=" i have no name";
        fciID=new FCIIdentity;
            fciID->setid("i have no id");
            fciID->setmail("i have no mail");
        age=0;
    }
    FCIStudent(string name,int age)  // a parametrized constructor
    {
        fciID=new FCIIdentity;
        this->name=name;
        this->age=age;


    }

    // setters and getters to the 3 private member variables

    void setname(string NAME){name=NAME;}

    void setage(int AGE){age=AGE;}

    void setfciID(string FCIID,string fciMAIL){fciID->setid(FCIID); fciID->setmail(fciMAIL);}

    void setfciID(const FCIIdentity &obj){fciID->setid(obj.getid()); fciID->setmail(obj.getmaiL());}

    string getname()const{return name;}

    int getage()const{return age;}

    FCIIdentity& getfciID() {return *fciID;}

    ~FCIStudent(){delete fciID;}

    // member function to print the details
    void printDetails()
    {
        cout<<"name : "<<name<<endl<<"age : "<<age<<endl;
        cout<<"id : "<<fciID->getid()<<endl<<"FCImail : "<<fciID->getmaiL()<<endl<<endl;


    }

};
              // there is a aggregation relationship between  FCIStudent and FCICourse


class FCICourse
{
private:
    string name;
    int maxNumberOfStudentsCanBeEnrolled;
    FCIStudent *StudentEnrolled;
public:
    FCICourse(){

        name="i have no name";
        maxNumberOfStudentsCanBeEnrolled=0;
        StudentEnrolled = new FCIStudent[maxNumberOfStudentsCanBeEnrolled];

        FCIStudent student;
        for(int i=0;i<maxNumberOfStudentsCanBeEnrolled;i++)
        {

            StudentEnrolled[i]=student;
        }
        }
    FCICourse(string name,int maxStudentsNum ){

        this->name=name;
        maxNumberOfStudentsCanBeEnrolled=maxStudentsNum;
        StudentEnrolled = new FCIStudent[maxNumberOfStudentsCanBeEnrolled];
        }

    // setters and getters of the 3 member variables

    void setname(string Name){name=Name;}
    void setMaxStudentsNum(int number){maxNumberOfStudentsCanBeEnrolled=number;}
    void setStudentsEnrolled(FCIStudent *stud)
    {
        for(int i=0;i<maxNumberOfStudentsCanBeEnrolled;i++)
        {
            StudentEnrolled[i]=stud[i];
        }
    }
    string getname()const{return name;}
    int getmaxStudentsNum()const{return maxNumberOfStudentsCanBeEnrolled;}

    //a member function to add a student to the list of students had enrolled to the course

    bool addStudent(FCIStudent *student )
    {
        FCIStudent st;
        int i;
        for(i=0;i<maxNumberOfStudentsCanBeEnrolled;i++){
            if(StudentEnrolled[i].getage()==st.getage() &&StudentEnrolled[i].getname()==st.getname())
                {
                    StudentEnrolled[i]=*student;
                    return true;
                }
        }
            if (i==maxNumberOfStudentsCanBeEnrolled)
                    return false;



    }

    // a member function printALLStudentsEnrolled to print the details about each student in the course

    void printAllStudentsEnrolled()
    {
        cout<<"name of the course : "<<name<<endl;
        for(int i=0;i<maxNumberOfStudentsCanBeEnrolled;i++)
        {
            StudentEnrolled[i].printDetails();
        }
    }
};
int main()
{


    //FCICourse math("math",3);

    FCIIdentity obj1("1234","someone@yahoo.com"),obj2("4567","ahmed@gmail.com"),obj3("8910","jack@gmail.com");
    FCIStudent student_1("some one",20),student_2("ahmed",19),student_3("jack",21),tempobj;

    student_1.setfciID("0123","moh@gmail.com");
    student_2.setfciID(obj2);
    student_3.setfciID(obj3);

    FCIStudent arr[3];
    arr[0]=student_1;
    arr[1]=student_2;
    arr[2]=tempobj;

    FCICourse math("math",3);
    math.setStudentsEnrolled(arr);

    math.printAllStudentsEnrolled();
    if(math.addStudent(&student_3))
        cout<<"........there is a place for one more student student........ "<<endl<<endl;

    math.printAllStudentsEnrolled();





}
