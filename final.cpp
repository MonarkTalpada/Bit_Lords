#include<iostream>
#include <ctime>
#include<string>
#include<string.h>

using namespace std;

class calendar
{
public:
    int year,month,day,v;

    void displayCalendar(int year, int month)
    {
            // Array to store the number of days in each month
            int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            // Check if it's a leap year (February has 29 days)
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
            daysInMonth[1] = 29;
            }
            // Calculate the day of the week for the first day of the month
        struct tm timeinfo = {0};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = 1;
        mktime(&timeinfo);
        int dayOfWeek = timeinfo.tm_wday;

        // Print the calendar header
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

        // Print the calendar
        int dayOfMonth = 1;
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    if (i == 0 && j < dayOfWeek)
                        {
                        // Print empty space for days before the first of the month
                        cout << "     ";
                        } else if (dayOfMonth > daysInMonth[month - 1])
                        {
                            // Print empty space for days after the last day of the month
                            cout << "     ";
                        } else
                        {
                        // Print the day of the month
                        printf("%5d", dayOfMonth);
                        dayOfMonth++;
                        }
                }
                cout << endl;
            }
    }//it was a method for a particular month of year

int dayNumber(int day, int month, int year)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    v= (year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
    return v;
}

string getMonthName(int monthNumber)
{
    string months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
                      };

    return (months[monthNumber]);
}

int numberOfDays (int monthNumber, int year)
{
    // January,March,May, July , August,October,December
    if (monthNumber == 0 || monthNumber == 2 || monthNumber == 4||monthNumber == 6||monthNumber == 7||monthNumber == 9||monthNumber == 11)
        return (31);

    // February
    if (monthNumber == 1)
    {
        // If the year is leap then February has
        // 29 days
        if (year % 400 == 0 ||
                (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }
    //April,June,September,November
    if (monthNumber == 3||monthNumber == 5||monthNumber == 8||monthNumber == 10)
        return (30);
}

void printCalendar(int year)
{
    printf ("         Calendar - %d\n", year);
    int days;

    // Index of the day from 0 to 6
    int current = dayNumber (1, 1, year);

    // i --> Iterate through all the months
    // j --> Iterate through all the days of the
    //       month - i
    for (int i = 0; i < 12; i++)
    {
        days = numberOfDays (i, year);

        // Print the current month name
        printf("\n  ------------%s-------------\n",
               getMonthName (i).c_str());

        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++k > 6)
            {
                k = 0;
                printf("\n");
            }
        }

        if (k)
            printf("\n");

        current = k;
    }

    return;
}
};
int main()
{
    calendar c1;
    register char choice;
    int year,month,v,date,g;
    label1:

    cout<<"------------------------------------------------"<<endl;
    cout<<"1.Calendar of a year"<<endl;
    cout<<"2.Particular month of a year"<<endl;
    cout<<"3.Day of week"<<endl;
    cout<<"------------------------------------------------"<<endl<<endl;
    cout<<"Enter what you want to do (1-3) : ";
    cin>>g;
    cout<<endl;
    system("cls");
    if(g>=1 && g<=3)
    {
    switch(g)
    {
    case 1:
        cout<<"Enter the year ( 1900 - 2100 ) : ";
        cin>>year;
        if(year<1900 || year>2100)
        {
            system("cls");
            cout<<"the return 3 statement shows that you have enter an invalid year"<<endl;
            return(3);
        }

        cout<<endl<<endl;
        system("cls");
        c1.printCalendar(year);
        break;
    case 2:
        cout << "Enter year (1900 - 2100) : ";
        cin >> year;
         if(year<1900 || year>2100)
        {
            system("cls");
            cout<<"the return 3 statement shows that you have enter an invalid year"<<endl;
            return(3);
        }
        system("cls");
        label:
        cout << "Enter month (1-12): ";
        cin >> month;
        cout<<endl<<endl;
        system("cls");
        if(month>=1 && month<=12)
        {
        // Display the calendar for the given year and month
        c1.displayCalendar(year, month);
        }
        else
        {
            cout<<"the return 2 statement shows that you have enter an invalid month"<<endl;
            return(2);
            goto label;
        }
        break;
    case 3:
        cout <<endl<< "Enter year ( 1900 - 2100 ) : ";
        cin >> year;
         if(year<1900 || year>2100)
        {
            system("cls");
            cout<<"the return 3 statement shows that you have enter an invalid year"<<endl;
            return(3);
        }

        system("cls");

        cout<< "Enter month (1-12): ";
        cin >> month;
        if(month<1 || month>12)
        {
            cout<<"the return 2 statement shows that you have enter an invalid month"<<endl;
            return(2);
        }
        if(year%4==0)
            {
                if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
                {
                    label2:
                    cout<<"enter date (1-31) : ";
                    cin>>date;
                    cout<<endl;
                    if(date<1 || date>31)
                    {
                        cout<<endl<<"Invalid"<<endl;
                        goto label2;
                    }
                }
                 if(month==2)
                {
                    label3:
                    cout<<"enter date (1-29) : ";
                    cin>>date;
                    cout<<endl;
                    if(date<1 || date>29)
                    {
                        cout<<endl<<"Invalid"<<endl;
                        goto label3;
                    }
                }
                 if(month==4||month==6||month==9||month==11)
                {
                    label4:
                    cout<<"enter date (1-30) : ";
                    cin>>date;
                    cout<<endl;
                    if(date<1 || date>30)
                    {
                        cout<<endl<<"Invalid"<<endl;
                        goto label4;
                    }
                }
            }
            else
            {
                if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
                {
                    label5:
                    cout<<"enter date (1-31) : ";
                    cin>>date;
                    cout<<endl;
                    if(date<1 || date>31)
                    {
                        cout<<endl<<"Invalid"<<endl;
                        goto label5;
                    }
                }
                 if(month==2)
                {
                    label6:
                    cout<<"enter date (1-28) : ";
                    cin>>date;
                    cout<<endl;
                    if(date<1 || date>28)
                    {
                        cout<<endl<<"Invalid"<<endl;
                        goto label6;
                    }
                }
                 if(month==4||month==6||month==9||month==11)
                {
                    label7:
                    cout<<"enter date (1-30) : ";
                    cin>>date;
                    cout<<endl;
                    if(date<1 || date>30)
                    {
                        cout<<endl<<"Invalid"<<endl;
                        goto label7;
                    }
                }
            }

            int i=c1.dayNumber(date,month,year);
            string arr[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
            cout<<"-----------------------------------------------------"<<endl<<endl;
            cout<<date<<"/"<<month<<"/"<<year<<endl;
            cout<<"The day is "<<arr[i]<<endl<<endl;
            cout<<"-----------------------------------------------------"<<endl<<endl;
        }
    }
    else
    {
         cout<<"the return 1 statement shows that you have enter an invalid case selected"<<endl;
         return(1);
    }
    cout<<endl<<endl<<"DO YOU WANT TO TRY OTHER FUNCTION (Y/N) : ";
    cin>>choice;
    cout<<endl<<endl;
     if(choice=='Y'||choice=='y')
    {
        system("cls");
        goto label1;
    }
    else
    {
        system("cls");
        cout<<endl<<endl;
        cout<<" ****************** thank you ******************"<<endl<<endl;
    }
    return 0;
}
