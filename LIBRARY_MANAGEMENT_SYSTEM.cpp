//LIBRARY MANAGEMENT PROJECT
#include<iostream>
#include<fstream>
#include<bits/stdc++.h>     // string is defined,transform function
#include<stdlib.h>
#include<conio.h>
#include<ios>
#include<limits>
#include<sstream>
//#include<windows.h>
#include<ctime>
#include<time.h>
#include<iomanip>
using namespace std;

int j;

struct Date
{
  int dd,mm,yy;
};

void view_booklist();
void add_book();
void delete_book();
void delete_();
void delete_copy();
void login();
void librarian();
void search_book();
void Books(int);
void add_new_book();
void add_copy();
void Book_librarian(int x=0);                 //
void issue_book();
void ISSUE_BOOK();
void view_issued_books();
void reissue_book();                        //
void ebooks();
void change_password();
void add_modify_link();                    //
float fine(Date d);                       //
unsigned long long int return_days(Date d);                //
void return_book();                                //
void conversion(int pk);
//void delay(unsigned int ms);
void finelist();
void display_rules();

/*void espeaker(string s)
{
  string command="espeak \""+s+"\"";
  const char* charCommand=command.c_str();
  system(charCommand);
}*/

void conversion(int pk)
{
	ostringstream ss;
	ss<<pk;
	string s=ss.str();
	//espeaker(s);
}

void delay(unsigned int ms)
{
    clock_t timedelay = ms + clock();
    while (timedelay > clock());
}

class book
{
   public:

   int bookid,copies;
   char author[50];
   char publication[50];
   char name[50];
   float cost;
   char link[100];
   void input();
   void display();
};

inline void book::input()             //use of inline      getline in which hf
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\t\t\t\t\t\t\t\t\tENTER NAME OF BOOK : ";
    //if(j==49){espeaker("Enter Name of Book ");}
    cin.get(name,50);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\n\t\t\t\t\t\t\t\t\tENTER AUTHOR : ";
    //if(j==49){espeaker("ENTER Author ");}
    cin.get(author,50);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\n\t\t\t\t\t\t\t\t\tENTER PUBLISHER : ";
    //if(j==49){espeaker("ENTER PUBLISHER");}
    cin.get(publication,50);
    cout<<"\n\t\t\t\t\t\t\t\t\tENTER BOOKID : ";
    //if(j==49){espeaker("ENTER BOOKID");}
    cin>>bookid;
    cout<<"\n\t\t\t\t\t\t\t\t\tENTER NO. OF COPIES : ";
    //if(j==49){espeaker("ENTER NO. OF COPIES");}
    cin>>copies;
    cout<<"\n\t\t\t\t\t\t\t\t\tENTER COST : ";
    //if(j==49){espeaker("ENTER COST");}
    cin>>cost;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\n\t\t\t\t\tENTER LINK FOR BOOK (TYPE \"None\" IF LINK DOESN'T EXIST) : ";
    //if(j==49){espeaker("Enter Link For Book (Type None If Link doesn't exist) ");}
    cin.get(link,100);
}

inline void book::display()
{
    cout<<left<<setw(25)<<bookid<<setw(43)<<name<<setw(35)<<author<<setw(40)<<publication<<setw(25)<<cost<<setw(25)<<copies<<endl;
}

class student
{
    public:
    char name[20];
    int roll_no;
    unsigned long long int contact;
    char book_name[50];
    int bookid;
    Date d;
    float fine=0;
    void input();
    void display();
    void display(int);
};

inline void student::input()
{
    system("cls");
    char slash;
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter Name of Student : ";
    //if(j==49){espeaker("Enter Name of Student");}
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(name,20);
    cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Roll No. of Student : ";
    //if(j==49){espeaker("Enter Roll No. of Student");}
    cin>>roll_no;
    cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Contact of Student : ";
    //if(j==49){espeaker("Enter Contact of Student");}
    cin>>contact;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Name of Book to be issued : ";
    //if(j==49){espeaker("Enter Name of Book to be issued");}
    cin.get(book_name,50);
    cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Book ID : ";
    //if(j==49){espeaker("Enter Book ID");}
    cin>>bookid;
    cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Date (dd/mm/yy) : ";
    //if(j==49){espeaker("Enter Date");}
    cin>>d.dd>>slash>>d.mm>>slash>>d.yy;
}

inline void student::display()
{
    char slash='/';
    cout<<"                 "<<left<<setw(25)<<name<<setw(25)<<roll_no<<setw(25)<<contact<<setw(25)<<book_name<<setw(25)<<bookid<<d.dd<<slash<<d.mm<<slash<<d.yy<<endl;
}

inline void student::display(int i)
{
    char slash='/';
    cout<<"              "<<left<<setw(25)<<name<<setw(25)<<roll_no<<setw(25)<<contact<<setw(25)<<book_name<<setw(25)<<bookid<<d.dd<<slash<<d.mm<<slash<<setw(15)<<d.yy<<fine<<endl;
}

int main()
{
    system("Color 0F");
    static int p=0;
    int n;
    system("cls");

    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t***LIBRARY MANAGEMENT SYSTEM***\n\n\n";
    //if(p==0){espeaker("WELCOME to LIBRARY MANAGEMENT SYSTEM");p++;
    //espeaker("if you need voice assistance press 1 ");
    //j=getch();
    cout<<"\t\t\t\t\t\t\t\t\t S.No.   OPTIONS\n\n";//if(j==49){espeaker("options ");}
    cout<<"\t\t\t\t\t\t\t\t\t [1]     STUDENT SECTION\n";//if(j==49){espeaker(" press 1 to VIEW STUDENT SECTION");}
    cout<<"\t\t\t\t\t\t\t\t\t [2]     LOGIN AS LIBRARIAN\n";//if(j==49){espeaker("press 2 to LOGIN AS LIBRARIAN ");}
    cout<<"\t\t\t\t\t\t\t\t\t [3]     e BOOKS\n";//if(j==49){espeaker("press 3 for e books ");}
    cout<<"\t\t\t\t\t\t\t\t\t [4]     RULES OF LIBRARY\n";//if(j==49){espeaker("press 4 to view rules of library ");}
    cout<<"\t\t\t\t\t\t\t\t\t [0]     EXIT\n\n";//if(j==49){espeaker("press 0 to exit  ");}
    //if(j==49){espeaker(" Enter Your Choice :");}
    cout<<"\t\t\t\t\t\t\t\t\t YOUR CHOICE : ";
    cin>>n;
    //if(j==49){espeaker("Your Choice");}
    if(j==49){conversion(n);}
    switch(n)
    {
        case 1:Books(0);
        break;
        case 2:login();
        break;
        case 3: ebooks();
        break;
        case 4:display_rules();
        case 0:exit(0);
        default:{cout<<"\n\t\t\t\t\t\t\t\t\t\tINVALID CHOICE\n\t\t\t\t\t\t\t\t\t\t       ";
//                 if(j==49){espeaker("INVALID CHOICE");}
                 _beep(900,2000);
                 cout<<"\n\n\t\t\t\t\t\t\t\t\t***PRESS ENTER TO CONTINUE***\n\t\t\t\t\t\t\t\t\t\t       ";
                 //if(j==49){espeaker("PRESS ENTER TO CONTINUE");}
                 getch();
                 main();
                }
    }
}

void display_rules()
{
    system("cls");
    system("Color 0A");
cout<<"\n\n\n\t\t\t\t\t\t\t\t\t*****RULES OF LIBRARY*****\n\n\t\t\t\t\t\t\t\t\t\t <<PAGE 1>>\n\n";
cout<<"\t\t\t\t\t\t\t\t\t   FOLLOW THE RULES!\n"<<endl;
cout<<"1.Carry your student ID card with you when you enter the library."<<endl;
cout<<"\n2.Do not take any book or other library material out of the library without following the borrowing procedures."<<endl;
cout<<"\n3.Make sure to return the borrowed items by the due date."<<endl;
cout<<"\n4.In case any of the borrowed items being lost, damaged, or destroyed, you are required to replace the lost /damaged/destroyed item with a new one."<<endl;
cout<<"\n5.Never write in books or cut pages out of them."<<endl;
cout<<"\n6.Return books/materials to their original location on the bookshelf.\n\n\n"<<endl;
getch();
cout<<"\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GO TO PAGE 2***";
//if(j==49){espeaker("PRESS ENTER TO GO TO PAGE 2");}
getch();

system("cls");
system("Color 0B");
cout<<"\n\n\n\t\t\t\t\t\t\t\t\t*****RULES OF LIBRARY*****\n\n\t\t\t\t\t\t\t\t\t\t <<PAGE 2>>\n\n";
cout<<"\t\t\t\t\t\t\t\t\t   PRACTICE GOOD MANNERS!\n"<<endl;
cout<<"1.Any food is not allowed to have in the library. Only drink bottles with a cap that could be tightly closed are permitted in the reading room."<<endl;
cout<<"\n2.Using of mobile phones is prohibited. Switch your mobile phone off and keep it in your bag, etc. while you are in the library."<<endl;
cout<<"\n3.Private conversations are not permitted. Even talking in a whisper or standing and chatting may be disturbing to others. Strictly prohibited from doing the above."<<endl;
cout<<"\n4.Refrain from leaving your baggage, etc. on library chairs/sofas, and avoid taking up two seats by sitting on one and putting your baggage, clothes, etc. on the other. Also, please be sure not to leave valuables unattended.\n\n"<<endl;
cout<<"\nYour cooperation is requested in providing a quiet reading environment.\n\n\n";
getch();
cout<<"\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GO TO PAGE 3***";
//if(j==49){espeaker("PRESS ENTER TO GO TO PAGE 3");}
getch();

system("cls");
system("Color 0F");
cout<<"\n\n\n\t\t\t\t\t\t\t\t\t*****RULES OF LIBRARY*****\n\n\t\t\t\t\t\t\t\t\t\t <<PAGE 3>>\n\n";
cout<<"\t\t\t\t\t\t\t\t\t       FINE RULES\n"<<endl;
cout<<"1. You can keep book with yourself for 15 days at RS 0 cost."<<endl;
cout<<"\n2. After 15 days 30 Rs/day."<<endl;
cout<<"\n3. After 15 days 50 Rs/day."<<endl;
cout<<"\n4. After 15 days 100 Rs/day.\n\n"<<endl;
cout<<"\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GO TO PAGE 4***";
getch();
//if(j==49){espeaker("PRESS ENTER TO GO TO PAGE 4");}
getch();

system("cls");
system("Color 0D");
cout<<"\n\n\n\t\t\t\t\t\t\t\t\t*****RULES OF LIBRARY*****\n\n\t\t\t\t\t\t\t\t\t\t <<PAGE 4>>\n\n";
cout<<"\t\t\t\t\t\t\t\t\t   RE-ISSUE CONDITION\n"<<endl;
cout<<"You can reissue book only if you issued some book and your name is not in defaulter list i.e. You have zero rupees pending fine.\n\n\n";
getch();
cout<<"\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GO TO MAIN MENU***";
//if(j==49){espeaker("PRESS ENTER TO GO TO MAIN MENU");}
getch();
main();
}

void finelist()
{

    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t     *****FINE DEFAULTERS*****\n\n";
    cout<<"              "<<left<<setw(25)<<"NAME"<<setw(25)<<"ROLL NO."<<setw(25)<<"CONTACT"<<setw(25)<<"BOOKNAME"<<setw(25)<<"BOOKID"<<setw(19)<<"ISSUE DATE"<<"FINE"<<endl<<endl;
    student s1;
    ifstream fin("Studentdata.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(s1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&s1,sizeof(s1));
        s1.fine=fine(s1.d);
        if(s1.fine!=0)
        {
            s1.display(1);
        }
    }
    fin.close();
    cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***PRESS ENTER TO GET BACK***\n";
    //if(j==49){espeaker("PRESS ENTER TO GET BACK");}
    getch();
    librarian();
}

unsigned long long int return_days(Date d)
{
    int years=d.yy;
    const int monthDays[12]= { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };

    if (d.mm <= 2)
    {years--;}

    unsigned long long int n1=d.yy * 365 + d.dd;
    for (int i = 0; i < d.mm - 1; i++)
    {
         n1 += monthDays[i];
    }
    n1+=years / 4
        - years / 100
        + years / 400;

        return n1;
}

float fine(Date d1)
{
    time_t t=time(NULL);
    tm* tptr = localtime(&t);
    Date d2={tptr->tm_mday,(tptr->tm_mon)+1,(tptr->tm_year)+1900};
    float fine;
    int days=return_days(d2)-return_days(d1);
    if(days<=15)
    {
        fine=0;
    }
    else if(days>15 && days<=30)
    {
        fine=(days-15)*30;
    }
    else if(days>30 && days<=60)
    {
        fine=(15*30)+(days-30)*50;
    }
    else
    {
        fine=(15*30)+(30*50)+(days-60)*100;
    }
    return fine;
}

void add_modify_link()
{
    system("cls");
    book b1;
    char book_name[50];
    int bookid,k=0;
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER NAME OF BOOK : ";
    //if(j==49){espeaker("ENTER NAME OF BOOK");}
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get(book_name,50);
    cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER BOOK ID : ";
    //if(j==49){espeaker("ENTER BOOK ID");}
    cin>>bookid;
    ifstream fin("Bookdata.txt");
    ofstream fout("Temporary.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(b1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&b1,sizeof(b1));
        if(!strcmp(book_name,b1.name) && bookid==b1.bookid)
        {
            k=1;
            if(!strcmp(b1.link,"None"))
            {
                cout<<"\n\n\t\t\t\t\t\t\t\t\tPREVIOUS LINK : None\n";
                cout<<"\n\t\t\t\t\t\t\t\t\tENTER NEW LINK : ";
                //if(j==49){espeaker("ENTER NEW LINK");}
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get(b1.link,100);
                fout.write((char *)&b1,sizeof(b1));
            }
            else
            {
                cout<<"\n\n\t\t\t\t\t\t\t\t\tPREVIOUS LINK : "<<b1.link<<"\n";
                cout<<"\n\t\t\t\t\t\t\t\t\tENTER NEW LINK : ";
                //if(j==49){espeaker("ENTER NEW LINK");}
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get(b1.link,100);
                fout.write((char *)&b1,sizeof(b1));
            }
        }
        else
        {
                fout.write((char *)&b1,sizeof(b1));
        }
    }
    if(k==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t\tBOOK NOT FOUND.\n";
        fin.close();
        fout.close();
        cout<<"\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK\n";
        //if(j==49){espeaker("BOOK NOT FOUND PRESS ENTER TO GET BACK");}
        getch();
        librarian();
    }
    fin.close();
    fout.close();
    ifstream fin1("Temporary.txt");
    ofstream fout1("Bookdata.txt");
    fin1.seekg(0,ios::end);
    n=fin1.tellg()/sizeof(b1);
    fin1.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin1.read((char *)&b1,sizeof(b1));
        fout1.write((char *)&b1,sizeof(b1));
    }
    fin.close();
    fout1.close();
    cout<<"\n\n\t\t\t\t\t\t\t\t\tLINK ADDED SUCCESSFULLY.\n";
    cout<<"\n\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK.\n";
    //if(j==49){espeaker("LINK ADDED SUCCESSFULLY PRESS ENTER TO GET BACK");}
    getch();
    librarian();
}

void issue_book()
{
    system("cls");
    student s1;
    book b1;
    s1.input();
    int k=0;
    ofstream fout("Studentdata.txt",ios::app);
    ifstream fin("Bookdata.txt");
    ofstream fout1("Temporary.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(b1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&b1,sizeof(b1));
        if(strcmp(b1.name,s1.book_name))
        {
            fout1.write((char *)&b1,sizeof(b1));
        }
        else
        {
            k=1;
            --b1.copies;
            fout1.write((char *)&b1,sizeof(b1));
        }
    }
    if(k==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t\tBOOK NOT FOUND.\n";
        fout.close();
        fin.close();
        fout1.close();
        cout<<"\n\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK***";
        //if(j==49){espeaker("BOOK NOT FOUND PRESS ENTER TO GET BACK");}
        getch();
        ISSUE_BOOK();
    }
    else
    {
        fout.write((char *)&s1,sizeof(s1));
        fout.close();
        fin.close();
        fout1.close();
        ofstream f("Bookdata.txt");
        ifstream fin1("Temporary.txt");
        fin1.seekg(0,ios::end);
        n=fin1.tellg()/sizeof(b1);
        fin1.seekg(0,ios::beg);
        for(int i=0;i<n;i++)
        {
            fin1.read((char *)&b1,sizeof(b1));
            f.write((char *)&b1,sizeof(b1));
        }
        fin1.close();
        f.close();
        cout<<"\n\n\t\t\t\t\t\t\t\t\tBOOK ISSUED SUCCESSFULLY.";
        cout<<"\n\n\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK**";
        //if(j==49){espeaker("BOOK ISSUED SUCCESSFULLY PRESS ENTER TO GET BACK");}
        getch();
        ISSUE_BOOK();
    }
}

void ISSUE_BOOK()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t***ISSUE BOOKS*\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t S.No.  Options\n\n";//if(j==49){espeaker("Options");}
    cout<<"\t\t\t\t\t\t\t\t\t [1]     ISSUE BOOK\n";//if(j==49){espeaker("PRESS 1 TO ISSUE BOOK");}
    cout<<"\t\t\t\t\t\t\t\t\t [2]     VIEW ISSUED BOOKS\n";//if(j==49){espeaker("PRESS 2 TO VIEW ISSUED BOOKS");}
    cout<<"\t\t\t\t\t\t\t\t\t [3]     REISSUE BOOK\n";//if(j==49){espeaker("PRESS 3 TO REISSUE BOOK");}
    cout<<"\t\t\t\t\t\t\t\t\t [0]     BACK\n\n";//if(j==49){espeaker("PRESS 0 TO GET BACK");}
    cout<<"\t\t\t\t\t\t\t\t\t Your Choice : ";
//    if(j==49){espeaker("YOUR CHOICE");}
    int n;
    cin>>n;
    if(j==49){conversion(n);}
    switch(n)
    {
        case 1:issue_book();
        break;
        case 2:view_issued_books();
        break;
        case 3:reissue_book();
        break;
        case 0:librarian();
        break;
        default:cout<<"\t\t\t\t\t\t\t\t\t\t**INVALID ENTRY**\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t***PRESS ENTER TO CONTINUE****";
        //if(j==49){espeaker("INVALID ENTRY PRESS ENTER TO CONTINUE");}
        getch();
        ISSUE_BOOK();
    }
    ISSUE_BOOK();
}

void reissue_book()
{
   system("cls");
   student s1,s2;
   char name[20];
   int roll_no,bookid,k=0;
   char book_name[50];
   cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER NAME OF STUDENT : ";
   //if(j==49){espeaker("ENTER NAME OF STUDENT");}
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
   cin.get(name,20);
   cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER ROLL NO. OF STUDENT : ";
   //if(j==49){espeaker("ENTER ROLL NO. OF STUDENT");}
   cin>>roll_no;
   cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER NAME OF BOOK : ";
   //if(j==49){espeaker("ENTER NAME OF BOOK");}
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
   cin.get(book_name,20);
   cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER BOOK ID : ";
   //if(j==49){espeaker("ENTER BOOK ID");}
   cin>>bookid;
   ifstream fin("Studentdata.txt");
   ofstream fout("Temporarystudent.txt");
   fin.seekg(0,ios::end);
   int n=fin.tellg()/sizeof(s1);
   fin.seekg(0,ios::beg);
   for(int i=0;i<n;i++)
   {
      fin.read((char *)&s1,sizeof(s1));
      s1.fine=fine(s1.d);
      if(!strcmp(name,s1.name) && !strcmp(book_name,s1.book_name) && roll_no==s1.roll_no && bookid==s1.bookid)
      {
          k=1;
          if(s1.fine==0)
           {
               s2=s1;
              char slash;
              cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER TODAY'S DATE (dd/mm/yy) : ";
              //if(j==49){espeaker("ENTER TODAY'S DATE");}
              cin>>s2.d.dd>>slash>>s2.d.mm>>slash>>s2.d.yy;
           }
           else
           {
              cout<<"\n\n\t\t\t\t\t\t\t\t\tBOOK CAN'T BE REISSUED BECAUSE OF PENDING FINE = "<<s1.fine<<" Rs.\n";
              //if(j==49){espeaker("BOOK CAN'T BE REISSUED BECAUSE OF PENDING FINE");}
              fin.close();
              fout.close();
              cout<<"\n\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK\n";
              //if(j==49){espeaker("PRESS ENTER TO GET BACK");}
              getch();
              ISSUE_BOOK();
           }
      }
      else
      {
          fout.write((char *)&s1,sizeof(s1));
      }
   }
   if(k==0)
   {
       cout<<"\n\n\t\t\t\t\t\t\t\t\tREISSUE CONDITIONS NOT MET.\n";
       fin.close();
       fout.close();
       cout<<"\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK\n";
       //if(j==49){espeaker("REISSUE CONDITIONS NOT MET PRESS ENTER TO GET BACK");}
       getch();
       ISSUE_BOOK();
   }
   fout.write((char*)&s2,sizeof(s2));
   fin.close();
   fout.close();
   ifstream fin1("Temporarystudent.txt");
   ofstream fout1("Studentdata.txt");
   fin1.seekg(0,ios::end);
   n=fin1.tellg()/sizeof(s1);
   fin1.seekg(0,ios::beg);
   for(int i=0;i<n;i++)
   {
       fin1.read((char *)&s1,sizeof(s1));
       fout1.write((char *)&s1,sizeof(s1));
   }
   fin1.close();
   fout1.close();
   cout<<"\n\n\t\t\t\t\t\t\t\t\tREISSUED SUCCESSFULLY.\n";
   cout<<"\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK\n";
   //if(j==49){espeaker("REISSUED SUCCESSFULLY PRESS ENTER TO GET BACK");}
   getch();
}

void view_issued_books()
{
    system("cls");
    cout<<"\n\n\t\t\t\t\t\t\t\t\t S.No.  Options\n\n";//if(j==49){espeaker("OPTIONS");}
    cout<<"\t\t\t\t\t\t\t\t\t [1]  VIEW ISSUED BOOKS\n";//if(j==49){espeaker("PRESS 1 TO VIEW ISSUED BOOKS");}
    cout<<"\t\t\t\t\t\t\t\t\t [2]  SORT BY DATE\n";//if(j==49){espeaker("PRESS 2 TO Sort issued books by date");}
    cout<<"\t\t\t\t\t\t\t\t\t [3]  SORT BY STUDENT NAME\n";//if(j==49){espeaker("PRESS 3 TO sort all books issued by a particular student");}
    cout<<"\t\t\t\t\t\t\t\t\t [0]  BACK\n";//if(j==49){espeaker("PRESS 0 BACK");}
    cout<<"\n\t\t\t\t\t\t\t\t\tYour Choice : ";
    //if(j==49){espeaker("Your Choice");}
    int n;
    cin>>n;
    if(j==49){conversion(n);}
    switch(n)
    {
        case 1:{system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t  ***ISSUED BOOKS LIST***\n\n";
    cout<<"                 "<<left<<setw(25)<<"NAME"<<setw(25)<<"ROLL NO."<<setw(25)<<"CONTACT"<<setw(25)<<"BOOKNAME"<<setw(25)<<"BOOKID"<<"ISSUE DATE"<<endl<<endl;
    student s1;
    ifstream fin("Studentdata.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(s1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&s1,sizeof(s1));
        s1.display();
    }
    fin.close();
    cout<<"\n\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK\n";
    //if(j==49){espeaker("PRESS ENTER TO GET BACK");}
    getch();
    view_issued_books();
    }
    case 2:{system("cls");
            Date d;char slash;
            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t  ***SORTED ISSUED BOOKS BY DATE***\n\n";
            cout<<"\t\t\t\t\t\t\t\t\tENTER DATE : ";
            //if(j==49){espeaker("ENTER DATE");}
            cin>>d.dd>>slash>>d.mm>>slash>>d.yy;
            cout<<"                 "<<left<<setw(25)<<"NAME"<<setw(25)<<"ROLL NO."<<setw(25)<<"CONTACT"<<setw(25)<<"BOOKNAME"<<setw(25)<<"BOOKID"<<"ISSUE DATE"<<endl<<endl;
            student s1;int count=0;
            ifstream fin("Studentdata.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(s1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&s1,sizeof(s1));
        if(d.dd==s1.d.dd && d.mm==s1.d.mm && d.yy==s1.d.yy)
        {
            ++count;
            s1.display();
        }
    }
    cout<<"\n\n\t\t\t\t\t\t\t\t\t"<<count<<" RESULTS FOUND.\n\n";
    if(j==49){conversion(count);}
    //if(j==49){espeaker("RESULTS FOUND");}
    fin.close();
    cout<<"\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK\n";
    //if(j==49){espeaker("PRESS ENTER TO GET BACK");}
    getch();
    view_issued_books();
    }

    case 3:{system("cls");
            char name[20];
            cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t  ***ALL BOOKS ISSUED BY A PARTICULAR STUDENT***\n\n";
            cout<<"\t\t\t\t\t\t\t\t\tENTER STUDENT NAME : ";
            //if(j==49){espeaker("ENTER STUDENT NAME");}
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin.get(name,20);
            cout<<"                 "<<left<<setw(25)<<"NAME"<<setw(25)<<"ROLL NO."<<setw(25)<<"CONTACT"<<setw(25)<<"BOOKNAME"<<setw(25)<<"BOOKID"<<"ISSUE DATE"<<endl<<endl;
            student s1;int count=0;
            ifstream fin("Studentdata.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(s1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&s1,sizeof(s1));
        if(!strcmp(name,s1.name))
        {
            ++count;
            s1.display();
        }
    }
    cout<<"\n\n\t\t\t\t\t\t\t\t\t"<<count<<" RESULTS FOUND.\n\n";
    if(j==49){conversion(count);}
    //if(j==49){espeaker("RESULTS FOUND");}
    fin.close();
    cout<<"\n\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO GET BACK\n";
    //if(j==49){espeaker("PRESS ENTER TO GET BACK");}
    getch();
    view_issued_books();
    }
   case 0: {ISSUE_BOOK();}
   default:{cout<<"\n\n\t\t\t\t\t\t\t\t\t  ***INVALID ENTRY***\n";
            cout<<"\t\t\t\t\t\t\t\t\t  ***PRESS ENTER TO CONTINUE***";
            //if(j==49){espeaker("INVALID ENTRY PRESS ENTER TO CONTINUE");}
            getch();
            view_issued_books();}
}
}

void change_password()
{
   system("cls");
   char password[50],password1[50],ch;
   int i=0;
   cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER NEW PASSWORD : ";
   //if(j==49){espeaker("ENTER NEW PASSWORD");};
    for(;;)
    {
        ch=getch();
        if(ch==13)
        {
            password[i]='\0';
            break;
        }
        else if(ch==8 && i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
            password[i]=ch;
            cout<<"*";
            i++;
        }
    }
    i=0;
   cout<<"\n\n\t\t\t\t\t\t\t\t\tCONFIRM PASSWORD : ";
   //if(j==49){espeaker("CONFIRM PASSWORD");};
   for(;;)
    {
        ch=getch();
        if(ch==13)
        {
            password1[i]='\0';
            break;
        }
        else if(ch==8 && i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
            password1[i]=ch;
            cout<<"*";
            i++;
        }
    }
   if(strcmp(password,password1))
   {
       cout<<"\n\n\t\t\t\t\t\t\t\t\t\t ***INVALID PASSWORD ENTRY***\n";
       //if(j==49){espeaker("INVALID PASSWORD ENTRY");};
   }
   else
   {
       ofstream fout("Password.txt");
       fout<<password;
       fout.close();
       cout<<"\n\n\t\t\t\t\t\t\t\t\t ***PASSWORD SUCCESSFULLY CHANGED***\n";
       //if(j==49){espeaker("PASSWORD SUCCESSFULLY CHANGED");};
   }
   cout<<"\n\t\t\t\t\t\t\t\t\t ***PRESS ENTER TO GET BACK***\n";
   //if(j==49){espeaker("PRESS ENTER TO GET BACK");};
   getch();
   librarian();
}

void ebooks()
{
    system("cls");
    char name[50];
    int bookid,k=0;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tEnter Name of Book : ";
    //if(j==49){espeaker("Enter Name of Book");}
    cin.get(name,50);
    cout<<"\n\n\t\t\t\t\t\t\t\t\tEnter Book ID : ";
    //if(j==49){espeaker("Enter Book ID ");}
    cin>>bookid;
    book b1;
    ifstream fin("Bookdata.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(b1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&b1,sizeof(b1));
        if(!(strcmp(name,b1.name)) && (bookid==b1.bookid))
        {
            k=1;
            if(b1.link=="None")
            {
                cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***LINK DOESN'T EXIST.***\n";
                //if(j==49){espeaker("LINK DOESN'T EXIST");}
            }
            else
            {
                char *c;
                c=b1.link;
                string t=c;
                cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***Press Enter To get link of book.***\n";
                //if(j==49){espeaker("Press Enter To get link of book");}
                getch();
                system(std::string("start "+ t).c_str());//system(std::string("start " + t).c_str());
            }
            break;
        }
    }
    if(k==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***BOOK NOT FOUND.***\n";
        //if(j==49){espeaker(" BOOK NOT FOUND");}
    }
    fin.close();
    getch();
    cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***PRESS ENTER TO GET BACK***\n";
    //if(j==49){espeaker(" PRESS ENTER TO GET BACK");}
    getch();
    main();
}

void login()
{
    system("cls");
    char s[50];
    int i=0;
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER PASSWORD : ";
    //if(j==49){espeaker(" Enter  PASSWORD :");}
    char s1[50];char ch;

    for(;;)
    {
        ch=getch();
        if(ch==13)
        {
            s1[i]='\0';
            break;
        }
        else if(ch==8 && i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
            s1[i]=ch;
            cout<<"*";
            i++;
        }
    }

    ifstream fin("Password.txt");
    fin.get(s,50);
    fin.close();

    if (!(strcmp(s,s1)))
    {
       librarian();
    }
    else
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t\tPASSWORD DOESN'T MATCH.";
        cout<<"\n\t\t\t\t\t\t\t\t\tPRESS ENTER TO CONTINUE.";
        //if(j==49){espeaker("PASSWORD DOESN'T MATCH   PRESS ENTER TO CONTINUE");}
        getch();
        main();
    }
}

void librarian()
{
    system("cls");
    int n;
    cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t         LIBRARIAN\n\n\n\t\t\t\t\t\t\t\t\t S.No.   Options\n\n";//if(j==49){espeaker("Options");}
    cout<<"\t\t\t\t\t\t\t\t\t [1]     ADD BOOKS\n";//if(j==49){espeaker(" PRESS 1 TO ADD BOOKS");}
    cout<<"\t\t\t\t\t\t\t\t\t [2]     DELETE BOOKS\n";//if(j==49){espeaker(" PRESS 2 TO DELETE BOOKS");}
    cout<<"\t\t\t\t\t\t\t\t\t [3]     ADD/MODIFY LINK\n";//if(j==49){espeaker(" PRESS 3 TO ADD or MODIFY LINK");}
    cout<<"\t\t\t\t\t\t\t\t\t [4]     ISSUE BOOK\n";//if(j==49){espeaker(" PRESS 4 TO ISSUE BOOK");}
    cout<<"\t\t\t\t\t\t\t\t\t [5]     RETURN BOOK\n";//if(j==49){espeaker(" PRESS 5 TO RETURN BOOK ");}
    cout<<"\t\t\t\t\t\t\t\t\t [6]     FINE DEFAULTER LIST\n";//if(j==49){espeaker(" PRESS 6 TO VIEW FINE DEFAULTER LIST");}
    cout<<"\t\t\t\t\t\t\t\t\t [7]     CHANGE PASSWORD\n";//if(j==49){espeaker(" PRESS 7 TO CHANGE PASSWORD");}
    cout<<"\t\t\t\t\t\t\t\t\t [0]     RETURN TO MAIN MENU\n\n";//if(j==49){espeaker(" PRESS 0 TO  RETURN TO MAIN MENU");}
    cout<<"\t\t\t\t\t\t\t\t\t Your Choice : ";
    //if(j==49){espeaker(" Your Choice");}
    cin>>n;
    if(j==49){conversion(n);}
    switch(n)
    {
        case 1:add_book();
        break;
        case 2:delete_();
        break;
        case 3:add_modify_link();
        break;
        case 4:ISSUE_BOOK();
        break;
        case 5:return_book();
        break;
        case 6:finelist();
        break;
        case 7:change_password();
        break;
        case 0:main();
        default:
       {cout<<"\t\t\t\t\t\t\t\t\t**INVALID ENTRY**\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t**PRESS ENTER TO CONTINUE**";
        //if(j==49){espeaker(" INVALID ENTRY  PRESS ENTER TO CONTINUE");}
        getch();
        librarian();
       }
    }
}

void return_book()
{
   system("cls");
   char name[20];
   char book_name[50];
   int roll_no,bookid;
   student s1;
   book b1;
   cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tENTER NAME OF STUDENT : ";
   //if(j==49){espeaker(" ENTER NAME OF STUDENT ");}
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
   cin.get(name,20);
   cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER STUDENT ROLL NO. : ";
   //if(j==49){espeaker(" ENTER STUDENT ROLL NO. ");}
   cin>>roll_no;
   cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER BOOK NAME : ";
   //if(j==49){espeaker("ENTER BOOK NAME ");}
   cin.ignore(numeric_limits<streamsize>::max(),'\n');
   cin.get(book_name,50);
   cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER BOOKID : ";
   //if(j==49){espeaker(" ENTER BOOKID");}
   cin>>bookid;
   ifstream fin("Studentdata.txt");
   ofstream fout("Temporarystudent.txt");
   fin.seekg(0,ios::end);
   int n=fin.tellg()/sizeof(s1),k=0;
   fin.seekg(0,ios::beg);
   for(int i=0;i<n;i++)
   {
       fin.read((char *)&s1,sizeof(s1));
       if(!strcmp(name,s1.name) && (roll_no==s1.roll_no) && (bookid==s1.bookid) && !strcmp(book_name,s1.book_name))
       {
           k=1;
           s1.fine=fine(s1.d);
           if(s1.fine==0)
           {
                cout<<"\n\n\t\t\t\t\t\t\t\t\tNO FINE :)";
                //if(j==49){espeaker(" NO FINE");}
           }
           else
           {
                cout<<"\n\n\t\t\t\t\t\t\t\t\tYour total fine is "<<s1.fine<<" Rs.\n";
                //if(j==49){espeaker(" Your total fine is ");}
                if(j==49){conversion(s1.fine);}
                //if(j==49){espeaker("  Rs");}
           }
           cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***PRESS ENTER TO RETURN BOOK.***\n";
           //if(j==49){espeaker(" PRESS ENTER TO RETURN BOOK  ");}
           getch();
           cout<<"\n\t\t\t\t\t\t\t\t\t   ***RETURED SUCCESSFULLY.***\n";
           //if(j==49){espeaker(" RETURED SUCCESSFULLY  ");}
       }
       else
       {
           fout.write((char *)&s1,sizeof(s1));
       }
   }
   fin.close();
   fout.close();
   if(k==0)
   {
       cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***INVALID ISSUE DETAILS.***\n";
       cout<<"\n\t\t\t\t\t\t\t\t\t    ***PRESS ENTER TO GET BACK.***\n";
       //if(j==49){espeaker(" INVALID ISSUE DETAILS PRESS ENTER TO GET BACK  ");}
       getch();
       librarian();
   }

   ifstream fin2("Temporarystudent.txt");
   ofstream fout2("Studentdata.txt");
   fin2.seekg(0,ios::end);
   n=fin2.tellg()/sizeof(s1);
   fin2.seekg(0,ios::beg);
   for(int i=0;i<n;i++)
   {
       fin2.read((char *)&s1,sizeof(s1));
       fout2.write((char *)&s1,sizeof(s1));
   }
   fin2.close();
   fout2.close();
   ifstream fin1("Bookdata.txt");
   ofstream fout1("Temporary.txt");
   fin1.seekg(0,ios::end);
   n=fin1.tellg()/sizeof(b1);
   fin1.seekg(0,ios::beg);
   for(int i=0;i<n;i++)
   {
       fin1.read((char *)&b1,sizeof(b1));
       if(!(strcmp(b1.name,book_name)) && bookid==b1.bookid)
       {
           ++b1.copies;
           fout1.write((char *)&b1,sizeof(b1));
       }
       else
       {
           fout1.write((char *)&b1,sizeof(b1));
       }
   }
   fin1.close();
   fout1.close();
   ofstream fout3("Bookdata.txt");
   ifstream fin3("Temporary.txt");
   fin3.seekg(0,ios::end);
   n=fin3.tellg()/sizeof(b1);
   fin3.seekg(0,ios::beg);
   for(int i=0;i<n;i++)
   {
       fin3.read((char *)&b1,sizeof(b1));
       fout3.write((char *)&b1,sizeof(b1));
   }
   fin3.close();
   fout3.close();
   cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***PRESS ENTER TO GET BACK.***\n";
   //if(j==49){espeaker(" PRESS ENTER TO GET BACK  ");}
   getch();
   librarian();
}

void view_booklist()
{
    system("cls");
    ios_base::fmtflags flags = cout.flags();
    cout<<"\n\n\t\t\t\t\t\t\t\t\t***BOOKLIST***\n\n\n";
    cout<<left<<setw(25)<<"BOOKID"<<setw(42)<<"   BOOKNAME"<<setw(35)<<"   AUTHOR"<<setw(40)<<"   PUBLISHER"<<setw(24)<<"COST"<<setw(25)<<"COPIES"<<endl<<endl;
    book b1;
    ifstream fin;
    fin.open("Bookdata.txt");
    fin.seekg(0,ios::end);
    int n;
    n=fin.tellg()/sizeof(b1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&b1,sizeof(b1));
        b1.display();
    }
    fin.close();
    cout<<"\n\n\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK***";
    //if(j==49){espeaker(" PRESS ENTER TO GET BACK  ");}
    getch();
}

void search_book()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t S.No.  Options\n\n";//if(j==49){espeaker(" Options  ");}
    cout<<"\t\t\t\t\t\t\t\t\t [1]  SEARCH ANY BOOK\n";//if(j==49){espeaker(" press 1 to  Search ANY BOOK ");}
    cout<<"\t\t\t\t\t\t\t\t\t [2]  SORT BY AUTHOR\n";//if(j==49){espeaker(" press 2 to SORT BY AUTHOR ");}
    cout<<"\t\t\t\t\t\t\t\t\t [3]  SORT BY PUBLICATION\n";//if(j==49){espeaker(" press 3 to  SORT BY PUBLICATION ");}
    cout<<"\n\n\t\t\t\t\t\t\t\t\t Your Choice : ";
    //if(j==49){espeaker("Your Choice");}
    int n;
    cin>>n;
    //if(j==49){conversion(n);}
    switch(n)
    {
        case 1:{
                 system("cls");
                 char name[50];
                 int bookid;
                 int k=0;
                 book b1;
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER NAME OF BOOK : ";
                 //if(j==49){espeaker(" ENTER NAME OF BOOK  ");}
                 cin.get(name,50);
                 cout<<"\t\t\t\t\t\t\t\t\tENTER BOOKID : ";
                 //if(j==49){espeaker("ENTER BOOKID   ");}
                 cin>>bookid;
                 cin.clear();
                 ifstream fin("Bookdata.txt");
                 fin.seekg(0,ios::end);
                 int n=fin.tellg()/sizeof(b1);
                 fin.seekg(0,ios::beg);
                 for(int i=0;i<n;i++)
                         {
                                 fin.read((char *)&b1,sizeof(b1));
                                 if(!(strcmp(b1.name,name)) && bookid==b1.bookid)
                                 {
                                     k=1;
                                     ios_base::fmtflags flags = cout.flags();
                                     cout<<"\n"<<left<<setw(25)<<"BOOKID"<<setw(42)<<"   BOOKNAME"<<setw(35)<<"   AUTHOR"<<setw(40)<<"   PUBLISHER"<<setw(24)<<"COST"<<setw(25)<<"COPIES"<<endl<<endl;
                                     b1.display();
                                     char *c;
                                     c=b1.link;
                                     string t=c;
                                     cout<<"\n\n\t\t\t\t\t\t\t\t\tPRESS 1 TO GET LINK    PRESS 0 TO GET BACK\n\t\t\t\t\t\t\t\t\t\t\t   ";
                                     //if(j==49){espeaker("PRESS 1 TO GET LINK    PRESS 0 TO GET BACK");}
                                     int w;
                                     cin>>w;
                                     if(w==1)
                                     {system(std::string("start "+ t).c_str());}
                                     else if(w==0)
                                     {
                                        break;
                                     }
                                     else
                                     {
                                         cout<<"\n\n\t\t\t\t\t\t\t\t\tINVALID ENTRY.";
                                         //if(j==49){espeaker("INVALID ENTRY");}
                                     }
                                 }
                         }
                 if(k==0)
                 {
                     cout<<"\n\n\t\t\t\t\t\t\t\t\tBOOK NOT FOUND.";
                     //if(j==49){espeaker(" BOOK NOT FOUND  ");}
                 }
                 fin.close();
                 getch();
                 cout<<"\n\n\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK***";
                 //if(j==49){espeaker(" PRESS ENTER TO GET BACK  ");}
                 getch();
                 break;
                }

          case 2:{
                    system("cls");
                    int count=0;
                    char author[50];
                    book b1;
                    cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER AUTHOR NAME : ";
                    //if(j==49){espeaker("ENTER AUTHOR NAME");}
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin.get(author,50);
                    ifstream fin("Bookdata.txt");
                    fin.seekg(0,ios::end);
                    int n=fin.tellg()/sizeof(b1);
                    fin.seekg(0,ios::beg);
                    cout<<"\n\n"<<left<<setw(25)<<"BOOKID"<<setw(42)<<"   BOOKNAME"<<setw(35)<<"   AUTHOR"<<setw(40)<<"   PUBLISHER"<<setw(24)<<"COST"<<setw(25)<<"COPIES"<<endl;
                    for(int i=0;i<n;i++)
                    {
                        fin.read((char *)&b1,sizeof(b1));
                        if(!strcmp(author,b1.author))
                        {
                            ++count;
                            b1.display();
                        }
                    }
                    if(count==1)
                    {cout<<"\n\n\t\t\t\t\t\t\t\t\t"<<count<<" RESULT FOUND.\n\n";}
                    //if(j==49){conversion(count);espeaker("RESULT FOUND");}}
                    else
                    {cout<<"\n\n\t\t\t\t\t\t\t\t\t"<<count<<" RESULTS FOUND.\n\n";}
                    //if(j==49){conversion(count);espeaker("RESULTS FOUND");}}
                    fin.close();
                    cout<<"\n\n\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK***";
                    //if(j==49){espeaker("PRESS ENTER TO GET BACK");}
                    getch();
                    break;
                }
        case 3:{
                    system("cls");
                    int count=0;
                    char publication[50];
                    book b1;
                    cout<<"\n\n\t\t\t\t\t\t\t\t\tENTER PUBLISHER : ";
                    //if(j==49){espeaker(" ENTER PUBLISHER   ");}
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cin.get(publication,50);
                    ifstream fin("Bookdata.txt");
                    fin.seekg(0,ios::end);
                    int n=fin.tellg()/sizeof(b1);
                    fin.seekg(0,ios::beg);
                    cout<<"\n\n"<<left<<setw(25)<<"BOOKID"<<setw(42)<<"   BOOKNAME"<<setw(35)<<"   AUTHOR"<<setw(40)<<"   PUBLISHER"<<setw(24)<<"COST"<<setw(25)<<"COPIES"<<endl;
                    for(int i=0;i<n;i++)
                    {
                        fin.read((char *)&b1,sizeof(b1));
                        if(!strcmp(publication,b1.publication))
                        {
                            ++count;
                            b1.display();
                        }
                    }
                    if(count==1)
                    {cout<<"\n\n\t\t\t\t\t\t\t\t\t"<<count<<" RESULT FOUND.\n\n";}
                    //if(j==49){conversion(count);espeaker("RESULT FOUND");}}
                    else
                    {cout<<"\n\n\t\t\t\t\t\t\t\t\t"<<count<<" RESULTS FOUND.\n\n";}
                    //if(j==49){conversion(count);espeaker("RESULTS FOUND");}}
                    fin.close();
                    cout<<"\n\n\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK***";
                    //if(j==49){espeaker("PRESS ENTER TO GET BACK");}
                    getch();break;
                 }
    default:{
             cout<<"\t\t\t\t\t\t\t\t\t\tINVALID ENTRY\n\n";
             cout<<"\n\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK***";
             //if(j==49){espeaker("INVALID ENTRY PRESS ENTER TO GET BACK  ");}
             getch();
             search_book();
            }
}
}

void add_new_book()
{
    system("cls");
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t    ***ADD NEW BOOK***\n\n\n";
    book b1;
    b1.input();
    ofstream fout;
    fout.open("Bookdata.txt",ios::app);
    fout.write((char *)&b1,sizeof(b1));
    fout.close();
    cout<<"\n\n\t\t\t\t\t\t\t\t\t    ***BOOK ADDED SUCCESSFULLY***";
    cout<<"\n\n\t\t\t\t\t\t\t\t\t    ***PRESS ENTER TO GET BACK***";
    //if(j==49){espeaker("BOOK ADDED SUCCESSFULLY        PRESS ENTER TO GET BACK ");}
    getch();
    add_book();
}

void add_copy()
{
    system("cls");
    cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t    ***ADD COPY/s OF BOOK***\n\n\n";
    char name[50];
    int k=0,c;
    book b1;
    cout<<"\t\t\t\t\t\t\t\t\tENTER NAME OF BOOK : ";
    //if(j==49){espeaker("ENTER NAME OF BOOK ");}
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(name,50);
    cout<<"\n\n\t\t\t\t\t\t\t\t\tHOW MANY COPIES TO BE ADDED: ";
    //if(j==49){espeaker("HOW MANY COPIES TO BE ADDED");}
    cin>>c;
    ifstream fin("Bookdata.txt");
    ofstream fout("Temporary.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(b1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&b1,sizeof(b1));
        if(strcmp(b1.name,name))
        {
            fout.write((char *)&b1,sizeof(b1));
        }
        else
        {
            k=1;
            b1.copies+=c;
            fout.write((char *)&b1,sizeof(b1));
        }
    }
    fin.close();
    fout.close();
    if(k==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***BOOK NOT FOUND***.";
        cout<<"\n\t\t\t\t\t\t\t\t\t   ***PRESS ENTER TO GET BACK***";
        //if(j==49){espeaker("BOOK NOT FOUND PRESS ENTER TO GET BACK");}
        getch();
        add_book();
    }
    ofstream fout1("Bookdata.txt");
    ifstream fin1("Temporary.txt");
    fin1.seekg(0,ios::end);
    n=fin1.tellg()/sizeof(b1);
    fin1.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin1.read((char *)&b1,sizeof(b1));
        fout1.write((char *)&b1,sizeof(b1));
    }
    fin1.close();
    fout1.close();
    if(c==1){cout<<"\n\n\t\t\t\t\t\t\t\t\t***COPY ADDED SUCCESSFULLY***\n\n.";
    cout<<"\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK***";}
    //if(j==49){espeaker("COPY ADDED SUCCESSFULLY    PRESS ENTER TO GET BACK");}}
    else{cout<<"\n\n\t\t\t\t\t\t\t\t\t***COPIES ADDED SUCCESSFULLY***\n\n.";
    cout<<"\t\t\t\t\t\t\t\t\t***PRESS ENTER TO GET BACK***";}
    //if(j==49){espeaker("COPIES ADDED SUCCESSFULLY    PRESS ENTER TO GET BACK");}}
    getch();
    add_book();
}

void add_book()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    ***ADD BOOKS***\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t S.No.  Options\n\n";//if(j==49){espeaker("ADD BOOKS Options ");}
    cout<<"\t\t\t\t\t\t\t\t\t [1]     ADD NEW BOOK\n";//if(j==49){espeaker("press 1 to Add New Book"); }
    cout<<"\t\t\t\t\t\t\t\t\t [2]     ADD COPY/s OF BOOK\n";//if(j==49){espeaker("press 2 to ADD COPIES OF A BOOK"); }
    cout<<"\t\t\t\t\t\t\t\t\t [3]     VIEW BOOK COLLECTION\n";//if(j==49){espeaker("press 3 to VIEW BOOK COLLECTION"); }
    cout<<"\t\t\t\t\t\t\t\t\t [0]     BACK\n\n";//if(j==49){espeaker("press 0 to get BACK"); }
    cout<<"\t\t\t\t\t\t\t\t\t Your Choice : ";
    //if(j==49){espeaker(" Your Choice"); }
    int n;
    cin>>n;
    if(j==49){conversion(n);}
    switch(n)
    {
        case 1:add_new_book();
        break;
        case 2:add_copy();
        break;
        case 3:Books(1);
        break;
        case 0:librarian();
        break;
        default:{
                cout<<"\n\t\t\t\t\t\t\t\t\t    ***INVALID ENTRY***\n\n";
                cout<<"\t\t\t\t\t\t\t\t\t   ***PRESS ENTER TO GET BACK***";
                //if(j==49){espeaker("INVALID ENTRY PRESS ENTER TO GET BACK "); }
                getch();
                add_book();
                }
    }

}

void delete_()
{
   system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    ***DELETE BOOKS***\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t S.No.  Options\n\n";//if(j==49){espeaker("DELETE BOOKS OPTIONS");}
    cout<<"\t\t\t\t\t\t\t\t\t [1]     DELETE ANY BOOK\n";//if(j==49){espeaker("press 1 to DELETE ANY BOOK");}
    cout<<"\t\t\t\t\t\t\t\t\t [2]     DELETE COPY/s OF A BOOK\n";//if(j==49){espeaker("press 2 to DELETE COPIES OF A BOOK"); }
    cout<<"\t\t\t\t\t\t\t\t\t [3]     VIEW BOOK COLLECTION\n";//if(j==49){espeaker("press 3 to VIEW BOOK COLLECTION"); }
    cout<<"\t\t\t\t\t\t\t\t\t [0]     BACK\n\n";//if(j==49){espeaker("press 0 to go back"); }
    cout<<"\t\t\t\t\t\t\t\t\t Your Choice : ";
    //if(j==49){espeaker("Your Choice");}
    int n;
    cin>>n;
    //if(j==49){conversion(n);}
    switch(n)
    {
        case 1:delete_book();
        break;
        case 2:delete_copy();
        break;
        case 3:Books(2);
        break;
        case 0:librarian();
        default:cout<<"\n\n\t\t\t\t\t\t\t\t\t    ***INVALID ENTRY***\n\n";
                //if(j==49){espeaker("INVALID ENTRY");}
    }
    cout<<"\t\t\t\t\t\t\t\t\t   ***PRESS ENTER TO GET BACK***";
    //if(j==49){espeaker("PRESS ENTER TO GET BACK ");}
    getch();
    delete_();
}

void delete_book()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    ***DELETE BOOKS***\n\n\n";
    char name[50];
    int k=0;
    book b1;
    cout<<"\t\t\t\t\t\t\t\tENTER NAME OF BOOK YOU WANT TO DELETE : ";
    //if(j==49){espeaker("ENTER NAME OF BOOK YOU WANT TO DELETE ");}
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(name,50);
    ifstream fin("Bookdata.txt");
    ofstream fout("Temporary.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(b1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&b1,sizeof(b1));
         if(strcmp(b1.name,name))
        {
            fout.write((char *)&b1,sizeof(b1));
        }
        else
        {
            k=1;
        }
    }
    fin.close();
    fout.close();
    if(k==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***BOOK NOT FOUND.***\n";
        cout<<"\t\t\t\t\t\t\t\t\t ***PRESS ENTER TO GET BACK***";
        //if(j==49){espeaker("BOOK NOT FOUND.   PRESS ENTER TO GET BACK");}
        getch();
        Books(2);
    }
    ifstream fin1("Temporary.txt");
    ofstream fout1("Bookdata.txt");
    fin1.seekg(0,ios::end);
    n=fin1.tellg()/sizeof(b1);
    fin1.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin1.read((char *)&b1,sizeof(b1));
        fout1.write((char *)&b1,sizeof(b1));
    }
    fin1.close();
    fout1.close();
    cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***DELETION SUCCESSFUL.***\n";
    cout<<"\t\t\t\t\t\t\t\t\t    ***PRESS ENTER TO GET BACK***";
    //if(j==49){espeaker("DELETION SUCCESSFUL PRESS ENTER TO GET BACK  ");}
    getch();
    delete_();
}

void delete_copy()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t    ***DELETE COPY/s OF BOOK***\n\n\n";
    char name[50];
    int k=0,c;
    book b1;
    cout<<"\t\t\t\t\t\t\t\t\tENTER NAME OF BOOK : ";
    //if(j==49){espeaker("ENTER NAME OF BOOK  ");}
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(name,50);
    cout<<"\n\n\t\t\t\t\t\t\t\t\tHOW MANY COPIES TO BE DELETED : ";
    //if(j==49){espeaker("HOW MANY COPIES TO BE DELETED  ");}
    cin>>c;
    ifstream fin("Bookdata.txt");
    ofstream fout("Temporary.txt");
    fin.seekg(0,ios::end);
    int n=fin.tellg()/sizeof(b1);
    fin.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin.read((char *)&b1,sizeof(b1));
        if(strcmp(b1.name,name))
        {
            fout.write((char *)&b1,sizeof(b1));
        }
        else
        {
            k=1;
            b1.copies-=c;
            fout.write((char *)&b1,sizeof(b1));
        }
    }
    fin.close();
    fout.close();
    if(k==0)
    {
        cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***BOOK NOT FOUND.***";
        cout<<"\n\t\t\t\t\t\t\t\t\t  ***PRESS ENTER TO GET BACK***";
        //if(j==49){espeaker("BOOK NOT FOUND. PRESS ENTER TO GET BACK ");}
        getch();
        delete_();
    }
    ofstream fout1("Bookdata.txt");
    ifstream fin1("Temporary.txt");
    fin1.seekg(0,ios::end);
    n=fin1.tellg()/sizeof(b1);
    fin1.seekg(0,ios::beg);
    for(int i=0;i<n;i++)
    {
        fin1.read((char *)&b1,sizeof(b1));
        fout1.write((char *)&b1,sizeof(b1));
    }
    fin1.close();
    fout1.close();
    if(c==1)
    {cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***COPY DELETED SUCCESSFULLY***\n.";}
    else
    {cout<<"\n\n\t\t\t\t\t\t\t\t\t   ***COPIES DELETED SUCCESSFULLY***\n.";}
    cout<<"\t\t\t\t\t\t\t\t\t    ***PRESS ENTER TO GET BACK***";
    /*if(c==1)
    {
        //if(j==49){espeaker("COPY DELETED SUCCESSFULLY  PRESS ENTER TO GET BACK");}
    }
    else
    {
        //if(j==49){espeaker("COPIES DELETED SUCCESSFULLY  PRESS ENTER TO GET BACK");}
    }*/
    getch();
    delete_();
}

void Books(int x)
{
    int n;
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t***BOOK COLLECTION***\n\n\n\t\t\t\t\t\t\t\t\t S.No.   OPTIONS\n\n";//if(j==49){espeaker("OPTIONS");}
    cout<<"\t\t\t\t\t\t\t\t\t [1]     VIEW BOOKLIST\n";//if(j==49){espeaker("press 1 to view booklist");}
    cout<<"\t\t\t\t\t\t\t\t\t [2]     SEARCH BOOK(GET BOOKLINK)\n";//if(j==49){espeaker("press 2  to  Search Book or GET BOOKLINK");}
    if(x==0)
    {cout<<"\t\t\t\t\t\t\t\t\t [0]     RETURN TO MAIN MENU\n\n";}//if(j==49){espeaker(" press 0 to    Return To Main Menu");}}
    else
    {cout<<"\t\t\t\t\t\t\t\t\t [0]     BACK\n\n";}//if(j==49){espeaker("PRESS 0 TO GET BACK");}}
    cout<<"\t\t\t\t\t\t\t\t\t YOUR CHOICE : ";
    //if(j==49){espeaker("Your Choice ");}
   cin>>n;
   if(j==49){conversion(n);}
   switch(n)
   {
       case 1:{
               view_booklist();
               break;
              }
       case 2:{
               search_book();
               break;
              }
       case 0:{
               if(x==0)
               {main();}
               else if(x==1)
               {add_book();}
               else if(x==2)
               {delete_();}
               break;
              }
       default:{
               cout<<"\n\t\t\t\t\t\t\t\t\t\t**INVALID ENTRY**\n\n";
               cout<<"\t\t\t\t\t\t\t\t\t   **PRESS ENTER TO CONTINUE**";
               //if(j==49){espeaker("INVALID ENTRY  PRESS ENTER TO CONTINUE");}
               getch();
               }
    }
    Books(x);
}
