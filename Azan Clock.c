#include<stdio.h>    /////STANDARD LIBRARY
#include<windows.h>  //// LIBRARY REQUIRED TO USE SOME FUNCTIONS
#include <stdlib.h>   //// LIBRARY REQUIRED TO USE SOME FUNCTIONS
#include <string.h>  /////LIBRARY FOR STRING
#include <ctype.h>   //// LIBRARY REQUIRED TO USE SOME FUNCTIONS
#include<conio.h>    //// LIBRARY REQUIRED TO USE SOME FUNCTIONS BUT MAINLY FOR COLOR
#include <time.h>    /////LIBRARY FOR TIMINGS
#include<MMsystem.h> /////LIBRARY FOR SOUND

#define azansec 1      /////TIME FOR PRINTING AZAN CLOCK
#define MAXMAIN 5      /////ARROW IN MAINMENU
#define MINMAIN 1      /////ARROW IN MAINMENU
#define MINDUA 1       /////ARROW IN DUA
#define MAXDUA 5       /////ARROW IN DUA
#define TIMESIDES 35      /////CLOCK PLACEMENT
#define TIMEUPDOWN 10      /////CLOCK PLACEMENT
#define MAXAZAN 7      /////AZAN EDITING ARROW
#define MINAZAN 1      /////AZAN EDITING ARROW
#define azantimingheaderside 54      /////AZAN TIMING HEADER BOX PLACEMENT
#define azantimingheaderdown 0      /////AZAN TIMING HEADER BOX PLACEMENT
#define azantimingtableside 50      /////AZAN TIMING TABLE PLACEMENT
#define azantimingtabledown 10      /////AZAN TIMING TABLE PLACEMENT
#define FAJRTIMEUPDOWN 10      /////FAJR AZAN TIMING TABLE PLACEMENT
#define SUNSETTIMEUPDOWN 14      /////SUNSET AZAN TIMING TABLE PLACEMENT
#define ZUHRTIMEUPDOWN 18      /////ZUHR AZAN TIMING TABLE PLACEMENT
#define ASRTIMEUPDOWN 22      /////ASR AZAN TIMING TABLE PLACEMENT
#define MAGRIBTIMEUPDOWN 26      /////MAGRIB AZAN TIMING TABLE PLACEMENT
#define ISHATIMEUPDOWN 30      /////ISHA AZAN TIMING TABLE PLACEMENT
#define exitdown 16    ///// EXIT ANIMATION
#define exitside 25    ///// EXIT ANIMATION
#define alarmdisplayside 55    ///// ALARM DISPLAYING PLACEMENT
#define alarmdisplaydown 13    ///// ALARM DISPLAYING PLACEMENT
#define DUASIDE 63   //// DUA OF AZAN PLACEMENT
#define DUAUP 3      //// DUA OF AZAN PLACEMENT
#define DUASIDE1 45  //// DUA FOR FORGIVENESS PLACEMENT
#define DUAUP1 3     //// DUA FOR FORGIVENESS PLACEMENT
#define DUASIDE2 53  //// DUA FOR GUIDANCE PLACEMENT
#define DUAUP2 3     //// DUA FOR GUIDANCE PLACEMENT
#define DUASIDE3 62  //// AYAT AL KURSI PLACEMENT
#define DUAUP3 1     //// AYAT AL KURSI PLACEMENT


int flag;  /// GLOBAL VALUE

void arrowhere(int realposition,int arrowposition)  //// ARROW
{
    char arrow1=205 , arrow2=16 ;
        if(realposition == arrowposition)
        {
            SetColor(34);
            printf(" %c%c   " , arrow1 , arrow2);
        }
        else
        {
            SetColor(14);
            printf("      ");
        }
}
void ClearConsoleToColors(int ForgC, int BackC)    /////COLOR
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     //This is used to get the handle to current output buffer.
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     //This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
                      //   This is a return value indicating how many characterss were written
                        //   It is not used but we need to capture this since it will be
                          //   written anyway (passing NULL causes an access violation).
     DWORD count;
                                   //This is a structure containing all the console info
                          // It is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
                     //Now the current color will be set by this handle
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                              //This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                              //This will set our cursor position for the next print statement
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}
void SetColor(int ForgC)      /////COLOR
{
     WORD wColor;
     //This handle is needed to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void MaximizeOutputWindow(void)    ////MAX CONSOLE
{
    HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window
    ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button
}
void gotoxy(int x, int y)    ////COORDINATIONS
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hidecursor()    ////HIDE CURSOR
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void box()    ////FRAME BOX
{
    SetColor(9);
    int i, j,TopBottomLines=166,Sidelines=41,x=0,y=0,a=0;

    for(i=0; i<=TopBottomLines+1; i++)    /////// TOP LINE
    {
        gotoxy(x+i, y);
        if(i==0)
        {
             printf("%c", 218);sleep(a);
        }
        else if(i==TopBottomLines+1){
            printf("%c\n", 191);sleep(a);}
        else
            printf("%c", 196);sleep(a);
        fflush(stdout);
    }

    for(i=1; i<=Sidelines; i++)    /////// SIDE LINE
    {
        gotoxy(x, y+i);
        printf("%c", 179);sleep(a);
        for(j=1; j<=TopBottomLines; j++)
            printf(" ");sleep(a);
        printf("%c\n", 179);sleep(a);
        fflush(stdout);
    }

    for(i=0; i<=TopBottomLines+1; i++)   /////// BOTTOM LINE
    {
        gotoxy(x+i, y+Sidelines);
        if(i==0)
        {
            printf("%c", 192);sleep(a);
        }
        else if(i==TopBottomLines+1)
        {
            printf("%c\n", 217);sleep(a);
        }
        else
        {
            printf("%c", 196);sleep(a);
        }

    }
 }
 void aboutbox()    ////FRAME BOX
{
    SetColor(9);
    int i, j,TopBottomLines=166,Sidelines=70,x=0,y=0,a=0;

    for(i=0; i<=TopBottomLines+1; i++)    /////// TOP LINE
    {
        gotoxy(x+i, y);
        if(i==0)
        {
             printf("%c", 218);sleep(a);
        }
        else if(i==TopBottomLines+1){
            printf("%c\n", 191);sleep(a);}
        else
            printf("%c", 196);sleep(a);
        fflush(stdout);
    }

    for(i=1; i<=Sidelines; i++)    /////// SIDE LINE
    {
        gotoxy(x, y+i);
        printf("%c", 179);sleep(a);
        for(j=1; j<=TopBottomLines; j++)
            printf(" ");sleep(a);
        printf("%c\n", 179);sleep(a);
        fflush(stdout);
    }

    for(i=0; i<=TopBottomLines+1; i++)   /////// BOTTOM LINE
    {
        gotoxy(x+i, y+Sidelines);
        if(i==0)
        {
            printf("%c", 192);sleep(a);
        }
        else if(i==TopBottomLines+1)
        {
            printf("%c\n", 217);sleep(a);
        }
        else
        {
            printf("%c", 196);sleep(a);
        }

    }
 }
 void clockbox()    ////CLOCK'S BOX
{
    SetColor(9);
    int i, j,Horizontal=120,Vertical=18,x=25,y=6,a=0;

    for(i=0; i<=Horizontal+1; i++)    /////// TOP LINE
    {
        gotoxy(x+i, y);
        if(i==0)
        {
             printf("%c", 218);sleep(a);
        }
        else if(i==Horizontal+1){
            printf("%c\n", 191);sleep(a);}
        else
            printf("%c", 196);sleep(a);
        fflush(stdout);
    }

    for(i=1; i<=Vertical; i++)    /////// BOTH SIDE LINES
    {
        gotoxy(x, y+i);
        printf("%c", 179);sleep(a);
        for(j=1; j<=Horizontal; j++)
            printf(" ");sleep(a);
        printf("%c\n", 179);sleep(a);
        fflush(stdout);
    }

    for(i=0; i<=Horizontal+1; i++)   /////// BOTTOM LINE
    {
        gotoxy(x+i, y+Vertical);
        if(i==0)
        {
            printf("%c", 192);sleep(a);
        }
        else if(i==Horizontal+1)
        {
            printf("%c\n", 217);sleep(a);
        }
        else
        {
            printf("%c", 196);sleep(a);
        }
    }
 }
  void editbox()      ///// EDIT AZAN TIMING BOX
{
    hidecursor();
    SetColor(4);
    int i, j,len1=30,len2=5,x=116,y=19,a=0;

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y);
        if(i==0)
        {
             printf("%c", 218);sleep(a);
        }
        else if(i==len1+1){
            printf("%c\n", 191);sleep(a);}
        else
            printf("%c", 196);sleep(a);
    }

    for(i=1; i<=len2; i++)
    {
        gotoxy(x, y+i);
        printf("%c", 179);sleep(a);
        for(j=1; j<=len1; j++)
            printf(" ");sleep(a);
        printf("%c\n", 179);sleep(a);
    }

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y+len2);
        if(i==0)
        {
            printf("%c", 192);sleep(a);
        }
        else if(i==len1+1)
        {
            printf("%c\n", 217);sleep(a);
        }
        else
        {
            printf("%c", 196);sleep(a);
        }
    }
    fflush(stdout);
 }
 void removeeditbox()      ///// EDIT AZAN TIMING REMOVE BOX
{
    hidecursor();
    int i, j,len1=30,len2=5,x=116,y=19,a=0;

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y);
        if(i==0)
        {
             printf(" ");sleep(a);
        }
        else if(i==len1+1){
            printf(" \n");sleep(a);}
        else
            printf(" ");sleep(a);
    }

    for(i=1; i<=len2; i++)
    {
        gotoxy(x, y+i);
        printf(" ");sleep(a);
        for(j=1; j<=len1; j++)
            printf(" ");sleep(a);
        printf(" ");sleep(a);
    }

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y+len2);
        if(i==0)
        {
            printf(" ");sleep(a);
        }
        else if(i==len1+1)
        {
            printf(" \n" );sleep(a);
        }
        else
        {
            printf(" ");sleep(a);
        }
    }
    fflush(stdout);
 }
 void headerbox()      ///// AZAN TIMING HEADER BOX
{
    hidecursor();
    int i, j,len1=57,len2=5,x=50,y=3,a=0;

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y);
        if(i==0)
        {
             printf("%c", 218);sleep(a);
        }
        else if(i==len1+1){
            printf("%c\n", 191);sleep(a);}
        else
            printf("%c", 196);sleep(a);
    }

    for(i=1; i<=len2; i++)
    {
        gotoxy(x, y+i);
        printf("%c", 179);sleep(a);
        for(j=1; j<=len1; j++)
            printf(" ");sleep(a);
        printf("%c\n", 179);sleep(a);
    }

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y+len2);
        if(i==0)
        {
            printf("%c", 192);sleep(a);
        }
        else if(i==len1+1)
        {
            printf("%c\n", 217);sleep(a);
        }
        else
        {
            printf("%c", 196);sleep(a);
        }
    }
    fflush(stdout);
 }
void headerbox2()      ///// DUA HEADER BOX
{
    hidecursor();
    int i, j,len1=22,len2=5,x=63,y=3,a=0;

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y);
        if(i==0)
        {
             printf("%c", 218);sleep(a);
        }
        else if(i==len1+1){
            printf("%c\n", 191);sleep(a);}
        else
            printf("%c", 196);sleep(a);
    }

    for(i=1; i<=len2; i++)
    {
        gotoxy(x, y+i);
        printf("%c", 179);sleep(a);
        for(j=1; j<=len1; j++)
            printf(" ");sleep(a);
        printf("%c\n", 179);sleep(a);
    }

    for(i=0; i<=len1+1; i++)
    {
        gotoxy(x+i, y+len2);
        if(i==0)
        {
            printf("%c", 192);sleep(a);
        }
        else if(i==len1+1)
        {
            printf("%c\n", 217);sleep(a);
        }
        else
        {
            printf("%c", 196);sleep(a);
        }
    }
    fflush(stdout);
 }
 void A()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,b,c,d,ar,arr,brr;
    int start=7,stop=20,side=30;
    for(brr=start;brr<=stop;brr++)///////////////////////////////////1st
    {
        r=side;rr=brr; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf("%c", a);
        gotoxy(r+4,b-1); printf("%c", a);
        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf("%c", a);
            r+=2;
        }

        usleep(rt);
        //////////////////////////----------------------------space
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
    for(brr=start+13;brr>=stop-10;brr--)/////////////////////////2md
    {
        rr=brr;r=side; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {

            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;

        gotoxy(r+2,b); printf("%c", a);

        gotoxy(r+4,b-1); printf("%c", a);

        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {

            gotoxy(r,d); printf("%c", a);
            r+=2;
        }
        usleep(rt);
        //////////////////////////----------------------------
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
    for(brr=start+3;brr<=stop;brr++)///////////////////3rd
    {
        rr=brr;r=side; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {

            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;

        gotoxy(r+2,b); printf("%c", a);

        gotoxy(r+4,b-1); printf("%c", a);

        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {

            gotoxy(r,d); printf("%c", a);
            r+=2;
        }
        usleep(rt);

        //////////////////////////----------------------------
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
    for(brr=start+13;brr>=stop-3;brr--)//////////////////4th
    {
        rr=brr;r=side; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {

            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;

        gotoxy(r+2,b); printf("%c", a);

        gotoxy(r+4,b-1); printf("%c", a);

        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {

            gotoxy(r,d); printf("%c", a);
            r+=2;
        }
        usleep(rt);
        if(brr==17)break;
        //////////////////////////----------------------------
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
    for(brr=start+10;brr<=stop;brr++)/////////////////5th
    {
        rr=brr;r=side; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {

            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;

        gotoxy(r+2,b); printf("%c", a);

        gotoxy(r+4,b-1); printf("%c", a);

        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {

            gotoxy(r,d); printf("%c", a);
            r+=2;
        }
        usleep(rt);
        if(brr==stop)break;
        //////////////////////////----------------------------
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
}
void Z()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,br,c,d,ar,arr,brr,drr,crr,cr;
    int start=1,stop=14,side=43;
    for(drr=start;drr<=stop;drr++)////////////////////////////1st
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr--;
        }
        r=cr; crr=crr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr--;
        }
        r=br; brr=brr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-10;drr--)/////////////////////////2md
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr--;
        }
        r=cr; crr=crr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr--;
        }
        r=br; brr=brr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r++;
        }
    }
    for(drr=start+3;drr<=stop;drr++)///////////////////3rd
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr--;
        }
        r=cr; crr=crr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr--;
        }
        r=br; brr=brr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-3;drr--)//////////////////4th
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr--;
        }
        r=cr; crr=crr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr--;
        }
        r=br; brr=brr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r++;
        }
    }
    for(drr=start+10;drr<=stop;drr++)/////////////////5th
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr--;
        }
        r=cr; crr=crr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            r++;
        }
        usleep(rt);
        if(drr==stop)break;
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=br; brr=brr+5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr--;
        }
        r=br; brr=brr+6;
        for(ri=1;ri<=9;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r++;
        }
    }
}
 void A2()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,b,c,d,ar,arr,brr;
    int start=7,stop=20,side=54;
    for(brr=start;brr<=stop;brr++)///////////////////////////////1st
    {
        r=side;rr=brr; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf("%c", a);
        gotoxy(r+4,b-1); printf("%c", a);
        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf("%c", a);
            r+=2;
        }

        usleep(rt);
        //////////////////////////----------------------------space
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
    for(brr=start+13;brr>=stop-10;brr--)/////////////////////////2md
    {
        rr=brr;r=side; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {

            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;

        gotoxy(r+2,b); printf("%c", a);

        gotoxy(r+4,b-1); printf("%c", a);

        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {

            gotoxy(r,d); printf("%c", a);
            r+=2;
        }
        usleep(rt);
        //////////////////////////----------------------------
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
    for(brr=start+3;brr<=stop;brr++)///////////////////3rd
    {
        rr=brr;r=side; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {

            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;

        gotoxy(r+2,b); printf("%c", a);

        gotoxy(r+4,b-1); printf("%c", a);

        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {

            gotoxy(r,d); printf("%c", a);
            r+=2;
        }
        usleep(rt);

        //////////////////////////----------------------------
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
    for(brr=start+13;brr>=stop-3;brr--)//////////////////4th
    {
        rr=brr;r=side; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {

            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;

        gotoxy(r+2,b); printf("%c", a);

        gotoxy(r+4,b-1); printf("%c", a);

        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {

            gotoxy(r,d); printf("%c", a);
            r+=2;
        }
        usleep(rt);
        if(brr==17)break;
        //////////////////////////----------------------------
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
    for(brr=start+10;brr<=stop;brr++)/////////////////5th
    {
        rr=brr;r=side; b=rr;c=rr;d=rr;ar=r;arr=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf("%c", a);
        gotoxy(r+4,b-1); printf("%c", a);
        gotoxy(r+6,b-1); printf("%c", a);
        gotoxy(r+8,b); printf("%c", a);
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf("%c", a);
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {

            gotoxy(r,d); printf("%c", a);
            r+=2;
        }
        usleep(rt);
        if(brr==stop)break;
        //////////////////////////----------------------------
        r=ar; rr=arr; b=rr;c=rr;d=rr;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        b=b-5;
        gotoxy(r+2,b); printf(" ");
        gotoxy(r+4,b-1); printf(" ");
        gotoxy(r+6,b-1); printf(" ");
        gotoxy(r+8,b); printf(" ");
        r=r+10; c=c-4;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,c); printf(" ");
            c++;
        }
        r=r-8;d=d-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,d); printf(" ");
            r+=2;
        }
    }
}
void N()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,br,c,d,ar,arr,brr,drr,crr,cr;
    int start=8,stop=20,side=67;
    for(drr=start;drr<=stop;drr++)//////////////////////////////1st
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr++;
        }
        r=cr+12;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            crr--;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr++;
        }
        r=cr+12;

        for(ri=1;ri<=8;ri++)
        {
            gotoxy(r,crr); printf(" ");
            crr++;
        }
    }
    for(drr=start+13;drr>=stop-10;drr--)/////////////////////////2md
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr++;
        }
        r=cr+12;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            crr--;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr++;
        }
        r=cr+12;

        for(ri=1;ri<=8;ri++)
        {
            gotoxy(r,crr); printf(" ");
            crr++;
        }
    }
    for(drr=start+3;drr<=stop;drr++)///////////////////3rd
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr++;
        }
        r=cr+12;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            crr--;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr++;
        }
        r=cr+12;

        for(ri=1;ri<=8;ri++)
        {
            gotoxy(r,crr); printf(" ");
            crr++;
        }
    }
    for(drr=start+13;drr>=stop-3;drr--)//////////////////4th
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr++;
        }
        r=cr+12;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            crr--;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr++;
        }
        r=cr+12;

        for(ri=1;ri<=8;ri++)
        {
            gotoxy(r,crr); printf(" ");
            crr++;
        }
    }
    for(drr=start+10;drr<=stop;drr++)/////////////////5th
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf("%c", a);
            r+=2; brr++;
        }
        r=cr+12;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,crr); printf("%c", a);
            crr--;
        }
        usleep(rt);
        if(drr==stop)break;
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=br+2; brr=brr-5;
        for(ri=1;ri<=5;ri++)
        {
            gotoxy(r,brr); printf(" ");
            r+=2; brr++;
        }
        r=cr+12;

        for(ri=1;ri<=8;ri++)
        {
            gotoxy(r,crr); printf(" ");
            crr++;
        }
    }
}
void C()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,br,c,d,ar,arr,brr,drr,crr,cr;
    int start=1,stop=14,side=90;
    for(drr=start;drr<=stop;drr++)////////////////////////////1st
    {
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-10;drr--)/////////////////////////2md
    {
       r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+3;drr<=stop;drr++)///////////////////3rd
    {
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-3;drr--)//////////////////4th
    {
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+10;drr<=stop;drr++)/////////////////5th
    {
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        if(drr==stop)break;
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
}
void L()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,br,c,d,ar,arr,brr,drr,crr,cr;
    int start=1,stop=14,side=102;
    for(drr=start;drr<=stop;drr++)////////////////////////////1st
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-10;drr--)/////////////////////////2md
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+3;drr<=stop;drr++)///////////////////3rd
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-3;drr--)//////////////////4th
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+10;drr<=stop;drr++)/////////////////5th
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        if(drr==stop)break;
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
}
void O()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,br,c,d,ar,arr,brr,drr,crr,cr;
    int start=1,stop=14,side=114;
    for(drr=start;drr<=stop;drr++)////////////////////////////1st
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);

        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-10;drr--)/////////////////////////2md
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);

        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+3;drr<=stop;drr++)///////////////////3rd
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);

        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-3;drr--)//////////////////4th
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);

        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+10;drr<=stop;drr++)/////////////////5th
    {
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        if(drr==stop)break;
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }

        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side+10;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
}
void C2()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,br,c,d,ar,arr,brr,drr,crr,cr;
    int start=1,stop=14,side=127;
    for(drr=start;drr<=stop;drr++)////////////////////////////1st
    {
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-10;drr--)/////////////////////////2md
    {
       r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+3;drr<=stop;drr++)///////////////////3rd
    {
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+13;drr>=stop-3;drr--)//////////////////4th
    {
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
    for(drr=start+10;drr<=stop;drr++)/////////////////5th
    {
        r=side;rr=drr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        r=side;rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf("%c", a);
            r++;
        }
        usleep(rt);
        if(drr==stop)break;
        ///////////////////////-------------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
        r=side;rr=drr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++;
        }
        r=side;rr=drr+6;
        for(ri=1;ri<=10;ri++)
        {
            gotoxy(r,rr); printf(" ");
            r++;
        }
    }
}
void K()    ////ALPHAPET OF AZAN CLOCK
{
    SetColor(14);
    hidecursor();
    char a=178;
    int i,r,rt=azansec,rr,ri,br,c,d,ar,arr,brr,drr,crr,cr;
    int start=7,stop=20,side=139;
    for(drr=start;drr<=stop;drr++)////////////////////////////1st
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr++; r+=2;
        }
        usleep(rt);
        /////////////////////////-----------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++; r+=2;
        }
    }
    for(drr=start+13;drr>=stop-10;drr--)/////////////////////////2md
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr++; r+=2;
        }
        usleep(rt);
        /////////////////////////-----------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++; r+=2;
        }
    }
    for(drr=start+3;drr<=stop;drr++)///////////////////3rd
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr++; r+=2;
        }
        usleep(rt);
        /////////////////////////-----------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++; r+=2;
        }
    }
    for(drr=start+13;drr>=stop-3;drr--)//////////////////4th
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr++; r+=2;
        }
        usleep(rt);;
        /////////////////////////-----------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("");
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++; r+=2;
        }
    }
    for(drr=start+10;drr<=stop;drr++)/////////////////5th
    {
        r=side; rr=drr;
        brr=rr;br=r;ar=r;arr=rr;crr=rr;cr=r;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf("%c",a);
            rr++; r+=2;
        }
        usleep(rt);
        if(drr==stop)break;
        /////////////////////////-----------------space
        r=ar; rr=arr; brr=rr;
        for(ri=1;ri<=7;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--;
        }
        r=side+2; rr=drr-3;
        for(ri=1;ri<=4;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr--; r+=2;
        }
        r=side+4; rr=drr-2;
        for(ri=1;ri<=3;ri++)
        {
            gotoxy(r,rr); printf(" ");
            rr++; r+=2;
        }
    }
}
void letter_A(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("|  |");

        fflush(stdout);
    }
}
void letter_B(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__)");
        if(i==2)
            printf("|__)");

        fflush(stdout);
    }
}
void letter_C(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|   ");
        if(i==2)
            printf("|__ ");

        fflush(stdout);
    }
}
void letter_D(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" _  ");
        if(i==1)
            printf("| \\");
        if(i==2)
            printf("|_/");

        fflush(stdout);
    }
}
void letter_E(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__ ");
        if(i==2)
            printf("|__");

        fflush(stdout);
    }
}
void letter_F(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|_  ");
        if(i==2)
            printf("|   ");

        fflush(stdout);
    }
}
void letter_G(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("| _ ");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
}
void letter_H(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("|  |");

        fflush(stdout);
    }
}
void letter_I(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" ");
        if(i==1)
            printf("|");
        if(i==2)
            printf("|");

        fflush(stdout);
    }
}
void letter_J(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("   ");
        if(i==1)
            printf("  |");
        if(i==2)
            printf("__|");

        fflush(stdout);
    }
}
void letter_K(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("   ");
        if(i==1)
            printf("|/");
        if(i==2)
            printf("|\\");

        fflush(stdout);
    }
}
void letter_L(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("   ");
        if(i==1)
            printf("|  ");
        if(i==2)
            printf("|__");

        fflush(stdout);
    }
}
void letter_M(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|\\/|");
        if(i==2)
            printf("|  |");

        fflush(stdout);
    }
}
void letter_N(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|\\ |");
        if(i==2)
            printf("| \\|");

        fflush(stdout);
    }
}
void letter_O(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|  |");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
}
void letter_P(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__)");
        if(i==2)
            printf("|   ");

        fflush(stdout);
    }
}
void letter_Q(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("| _|");
        if(i==2)
            printf("|__%c", 191);

        fflush(stdout);
    }
}
void letter_R(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("|  \\");

        fflush(stdout);
    }
}
void letter_S(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__ ");
        if(i==2)
            printf(" __|");

        fflush(stdout);
    }
}
void letter_T(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" ___");
        if(i==1)
            printf("  | ");
        if(i==2)
            printf("  | ");

        fflush(stdout);
    }
}
void letter_U(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|  |");
        if(i==2)
            printf("|__|");

        fflush(stdout);
    }
}
void letter_V(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("\\  /");
        if(i==2)
            printf(" \\/ ");

        fflush(stdout);
    }
}
void letter_W(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|  |");
        if(i==2)
            printf("|/\\|");

        fflush(stdout);
    }
}
void letter_X(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf(" \\/");
        if(i==2)
            printf(" /\\");

        fflush(stdout);
    }
}
void letter_Y(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("\\ /");
        if(i==2)
            printf(" |  ");

        fflush(stdout);
    }
}
void letter_Z(int x, int y)    ////ALPHAPET
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("  / ");
        if(i==2)
            printf(" /_");

        fflush(stdout);
    }
}
void boldletter_A(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("%c      %c",219,219);
        if(i==5)
            printf("%c      %c",219,219);
        if(i==6)
            printf("%c      %c",219,219);

        fflush(stdout);
    }
}
void boldletter_B(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219);
        if(i==4)
            printf("%c      %c",219,219);
        if(i==5)
            printf("%c      %c",219,219);
        if(i==6)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_C(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219);
        if(i==1)
            printf("%c      ",219,219);
        if(i==2)
            printf("%c      ",219,219);
        if(i==3)
            printf("%c",219,219,219,219,219,219,219);
        if(i==4)
            printf("%c      ",219,219);
        if(i==5)
            printf("%c      ",219,219);
        if(i==6)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_D(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c      %c",219,219,219,219,219,219,219);
        if(i==4)
            printf("%c      %c",219,219);
        if(i==5)
            printf("%c      %c",219,219);
        if(i==6)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_E(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c   ",219);
        if(i==2)
            printf("%c   ",219);
        if(i==3)
            printf("%c%c%c%c%c%c",219,219,219,219,219,219);
        if(i==4)
            printf("%c   ",219);
        if(i==5)
            printf("%c   ",219);
        if(i==6)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        fflush(stdout);
    }
}
void boldletter_F(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c   ",219);
        if(i==2)
            printf("%c   ",219);
        if(i==3)
            printf("%c%c%c%c%c%c",219,219,219,219,219,219);
        if(i==4)
            printf("%c   ",219);
        if(i==5)
            printf("%c   ",219);
        if(i==6)
            printf("%c   ",219);

        fflush(stdout);
    }
}
void boldletter_G(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c   ",219);
        if(i==2)
            printf("%c   ",219);
        if(i==3)
            printf("%c   %c%c%c%c",219,219,219,219,219);
        if(i==4)
            printf("%c      %c",219,219);
        if(i==5)
            printf("%c      %c",219,219);
        if(i==6)
            printf("%c%c%c%c%c%c%c%c ",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_H(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c      %c",219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("%c      %c",219,219);
        if(i==5)
            printf("%c      %c",219,219);
        if(i==6)
            printf("%c      %c",219,219);

        fflush(stdout);
    }
}
void boldletter_I(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219);
        if(i==1)
            printf("   %c",219);
        if(i==2)
            printf("   %c",219);
        if(i==3)
            printf("   %c   ",219);
        if(i==4)
            printf("   %c   ",219);
        if(i==5)
            printf("   %c   ",219);
        if(i==6)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219,219);
        fflush(stdout);
    }
}
void boldletter_J(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("     %c",219);
        if(i==2)
            printf("     %c",219);
        if(i==3)
            printf("     %c",219);
        if(i==4)
            printf("     %c",219);
        if(i==5)
            printf("%c    %c",219,219);
        if(i==6)
            printf("%c%c%c%c%c%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_K(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c   %c ",219,219,219,219,219,219,219);
        if(i==1)
            printf("%c  %c",219,219);
        if(i==2)
            printf("%c %c",219,219);
        if(i==3)
            printf("%c%c",219,219,219,219,219,219,219);
        if(i==4)
            printf("%c %c",219,219);
        if(i==5)
            printf("%c  %c",219,219);
        if(i==6)
            printf("%c   %c",219,219);

        fflush(stdout);
    }
}
void boldletter_L(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c   ",219);
        if(i==2)
            printf("%c   ",219);
        if(i==3)
            printf("%c",219,219,219,219,219,219);
        if(i==4)
            printf("%c   ",219);
        if(i==5)
            printf("%c   ",219);
        if(i==6)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_M(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c     %c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c %c   %c %c",219,219);
        if(i==2)
            printf("%c  %c %c  %c",219,219);
        if(i==3)
            printf("%c   %c   %c",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("%c       %c",219,219);
        if(i==5)
            printf("%c       %c",219,219);
        if(i==6)
            printf("%c       %c",219,219);

        fflush(stdout);
    }
}
void boldletter_N(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c      %c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c %c     %c",219,219);
        if(i==2)
            printf("%c  %c    %c",219,219);
        if(i==3)
            printf("%c   %c   %c",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("%c    %c  %c",219,219);
        if(i==5)
            printf("%c     %c %c",219,219);
        if(i==6)
            printf("%c      %c%c",219,219);

        fflush(stdout);
    }
}
void boldletter_O(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c      %c",219,219);
        if(i==4)
            printf("%c      %c",219,219);
        if(i==5)
            printf("%c      %c",219,219);
        if(i==6)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_P(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("%c      ",219,219);
        if(i==5)
            printf("%c      ",219,219);
        if(i==6)
            printf("%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_Q(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c      %c",219,219);
        if(i==4)
            printf("%c      %c",219,219);
        if(i==5)
            printf("%c    %c %c",219,219,219);
        if(i==6)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==7)
          //  printf("       %c",219,219);

        fflush(stdout);
    }
}
void boldletter_R(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c ",219,219,219,219,219,219,219);
        if(i==1)
            printf("%c     %c",219,219);
        if(i==2)
            printf("%c     %c",219,219);
        if(i==3)
            printf("%c%c%c%c%c%c",219,219,219,219,219,219,219);
        if(i==4)
            printf("%c   %c",219,219);
        if(i==5)
            printf("%c    %c",219,219);
        if(i==6)
            printf("%c     %c",219,219);

        fflush(stdout);
    }
}
void boldletter_S(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c      ",219,219);
        if(i==2)
            printf("%c      ",219,219);
        if(i==3)
            printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("      %c",219,219);
        if(i==5)
            printf("      %c",219,219);
        if(i==6)
            printf("%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_T(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c ",219,219,219,219,219,219,219);
        if(i==1)
            printf("   %c",219);
        if(i==2)
            printf("   %c",219);
        if(i==3)
            printf("   %c   ",219);
        if(i==4)
            printf("   %c   ",219);
        if(i==5)
            printf("   %c   ",219);
        if(i==6)
            printf("   %c ",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_U(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c      %c",219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c      %c",219,219);
        if(i==4)
            printf("%c      %c",219,219);
        if(i==5)
            printf("%c      %c",219,219);
        if(i==6)
            printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_V(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c      %c",219,219);
        if(i==1)
            printf("%c      %c",219,219);
        if(i==2)
            printf("%c      %c",219,219);
        if(i==3)
            printf("%c      %c",219,219);
        if(i==4)
            printf(" %c    %c",219,219);
        if(i==5)
            printf("  %c  %c",219,219);
        if(i==6)
            printf("   %c%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_W(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c       %c",219,219);
        if(i==1)
            printf("%c       %c",219,219);
        if(i==2)
            printf("%c       %c",219,219);
        if(i==3)
            printf("%c   %c   %c",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("%c  %c %c  %c",219,219);
        if(i==5)
            printf("%c %c   %c %c",219,219);
        if(i==6)
            printf("%c%c     %c%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_X(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" %c     %c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("  %c   %c ",219,219);
        if(i==2)
            printf("   %c %c ",219,219);
        if(i==3)
            printf("    %c    ",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("   %c %c   ",219,219);
        if(i==5)
            printf("  %c   %c ",219,219);
        if(i==6)
            printf(" %c     %c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void boldletter_Y(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" %c     %c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("  %c   %c ",219,219);
        if(i==2)
            printf("   %c %c ",219,219);
        if(i==3)
            printf("    %c    ",219,219,219,219,219,219,219,219);
        if(i==4)
            printf("    %c",219);
        if(i==5)
            printf("    %c",219);
        if(i==6)
            printf("    %c",219);

        fflush(stdout);
    }
}
void boldletter_Z(int x, int y)    ////BOLD ALPHAPET
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c",219,219,219,219,219,219,219,219);
        if(i==1)
            printf("    %c",219,219);
        if(i==2)
            printf("   %c",219,219);
        if(i==3)
            printf("  %c",219,219);
        if(i==4)
            printf(" %c",219,219);
        if(i==5)
            printf("%c",219,219);
        if(i==6)
            printf("%c%c%c%c%c",219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}

void zero(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c          %c",219,219);
        if(i==2)
            printf("%c          %c",219,219);
        if(i==3)
            printf("%c          %c",219,219);
        if(i==4)
            printf("%c          %c",219,219);
        if(i==5)
            printf("%c          %c",219,219);
        if(i==6)
            printf("%c          %c",219,219);
        if(i==7)
            printf("%c          %c",219,219);
        if(i==8)
            printf("%c          %c",219,219);
        if(i==9)
            printf("%c          %c",219,219);
        if(i==10)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void one(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("          %c ",219);
        if(i==1)
            printf("          %c ",219);
        if(i==2)
            printf("          %c ",219);
        if(i==3)
            printf("          %c ",219);
        if(i==4)
            printf("          %c ",219);
        if(i==5)
            printf("          %c ",219);
        if(i==6)
            printf("          %c ",219);
        if(i==7)
            printf("          %c ",219);
        if(i==8)
            printf("          %c ",219);
        if(i==9)
            printf("          %c ",219);
        if(i==10)
            printf("          %c ",219);

        fflush(stdout);
    }
}
void two(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==1)
            printf("           %c",219);
        if(i==2)
            printf("           %c",219);
        if(i==3)
            printf("           %c",219);
        if(i==4)
            printf("           %c",219);
        if(i==5)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==6)
            printf("%c           ",219);
        if(i==7)
            printf("%c           ",219);
        if(i==8)
            printf("%c           ",219);
        if(i==9)
            printf("%c           ",219);
        if(i==10)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void three(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==1)
            printf("           %c",219);
        if(i==2)
            printf("           %c",219);
        if(i==3)
            printf("           %c",219);
        if(i==4)
            printf("           %c",219);
        if(i==5)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==6)
            printf("           %c",219);
        if(i==7)
            printf("           %c",219);
        if(i==8)
            printf("           %c",219);
        if(i==9)
            printf("           %c",219);
        if(i==10)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void four(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c          %c",219,219);
        if(i==1)
            printf("%c          %c",219,219);
        if(i==2)
            printf("%c          %c",219,219);
        if(i==3)
            printf("%c          %c",219,219);
        if(i==4)
            printf("%c          %c",219,219);
        if(i==5)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==6)
            printf("           %c",219);
        if(i==7)
            printf("           %c",219);
        if(i==8)
            printf("           %c",219);
        if(i==9)
            printf("           %c",219);
        if(i==10)
            printf("           %c",219);
        fflush(stdout);
    }
}
void five(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c           ",219);
        if(i==2)
            printf("%c           ",219);
        if(i==3)
            printf("%c           ",219);
        if(i==4)
            printf("%c           ",219);
        if(i==5)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==6)
            printf("           %c",219);
        if(i==7)
            printf("           %c",219);
        if(i==8)
            printf("           %c",219);
        if(i==9)
            printf("           %c",219);
        if(i==10)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void six(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c           ",219);
        if(i==2)
            printf("%c           ",219);
        if(i==3)
            printf("%c           ",219);
        if(i==4)
            printf("%c           ",219);
        if(i==5)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==6)
            printf("%c          %c",219,219);
        if(i==7)
            printf("%c          %c",219,219);
        if(i==8)
            printf("%c          %c",219,219);
        if(i==9)
            printf("%c          %c",219,219);
        if(i==10)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void seven(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==1)
            printf("           %c",219);
        if(i==2)
            printf("           %c",219);
        if(i==3)
            printf("           %c",219);
        if(i==4)
            printf("           %c",219);
        if(i==5)
            printf("           %c",219);
        if(i==6)
            printf("           %c",219);
        if(i==7)
            printf("           %c",219);
        if(i==8)
            printf("           %c",219);
        if(i==9)
            printf("           %c",219);
        if(i==10)
            printf("           %c",219);

        fflush(stdout);
    }

}
void eight(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c          %c",219,219);
        if(i==2)
            printf("%c          %c",219,219);
        if(i==3)
            printf("%c          %c",219,219);
        if(i==4)
            printf("%c          %c",219,219);
        if(i==5)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==6)
            printf("%c          %c",219,219);
        if(i==7)
            printf("%c          %c",219,219);
        if(i==8)
            printf("%c          %c",219,219);
        if(i==9)
            printf("%c          %c",219,219);
        if(i==10)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);

        fflush(stdout);
    }
}
void nine(int x, int y)    ////NUMBER OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==1)
            printf("%c          %c",219,219);
        if(i==2)
            printf("%c          %c",219,219);
        if(i==3)
            printf("%c          %c",219,219);
        if(i==4)
            printf("%c          %c",219,219);
        if(i==5)
            printf("%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219);
        if(i==6)
            printf("           %c",219);
        if(i==7)
            printf("           %c",219);
        if(i==8)
            printf("           %c",219);
        if(i==9)
            printf("           %c",219);
        if(i==10)
            printf("           %c",219);

        fflush(stdout);
    }
}
void szero(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|  |");
        if(i==2)
            printf("|__|");
    }
    fflush(stdout);
}
void sone(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("  | ");
        if(i==2)
            printf("  | ");
    }
    fflush(stdout);
}
void stwo(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf(" __|");
        if(i==2)
            printf("|__ ");
    }
    fflush(stdout);
}
void sthree(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf(" __|");
        if(i==2)
            printf(" __|");
    }
    fflush(stdout);
}
void sfour(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("    ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("   |");
    }
    fflush(stdout);
}
void sfive(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__ ");
        if(i==2)
            printf(" __|");
    }
    fflush(stdout);
}
void ssix(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__ ");
        if(i==2)
            printf("|__|");
    }
    fflush(stdout);
}
void sseven(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("   |");
        if(i==2)
            printf("   |");
    }
    fflush(stdout);
}
void seight(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("|__|");
    }
    fflush(stdout);
}
void snine(int x, int y)    //// small size numbers
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf(" __ ");
        if(i==1)
            printf("|__|");
        if(i==2)
            printf("   |");
    }
    fflush(stdout);
}
void colon(int x, int y)    ////COLON OF CLOCK
{
    int i;
    for(i=0; i<11; i++)
    {
        gotoxy( x, y+i);
        if(i==0)
            printf("   ");
        if(i==1)
            printf("   ");
        if(i==2)
            printf("   ");
        if(i==3)
            printf(" %c ",219);
        if(i==4)
            printf("   ");
        if(i==5)
            printf("   ");
        if(i==6)
            printf("   ");
        if(i==7)
            printf(" %c ",219);
        if(i==8)
            printf("   ");
        if(i==9)
            printf("   ");
        if(i==10)
            printf("   ");
        fflush(stdout);
    }
 }
void scolon(int x, int y)    //// small size colon
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);
        if(i==0)
            printf("   ");
        if(i==1)
            printf(" . ");
        if(i==2)
            printf(" . ");
    }
    fflush(stdout);
 }
void line(int x, int y)    ////line
{
    int i;
    for(i=0; i<3; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("|");
        if(i==1)
            printf("|");
        if(i==2)
            printf("|");
    }
    fflush(stdout);
}
void speaker(int x, int y)    ////SPEAKER DESIGN
{
    int i;
    for(i=0; i<7; i++)
    {
        SetColor(8);
        gotoxy( x, y+i);

        if(i==0)
            printf("    %c%c     %c",219,219,42);
        if(i==1)
            printf("   %c%c%c   %c",219,219,219,42);
        if(i==2)
            printf("%c%c%c%c%c  %c",219,219,219,219,219,42);
        if(i==3)
            printf("%c%c%c%c%c  %c %c %c",219,219,219,219,219,42,42,42);
        if(i==4)
            printf("%c%c%c%c%c  %c",219,219,219,219,219,42);
        if(i==5)
            printf("   %c%c%c   %c",219,219,219,42);
        if(i==6)
            printf("    %c%c     %c",219,219,42);

        fflush(stdout);
    }
}
void exclamation(int x, int y)    ////EXCLAMATION MARK
{
    int i;
    for(i=0; i<7; i++)
    {
        gotoxy( x, y+i);

        if(i==0)
            printf("   %c",219,219,219,219,219,219,219);
        if(i==1)
            printf("   %c",219);
        if(i==2)
            printf("   %c",219);
        if(i==3)
            printf("   %c",219);
        if(i==4)
            printf("   %c",219);
        if(i==5)
            printf("     ",219);
        if(i==6)
            printf("   %c",219,219,219,219,219,219,219,219);
        fflush(stdout);
    }
}

void FajrtimeDigit_1sthour(int digit)    //// FAJR 1ST HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40,y=FAJRTIMEUPDOWN;
    switch (digit) {
        case 0:
            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void FajrtimeDigit_2ndhour(int digit)    //// FAJR 2ND HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+4,y=FAJRTIMEUPDOWN;
    switch (digit) {
        case 0:
            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
    scolon(azantimingtableside+40+8,FAJRTIMEUPDOWN);
}
void FajrtimeDigit_1stmin(int digit)    //// FAJR 1ST MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+11,y=FAJRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void FajrtimeDigit_2ndmin(int digit)    //// FAJR 2ND MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+15,y=FAJRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}

void SunsettimeDigit_1sthour(int digit)    //// SUNSET 1ST HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40,y=SUNSETTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void SunsettimeDigit_2ndhour(int digit)    //// SUNSET 2ND HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+4,y=SUNSETTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
    scolon(azantimingtableside+40+8,SUNSETTIMEUPDOWN);
}
void SunsettimeDigit_1stmin(int digit)    //// SUNSET 1ST MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+11,y=SUNSETTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void SunsettimeDigit_2ndmin(int digit)    //// SUNSET 2ND MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+15,y=SUNSETTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}

void ZuhrtimeDigit_1sthour(int digit)    //// ZUHR 1ST HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40,y=ZUHRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void ZuhrtimeDigit_2ndhour(int digit)    //// ZUHR 2ND HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+4,y=ZUHRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
    scolon(azantimingtableside+40+8,ZUHRTIMEUPDOWN);
}
void ZuhrtimeDigit_1stmin(int digit)    //// ZUHR 1ST MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+11,y=ZUHRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void ZuhrtimeDigit_2ndmin(int digit)    //// ZUHR 2ND MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+15,y=ZUHRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}

void AsrtimeDigit_1sthour(int digit)    //// ASR 1ST HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40,y=ASRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void AsrtimeDigit_2ndhour(int digit)    //// ASR 2ND HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+4,y=ASRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
    scolon(azantimingtableside+40+8,ASRTIMEUPDOWN);
}
void AsrtimeDigit_1stmin(int digit)    //// ASR 1ST MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+11,y=ASRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void AsrtimeDigit_2ndmin(int digit)    //// ASR 2ND MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+15,y=ASRTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}

void MagribtimeDigit_1sthour(int digit)    //// MAGRIB 1ST HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40,y=MAGRIBTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void MagribtimeDigit_2ndhour(int digit)    //// MAGRIB 2ND HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+4,y=MAGRIBTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
    scolon(azantimingtableside+40+8,MAGRIBTIMEUPDOWN);
}
void MagribtimeDigit_1stmin(int digit)    //// MAGRIB 1ST MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+11,y=MAGRIBTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void MagribtimeDigit_2ndmin(int digit)    //// MAGRIB 2ND MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+15,y=MAGRIBTIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}

void IshatimeDigit_1sthour(int digit)    //// ISHA 1ST HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40,y=ISHATIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void IshatimeDigit_2ndhour(int digit)    //// ISHA 2ND HOUR DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+4,y=ISHATIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
    scolon(azantimingtableside+40+8,ISHATIMEUPDOWN);
}
void IshatimeDigit_1stmin(int digit)    //// ISHA 1ST MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+11,y=ISHATIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}
void IshatimeDigit_2ndmin(int digit)    //// ISHA 2ND MINUTE DIGIT OF THE azan timing
{
     int i,x=azantimingtableside+40+15,y=ISHATIMEUPDOWN;
    switch (digit) {
        case 0:

            szero(x,y);
            break;
        case 1:
            sone(x,y);
            break;
        case 2:
            stwo(x,y);
            break;
        case 3:
            sthree(x,y);
            break;
        case 4:
            sfour(x,y);
            break;
        case 5:
            sfive(x,y);
            break;
        case 6:
            ssix(x,y);
            break;
        case 7:
            sseven(x,y);
            break;
        case 8:
            seight(x,y);
            break;
        case 9:
            snine(x,y);
            break;
    }
}

void displayDigit_1sthour(int digit)    //// 1ST HOUR DIGIT OF THE CLOCK
{
     int i,x=TIMESIDES,y=TIMEUPDOWN;
    switch (digit) {
        case 0:

            zero(x,y);
            break;
        case 1:
            one(x,y);
            break;
        case 2:
            two(x,y);
            break;
        case 3:
            three(x,y);
            break;
        case 4:
            four(x,y);
            break;
        case 5:
            five(x,y);
            break;
        case 6:
            six(x,y);
            break;
        case 7:
            seven(x,y);
            break;
        case 8:
            eight(x,y);
            break;
        case 9:
            nine(x,y);
            break;
    }
}
void displayDigit_2ndhour(int digit)    //// 2ND HOUR DIGIT OF THE CLOCK
{
     int i,x=TIMESIDES+15,y=TIMEUPDOWN;
    switch (digit) {
        case 0:

            zero(x,y);
            break;
        case 1:
            one(x,y);
            break;
        case 2:
            two(x,y);
            break;
        case 3:
            three(x,y);
            break;
        case 4:
            four(x,y);
            break;
        case 5:
            five(x,y);
            break;
        case 6:
            six(x,y);
            break;
        case 7:
            seven(x,y);
            break;
        case 8:
            eight(x,y);
            break;
        case 9:
            nine(x,y);
            break;
    }
}
void displayDigit_1stmin(int digit)    //// 1ST MINUTE DIGIT OF THE CLOCK
{
     int i,x=TIMESIDES+36,y=TIMEUPDOWN;
    switch (digit) {
        case 0:

            zero(x,y);
            break;
        case 1:
            one(x,y);
            break;
        case 2:
            two(x,y);
            break;
        case 3:
            three(x,y);
            break;
        case 4:
            four(x,y);
            break;
        case 5:
            five(x,y);
            break;
        case 6:
            six(x,y);
            break;
        case 7:
            seven(x,y);
            break;
        case 8:
            eight(x,y);
            break;
        case 9:
            nine(x,y);
            break;
    }
}
void displayDigit_2ndmin(int digit)    //// 2ND MINUTE DIGIT OF THE CLOCK
{
     int i,x=TIMESIDES+51,y=TIMEUPDOWN;
    switch (digit) {
        case 0:

            zero(x,y);
            break;
        case 1:
            one(x,y);
            break;
        case 2:
            two(x,y);
            break;
        case 3:
            three(x,y);
            break;
        case 4:
            four(x,y);
            break;
        case 5:
            five(x,y);
            break;
        case 6:
            six(x,y);
            break;
        case 7:
            seven(x,y);
            break;
        case 8:
            eight(x,y);
            break;
        case 9:
            nine(x,y);
            break;
    }
}
void displayDigit_1stsec(int digit)    //// 1ST SECOND DIGIT OF THE CLOCK
{
     int i,x=TIMESIDES+72,y=TIMEUPDOWN;
    switch (digit) {
        case 0:

            zero(x,y);
            break;
        case 1:
            one(x,y);
            break;
        case 2:
            two(x,y);
            break;
        case 3:
            three(x,y);
            break;
        case 4:
            four(x,y);
            break;
        case 5:
            five(x,y);;
            break;
        case 6:
            six(x,y);
            break;
        case 7:
            seven(x,y);
            break;
        case 8:
            eight(x,y);
            break;
        case 9:
            nine(x,y);
            break;
    }
}
void displayDigit_2ndsec(int digit)    //// 2ND SECOND DIGIT OF THE CLOCK
{
     int i,x=TIMESIDES+87,y=TIMEUPDOWN;
    switch (digit) {
        case 0:

            zero(x,y);
            break;
        case 1:
            one(x,y);
            break;
        case 2:
            two(x,y);
            break;
        case 3:
            three(x,y);
            break;
        case 4:
            four(x,y);
            break;
        case 5:
            five(x,y);
            break;
        case 6:
            six(x,y);
            break;
        case 7:
            seven(x,y);
            break;
        case 8:
            eight(x,y);
            break;
        case 9:
            nine(x,y);
            break;
    }
}
void AmPm(int hour)    ////   AM/PM
{
    if (hour >= 12)
    {
        letter_P(TIMESIDES+100,TIMEUPDOWN);
        letter_M(TIMESIDES+105,TIMEUPDOWN);
    }
    else
    {
        letter_A(TIMESIDES+100,TIMEUPDOWN);
        letter_M(TIMESIDES+105,TIMEUPDOWN);
    }
}
void CurrentTime12HoursFormat()    //// 12 HOURS FORMAT
{
    flag=1;
    // Get the current time
    time_t rawTime;
    struct tm *currentTime;
    time(&rawTime);
    currentTime = localtime(&rawTime);
    // Extract hours, minutes, and seconds
     int hours = currentTime->tm_hour;
     int minutes = currentTime->tm_min;
     int seconds = currentTime->tm_sec;
        // Convert hour to 12-hour format
        int displayHour = (hours > 12) ? hours - 12 : hours;
        if(hours==00)
        {
            displayHour = 12;
        }
        displayDigit_1sthour(displayHour / 10);
        displayDigit_2ndhour(displayHour % 10);
        colon(TIMESIDES+30,TIMEUPDOWN);
        displayDigit_1stmin(minutes / 10);
        displayDigit_2ndmin(minutes % 10);
        colon(TIMESIDES+66,TIMEUPDOWN);
        displayDigit_1stsec(seconds / 10);
        displayDigit_2ndsec(seconds % 10);
        AmPm(hours);
        alarm();
}
void CurrentTime24HoursFormat()    //// 24 HOURS FORMAT
{
    flag=1;
    // Get the current time
    time_t rawTime;
    struct tm *currentTime;
    time(&rawTime);
    currentTime = localtime(&rawTime);
    // Extract hours, minutes, and seconds
    int  hours = currentTime->tm_hour;
    int minutes = currentTime->tm_min;
    int seconds = currentTime->tm_sec;
        displayDigit_1sthour(hours / 10);
        displayDigit_2ndhour(hours % 10);
        colon(TIMESIDES+30,TIMEUPDOWN);
        displayDigit_1stmin(minutes / 10);
        displayDigit_2ndmin(minutes % 10);
        colon(TIMESIDES+66,TIMEUPDOWN);
        displayDigit_1stsec(seconds / 10);
        displayDigit_2ndsec(seconds % 10);
        alarm();
}
void TAG()    ////TAGLINE OF THE APP
{
    SetColor(11);
    gotoxy(30,22);
    printf("Time Management Perfected. Azan Clock at Your Service...");
}
void PRESS()    ////PRESS ANY KEY TO CONTINUE
{
    SetColor(10);
    char key;
    usleep(500000);
    gotoxy(30,30);
    printf("Press any key to continue...");
    getch();
}
void MainMenu()    ////MAIN MENU
{
     //int EXIT;

    system("cls");
    int position = 1;
    int keypressed = 0;
    char aboutkey;
    box();
    while(1)
    {
            gotoxy(45,11);arrowhere(1,position);letter_C(60,10);letter_L(64,10);letter_O(68,10);letter_C(72,10);letter_K(76,10);
            gotoxy(45,11+3);arrowhere(2,position); letter_A(60,13);letter_Z(64,13);letter_A(68,13);letter_N(72,13);letter_T(78,13);letter_I(82,13);letter_M(83,13);letter_I(87,13);letter_N(88,13);letter_G(92,13);letter_S(96,13);
            gotoxy(45,11+6);arrowhere(3,position); letter_D(60,16);letter_U(64,16);letter_A(68,16);letter_S(72,16);
            gotoxy(45,11+9);arrowhere(4,position); letter_A(60,19);letter_B(64,19);letter_O(68,19);letter_U(72,19);letter_T(76,19);
            gotoxy(45,11+12); arrowhere(5,position);  letter_E(60,22);letter_X(64,22);letter_I(68,22);letter_T(69,22);
        flag=0;
        alarm();
        if(kbhit())
        {
            keypressed= getch();
            if(keypressed == 13)
            {
                if(position == 1)
                {
                    CurrentTime();
                    break;
                }
               else  if(position == 2)
                {
                    edit_azan();
                    break;
                }
                else  if(position == 3)
                {
                    dua();
                    break;
                }
                else if(position == 4)
                {
                    system("cls");
                    about();
                    break;
                }
                else if(position == 5)
                {
                    system("cls");
                    box();
                    SetColor(11);
                    gotoxy(exitside,exitdown-2);printf("THANKS FOR USING THE APP!!!...");
                    boldletter_G(exitside,exitdown);boldletter_O(exitside+10,exitdown);boldletter_O(exitside+20,exitdown);boldletter_D(exitside+30,exitdown);boldletter_B(exitside+50,exitdown);boldletter_Y(exitside+60,exitdown);boldletter_E(exitside+70,exitdown);
                    exclamation(exitside+80,exitdown);exclamation(exitside+85,exitdown);exclamation(exitside+90,exitdown);
                    SetColor(2);gotoxy(exitside,exitdown+20);printf("PRESS ANY 'KEY' TO EXIT THE CONSOLE...");
                    getch();
                    system("cls");
                    break;
                }

            }
            else if(keypressed == 80 && position != MAXMAIN)
            {
                position++;
            }
            else if(keypressed == 72 && position != MINMAIN)
            {
                position--;
            }
            else
            {
                position = position;

            }
        }


    }
}
void CurrentTime()    ////CURRENT TIME (WITH 12 FORMAT AND 24 FORMAT)
{
    int choose,f=0,i,j;
    system("cls");
    box();
    clockbox();
    while(1)
    {


        CurrentTime24HoursFormat();
        SetColor(38);gotoxy(20,30);printf("Press 'RIGHT SHIFT' to change to 12 hours format");
        SetColor(38);gotoxy(20,32);printf("Press <ESC> to go back");
        if(GetAsyncKeyState(VK_RSHIFT))
        {
            for(i=10;i<=TIMEUPDOWN+11;i++)
            {
                for(j=35;j<=TIMESIDES+15;j++)
                {
                    gotoxy(j,i);printf(" ");
                }
            }
            /*system("cls");
            box();
            clockbox();*/

            while(1)
            {
               CurrentTime12HoursFormat();
               SetColor(38);gotoxy(20,30);printf("Press 'LEFT SHIFT' to change to 24 hours format ");
             //  SetColor(38);gotoxy(20,32);printf("Press <ESC> to go back");
               if(GetAsyncKeyState(VK_LSHIFT))
                {
                    for(i=10;i<=TIMEUPDOWN+11;i++)
                    {
                        for(j=35;j<=TIMESIDES+15;j++)
                        {
                            gotoxy(j,i);printf(" ");
                        }
                    }
                    for(i=10;i<=TIMEUPDOWN+11;i++)
                    {
                        for(j=135;j<=145;j++)
                        {
                            gotoxy(j,i);printf(" ");
                        }
                    }
                  /*  system("cls");
                    box();
                    clockbox();*/
                    break;
                }
                if(GetAsyncKeyState(VK_ESCAPE))
                {
                    system("cls");
                    MainMenu();
                    f++;
                    break;
                }
            }
        }
        if(f>0)
        {
            break;
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            MainMenu();
            break;
        }
    }

}
struct azan_time   ////STRUCTURE FOR FILING
{
    int hour , minute;
};

struct azan_time std[100];

void readfile() ////// READ FILE
{
        int i;
        FILE *fp;
        fp = fopen("digitalclock.txt" ,"r" );
        if(fp==0)
        {
            printf("file unavailable");
            return 0;
        }
        for(i=1 ; i<=6 ; i++)
        {
            fscanf(fp , "%d" ,&std[i].hour );
            fscanf(fp , "%d" ,&std[i].minute );
        }
        fclose(fp);
}

void writefile()     //////WRITE FILE
{
        int i ;
        FILE *fp;
        fp = fopen("digitalclock.txt" , "w");
        for(i=1 ; i<=6 ; i++)
        {
            fprintf(fp , "%d " ,std[i].hour );
            fprintf(fp , "%d\n" ,std[i].minute );
        }
        fclose(fp);
}
void show_azan_menu() //////AZAN TIMING TABLE MENU
{

       // box();
       // headerbox();
        readfile();
        SetColor(12);
            letter_A(azantimingheaderside,azantimingheaderdown+4);letter_Z(azantimingheaderside+4,azantimingheaderdown+4);letter_A(azantimingheaderside+8,azantimingheaderdown+4);letter_N(azantimingheaderside+13,azantimingheaderdown+4);
            letter_T(azantimingheaderside+24,azantimingheaderdown+4);letter_I(azantimingheaderside+29,azantimingheaderdown+4);letter_M(azantimingheaderside+31,azantimingheaderdown+4); letter_I(azantimingheaderside+36,azantimingheaderdown+4);letter_N(azantimingheaderside+38,azantimingheaderdown+4);letter_G(azantimingheaderside+43,azantimingheaderdown+4);letter_S(azantimingheaderside+47,azantimingheaderdown+4);

        SetColor(11);
            letter_F(azantimingtableside,azantimingtabledown);letter_A(azantimingtableside+4,azantimingtabledown);letter_J(azantimingtableside+9,azantimingtabledown);letter_R(azantimingtableside+13,azantimingtabledown);line(azantimingtableside+35,azantimingtabledown);
            FajrtimeDigit_1sthour(std[1].hour / 10);FajrtimeDigit_2ndhour(std[1].hour % 10);FajrtimeDigit_1stmin(std[1].minute / 10);FajrtimeDigit_2ndmin(std[1].minute % 10);

            letter_S(azantimingtableside,azantimingtabledown+4);letter_U(azantimingtableside+5,azantimingtabledown+4);letter_N(azantimingtableside+10,azantimingtabledown+4);letter_R(azantimingtableside+15,azantimingtabledown+4);letter_I(azantimingtableside+20,azantimingtabledown+4);letter_S(azantimingtableside+22,azantimingtabledown+4);letter_E(azantimingtableside+27,azantimingtabledown+4);line(azantimingtableside+35,azantimingtabledown+4);
            SunsettimeDigit_1sthour(std[2].hour / 10);SunsettimeDigit_2ndhour(std[2].hour % 10);SunsettimeDigit_1stmin(std[2].minute / 10);SunsettimeDigit_2ndmin(std[2].minute % 10);

            letter_Z(azantimingtableside,azantimingtabledown+8);letter_U(azantimingtableside+4,azantimingtabledown+8);letter_H(azantimingtableside+9,azantimingtabledown+8);letter_R(azantimingtableside+14,azantimingtabledown+8);line(azantimingtableside+35,azantimingtabledown+8);
            ZuhrtimeDigit_1sthour(std[3].hour / 10);ZuhrtimeDigit_2ndhour(std[3].hour % 10);ZuhrtimeDigit_1stmin(std[3].minute / 10);ZuhrtimeDigit_2ndmin(std[3].minute % 10);

            letter_A(azantimingtableside,azantimingtabledown+12);letter_S(azantimingtableside+5,azantimingtabledown+12);letter_R(azantimingtableside+10,azantimingtabledown+12);line(azantimingtableside+35,azantimingtabledown+12);
            AsrtimeDigit_1sthour(std[4].hour / 10);AsrtimeDigit_2ndhour(std[4].hour % 10);AsrtimeDigit_1stmin(std[4].minute / 10);AsrtimeDigit_2ndmin(std[4].minute % 10);

            letter_M(azantimingtableside,azantimingtabledown+16);letter_A(azantimingtableside+5,azantimingtabledown+16);letter_G(azantimingtableside+10,azantimingtabledown+16);letter_R(azantimingtableside+15,azantimingtabledown+16);letter_I(azantimingtableside+20,azantimingtabledown+16);letter_B(azantimingtableside+22,azantimingtabledown+16);line(azantimingtableside+35,azantimingtabledown+16);
            MagribtimeDigit_1sthour(std[5].hour / 10);MagribtimeDigit_2ndhour(std[5].hour % 10);MagribtimeDigit_1stmin(std[5].minute / 10);MagribtimeDigit_2ndmin(std[5].minute % 10);

            letter_I(azantimingtableside,azantimingtabledown+20);letter_S(azantimingtableside+2,azantimingtabledown+20);letter_H(azantimingtableside+7,azantimingtabledown+20);letter_A(azantimingtableside+12,azantimingtabledown+20);line(azantimingtableside+35,azantimingtabledown+20);
            IshatimeDigit_1sthour(std[6].hour / 10);IshatimeDigit_2ndhour(std[6].hour % 10);IshatimeDigit_1stmin(std[6].minute / 10);IshatimeDigit_2ndmin(std[6].minute % 10);

}
void edit_azan()    //////AZAN EDITING OPTION
{


    box();
    headerbox();
    int position = 1;
    int keypressed = 0;

    while(1)
    {
        flag=2;
        show_azan_menu();
        gotoxy(5,38); arrowhere(1,position); printf("  EDIT AZAN  \n");
        gotoxy(5,40); arrowhere(2,position); printf("  BACK TO MAIN MENU  ");
        alarm();
        if(kbhit())
        {
           keypressed = getch();

            if(keypressed == 13){
                if(position==1)
                {
                    system("cls");
                    Azan_menu();
                    system("cls");
                    box();
                    headerbox();
                }
                else if(position==2)
                {
                    system("cls");
                    MainMenu();
                    break;
                }
            }
            if(keypressed == 80 && position != 2)
            {
                position++;
            }
            else if(keypressed == 72 && position != 1)
            {
                position--;
            }
            else
            {
                position = position;
            }
        }

    }
}

 ///function for Azan timings===============================================
char arrow1=205 , arrow2=16 , diamond=4 , acolon=':';
void Azan_menu()     /////// AZAN EDITING MENU
{
        headerbox();
        int i , newhour , newminute;
        box();
        int position = 1;
        int keypressed = 0;
        headerbox();

        while (1)
        {
            SetColor(12);
            letter_A(azantimingheaderside,azantimingheaderdown+4);letter_Z(azantimingheaderside+4,azantimingheaderdown+4);letter_A(azantimingheaderside+8,azantimingheaderdown+4);letter_N(azantimingheaderside+13,azantimingheaderdown+4);
            letter_T(azantimingheaderside+25,azantimingheaderdown+4);letter_I(azantimingheaderside+30,azantimingheaderdown+4);letter_M(azantimingheaderside+32,azantimingheaderdown+4); letter_I(azantimingheaderside+37,azantimingheaderdown+4);letter_N(azantimingheaderside+39,azantimingheaderdown+4);letter_G(azantimingheaderside+44,azantimingheaderdown+4);letter_S(azantimingheaderside+48,azantimingheaderdown+4);

            readfile();

            removeeditbox();
            gotoxy(120,25);SetColor(4); printf("                                             ");
            gotoxy(120,26);SetColor(4); printf("                                     ");


            gotoxy(28,11);  arrowhere(1,position);
            letter_F(azantimingtableside,azantimingtabledown);letter_A(azantimingtableside+4,azantimingtabledown);letter_J(azantimingtableside+9,azantimingtabledown);letter_R(azantimingtableside+13,azantimingtabledown);line(azantimingtableside+35,azantimingtabledown);
            FajrtimeDigit_1sthour(std[1].hour / 10);FajrtimeDigit_2ndhour(std[1].hour % 10);FajrtimeDigit_1stmin(std[1].minute / 10);FajrtimeDigit_2ndmin(std[1].minute % 10);

            gotoxy(28,11+4);  arrowhere(2,position);
            letter_S(azantimingtableside,azantimingtabledown+4);letter_U(azantimingtableside+5,azantimingtabledown+4);letter_N(azantimingtableside+10,azantimingtabledown+4);letter_R(azantimingtableside+15,azantimingtabledown+4);letter_I(azantimingtableside+20,azantimingtabledown+4);letter_S(azantimingtableside+22,azantimingtabledown+4);letter_E(azantimingtableside+27,azantimingtabledown+4);line(azantimingtableside+35,azantimingtabledown+4);
            SunsettimeDigit_1sthour(std[2].hour / 10);SunsettimeDigit_2ndhour(std[2].hour % 10);SunsettimeDigit_1stmin(std[2].minute / 10);SunsettimeDigit_2ndmin(std[2].minute % 10);

            gotoxy(28,11+8);  arrowhere(3,position);
            letter_Z(azantimingtableside,azantimingtabledown+8);letter_U(azantimingtableside+4,azantimingtabledown+8);letter_H(azantimingtableside+9,azantimingtabledown+8);letter_R(azantimingtableside+14,azantimingtabledown+8);line(azantimingtableside+35,azantimingtabledown+8);
            ZuhrtimeDigit_1sthour(std[3].hour / 10);ZuhrtimeDigit_2ndhour(std[3].hour % 10);ZuhrtimeDigit_1stmin(std[3].minute / 10);ZuhrtimeDigit_2ndmin(std[3].minute % 10);

            gotoxy(28,11+12);  arrowhere(4,position);
            letter_A(azantimingtableside,azantimingtabledown+12);letter_S(azantimingtableside+5,azantimingtabledown+12);letter_R(azantimingtableside+10,azantimingtabledown+12);line(azantimingtableside+35,azantimingtabledown+12);
            AsrtimeDigit_1sthour(std[4].hour / 10);AsrtimeDigit_2ndhour(std[4].hour % 10);AsrtimeDigit_1stmin(std[4].minute / 10);AsrtimeDigit_2ndmin(std[4].minute % 10);

            gotoxy(28,11+16);  arrowhere(5,position);
            letter_M(azantimingtableside,azantimingtabledown+16);letter_A(azantimingtableside+5,azantimingtabledown+16);letter_G(azantimingtableside+10,azantimingtabledown+16);letter_R(azantimingtableside+15,azantimingtabledown+16);letter_I(azantimingtableside+20,azantimingtabledown+16);letter_B(azantimingtableside+22,azantimingtabledown+16);line(azantimingtableside+35,azantimingtabledown+16);
            MagribtimeDigit_1sthour(std[5].hour / 10);MagribtimeDigit_2ndhour(std[5].hour % 10);MagribtimeDigit_1stmin(std[5].minute / 10);MagribtimeDigit_2ndmin(std[5].minute % 10);

            gotoxy(28,11+20);  arrowhere(6,position);
            letter_I(azantimingtableside,azantimingtabledown+20);letter_S(azantimingtableside+2,azantimingtabledown+20);letter_H(azantimingtableside+7,azantimingtabledown+20);letter_A(azantimingtableside+12,azantimingtabledown+20);line(azantimingtableside+35,azantimingtabledown+20);
            IshatimeDigit_1sthour(std[6].hour / 10);IshatimeDigit_2ndhour(std[6].hour % 10);IshatimeDigit_1stmin(std[6].minute / 10);IshatimeDigit_2ndmin(std[6].minute % 10);

            gotoxy(40,11+26); arrowhere(7,position); printf("      %c <BACK  %c     \n" , diamond, diamond);
            flag=2;
            alarm();
            if(kbhit())
            {
               keypressed= getch();

                if(keypressed==13)
                {
                    if(position==7)
                    {
                        show_azan_menu();
                        break;
                    }
                    editbox();
                    gotoxy(120,20);SetColor(3);printf("     SET PRAYER TIME ");gotoxy(120,21);printf(" ( IN 24 HOURS FORMAT ) ");
                    gotoxy(125,23);SetColor(3); printf("Hr:  "); SetColor(36);gotoxy(129,23); scanf("%d" , &newhour );
                    gotoxy(134,23);SetColor(3); printf("Min: "); SetColor(36);gotoxy(139,23); scanf("%d", &newminute);
                    gotoxy(120,25);SetColor(4); printf("UPDATING....!");



                    if(newhour>=0 && newhour<=23 && newminute>=0 && newminute<=59)
                    {
                        sleep(0);
                        removeeditbox();
                        gotoxy(120,20);printf("                      ");gotoxy(120,21);printf("                      ");
                        gotoxy(125,23);SetColor(3); printf("                      ");
                        gotoxy(134,23);SetColor(3); printf("                      ");
                        sleep(1);
                        gotoxy(120,25);SetColor(4); printf("            ");
                        gotoxy(120,25);SetColor(4); printf("UPDATED!     ");
                        sleep(1);
                        gotoxy(120,25);SetColor(4); printf("            ");
                        for(i=1 ; i<=6 ; i++)
                        {
                            if(i==position)
                            {
                                std[i].hour = newhour;
                                std[i].minute = newminute;
                            }
                        }
                        writefile();
                    }
                    else
                    {
                        gotoxy(120,25);SetColor(4); printf("INVALID INPUT!!!...");
                        gotoxy(120,26);SetColor(4); printf("CHOOSE AZAN AND TAKE INPUT AGAIN.");
                        sleep(2);
                    }
                }

                else if(keypressed == 80 && position != MAXAZAN)
                {
                    position++;
                }
                else if(keypressed == 72 && position != MINAZAN)
                {
                    position--;
                }
                else
                {
                    position = position;
                }
            }

        }
}
void alarm()    ///// ALARM
{
    // Get the current time
    time_t rawTime;
    struct tm *currentTime;
    time(&rawTime);
    currentTime = localtime(&rawTime);
    // Extract hours, minutes, and seconds
     int hours = currentTime->tm_hour;
     int minutes = currentTime->tm_min;
     int seconds = currentTime->tm_sec;

    readfile();
    if((std[1].hour==hours)&&(std[1].minute==minutes)&&(seconds<1))   //////FAJR ALARM
    {
        system("cls");
        box();
        SetColor(14);
        boldletter_F(alarmdisplayside,alarmdisplaydown);boldletter_A(alarmdisplayside+10,alarmdisplaydown);boldletter_J(alarmdisplayside+20,alarmdisplaydown);boldletter_R(alarmdisplayside+30,alarmdisplaydown);
        SetColor(11);gotoxy(65,21);printf("LETS PRAY!!!");
        SetColor(10);gotoxy(56,30);printf("(PRESS %cSPACE%c TO STOP AZAN)",34,34);
        speaker(103,8);
        PlaySound(TEXT("AZAN.wav"),NULL,SND_ASYNC);
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                PlaySound(NULL, NULL, 0);
                system("cls");
                box();
                if(flag==1)
                {
                  clockbox();
                }
                if(flag==2)
                {
                  headerbox();
                }
                if(flag==3)
                {
                    PlaySound(NULL, NULL, 0);
                    about();
                    flag=4;
                }


                break;
            }
        }
    }
    if((std[3].hour==hours)&&(std[3].minute==minutes)&&(seconds<1))    /////ZUHR ALARM
    {
        system("cls");
        box();
        SetColor(14);
        boldletter_Z(alarmdisplayside,alarmdisplaydown);boldletter_U(alarmdisplayside+7,alarmdisplaydown);boldletter_H(alarmdisplayside+17,alarmdisplaydown);boldletter_R(alarmdisplayside+27,alarmdisplaydown);
        SetColor(11);gotoxy(65,21);printf("LETS PRAY!!!");
        SetColor(10);gotoxy(56,30);printf("(PRESS %cSPACE%c TO STOP AZAN)",34,34);
        speaker(100,8);
        PlaySound(TEXT("AZAN.wav"),NULL,SND_ASYNC);
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                PlaySound(NULL, NULL, 0);
                system("cls");
                box();
                if(flag==1)
                {
                  clockbox();
                }
                if(flag==2)
                {
                  headerbox();
                }
                if(flag==3)
                {
                    PlaySound(NULL, NULL, 0);
                    about();
                    flag=4;
                }

                break;
            }
        }
    }
    if((std[4].hour==hours)&&(std[4].minute==minutes)&&(seconds<1))    /////ASR ALARM
    {
        system("cls");
        box();
        SetColor(14);
        boldletter_A(alarmdisplayside,alarmdisplaydown);boldletter_S(alarmdisplayside+10,alarmdisplaydown);boldletter_R(alarmdisplayside+19,alarmdisplaydown);//boldletter_R(alarmdisplayside+27,alarmdisplaydown);
        SetColor(11);gotoxy(65,21);printf("LETS PRAY!!!");
        SetColor(10);gotoxy(56,30);printf("(PRESS %cSPACE%c TO STOP AZAN)",34,34);
        speaker(92,8);
        PlaySound(TEXT("AZAN.wav"),NULL,SND_ASYNC);
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                PlaySound(NULL, NULL, 0);
                system("cls");
                box();
                if(flag==1)
                {
                  clockbox();
                }
                if(flag==2)
                {
                  headerbox();
                }
                if(flag==3)
                {
                    PlaySound(NULL, NULL, 0);
                    about();
                    flag=4;
                }

                break;
            }
        }
    }
    if((std[5].hour==hours)&&(std[5].minute==minutes)&&(seconds<1))    /////MAGRIB ALARM
    {
        system("cls");
        box();
        SetColor(14);
        boldletter_M(alarmdisplayside,alarmdisplaydown);boldletter_A(alarmdisplayside+11,alarmdisplaydown);boldletter_G(alarmdisplayside+21,alarmdisplaydown);boldletter_R(alarmdisplayside+31,alarmdisplaydown);boldletter_I(alarmdisplayside+40,alarmdisplaydown);boldletter_B(alarmdisplayside+49,alarmdisplaydown);
        SetColor(11);gotoxy(58,21);printf("LETS PRAY!!!");
        SetColor(10);gotoxy(56,30);printf("(PRESS %cSPACE%c TO STOP AZAN)",34,34);
        speaker(115,8);
        PlaySound(TEXT("AZAN.wav"),NULL,SND_ASYNC);
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                PlaySound(NULL, NULL, 0);
                system("cls");
                box();
                if(flag==1)
                {
                  clockbox();
                }
                if(flag==2)
                {
                  headerbox();
                }
                if(flag==3)
                {
                    PlaySound(NULL, NULL, 0);
                    about();
                    flag=4;
                }

                break;
            }
        }
    }
    if((std[6].hour==hours)&&(std[6].minute==minutes)&&(seconds<1))    /////ISHA ALARM
    {
        system("cls");
        box();
        SetColor(14);
        boldletter_I(alarmdisplayside,alarmdisplaydown);boldletter_S(alarmdisplayside+9,alarmdisplaydown);boldletter_H(alarmdisplayside+18,alarmdisplaydown);boldletter_A(alarmdisplayside+28,alarmdisplaydown);
        SetColor(11);gotoxy(65,21);printf("LETS PRAY!!!");
        SetColor(10);gotoxy(56,30);printf("(PRESS %cSPACE%c TO STOP AZAN)",34,34);
        speaker(103,8);
        PlaySound(TEXT("AZAN.wav"),NULL,SND_ASYNC);
        while(1)
        {
            if(GetAsyncKeyState(VK_SPACE))
            {
                PlaySound(NULL, NULL, 0);
                system("cls");
                box();
                if(flag==1)
                {
                  clockbox();
                }
                if(flag==2)
                {
                  headerbox();
                }
                if(flag==3)
                {
                    PlaySound(NULL, NULL, 0);
                    about();
                    flag=4;
                }

                break;
            }
        }
    }
}
void dua()          /////DUA MENU
{
 system("cls");
    int position = 1;
    int keypressed = 0;
    char aboutkey;
    box();
    headerbox2();
    while(1)
    {
                                                      SetColor(12);  letter_D(67,4);letter_U(71,4);letter_A(75,4);letter_S(79,4);
            gotoxy(40,11+2);arrowhere(1,position); letter_D(50,12);letter_U(54,12);letter_A(58,12);letter_O(65,12);letter_F(69,12);letter_A(76,12);letter_Z(80,12);letter_A(84,12);letter_N(88,12);
            gotoxy(40,11+6);arrowhere(2,position); letter_D(50,16);letter_U(54,16);letter_A(58,16);letter_F(65,16);letter_O(69,16);letter_R(73,16);letter_F(80,16);letter_O(84,16);letter_R(88,16);letter_G(92,16);letter_I(96,16);letter_V(98,16);letter_E(102,16);letter_N(106,16);letter_E(110,16);letter_S(114,16);letter_S(118,16);
            gotoxy(40,11+10);arrowhere(3,position); letter_D(50,20);letter_U(54,20);letter_A(58,20);letter_F(65,20);letter_O(69,20);letter_R(73,20);letter_G(80,20);letter_U(84,20);letter_I(88,20);letter_D(90,20);letter_A(94,20);letter_N(98,20);letter_C(102,20);letter_E(106,20);
            gotoxy(40,11+14); arrowhere(4,position); letter_A(50,24);letter_Y(54,24);letter_A(58,24);letter_T(62,24);letter_A(69,24);letter_L(73,24);letter_K(80,24);letter_U(83,24);letter_R(87,24);letter_S(91,24);letter_I(95,24);
            gotoxy(8,11+26); arrowhere(5,position); gotoxy(17,37); printf("<< BACK");
        flag=0;
        alarm();
        if(kbhit())
        {
            keypressed= getch();
            if(keypressed == 13)
            {
                if(position == 1)
                {
                    DuaOfAzan();
                    headerbox2();
                }
                else  if(position == 2)
                {
                    DuaForForgiveness();
                    headerbox2();
                }
                else  if(position == 3)
                {
                    DuaForGuidance();
                    headerbox2();
                }
                else if(position == 4)
                {
                   AyatAlKursi();
                   headerbox2();
                }
                 if(position == 5)
                {
                    system("cls");
                    MainMenu();
                    break;
                }

            }
            else if(keypressed == 80 && position != MAXDUA)
            {
                position++;
            }
            else if(keypressed == 72 && position != MINDUA)
            {
                position--;
            }
            else
            {
                position = position;

            }
        }


    }


}
void DuaOfAzan()      ////DUA OF AZAN
{
    hidecursor();
    system("cls");
    box();
    SetColor(6);
    letter_D(DUASIDE,DUAUP);letter_U(DUASIDE+4,DUAUP);letter_A(DUASIDE+9,DUAUP);
    letter_O(DUASIDE+16,DUAUP);letter_F(DUASIDE+21,DUAUP);
    letter_A(DUASIDE+27,DUAUP);letter_Z(DUASIDE+31,DUAUP);letter_A(DUASIDE+35,DUAUP);letter_N(DUASIDE+40,DUAUP);
    SetColor(6);gotoxy(25,13);printf("TRANSLITERATION:");
    SetColor(14);
    gotoxy(25,15);printf("     Allahumma Rabba hadhihi-ddawatit-tammah, was-salatil qa%cimah,",39);
    gotoxy(25,17);printf("     ati Muhammadan al-wasilata wal-fadilah, wa bath-hu maqaman mahmudan-il-ladhi wa%cadtahu",39);
    SetColor(6);gotoxy(24,20);printf("MEANING:");
    SetColor(14);
    gotoxy(25,22);printf("     O Allah! Lord of this perfect call (perfect by not ascribing partners to You) and of the regular ");
    gotoxy(25,24);printf("     prayer which is going to be established, give Muhammad the right of intercession and illustriousness ");
    gotoxy(25,26);printf("     and resurrect him to the best and the highest place in Paradise that You promised him (of).");
    SetColor(66);
    gotoxy(63,35);printf("(PRESS 'ESCAPE' TO GO BACK...)");
    PlaySound(TEXT("DUA OF AZAN.wav"),NULL,SND_ASYNC);
    while(1)
    {
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            PlaySound(NULL, NULL, 0);
            system("cls");
            box();

            break;
        }
    }
}
void DuaForForgiveness()     //// DUA FOR FORGIVENESS
{
    hidecursor();
    box();
    SetColor(6);
    letter_D(DUASIDE1,DUAUP1);letter_U(DUASIDE1+4,DUAUP1);letter_A(DUASIDE1+9,DUAUP1);
    letter_F(DUASIDE1+16,DUAUP1);letter_O(DUASIDE1+20,DUAUP1);letter_R(DUASIDE1+25,DUAUP1);
    letter_F(DUASIDE1+32,DUAUP1);letter_O(DUASIDE1+36,DUAUP1);letter_R(DUASIDE1+41,DUAUP1);
    letter_G(DUASIDE1+46,DUAUP1);letter_I(DUASIDE1+51,DUAUP1);letter_V(DUASIDE1+53,DUAUP1);letter_E(DUASIDE1+58,DUAUP1);
    letter_N(DUASIDE1+62,DUAUP1);letter_E(DUASIDE1+67,DUAUP1);letter_S(DUASIDE1+71,DUAUP1);letter_S(DUASIDE1+75,DUAUP1);
    SetColor(6); gotoxy(25,11);printf("TRANSLITERATION:");
    SetColor(14);
    gotoxy(25,13);printf("     Allahumma anta Rabbii laa ilaaha illaa anta, Khalaq-tanii wa ana %cAbduka,",39);
    gotoxy(25,15);printf("     wa ana a%cla a%chdika wa wa%cdika mastata%ctu, a%cudhu bika min sharri maa sana%ctu,",39,39,39,39,39,39);
    gotoxy(25,17);printf("     abuo-u laka bini%cmatika a%claiya, wa abuo-u laka bidhanbii faghfirli, " , 39,39);
    gotoxy(25,19);printf("     fa innahuo laa yaghfiru-dhunouba illaa anta.");
    SetColor(6);gotoxy(25,22);printf("MEANING:");
    SetColor(14);
    gotoxy(25,24);printf("     O Allah, you are my Lord. There is no god but You. You created me. And I am your servant.");
    gotoxy(25,26);printf("     And I stand by your covenant and promise. I seek refuge in You, according to my power, ");
    gotoxy(25,28);printf("     from my iniquities. And I confess your blessings and confess my sins. So forgive me my sins.");
    gotoxy(25,30);printf("     and resurrect him to the best and the highest place in Paradise that You promised him (of).");
    SetColor(66);gotoxy(63,35);printf("(PRESS 'ESCAPE' TO GO BACK...)");
    PlaySound(TEXT("DUA FOR FORGIVENESS.wav"),NULL,SND_ASYNC);
    while(1)
    {
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            PlaySound(NULL, NULL, 0);
            system("cls");
            box();

            break;
        }
    }
}
void DuaForGuidance()        //// DUA FOR GUIDANCE
{
    hidecursor();
    box();
    SetColor(6);
    letter_D(DUASIDE2,DUAUP2);letter_U(DUASIDE2+4,DUAUP2);letter_A(DUASIDE2+9,DUAUP2);
    letter_F(DUASIDE2+16,DUAUP2);letter_O(DUASIDE2+20,DUAUP2);letter_R(DUASIDE2+25,DUAUP2);
    letter_G(DUASIDE2+32,DUAUP2);letter_U(DUASIDE2+37,DUAUP2);letter_I(DUASIDE2+42,DUAUP2);letter_D(DUASIDE2+44,DUAUP2);
    letter_A(DUASIDE2+48,DUAUP2);letter_N(DUASIDE2+53,DUAUP2);letter_C(DUASIDE2+58,DUAUP2);letter_E(DUASIDE2+62,DUAUP2);
    SetColor(6);gotoxy(25,16);printf("TRANSLITERATION:");
    SetColor(14);
    gotoxy(25,18);printf("    ALLAHUMMA INNI AS%cALUKAL%cHUDA, WAT%cTUQA, WAL%c%cAFAFA, WAL%cGHINA" , 39,45,45,45,39,45);
    SetColor(6);gotoxy(25,20);printf("MEANING:");
    SetColor(14);
    gotoxy(25,22);printf("    O' ALLAH! I BESEECH YOU FOR GUIDANCE, PIETY, CHASTITY AND CONTENTMENT.");
    SetColor(66);gotoxy(63,35);printf("(PRESS 'ESCAPE' TO GO BACK...)");
    PlaySound(TEXT("DUA FOR GUIDANCE.wav"),NULL,SND_ASYNC);
    while(1)
    {
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            PlaySound(NULL, NULL, 0);
            system("cls");
            box();

            break;
        }
    }
}
void AyatAlKursi()     /////AYAT AL KURSI
{
    MaximizeOutputWindow();
    hidecursor();
    system("cls");
    box();
    SetColor(6);
    letter_A(DUASIDE3,DUAUP3);letter_Y(DUASIDE3+5,DUAUP3);letter_A(DUASIDE3+9,DUAUP3);letter_T(DUASIDE3+13,DUAUP3);
    letter_A(DUASIDE3+20,DUAUP3);letter_L(DUASIDE3+25,DUAUP3);
    letter_K(DUASIDE3+31,DUAUP3);letter_U(DUASIDE3+34,DUAUP3);letter_R(DUASIDE3+39,DUAUP3);letter_S(DUASIDE3+44,DUAUP3);letter_I(DUASIDE3+49,DUAUP3);
    SetColor(6);gotoxy(25,6);printf("TRANSLITERATION:");
    SetColor(14);
    gotoxy(25,8);printf("     Allahu laaa ilaaha illaa huwal haiyul qai-yoom ");
    gotoxy(25,10);printf("     laa taakhuzuhoo sinatunw wa laa nawm; lahoo maa fissamaawaati wa maa fil ard ");
    gotoxy(25,12);printf("     man zallazee yashfa%cu indahooo illaa be iznih",39);
    gotoxy(25,14);printf("     ya%clamu maa baina aideehim wa maa khalfahum",39);
    gotoxy(25,16);printf("     wa laa yuheetoona beshai %cimmin %cilmihee illa be maa shaaa%ca",39,39,39);
    gotoxy(25,18);printf("     wasi%ca kursiyyuhus samaa waati wal arda wa la ya%cooduho hifzuhumaa",39,39);
    gotoxy(25,20);printf("     wa huwal aliyyul %cazeem %c",39,127);
    SetColor(6);gotoxy(25,23);printf("MEANING:");
    SetColor(14);
    gotoxy(25,25);printf("     Allah - there is no deity except Him, the Ever-Living, the Sustainer of [all] existence.");
    gotoxy(25,27);printf("     Neither drowsiness overtakes Him nor sleep; To Him belongs whatever is in the heavens and whatever is on the earth.");
    gotoxy(25,29);printf("     Who is it that can intercede with Him except by His permission?");
    gotoxy(25,31);printf("     He knows what is [presently] before them and what will be after them,");
    gotoxy(25,33);printf("     and they encompass not a thing of His knowledge except for what He wills.");
    gotoxy(25,35);printf("     His Kursi(chair) extends over the heavens and the earth, and their preservation tires Him not.");
    gotoxy(25,37);printf("     And He is the Most High, the Most Great.");
    SetColor(66);gotoxy(63,40);printf("(PRESS 'ESCAPE' TO GO BACK...)");
    PlaySound(TEXT("AYAT UL KURSI.wav"),NULL,SND_ASYNC);
    while(1)
    {
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            PlaySound(NULL, NULL, 0);
            system("cls");
            box();

            break;
        }
    }
}
void about()    /////ABOUT THE APP AND DEVELOPERS
{
    aboutbox();
    char gem = 4 , smile = 1;
    int side=55,down=2;

    gotoxy(10,11); SetColor(11);printf("The basic program was built using C programming language. It is a console based application.");
    gotoxy(10,11+2); SetColor(12);printf("The 3 main features are:");
    gotoxy(13,14+2); SetColor(4); printf("1.");SetColor(7); gotoxy(15,14+2); printf(" CLOCK:          It will diplay the default time of the user's system in digits.");
    gotoxy(13,15+2); SetColor(4); printf("2.");SetColor(7); gotoxy(15,15+2); printf(" AZAN TIMINGS:   The user can set the time for Azan and an alarm of azan will play according to the Azan Timing Table.");
    gotoxy(13,15+3); SetColor(4); printf("3.");SetColor(7); gotoxy(15,15+3); printf(" DU'AS:          The following menu contains few important du'as. The user will be able to listen to an audio of the selected dua and read it as well.");
    gotoxy(10,17+4); SetColor(11); printf("Exceptional feature:");SetColor(7); printf("  When the clock time hits the specific time for Azan , the program begins to call for the prayer as well as ");
    gotoxy(32,20+2); printf("display the specific prayer name."); SetColor(22); printf(" (except for sunrise)"); SetColor(7);
    gotoxy(10,21+5); SetColor(10); printf("DEVELOPED BY:");
    gotoxy(15,26+2); SetColor(14); printf("%c" , gem); SetColor(7); printf("  NAME:"); printf("                Adnan Shamim");
    gotoxy(18,28+2); printf("ORGANIZATION:"); printf("        INTERNATIONAL ISLAMIC UNIVERSITY CHITTAGONG (IIUC)");
    gotoxy(18,30+2); printf("METRIC ID:");    printf("           C231118");
    gotoxy(15,32+2); SetColor(14); printf("%c" , gem); SetColor(7); printf("  NAME:"); printf("                Mohammed Abdullah");
    gotoxy(18,34+2); printf("ORGANIZATION:"); printf("        INTERNATIONAL ISLAMIC UNIVERSITY CHITTAGONG (IIUC)");
    gotoxy(18,36+2); printf("METRIC ID:");    printf("           C231097");
    gotoxy(15,38+2); SetColor(14); printf("%c" , gem); SetColor(7); printf("  NAME:"); printf("                Rohit Barua");
    gotoxy(18,40+2); printf("ORGANIZATION:"); printf("        INTERNATIONAL ISLAMIC UNIVERSITY CHITTAGONG (IIUC)");
    gotoxy(18,42+2); printf("METRIC ID:");    printf("           C231120");

    gotoxy(10,50+4); SetColor(15); printf("Created on:  20th of May 2023.");
    gotoxy(10,54+3); printf("This is our first program which was mainly built for our 1st semester%cs university project.", 39);
    gotoxy(10,57+2); printf("Hope you all appreciate it.");
    gotoxy(10,59+2); printf("REGARDS %c" , smile);
    gotoxy(56,62+2); SetColor(10); printf("(PRESS %cESC%c TO GO BACK)", 34,34);
    gotoxy(35,64+2); SetColor(14); printf("--------------------------------XXX--------------------------");
    boldletter_A(side,down);boldletter_B(side+10,down);boldletter_O(side+20,down);boldletter_U(side+30,down);boldletter_T(side+40,down);
    gotoxy(10,0);SetColor(9);printf("%c", 196);
    while(1)
    {
        flag=3;
        alarm();
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            MainMenu();
            break;
        }
        if(flag==4)
        {
            break;
        }
    }
}

int main()  /////START OF THE PROGRAM
{
    MaximizeOutputWindow();
    hidecursor();
    box();
    A();Z();A2();N();  C();L();O();C2();K();
    TAG();
    PRESS();

    MainMenu();
    return 0;
}
