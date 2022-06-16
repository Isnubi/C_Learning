#include <stdio.h>
#include <windows.h>
#include <conio.h>

int getkey();
void display(int, int, int, int[]);
void calendar(int, int);

//function to goto X,Y
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//function to set color
void setcolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0);
        wColor = (wColor | (ForgC & 0x0F));
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
char *week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int calend() {
    int nmonth, nyr, ch;
    enteryear:
    while(1) {
        printf("Enter the year: ");
        scanf("%d", &nyr);
        if (nyr < 1945) {
            printf("The year must be greater than 1945\n");
            continue;
        }
        else {
            printf("Enter the month(number): ");
            scanf("%d", &nmonth);
            if (nmonth < 1 || nmonth > 12) {
                printf("The month must be between 1 and 12\n");
                continue;
            }
            else {
                calendar(nyr, nmonth);
            }
        }
        while(1){
            gotoxy(20, 20);
            printf(("(*) Use arrow keys to navigate\n"));
            gotoxy(20, 22);
            printf(("(*) Press P to go to particular year and month\n"));
            gotoxy(20, 24);
            printf(("(*) Press Esc to exit\n"));
            ch = getkey();
            switch(ch){
                case 80: //DOWN ARROWN
                    if (nmonth == 12) {
                        nmonth = 1;
                        nyr++;
                    }
                    else {
                        nmonth++;
                    }
                    calendar(nyr, nmonth);
                    break;
                case 72: //UP ARROWN
                    if (nmonth == 1) {
                        nmonth = 12;
                        nyr--;
                    }
                    else {
                        nmonth--;
                    }
                    calendar(nyr, nmonth);
                    break;
                case 77: //RIGHT ARROWN
                    nyr++;
                    calendar(nyr, nmonth);
                    break;
                case 75: //LEFT ARROWN
                    if(nyr == 1945) {
                        gotoxy(15, 2);
                        printf("The year must be greater than 1945");
                    }
                    else {
                        nyr--;
                        calendar(nyr, nmonth);
                    }
                    break;
                case 112: //P
                    system("cls");
                    goto enteryear;
                case 27: //ESC
                    system("cls");
                    gotoxy(50, 14);
                    printf("Thank you for using the calendar");
                    exit(0);
            }
        }
        break;
    }
    getch();
    return 0;
}

void display(int nyr, int nmonth, int tdays, int days[]) {
    int i, j, pos;
    setcolor(12);
    gotoxy(56, 6);
    printf("%s %d", month[nmonth - 1], nyr);
    for(i = 0, pos = 30; i < 7; i++, pos += 10) {
        if(i == 6){
            setcolor(6);
        }
        else{
            setcolor(10);
        }
        gotoxy(pos, 8);
        printf("%s", week[i]);
    }

    setcolor(15);

    tdays++;
    switch(tdays) {
        case 0:
            pos = 91;
        case 1:
            pos = 31;
        case 2:
            pos = 41;
        case 3:
            pos = 51;
        case 4:
            pos = 61;
        case 5:
            pos = 71;
        case 6:
            pos = 81;
    }

    for(i = 0, j = 10, pos; i < days[nmonth - 1]; i++, pos += 10) {
        if(pos == 91){
            setcolor(8);
        }
        else{
            setcolor(7);
        }
        gotoxy(pos, j);
        printf("%d", i + 1);
        if(pos == 91){
            pos = 21;
            j++;
        }
    }

    setcolor(5);

    for(i=22;i<102;i++)
    {
        gotoxy(i,4);printf("%c",196);
        gotoxy(i,17);printf("%c",196);
    }

    gotoxy(21,4);printf("%c",218);
    gotoxy(102,4);printf("%c",191);
    gotoxy(21,17);printf("%c",192);
    gotoxy(102,17);printf("%c",217);

    for(i=5;i<17;i++)
    {
        gotoxy(21,i);printf("%c",179);
        gotoxy(102,i);printf("%c",179);
    }

    setcolor(11);

    gotoxy(24,11);printf("%c",174);
    gotoxy(98,11);printf("%c",175);
}

int getkey(){
    int ch;
    ch = getch();
    if(ch == 0){
        printf("zero");
        ch = getch();
        return ch;
    }
    return ch;
}

void calendar(int nyr, int nmonth) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tdays = 0, k, myear;
    system("cls");
    myear = nyr - 1;
    if(myear >= 1945){
        for(k = 1945; k <= myear; k++){
            if(k % 4 == 0){
                tdays = tdays + 366;
            }
            else{
                tdays = tdays + 365;
            }
        }

        if(k % 4 == 0){
            tdays = tdays + 366;
        }
        else{
            tdays = tdays + 365;
        }

        for(k = 0; k < (nmonth - 1); k++){
            tdays = tdays + days[k];
        }

        tdays = tdays % 7;
        display(nyr, nmonth, tdays, days);
    }
}