#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

int num = 0;
int bus_price;
int hotel_price;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void text(char t[])
{
    int i;
    for(i=0; t[i]!='\0'; i++)
    {
    cout <<t[i];
    Sleep(50);
    }
    cout << endl;
}

int int_only()
{
    int num=0;
    int ch;
    for(;;)
    {
        ch = getch();
        if(ch >= 48 && ch <= 57)
        {
            cout << char(ch);
            num=num*10+(ch-48);
        }
        if(ch==13)
        {
            break;
        }
        if(ch==8)
        {
            stringstream a;
            a << num;

            string str_num = a.str();

            if(str_num.length()>0)
            {
                cout<<"\b \b";
                str_num.erase(str_num.length()-1);
            }
        }
    }
    return num;
}

void software_chasers();
void admin_panel();
void default_screen();
void ex();

void set_bus_price(int x)
{
    bus_price = x;
}

int get_bus_price()
{
    return bus_price;
}

void set_hotel_price(int x)
{
    hotel_price = x;
}

int get_hotel_price()
{
    return hotel_price;
}

class file
{
    public:
        void file_system_add(string a)
        {
            ofstream file("Database.txt", ios :: app);
            file << a << "    ";
        }
        void file_system_next()
        {
            ofstream file("Database.txt", ios :: app);
            file << endl;
        }
};

class conclude
{
    public:
        int stay;
        void dates()
        {
            int d;
            int a;
            system("cls");
            file f;
            default_screen();
            gotoxy(42, 10);
            text("~~~ Timetable ~~~");
            gotoxy(40, 12);
            text("Departure:   /04/2020");
            gotoxy(51, 12);
            d = int_only();            gotoxy(40, 13);
            text("Arrival  :   /04/2020");
            gotoxy(51, 13);
            a = int_only();

            if(0 < a && a > 31)
            {
                gotoxy(44, 15);
                text("Invalid date");
                getch();
                dates();
            }
            else if(0 < d && d > 31)
            {
                gotoxy(44, 15);
                text("Invalid date");
                getch();
                dates();
            }
            else if(d > a)
            {
                gotoxy(44, 15);
                text("Invalid date");
                getch();
                dates();
            }
            else if(d == a)
            {
                gotoxy(44, 15);
                text("Invalid date");
                getch();
                dates();
            }

            stay = a-d;

            gotoxy(36, 15);
            cout << "You will be staying for " << stay << " days";

            stringstream ss;
            ss << stay;

            string str_stay = ss.str();

            f.file_system_add(str_stay);

            getch();

            done();
        }

        void done()
        {
            system("cls");
            file f;
            default_screen();
            gotoxy(43, 9);
            text("CONGRATULATION");
            gotoxy(43, 10);
            text("--------------");
            gotoxy(38, 12);
            text("Your tour has been booked");
            gotoxy(35, 14);
            cout << "The tour cost will be: " << get_bus_price() + (get_hotel_price() * stay) << " Taka";

            stringstream ss;
            ss << get_bus_price() + (get_hotel_price() * stay);

            string str_taka = ss.str();

            f.file_system_add(str_taka);

            f.file_system_next();

            gotoxy(38, 16);
            text("Press any key to Exit..");
            gotoxy(61, 16);
            getch();
            ex();
        }
};

class forest_sundarban
{
    public:
        void sundarban_bus()
        {
            system("cls");
            file f;

            default_screen();
            gotoxy(33, 9);
            text("|| DHAKA - SUNDARBAN BUS SERVICE ||");
            gotoxy(37, 11);
            text("(1) Hanif      : 600  TAKA");
            gotoxy(37, 12);
            text("(2) Shyamol    : 1000 TAKA");
            gotoxy(37, 13);
            text("(3) Green Line : 1650 TAKA");
            gotoxy(41, 15);
            text("Choose an option: ");
            gotoxy(59, 15);
            num = int_only();

            switch(num)
            {
            case 1:
                f.file_system_add("Hanif");
                set_bus_price(600);
                sundarban_hotel();
                break;
            case 2:
                f.file_system_add("Shyamol");
                set_bus_price(1000);
                sundarban_hotel();
                break;
            case 3:
                f.file_system_add("Green_Line");
                set_bus_price(1650);
                sundarban_hotel();
                break;
            default:
                gotoxy(44, 17);
                text("Invalid Input");
                gotoxy(57, 17);
                getch();
                system("cls");
                sundarban_bus();
            }
        }

        void sundarban_hotel()
        {
            system("cls");
            conclude c;
            file f;

            default_screen();

            gotoxy(36, 9);
            text("|| SUNDARBAN HOTEL SERVICE ||");
            gotoxy(34, 11);
            text("(1) Ruma Resort      : 2750 TAKA");
            gotoxy(34, 12);
            text("(2) Sundarban Motel  : 3500 TAKA");
            gotoxy(34, 13);
            text("(3) Forest View      : 4300 TAKA");
            gotoxy(41, 15);
            text("Choose an option: ");
            gotoxy(59, 15);
            num = int_only();

            switch(num)
            {
            case 1:
                f.file_system_add("Ruma_Resort");
                set_hotel_price(2750);
                c.dates();
                break;
            case 2:
                f.file_system_add("Sundarban_Motel");
                set_hotel_price(3500);
                c.dates();
                break;
            case 3:
                f.file_system_add("Forest_View");
                set_hotel_price(4300);
                c.dates();
                break;
            default:
                gotoxy(44, 17);
                text("Invalid Input");
                gotoxy(57, 17);
                getch();
                system("cls");
                sundarban_hotel();
            }
        }
};

class forest_ratargul
{
public:
    void ratargul_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(34, 9);
        text("|| DHAKA - RATARGUL BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Hanif      : 600  TAKA");
        gotoxy(37, 12);
        text("(2) Shyamol    : 1000 TAKA");
        gotoxy(37, 13);
        text("(3) Ena        : 1650 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Hanif");
            set_bus_price(600);
            ratargul_hotel();
            break;
        case 2:
            f.file_system_add("Shyamol");
            set_bus_price(1000);
            ratargul_hotel();
            break;
        case 3:
            f.file_system_add("Ena");
            set_bus_price(1650);
            ratargul_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            ratargul_bus();
        }
    }

    void ratargul_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(36, 9);
        text("|| RATARGUL HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Ratargul Resort  : 2800 TAKA");
        gotoxy(34, 12);
        text("(2) Nirvana Inn      : 3200 TAKA");
        gotoxy(34, 13);
        text("(3) Rose View Hotel  : 4500 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Ratargul_Resort");
            set_hotel_price(2800);
            c.dates();
            break;
        case 2:
            f.file_system_add("Nirvana_Inn");
            set_hotel_price(3200);
            c.dates();
            break;
        case 3:
            f.file_system_add("Rose_View_Hotel");
            set_hotel_price(4500);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            ratargul_hotel();
        }
    }
};

class forest_rema
{
public:
    void rema_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(35, 9);
        text("|| DHAKA - REMA BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Hanif      : 600  TAKA");
        gotoxy(37, 12);
        text("(2) Shyamol    : 1000 TAKA");
        gotoxy(37, 13);
        text("(3) Green Line : 1650 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Hanif");
            set_bus_price(600);
            rema_hotel();
            break;
        case 2:
            f.file_system_add("Shyamol");
            set_bus_price(1000);
            rema_hotel();
            break;
        case 3:
            f.file_system_add("Green_Line");
            set_bus_price(1650);
            rema_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            rema_bus();
        }
    }

    void rema_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(39, 9);
        text("|| REMA HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Shantibari Resort : 2750 TAKA");
        gotoxy(34, 12);
        text("(2) Novem Eco Resort  : 3500 TAKA");
        gotoxy(34, 13);
        text("(3) Grand Resort      : 4300 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Shantibari_Resort");
            set_hotel_price(2750);
            c.dates();
            break;
        case 2:
            f.file_system_add("Novem_Eco_Resort");
            set_hotel_price(3500);
            c.dates();
            break;
        case 3:
            f.file_system_add("Grand_Resort");
            set_hotel_price(4300);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            rema_hotel();
        }
    }
};

class hill_bandarban
{
public:
    void bandarban_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 10);
        text("~~~ Packages ~~~");
        gotoxy(34, 12);
        text("(1) Nilgiri - Nilachal - Chimbuk");
        gotoxy(34, 13);
        text("(2) Roma - Bogalake - Keokradong");
        gotoxy(40, 15);
        text("Choose your package: ");
        gotoxy(61, 15);
        num = int_only();

        switch (num)
        {
        case 1:
            bandarban_bus();
            break;
        case 2:
            bandarban_bus();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            bandarban_package();
        }
    }

    void bandarban_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(33, 9);
        text("|| DHAKA - BANDARBAN BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Shyamoli   : 600  TAKA");
        gotoxy(37, 12);
        text("(2) St. Martin : 1100 TAKA");
        gotoxy(37, 13);
        text("(3) Green Line : 1650 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Shyamoli");
            set_bus_price(600);
            bandarban_hotel();
            break;
        case 2:
            f.file_system_add("St.Martin");
            set_bus_price(1100);
            bandarban_hotel();
            break;
        case 3:
            f.file_system_add("Green_Line");
            set_bus_price(1650);
            bandarban_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            bandarban_bus();
        }
    }

    void bandarban_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(36, 9);
        text("|| BANDARBAN HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Hotel Hill View    : 1650 TAKA");
        gotoxy(34, 12);
        text("(2) Fanush Resort      : 2300 TAKA");
        gotoxy(34, 13);
        text("(3) Holiday Resort     : 3500 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Hotel_Hill_View");
            set_hotel_price(1650);
            c.dates();
            break;
        case 2:
            f.file_system_add("Fanush_Resort");
            set_hotel_price(2300);
            c.dates();
            break;
        case 3:
            f.file_system_add("Holiday_Resort");
            set_hotel_price(3500);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            bandarban_hotel();
        }
    }
};

class hill_rangamati
{
public:
    void rangamati_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 10);
        text("~~~ Packages ~~~");
        gotoxy(34, 12);
        text("(1) Shajek Valley - Konglak Para");
        gotoxy(34, 13);
        text("(2) Kaptai Lake - Hanging Bridge");
        gotoxy(40, 15);
        text("Choose your package: ");
        gotoxy(61, 15);
        num = int_only();

        switch (num)
        {
        case 1:
            rangamati_bus();
            break;
        case 2:
            rangamati_bus();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            rangamati_package();
        }
    }

    void rangamati_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(33, 9);
        text("|| DHAKA - RANGAMATI BUS SERVICE ||");
        gotoxy(39, 11);
        text("(1) Eagle  : 550  TAKA");
        gotoxy(39, 12);
        text("(2) Shanti : 950 TAKA");
        gotoxy(39, 13);
        text("(3) Hanif  : 1450 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Eagle");
            set_bus_price(550);
            rangamati_hotel();
            break;
        case 2:
            f.file_system_add("Shanti");
            set_bus_price(950);
            rangamati_hotel();
            break;
        case 3:
            f.file_system_add("Hanif");
            set_bus_price(1450);
            rangamati_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            rangamati_bus();
        }
    }

    void rangamati_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(36, 9);
        text("|| RANGAMARI HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Nibas Hotel        : 1650 TAKA");
        gotoxy(34, 12);
        text("(2) Hill Taj Resort    : 2300 TAKA");
        gotoxy(34, 13);
        text("(3) Grand Crown Hotel  : 3500 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Nibas_Hotel");
            set_hotel_price(1650);
            c.dates();
            break;
        case 2:
            f.file_system_add("Hill_Taj_Resort");
            set_hotel_price(2300);
            c.dates();
            break;
        case 3:
            f.file_system_add("Grand_Crown_Hotel");
            set_hotel_price(3500);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            rangamati_hotel();
        }
    }
};

class hill_coxsBazar
{
public:
    void coxsBazar_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 10);
        text("~~~ Packages ~~~");
        gotoxy(36, 12);
        text("(1) Himchari - Sharna Mandir");
        gotoxy(40, 14);
        text("Choose your package: ");
        gotoxy(61, 14);
        num = int_only();

        switch (num)
        {
        case 1:
            coxsBazar_bus();
            break;
        default:
            gotoxy(44, 16);
            text("Invalid Input");
            gotoxy(57, 16);
            getch();
            system("cls");
            coxsBazar_package();
        }
    }

    void coxsBazar_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(32, 9);
        text("|| DHAKA - COX'S BAZAR BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Unique     : 600  TAKA");
        gotoxy(37, 12);
        text("(2) Soudia     : 950  TAKA");
        gotoxy(37, 13);
        text("(3) Green Line : 1650 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Unique");
            set_bus_price(600);
            coxsBazar_hotel();
            break;
        case 2:
            f.file_system_add("Soudia");
            set_bus_price(950);
            coxsBazar_hotel();
            break;
        case 3:
            f.file_system_add("Green_Line");
            set_bus_price(1650);
            coxsBazar_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            coxsBazar_bus();
        }
    }

    void coxsBazar_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(35, 9);
        text("|| COX's BAZAR HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Hotel Seashore     : 1650 TAKA");
        gotoxy(34, 12);
        text("(2) Ocean Palace       : 2450 TAKA");
        gotoxy(34, 13);
        text("(3) Hotel CoxToday     : 3700 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Hotel_Seashore");
            set_hotel_price(1650);
            c.dates();
            break;
        case 2:
            f.file_system_add("Ocean_Palace");
            set_hotel_price(2450);
            c.dates();
            break;
        case 3:
            f.file_system_add("Hotel_CoxToday");
            set_hotel_price(3700);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            coxsBazar_hotel();
        }
    }
};

class hill_sylhet
{
public:
    void sylhet_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 10);
        text("~~~ Packages ~~~");
        gotoxy(37, 12);
        text("(1) Ratargul - Jaflong");
        gotoxy(37, 13);
        text("(2) Sreemangal - Bisanakandi");
        gotoxy(40, 15);
        text("Choose your package: ");
        gotoxy(61, 15);
        num = int_only();

        switch (num)
        {
        case 1:
            sylhet_bus();
            break;
        case 2:
            sylhet_bus();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            sylhet_package();
        }
    }

    void sylhet_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(34, 9);
        text("|| DHAKA - SYLHET BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Shyamoli   : 600  TAKA");
        gotoxy(37, 12);
        text("(2) Hanif      : 1000 TAKA");
        gotoxy(37, 13);
        text("(3) Green Line : 1650 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Shyamoli");
            set_bus_price(600);
            sylhet_hotel();
            break;
        case 2:
            f.file_system_add("Hanif");
            set_bus_price(1000);
            sylhet_hotel();
            break;
        case 3:
            f.file_system_add("Green_Line");
            set_bus_price(1650);
            sylhet_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            sylhet_bus();
        }
    }

    void sylhet_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(37, 9);
        text("|| SYLHET HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Farmis Garden      : 1550 TAKA");
        gotoxy(34, 12);
        text("(2) Noorjahan Hotel    : 2800 TAKA");
        gotoxy(34, 13);
        text("(3) Grand Sultan       : 5000 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Farmis_Garden");
            set_hotel_price(1550);
            c.dates();
            break;
        case 2:
            f.file_system_add("Noorjahan_Hotel");
            set_hotel_price(2800);
            c.dates();
            break;
        case 3:
            f.file_system_add("Grand_Sultan");
            set_hotel_price(5000);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            sylhet_hotel();
        }
    }
};

class sea_coxsBazar
{
public:
    void coxsBazar_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 10);
        text("~~~ Packages ~~~");
        gotoxy(41, 12);
        text("(1) Inani - Laboni");
        gotoxy(41, 13);
        text("(2) Saint Martin");
        gotoxy(40, 15);
        text("Choose your package: ");
        gotoxy(61, 15);
        num = int_only();

        switch (num)
        {
        case 1:
            coxsBazar_bus();
            break;
        case 2:
            coxsBazar_bus();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            coxsBazar_package();
        }
    }

    void coxsBazar_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(32, 9);
        text("|| DHAKA - COX'S BAZAR BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Eagle      : 550  TAKA");
        gotoxy(37, 12);
        text("(2) Echono     : 1000 TAKA");
        gotoxy(37, 13);
        text("(3) Green Line : 1650 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Eagle");
            set_bus_price(550);
            coxsBazar_hotel();
            break;
        case 2:
            f.file_system_add("Echono");
            set_bus_price(1000);
            coxsBazar_hotel();
            break;
        case 3:
            f.file_system_add("Green_Line");
            set_bus_price(1650);
            coxsBazar_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            coxsBazar_bus();
        }
    }

    void coxsBazar_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(35, 9);
        text("|| COX's BAZAR HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Inani Resort       : 2200 TAKA");
        gotoxy(34, 12);
        text("(2) Orchid Blue        : 3100 TAKA");
        gotoxy(34, 13);
        text("(3) Hotel South        : 4050 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Inani_Resort");
            set_hotel_price(2200);
            c.dates();
            break;
        case 2:
            f.file_system_add("Orchid_Blue");
            set_hotel_price(3100);
            c.dates();
            break;
        case 3:
            f.file_system_add("Hotel_South");
            set_hotel_price(4050);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            coxsBazar_hotel();
        }
    }
};

class sea_kuakata
{
public:
    void kuakata_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(34, 9);
        text("|| DHAKA - KUAKATA BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Tubaline   : 600  TAKA");
        gotoxy(37, 12);
        text("(2) Ena        : 950 TAKA");
        gotoxy(37, 13);
        text("(3) Green Line : 1550 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Tubaline");
            set_bus_price(600);
            kuakata_hotel();
            break;
        case 2:
            f.file_system_add("Ena");
            set_bus_price(950);
            kuakata_hotel();
            break;
        case 3:
            f.file_system_add("Green_Line");
            set_bus_price(1550);
            kuakata_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            kuakata_bus();
        }
    }

    void kuakata_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(37, 9);
        text("|| KUAKATA HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Long Beach Hotel   : 2800 TAKA");
        gotoxy(34, 12);
        text("(2) Hotel Golden Hill  : 3300 TAKA");
        gotoxy(34, 13);
        text("(3) Laguna Resort      : 4500 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Long_Beach_Hotel");
            set_hotel_price(2800);
            c.dates();
            break;
        case 2:
            f.file_system_add("Hotel_Golden_Hill");
            set_hotel_price(3300);
            c.dates();
            break;
        case 3:
            f.file_system_add("Laguna_Resort");
            set_hotel_price(4500);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            kuakata_hotel();
        }
    }
};

class sea_patenga
{
public:
    void patenga_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(34, 9);
        text("|| DHAKA - PATENGA BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Hanif      : 650  TAKA");
        gotoxy(37, 12);
        text("(2) Shyamol    : 1200 TAKA");
        gotoxy(37, 13);
        text("(3) Green Line : 1550 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Hanif");
            set_bus_price(650);
            patenga_hotel();
            break;
        case 2:
            f.file_system_add("Shyamol");
            set_bus_price(1200);
            patenga_hotel();
            break;
        case 3:
            f.file_system_add("Green_Line");
            set_bus_price(1550);
            patenga_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            patenga_bus();
        }
    }

    void patenga_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(37, 9);
        text("|| PATENGA HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Hotel Miskha      : 2750 TAKA");
        gotoxy(34, 12);
        text("(2) Sikder Resort     : 3500 TAKA");
        gotoxy(34, 13);
        text("(3) Abakash Parjatan  : 4300 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Hotel_Miskha");
            set_hotel_price(2750);
            c.dates();
            break;
        case 2:
            f.file_system_add("Sikder_Resort");
            set_hotel_price(3500);
            c.dates();
            break;
        case 3:
            f.file_system_add("Abakash_Parjatan");
            set_hotel_price(4300);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            patenga_hotel();
        }
    }
};

class his_narayanganj
{
public:
    void narayanganj_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 9);
        text("~~~ Packages ~~~");
        gotoxy(43, 11);
        text("(1) Sonargaon");
        gotoxy(43, 12);
        text("(2) Zinda Park");
        gotoxy(43, 13);
        text("(3) Taj Mahal");
        gotoxy(40, 15);
        text("Choose your package: ");
        gotoxy(61, 15);
        num = int_only();

        switch (num)
        {
        case 1:
            narayanganj_bus();
            break;
        case 2:
            narayanganj_bus();
            break;
        case 3:
            narayanganj_bus();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            narayanganj_package();
        }
    }

    void narayanganj_bus()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(32, 9);
        text("|| DHAKA - NARAYANGANJ BUS SERVICE ||");
        gotoxy(40, 11);
        text("(1) Sheetal : 50 TAKA");
        gotoxy(40, 12);
        text("(2) BRTC    : 40 TAKA");
        gotoxy(41, 14);
        text("Choose an option: ");
        gotoxy(59, 14);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Sheetal");
            f.file_system_add("N/A");
            f.file_system_add("N/A");
            set_bus_price(50);
            c.done();
            break;
        case 2:
            f.file_system_add("BRTC");
            f.file_system_add("N/A");
            f.file_system_add("N/A");
            set_bus_price(40);
            c.done();
            break;
        default:
            gotoxy(44, 16);
            text("Invalid Input");
            gotoxy(57, 16);
            getch();
            system("cls");
            narayanganj_bus();
        }
    }
};

class his_bagherhat
{
public:
    void bagherhat_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 8);
        text("~~~ Packages ~~~");
        gotoxy(48, 10);
        text("(1)");
        gotoxy(40, 12);
        text("Shaat Gombuj Masjid &");
        gotoxy(42, 13);
        text("Bagherhat Museum &");
        gotoxy(36, 14);
        text("Hazrat Khan Jahan Ali's Tomb");
        gotoxy(40, 16);
        text("Choose your package: ");
        gotoxy(61, 16);
        num = int_only();

        switch (num)
        {
        case 1:
            bagherhat_bus();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            bagherhat_package();
        }
    }

    void bagherhat_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(33, 9);
        text("|| DHAKA - BAGHERHAT BUS SERVICE ||");
        gotoxy(38, 11);
        text("(1) Shohag    : 550  TAKA");
        gotoxy(38, 12);
        text("(2) Sundarban : 950  TAKA");
        gotoxy(38, 13);
        text("(3) Polash    : 1000 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Shohag");
            set_bus_price(550);
            bagherhat_hotel();
            break;
        case 2:
            f.file_system_add("Sundarban");
            set_bus_price(950);
            bagherhat_hotel();
            break;
        case 3:
            f.file_system_add("Polash");
            set_bus_price(1000);
            bagherhat_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            bagherhat_bus();
        }
    }

    void bagherhat_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(36, 9);
        text("|| BAGHERHAT HOTEL SERVICE ||");
        gotoxy(34, 11);
        text("(1) Hotel Momtaj      : 1600 TAKA");
        gotoxy(34, 12);
        text("(2) Cinderella Resort : 3350 TAKA");
        gotoxy(34, 13);
        text("(3) Circuit Hotel     : 4300 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Hotel_Momtaj");
            set_hotel_price(1600);
            c.dates();
            break;
        case 2:
            f.file_system_add("Cinderella_Resort");
            set_hotel_price(3350);
            c.dates();
            break;
        case 3:
            f.file_system_add("Circuit_Hotel");
            set_hotel_price(4300);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            bagherhat_hotel();
        }
    }
};

class his_nagoan
{
public:
    void nagoan_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 8);
        text("~~~ Packages ~~~");
        gotoxy(34, 10);
        text("(1) Gandhi Asrom - Balihar Rajbari");
        gotoxy(41, 11);
        text("- Sampura Mahavihara");
        gotoxy(34, 13);
        text("(2) Kusumba Mosque - Dibar Dighi");
        gotoxy(41, 14);
        text("- Dubolhati Rajbari");
        gotoxy(40, 16);
        text("Choose your package: ");
        gotoxy(61, 16);
        num = int_only();

        switch (num)
        {
        case 1:
            nagoan_bus();
            break;
        case 2:
            nagoan_bus();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            nagoan_package();
        }
    }

    void nagoan_bus()
    {
        system("cls");
        file f;
        default_screen();
        gotoxy(34, 9);
        text("|| DHAKA - NAGOAN BUS SERVICE ||");
        gotoxy(37, 11);
        text("(1) Dipjol      : 550 TAKA");
        gotoxy(37, 12);
        text("(2) S.R Travels : 850 TAKA");
        gotoxy(37, 13);
        text("(3) Akota       : 950 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Dipjol");
            set_bus_price(550);
            nagoan_hotel();
            break;
        case 2:
            f.file_system_add("S.R_Travels");
            set_bus_price(850);
            nagoan_hotel();
            break;
        case 3:
            f.file_system_add("Akota");
            set_bus_price(950);
            nagoan_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            nagoan_bus();
        }
    }

    void nagoan_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(37, 9);
        text("|| NAGOAN HOTEL SERVICE ||");
        gotoxy(36, 11);
        text("(1) Hotel Minarva : 2250 TAKA");
        gotoxy(36, 12);
        text("(2) Mollika inn   : 2500 TAKA");
        gotoxy(36, 13);
        text("(3) Hotel Abokash : 2650 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("Hotel_Minarva");
            set_hotel_price(2250);
            c.dates();
            break;
        case 2:
            f.file_system_add("Mollika_inn");
            set_hotel_price(2500);
            c.dates();
            break;
        case 3:
            f.file_system_add("Hotel_Abokash");
            set_hotel_price(2650);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            nagoan_hotel();
        }
    }
};

class his_dhaka
{
public:
    void dhaka_package()
    {
        system("cls");
        default_screen();
        gotoxy(42, 8);
        text("~~~ Packages ~~~");
        gotoxy(34, 10);
        text("(1) Lalbagh Fort - Shaheed Minar");
        gotoxy(40, 11);
        text("- Ahasan Manzil Museum");
        gotoxy(34, 13);
        text("(2) Armenian Church - LalKuthi");
        gotoxy(42, 14);
        text("- National Museum");
        gotoxy(40, 16);
        text("Choose your package: ");
        gotoxy(61, 16);
        num = int_only();

        switch (num)
        {
        case 1:
            dhaka_hotel();
            break;
        case 2:
            dhaka_hotel();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            dhaka_package();
        }
    }

    void dhaka_hotel()
    {
        system("cls");

        conclude c;
        file f;
        default_screen();
        gotoxy(38, 9);
        text("|| DHAKA HOTEL SERVICE ||");
        gotoxy(36, 11);
        text("(1) Hotel Plaza   : 4550 TAKA");
        gotoxy(36, 12);
        text("(2) The Olives    : 5000 TAKA");
        gotoxy(36, 13);
        text("(3) Asia Hotel    : 7250 TAKA");
        gotoxy(41, 15);
        text("Choose an option: ");
        gotoxy(59, 15);
        num = int_only();

        switch(num)
        {
        case 1:
            f.file_system_add("N/A");
            f.file_system_add("Hotel_Plaza");
            set_hotel_price(4550);
            c.dates();
            break;
        case 2:
            f.file_system_add("N/A");
            f.file_system_add("The_Olives");
            set_hotel_price(5000);
            c.dates();
            break;
        case 3:
            f.file_system_add("N/A");
            f.file_system_add("Asia_Hotel");
            set_hotel_price(7250);
            c.dates();
            break;
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            dhaka_hotel();
        }
    }
};

void ex()
{
    system("cls");
    system("color a");
    gotoxy(25, 6);
    cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << endl;
    Sleep(50);
    gotoxy(25, 7);
    cout << char(196) << char(218) << char(196) << char(196) << char(196) << char(196) << char(191) << char(218) << char(191) << char(196) << char(218) << char(191) << char(218) << char(196) << char(196) << char(196) << char(191) << char(218) << char(196) << char(191) << char(196) << char(218) << char(191) << char(218) << char(191) << char(218) << char(196) << char(191) << char(196) << char(196) << char(196) << char(196) << char(218) << char(191) << char(196) << char(196) << char(218) << char(191) << char(218) << char(196) << char(196) << char(196) << char(191) << char(218) << char(191) << char(196) << char(218) << char(191) << char(196) << endl;
    Sleep(50);
    gotoxy(25, 8);    cout << char(196) << char(179) << char(218) << char(191) << char(218) << char(191) << char(179) << char(179) << char(179) << char(196) << char(179) << char(179) << char(179) << char(218) << char(196) << char(191) << char(179) << char(179) << char(179) << char(192) << char(191) << char(179) << char(179) << char(179) << char(179) << char(179) << char(218) << char(217) << char(196) << char(196) << char(196) << char(196) << char(179) << char(192) << char(191) << char(218) << char(217) << char(179) << char(179) << char(218) << char(196) << char(191) << char(179) << char(179) << char(179) << char(196) << char(179) << char(179) << char(196) << endl;
    Sleep(50);
    gotoxy(25, 9);    cout << char(196) << char(192) << char(217) << char(179) << char(179) << char(192) << char(217) << char(179) << char(192) << char(196) << char(217) << char(179) << char(179) << char(179) << char(196) << char(179) << char(179) << char(179) << char(218) << char(191) << char(192) << char(217) << char(179) << char(179) << char(192) << char(217) << char(217) << char(196) << char(196) << char(196) << char(196) << char(196) << char(192) << char(191) << char(192) << char(217) << char(218) << char(217) << char(179) << char(179) << char(196) << char(179) << char(179) << char(179) << char(179) << char(196) << char(179) << char(179) << char(196) << endl;
    Sleep(50);
    gotoxy(25, 10);    cout << char(196) << char(196) << char(196) << char(179) << char(179) << char(196) << char(196) << char(179) << char(218) << char(196) << char(191) << char(179) << char(179) << char(192) << char(196) << char(217) << char(179) << char(179) << char(179) << char(192) << char(191) << char(179) << char(179) << char(179) << char(218) << char(191) << char(179) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(192) << char(191) << char(218) << char(217) << char(196) << char(179) << char(179) << char(196) << char(179) << char(179) << char(179) << char(179) << char(196) << char(179) << char(179) << char(196) << endl;
    Sleep(50);
    gotoxy(25, 11);    cout << char(196) << char(196) << char(218) << char(217) << char(192) << char(191) << char(196) << char(179) << char(179) << char(196) << char(179) << char(179) << char(179) << char(218) << char(196) << char(191) << char(179) << char(179) << char(179) << char(196) << char(179) << char(179) << char(179) << char(179) << char(179) << char(179) << char(192) << char(191) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(179) << char(179) << char(196) << char(196) << char(179) << char(192) << char(196) << char(217) << char(179) << char(179) << char(192) << char(196) << char(217) << char(179) << char(196) << endl;
    Sleep(50);
    gotoxy(25, 12);
    cout << char(196) << char(196) << char(192) << char(196) << char(196) << char(217) << char(196) << char(192) << char(217) << char(196) << char(192) << char(217) << char(192) << char(217) << char(196) << char(192) << char(217) << char(192) << char(217) << char(196) << char(192) << char(196) << char(217) << char(192) << char(217) << char(192) << char(196) << char(217) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(192) << char(217) << char(196) << char(196) << char(192) << char(196) << char(196) << char(196) << char(217) << char(192) << char(196) << char(196) << char(196) << char(217) << char(196) << endl;
    Sleep(50);
    gotoxy(25, 13);
    cout << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << endl;

    system("color c");
    Sleep(100);    system("color d");
    Sleep(100);
    system("color b");
    Sleep(100);    system("color d");
    Sleep(100);
    system("color e");

    gotoxy(31, 16);
    text("@SOFTWARE_CHASERS All Right Reserved");
    gotoxy(67, 16);
    getch();
    cout << endl;
    exit (0);
}

class travel
{
public:
    void destinations();
    void forest();
    void hillSide();
    void seaBeach();
    void historical();
};

class log
{
public:
    void admin()
    {
        string username, password;

        system("cls");

        default_screen();

        int ch;

        gotoxy(39, 10);
        text("~~~ Admin Only Area ~~~");
        gotoxy(40, 12);
        text("Enter username: ");
        gotoxy(56, 12);
        cin >> username;
        gotoxy(40, 13);
        text("Enter password: ");
        gotoxy(56, 13);
        while(ch = getch())
        {
            if(ch == 13)
            {
                if(username == "admin" && password == "1234")
                {
                    gotoxy(42, 15);
                    text("Login Successful");
                    gotoxy(58, 15);
                    getch();
                    admin_panel();
                }
                else
                {
                    gotoxy(42, 15);
                    text("Login Unsuccessful");
                    gotoxy(60, 15);
                    getch();
                    system("cls");
                    showLog();
                }
            }
            else if(ch==8)
            {
                if(password.length()>0)
                {
                    cout<<"\b \b";
                    password.erase(password.length()-1);
                }
            }
            else
            {
                cout<<"*";
                password += ch;
            }
        }
    }
    void addAccount()
    {
        string username, password, filename;

        system("cls");

        default_screen();

        gotoxy(42, 10);
        text("~~~ Register  ~~~");
        gotoxy(37, 12);
        text("Enter your username: ");
        gotoxy(58, 12);
        cin >> username;
        gotoxy(37, 13);
        text("Enter your password: ");
        gotoxy(58, 13);
        cin >> password;

        filename = username + ".txt";

        ofstream file;
        file.open(filename.c_str());
        file << username << endl << password << endl;

        file.close();

        gotoxy(42, 15);
        text("Register Success");
        gotoxy(58, 15);
        getch();
        system("cls");
        showLog();
    }
    void isLog()
    {
        travel destinations;
        string username, password, u, p, filename;
        int ch;
        system("cls");

        default_screen();

        gotoxy(44,10);
        text("~~~ LOGIN ~~~");
        gotoxy(40,12);
        text("Enter username: ");
        gotoxy(56, 12);
        cin >> username;
        gotoxy(40, 13);

        filename = username + ".txt";

        ifstream read(filename.c_str());
        getline(read, u);
        getline(read, p);

        text("Enter password: ");
        gotoxy(56, 13);
        while(ch = getch())
        {
            if(ch == 13)
            {
                if(u == username && p == password)
                {
                    gotoxy(43, 15);
                    text("Login Successful");
                    gotoxy(59, 15);
                    getch();
                    system("cls");
                    destinations.destinations();
                }
                else
                {
                    gotoxy(42, 15);
                    text("Login Unsuccessful");
                    gotoxy(60, 15);
                    getch();
                    system("cls");
                    showLog();
                }
            }
            else if(ch==8)
            {
                if(password.length()>0)
                {
                    cout<<"\b \b";
                    password.erase(password.length()-1);
                }
            }
            else
            {
                cout<<"*";
                password += ch;
            }
        }
    }
    void showLog()
    {
        system("cls");
        default_screen();

        gotoxy(40, 9);
        text("~~~ ACCOUNT PAGE ~~~");
        gotoxy(43, 11);
        text("(1) Login");
        gotoxy(43, 12);
        text("(2) Register");
        gotoxy(43, 13);
        text("(3) Admin Panel");
        gotoxy(43, 14);        text("(4) Exit");
        gotoxy(41, 16);
        text("Choose an option: ");
        gotoxy(59, 16);
        num = int_only();

        switch(num)
        {
        case 1:
            isLog();
            break;
        case 2:
            addAccount();
            break;
        case 3:
            admin();
            break;
        case 4:
            ex();
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            showLog();
        }
    }
};

void travel :: destinations()
{
    travel destinations;
    travel hillSide;
    travel seaBeach;
    travel forest;
    travel historical;

    log login;

    default_screen();
    gotoxy(38, 8);
    text("~~~~~ DESTINATIONS ~~~~~");
    gotoxy(43, 10);
    text("(1) Forest");
    gotoxy(43, 11);
    text("(2) Hill Side");
    gotoxy(43, 12);
    text("(3) Sea Beach");
    gotoxy(43, 13);
    text("(4) Historical");
    gotoxy(43, 14);
    text("(5) Account page");
    gotoxy(43, 15);    text("(6) Exit");
    gotoxy(42, 17);
    text("Choose an option: ");
    gotoxy(60, 17);    num = int_only();
    switch(num)
    {
    case 1:
        system("cls");
        forest.forest();
        break;
    case 2:
        system("cls");
        hillSide.hillSide();
        break;
    case 3:
        system("cls");
        seaBeach.seaBeach();
        break;
    case 4:
        system("cls");
        historical.historical();
        break;
    case 5:
        system("cls");
        login.showLog();
        break;
    case 6:
        ex();
    default:
        gotoxy(44, 18);
        text("Invalid Input");
        gotoxy(57, 18);
        getch();
        system("cls");
        destinations.destinations();
    }
}

void travel :: forest()
{
    travel destinations;
    travel forest;
    forest_sundarban sundar;
    forest_ratargul ratar;
    forest_rema rem;
    file f;

    default_screen();

    gotoxy(40, 8);
    text("~~~~~ FOREST ~~~~~");
    gotoxy(42, 10);
    text("(1) Sundarban");
    gotoxy(42, 11);
    text("(2) Ratargul");
    gotoxy(42, 12);
    text("(3) Rema Kalenga");
    gotoxy(42, 13);
    text("(4) Destinations");
    gotoxy(42, 14);
    text("(5) Exit");
    gotoxy(41, 16);
    text("Choose an option: ");
    gotoxy(59, 16);
    num = int_only();

    switch(num)
    {
        case 1:
            f.file_system_add("Sundarban");
            sundar.sundarban_bus();
            break;
        case 2:
            f.file_system_add("Ratargul");
            ratar.ratargul_bus();
            break;
        case 3:
            f.file_system_add("Rema_Kalenga");
            rem.rema_bus();
            break;
        case 4:
            system("cls");
            destinations.destinations();
            break;
        case 5:
            ex();
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            forest.forest();
    }
}

void travel :: hillSide()
{
    travel destinations;
    travel hillSide;
    hill_bandarban ban;
    hill_rangamati rang;
    hill_coxsBazar cox;
    hill_sylhet syl;
    file f;

    default_screen();

    gotoxy(40, 8);
    text("~~~~~ HILL SIDE ~~~~~");
    gotoxy(42, 10);
    text("(1) Bandarban");
    gotoxy(42, 11);
    text("(2) Rangamati");
    gotoxy(42, 12);
    text("(3) Cox's Bazar");
    gotoxy(42, 13);
    text("(4) Sylhet");
    gotoxy(42, 14);
    text("(5) Destinations");
    gotoxy(42, 15);
    text("(6) Exit");
    gotoxy(41, 17);
    text("Choose an option: ");
    gotoxy(59, 17);
    num = int_only();
    switch(num)
    {
        case 1:
            f.file_system_add("Bandarban");
            ban.bandarban_package();
            break;
        case 2:
            f.file_system_add("Rangamati");
            rang.rangamati_package();
            break;
        case 3:
            f.file_system_add("Cox's_Bazar");
            cox.coxsBazar_package();
            break;
        case 4:
            f.file_system_add("Sylhet");
            syl.sylhet_package();
            break;
        case 5:
            system("cls");
            destinations.destinations();
            break;
        case 6:
            ex();
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            hillSide.hillSide();
    }
}

void travel :: seaBeach()
{
    travel destinations;
    travel seaBeach;
    sea_coxsBazar cox;
    sea_kuakata kua;
    sea_patenga pat;
    file f;

    default_screen();

    gotoxy(40, 8);
    text("~~~~~ SEA BEACH ~~~~~");
    gotoxy(42, 10);
    text("(1) Cox's Bazar");
    gotoxy(42, 11);
    text("(2) Kuakata");
    gotoxy(42, 12);
    text("(3) Patenga");
    gotoxy(42, 13);    text("(4) Destinations");
    gotoxy(42, 14);
    text("(5) Exit");
    gotoxy(41, 16);    text("Choose an option: ");
    gotoxy(59, 16);    num = int_only();
    switch(num)
    {
        case 1:
            f.file_system_add("Cox's_Bazar");
            cox.coxsBazar_package();
            break;
        case 2:
            f.file_system_add("Kuakata");
            kua.kuakata_bus();
            break;
        case 3:
            f.file_system_add("Patenga");
            pat.patenga_bus();
            break;
        case 4:
            system("cls");
            destinations.destinations();
            break;
        case 5:
            ex();
        default:
            gotoxy(44, 17);
            text("Invalid Input");
            gotoxy(57, 17);
            getch();
            system("cls");
            seaBeach.seaBeach();
    }
}

void travel :: historical()
{
    travel destinations;
    travel historical;
    his_narayanganj nar;
    his_bagherhat bag;
    his_nagoan nag;
    his_dhaka dha;
    file f;

    default_screen();

    gotoxy(40, 8);
    text("~~~~~ HISTORICAL ~~~~~");
    gotoxy(42, 10);
    text("(1) Narayanganj");
    gotoxy(42, 11);
    text("(2) Bagherhat");
    gotoxy(42, 12);
    text("(3) Nagoan");
    gotoxy(42, 13);
    text("(4) Dhaka");
    gotoxy(42, 14);
    text("(5) Destinations");
    gotoxy(42, 15);
    text("(6) Exit");
    gotoxy(41, 17);
    text("Choose an option: ");
    gotoxy(59, 17);
    num = int_only();

    switch(num)
    {
        case 1:
            f.file_system_add("Narayanganj");
            nar.narayanganj_package();
            break;
        case 2:
            f.file_system_add("Bagherhat");
            bag.bagherhat_package();
            break;
        case 3:
            f.file_system_add("Nagoan");
            nag.nagoan_package();
            break;
        case 4:
            f.file_system_add("Dhaka");
            dha.dhaka_package();
            break;
        case 5:
            system("cls");
            destinations.destinations();
            break;
        case 6:
            ex();
        default:
            gotoxy(44, 18);
            text("Invalid Input");
            gotoxy(57, 18);
            getch();
            system("cls");
            historical.historical();
    }
}

void software_chasers()
{
    Sleep(100);
    system("color 9");

    cout << endl << endl << endl << endl << endl;

    cout << "\t\t" << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(187) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << endl;
    cout << "\t\t" << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << char(176) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(187) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
    cout << "\t\t" << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(176) << char(176) << char(176) << char(176) << char(219) << char(219) << char(186) << char(176) << char(176) << char(176) << char(176) << char(200) << char(219) << char(219) << char(187) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(188) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(176) << endl;
    cout << "\t\t" << char(176) << char(200) << char(205) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << char(176) << char(176) << char(176) << char(176) << char(176) << char(219) << char(219) << char(186) << char(176) << char(176) << char(176) << char(176) << char(176) << char(219) << char(219) << char(219) << char(219) << char(201) << char(205) << char(219) << char(219) << char(219) << char(219) << char(186) << char(176) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << char(176) << char(176) << endl;
    cout << "\t\t" << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(219) << char(219) << char(186) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(219) << char(219) << char(186) << char(176) << char(176) << char(176) << char(176) << char(176) << char(200) << char(219) << char(219) << char(201) << char(188) << char(176) << char(200) << char(219) << char(219) << char(201) << char(188) << char(176) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << endl;
    cout << "\t\t" << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(176) << char(176) << char(200) << char(205) << char(205) << char(205) << char(205) << char(188) << char(176) << char(200) << char(205) << char(188) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(200) << char(205) << char(188) << char(176) << char(176) << char(176) << char(176) << char(176) << char(176) << char(200) << char(205) << char(188) << char(176) << char(176) << char(176) << char(200) << char(205) << char(188) << char(176) << char(176) << char(200) << char(205) << char(188) << char(176) << char(176) << char(200) << char(205) << char(188) << char(200) << char(205) << char(188) << char(176) << char(176) << char(200) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;

    Sleep(100);    system("color a");
    Sleep(100);    system("color b");
    Sleep(100);    system("color c");
    Sleep(100);
    system("color d");
    Sleep(100);    system("color e");
    Sleep(100);
    system("color 9");

    cout << endl << endl << endl;

    cout << "\t\t\t" << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(187) << char(176) << char(176) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << endl;
    cout << "\t\t\t" << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
    cout << "\t\t\t" << char(219) << char(219) << char(186) << char(176) << char(176) << char(200) << char(205) << char(188) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << char(176) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(176) << endl;
    cout << "\t\t\t" << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(186) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(186) << char(176) << char(200) << char(205) << char(205) << char(205) << char(219) << char(219) << char(187) << char(219) << char(219) << char(201) << char(205) << char(205) << char(188) << char(176) << char(176) << char(219) << char(219) << char(201) << char(205) << char(205) << char(219) << char(219) << char(187) << char(176) << char(200) << char(205) << char(205) << char(205) << char(219) << char(219) << char(187) << endl;
    cout << "\t\t\t" << char(200) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(187) << char(219) << char(219) << char(186) << char(176) << char(176) << char(219) << char(219) << char(186) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(201) << char(188) << endl;
    cout << "\t\t\t" << char(176) << char(200) << char(205) << char(205) << char(205) << char(205) << char(188) << char(176) << char(200) << char(205) << char(188) << char(176) << char(176) << char(200) << char(205) << char(188) << char(200) << char(205) << char(188) << char(176) << char(176) << char(200) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(176) << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(188) << char(176) << char(176) << char(200) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << char(176);

    Sleep(100);    system("color a");
    Sleep(100);    system("color b");
    Sleep(100);    system("color c");
    Sleep(100);
    system("color d");
    Sleep(100);    system("color e");
}

void welcome()
{
    int i, j, k, l;

    system("color b");

    for(i=1; i<=100; i++) ///top
    {
        gotoxy(i, 1);
        cout << "*";
        Sleep(10);
    }

    system("color c");

    for(l=1; l<=24; l++) ///right
    {
        gotoxy(100, l);
        cout << "*";
        Sleep(10);
    }

    system("color a");

    for(k=100; k>=1; k--) ///bottom
    {
        gotoxy(k, 24);
        cout << "*";
        Sleep(10);
    }

    system("color d");

    for(j=24; j>=1; j--) ///left
    {
        gotoxy(1, j);
        cout << "*";
        Sleep(10);
    }

    system("color e");

    gotoxy(36, 4);
    text("WELCOME TO OUR GROUP PROJECT");
    gotoxy(35, 6);
    text("PROJECT TITLE: TRAVELLERS GUIDE");
    gotoxy(36, 8);
    text("GROUP NAME: SOFTWARE CHASERS");
    gotoxy(44, 11);
    text("GROUP MEMBERS");
    gotoxy(44, 12);
    text("-------------");
    gotoxy(20, 14);
    text("ABDULLAH RAYED");
    gotoxy(65, 14);
    text("20-41846-1");
    gotoxy(20, 16);
    text("ABRAR IBNE AHSAN");
    gotoxy(65, 16);
    text("19-41389-3");
    gotoxy(20, 18);
    text("RION UDDIN DIPTO");
    gotoxy(65, 18);
    text("20-41879-1");
    gotoxy(20, 20);
    text("SAFUAN ALAM SAIFEE");
    gotoxy(65, 20);
    text("20-41861-1");
    gotoxy(75, 20);
    getch();
}

void admin_panel()
{
    system("cls");
    int i, j, k, l;

    system("color d");

    for(i=1; i<=100; i++) ///top
    {
        gotoxy(i, 1);
        cout << char(205);
        Sleep(10);
    }

    system("color c");

    for(l=1; l<=25; l++) ///right
    {
        gotoxy(100, l);
        cout << char(186);
        Sleep(10);
    }

    system("color a");

    for(k=100; k>=1; k--) ///bottom
    {
        gotoxy(k, 25);
        cout << char(205);
        Sleep(10);
    }

    system("color b");

    for(j=25; j>=1; j--) ///left
    {
        gotoxy(1, j);
        cout << char(186);
        Sleep(10);
    }

    system("color d");

    for(i=1; i<=100; i++) ///1 H
    {
        gotoxy(i, 5);
        cout << char(205);
        Sleep(10);
    }

    system("color c");

    for(l=1; l<=24; l++) ///1 V
    {
        gotoxy(21, l);
        cout << char(186);
        Sleep(10);
    }

    for(i=1; i<=100; i++) ///2 H
    {
        gotoxy(i, 9);
        cout << char(205);
        Sleep(10);
    }

    system("color a");

    for(l=1; l<=24; l++) ///2 V
    {
        gotoxy(41, l);
        cout << char(186);
        Sleep(10);
    }

    for(i=1; i<=100; i++) ///3 H
    {
        gotoxy(i, 13);
        cout << char(205);
        Sleep(10);
    }

    system("color b");

    for(l=1; l<=24; l++) ///3 V
    {
        gotoxy(61, l);
        cout << char(186);
        Sleep(10);
    }

    for(i=1; i<=100; i++) ///4 H
    {
        gotoxy(i, 17);
        cout << char(205);
        Sleep(10);
    }

    system("color c");

    for(l=1; l<=24; l++) ///4 V
    {
        gotoxy(81, l);
        cout << char(186);
        Sleep(10);
    }

    for(i=1; i<=100; i++) ///5 H
    {
        gotoxy(i, 21);
        cout << char(205);
        Sleep(10);
    }

    system("color e");

    gotoxy(6, 3);
    text("Destination");
    gotoxy(30, 3);
    text("Bus");
    gotoxy(49, 3);
    text("Hotel");
    gotoxy(70, 3);
    text("Stay");
    gotoxy(89, 3);
    text("Cost");

    for(l=6; l<=25; l++) ///right
    {
        gotoxy(5, l);
        cout << char(186);
        Sleep(10);
    }

    gotoxy(3, 7);
    text("1");
    gotoxy(3, 11);
    text("2");
    gotoxy(3, 15);
    text("3");
    gotoxy(3, 19);
    text("4");
    gotoxy(3, 23);
    text("5");

    ifstream file("Database.txt");

    char a[100] = {0}, b[100] = {0}, c[100] = {0}, d[100] = {0}, e[100] = {0};

    file >> a >> b >> c >> d >> e;

    gotoxy(7, 7);
    text(a);
    gotoxy(23, 7);
    text(b);
    gotoxy(43, 7);
    text(c);
    gotoxy(71, 7);
    text(d);
    gotoxy(89, 7);
    text(e);

    char f[100] = {0}, g[100] = {0}, h[100] = {0}, i1[100] = {0}, j1[100] = {0};

    file >> f >> g >> h >> i1 >> j1;

    gotoxy(7, 11);
    text(f);
    gotoxy(23, 11);
    text(g);
    gotoxy(43, 11);
    text(h);
    gotoxy(71, 11);
    text(i1);
    gotoxy(89, 11);
    text(j1);

    char k1[100] = {0}, l1[100] = {0}, m[100] = {0}, n[100] = {0}, o[100] = {0};

    file >> k1 >> l1 >> m >> n >> o;

    gotoxy(7, 15);
    text(k1);
    gotoxy(23, 15);
    text(l1);
    gotoxy(43, 15);
    text(m);
    gotoxy(71, 15);
    text(n);
    gotoxy(89, 15);
    text(o);

    char p[100] = {0}, q[100] = {0}, r[100] = {0}, s[100] = {0}, t[100] = {0};

    file >> p >> q >> r >> s >> t;

    gotoxy(7, 19);
    text(p);
    gotoxy(23, 19);
    text(q);
    gotoxy(43, 19);
    text(r);
    gotoxy(71, 19);
    text(s);
    gotoxy(89, 19);
    text(t);

    char u[100] = {0}, v[100] = {0}, w[100] = {0}, x[100] = {0}, y[100] = {0};

    file >> u >> v >> w >> x >> y;

    gotoxy(7, 23);
    text(u);
    gotoxy(23, 23);
    text(v);
    gotoxy(43, 23);
    text(w);
    gotoxy(71, 23);
    text(x);
    gotoxy(89, 23);
    text(y);

    gotoxy(101, 25);
    getch();
    log login;
    login.showLog();
}

void default_screen()
{
        gotoxy(24, 1);
        cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(187) << char(201) << char(205) << char(205) << char(205) << char(187) << char(201) << char(205) << char(205) << char(205) << char(187) << char(201) << char(187) << char(255) << char(255) << char(201) << char(187) << char(201) << char(205) << char(205) << char(205) << char(187) << char(201) << char(187) << char(255) << char(255) << char(255) << char(201) << char(187) << char(255) << char(255) << char(255) << char(201) << char(205) << char(205) << char(205) << char(187) << char(201) << char(205) << char(205) << char(205) << char(187) << char(201) << char(205) << char(205) << char(205) << char(187) << endl;
        Sleep(50);
        gotoxy(24, 2);
        cout << char(186) << char(201) << char(187) << char(201) << char(187) << char(186) << char(186) << char(201) << char(205) << char(187) << char(186) << char(186) << char(201) << char(205) << char(187) << char(186) << char(186) << char(200) << char(187) << char(201) << char(188) << char(186) << char(186) << char(201) << char(205) << char(205) << char(188) << char(186) << char(186) << char(255) << char(255) << char(255) << char(186) << char(186) << char(255) << char(255) << char(255) << char(186) << char(201) << char(205) << char(205) << char(188) << char(186) << char(201) << char(205) << char(187) << char(186) << char(186) << char(201) << char(205) << char(187) << char(186) << endl;
        Sleep(50);        gotoxy(24, 3);
        cout << char(200) << char(188) << char(186) << char(186) << char(200) << char(188) << char(186) << char(200) << char(205) << char(188) << char(186) << char(186) << char(186) << char(255) << char(186) << char(186) << char(200) << char(187) << char(186) << char(186) << char(201) << char(188) << char(186) << char(200) << char(205) << char(205) << char(187) << char(186) << char(186) << char(255) << char(255) << char(255) << char(186) << char(186) << char(255) << char(255) << char(255) << char(186) << char(200) << char(205) << char(205) << char(187) << char(186) << char(200) << char(205) << char(188) << char(186) << char(186) << char(200) << char(205) << char(205) << char(187) << endl;
        Sleep(50);
        gotoxy(24, 4);
        cout << char(255) << char(255) << char(186) << char(186) << char(255) << char(255) << char(186) << char(201) << char(187) << char(201) << char(188) << char(186) << char(200) << char(205) << char(188) << char(186) << char(255) << char(186) << char(200) << char(188) << char(186) << char(255) << char(186) << char(201) << char(205) << char(205) << char(188) << char(186) << char(186) << char(255) << char(201) << char(187) << char(186) << char(186) << char(255) << char(201) << char(187) << char(186) << char(201) << char(205) << char(205) << char(188) << char(186) << char(201) << char(187) << char(201) << char(188) << char(200) << char(205) << char(205) << char(187) << char(186) << endl;
        Sleep(50);
        gotoxy(24, 5);
        cout << char(255) << char(201) << char(188) << char(200) << char(187) << char(255) << char(186) << char(186) << char(186) << char(200) << char(187) << char(186) << char(201) << char(205) << char(187) << char(186) << char(255) << char(200) << char(187) << char(201) << char(188) << char(255) << char(186) << char(200) << char(205) << char(205) << char(187) << char(186) << char(200) << char(205) << char(188) << char(186) << char(186) << char(200) << char(205) << char(188) << char(186) << char(186) << char(200) << char(205) << char(205) << char(187) << char(186) << char(186) << char(186) << char(200) << char(187) << char(186) << char(200) << char(205) << char(188) << char(186) << endl;
        Sleep(50);
        gotoxy(24, 6);
        cout << char(255) << char(200) << char(205) << char(205) << char(188) << char(255) << char(200) << char(188) << char(200) << char(205) << char(188) << char(200) << char(188) << char(255) << char(200) << char(188) << char(255) << char(255) << char(200) << char(188) << char(255) << char(255) << char(200) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(188) << char(200) << char(188) << char(200) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(188) << endl;
        Sleep(50);


        gotoxy(38, 24);
        cout << char(200) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(188) << char(200) << char(205) << char(205) << char(205) << char(188) << endl;
        Sleep(50);
        gotoxy(38, 23);
        cout << char(186) << char(200) << char(202) << char(205) << char(186) << char(186) << char(200) << char(205) << char(188) << char(186) << char(201) << char(185) << char(204) << char(187) << char(201) << char(188) << char(200) << char(188) << char(186) << char(186) << char(200) << char(205) << char(205) << char(187) << endl;
        Sleep(50);
        gotoxy(38, 22);
        cout << char(186) << char(186) << char(201) << char(205) << char(187) << char(186) << char(186) << char(255) << char(186) << char(186) << char(255) << char(186) << char(186) << char(255) << char(255) << char(186) << char(186) << char(186) << char(186) << char(186) << char(201) << char(205) << char(205) << char(188) << endl;
        Sleep(50);
        gotoxy(38, 21);
        cout << char(186) << char(186) << char(255) << char(200) << char(188) << char(186) << char(186) << char(255) << char(186) << char(186) << char(255) << char(186) << char(186) << char(255) << char(255) << char(186) << char(186) << char(186) << char(186) << char(186) << char(200) << char(205) << char(205) << char(187) << endl;
        Sleep(50);
        gotoxy(38, 20);
        cout << char(186) << char(201) << char(205) << char(187) << char(186) << char(186) << char(186) << char(255) << char(186) << char(186) << char(200) << char(185) << char(204) << char(188) << char(200) << char(187) << char(201) << char(187) << char(186) << char(186) << char(201) << char(205) << char(205) << char(188) << endl;
        Sleep(50);
        gotoxy(38, 19);
        cout << char(201) << char(205) << char(205) << char(205) << char(187) << char(201) << char(187) << char(255) << char(201) << char(187) << char(201) << char(205) << char(205) << char(187) << char(201) << char(205) << char(205) << char(205) << char(187) << char(201) << char(205) << char(205) << char(205) << char(187) << endl;

        int j, l;

        system("color e");

        for(l=7; l<=24; l++) ///right
        {
            gotoxy(70, l);
            cout << "*";
            Sleep(30);
        }

        for(j=24; j>=7; j--) ///left
        {
            gotoxy(30, j);
            cout << "*";
            Sleep(30);
        }
}

int main()
{
    system("color e");
    software_chasers();
    getch();
    system("cls");
    welcome();
    system("cls");

    log login;
    login.showLog();
}
