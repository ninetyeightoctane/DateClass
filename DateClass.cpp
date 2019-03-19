#include<iostream>
#include<string.h>

using namespace std;

class MyDate{
    int dt, month, year;
public:

    MyDate(){
        dt = month = year = 0;
    }



    void operator ++ (){

        if(dt == 31 && month == 12){
            dt = 1; month = 1; year++;
        }
        else{
            if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && dt == 31){
                dt = 1; month++;
            }
            else if((month == 4 || month == 6 || month == 9 || month == 11) && dt == 30){
                dt = 1; month++;
            }
            else if(month == 2 && dt == 28){
                dt = 1; month++;
            }
            else
                dt++;
        }
    }



    void operator ++ (int){

        if(dt == 31 && month == 12){
            dt = 1; month = 1; year++;
        }
        else{
            if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && dt == 31){
                dt = 1; month++;
            }
            else if((month == 4 || month == 6 || month == 9 || month == 11) && dt == 30){
                dt = 1; month++;
            }
            else if(month == 2 && dt == 28){
                dt = 1; month++;
            }
            else
                dt++;
        }
    }



    void operator -- (){
        if(dt == 1 && month == 1){
            dt = 31; month = 12; year--;
        }
        else{
            if((month == 2 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && dt == 1){
                dt = 30; month--;
            }
            else if((month == 4 || month == 6 || month == 9 || month == 11) && dt == 1){
                dt = 31; month--;
            }
            else if(month == 3 && dt == 1){
                dt = 29; month--;
            }
            else
                dt--;
        }
    }



    void operator -- (int){
        if(dt == 1 && month == 1){
            dt = 31; month = 12; year--;
        }
        else{
            if((month == 2 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && dt == 1){
                dt = 30; month--;
            }
            else if((month == 4 || month == 6 || month == 9 || month == 11) && dt == 1){
                dt = 31; month--;
            }
            else if(month == 3 && dt == 1){
                dt = 29; month--;
            }
            else
                dt--;
        }
    }



    int operator - (MyDate dd){
        return dt - dd.dt;
    }



    friend ostream & operator << (ostream &out, MyDate &m){
        string ss;
        switch(m.month){
            case 1:
                ss = "January";
                break;
            case 2:
                ss = "February";
                break;
            case 3:
                ss = "March";
                break;
            case 4:
                ss = "April";
                break;
            case 5:
                ss = "May";
                break;
            case 6:
                ss = "June";
                break;
            case 7:
                ss = "July";
                break;
            case 8:
                ss = "August";
                break;
            case 9:
                ss = "September";
                break;
            case 10:
                ss = "October";
                break;
            case 11:
                ss = "November";
                break;
            case 12:
                ss = "December";
                break;
        }
        out<<ss<<" "<<m.dt<<" "<<m.year;
        return out;
    }



    friend istream & operator >> (istream &in, MyDate &md){

        cout<<"\n Enter Month: ";
        in>>md.month;
        cout<<"\n Enter Date: ";
        in>>md.dt;
        cout<<"\n Enter Year: ";
        in>>md.year;

        if(md.month >= 1 && md.month <= 12){
            if(md.dt >= 1 && md.dt <= 31){
                return in;
            }
            else
                cout<<"\n Invalid Date: ";
        }
        else
            cout<<"\n Invalid Month: ";
    }
};



int main(){
    MyDate st, en;
    cout<<"\n Enter Date: ";
    cin>>st;
    cout<<"\n\n Date: ";
    cout<<st;

    --st;
    cout<<"\n After Prefix Decrement: ";
    cout<<st;

    st--;
    cout<<"\n After Postfix Decrement: ";
    cout<<st;

    ++st;
    cout<<"\n After Prefix Increment: ";
    cout<<st;

    st++;
    cout<<"\n After Postfix Increment: ";
    cout<<st;

    cout<<"\n Enter the Ending Date: ";
    cin>>en;

    cout<<"\n\n Starting Date: ";
    cout<<st;
    cout<<"\n Ending Date: ";
    cout<<en;
    cout<<"\n\n After Subtraction: ";
    cout<<en - st;
}