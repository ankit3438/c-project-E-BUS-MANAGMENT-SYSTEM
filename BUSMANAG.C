#include<stdio.h>
#include<conio.h>
#include<string.h>
#define go(r,c) gotoxy(c,r)
#include<time.h>
#include<dos.h>
//declaration of built functions:-
void login();//****************completed*****************
void mainmenu();//***************completed*****************
void recordm();//*****************completed*****************
void addrecord1();//*****************completed***************
void addrecord2();//*****************completed***************
void updaterecord();//****************completed***************
void viewrecord();//******************completed***************
void viewbus();//********************completed******************
void viewdriver();//******************completed*********************
void updatebus();  //******************completed*********************
void updatedriver();//********************competed*********************
void previous();//***********************completed***********************
void rupdate();//********************completed*************************
void check();//***********************completed***********************
void searchroute();//********************completed************************
void registerroute();//*********************completed***********************
void viewroute();//***************************completed*********************
void specificroute();//*********************completed***********************
void fares();//******************************completed**********************
// making structure*****************************************************
struct bus
{
char busno[22],from[51],to[51],d[20],time[22],date[22];
};
struct bus b;
struct driver
{
char name[22],busno[22],date[24],age[6];
};
struct driver dri;
struct routes
{
char from[51],to[51],fare[22];
};
struct routes rut;
FILE *fp;
//functions usd for creating border:-
//********************************************************************
void line1(int r,int c1,int c2)
{
int i;
go(r,c1);
for(i=c1;i<=c2;i++)
{
go(r,i);printf("-");
}
}
void line2(int r1,int r2,int c)
{
int i;
go(r1,c);
for(i=r1;i<=r2;i++)
{
go(i,c);printf("||");
}
}
void line2c(int r1,int r2,int c)
{
int i;
go(r1,c);
for(i=r1;i<=r2;i++)
{
go(i,c);printf("|");
}
}
//*******************************************************************
//function for making color box:-(for blue only)
void colorbox(int size)
{
int i;
textbackground(BLUE);
for(i=1;i<=size;i++){cprintf(" ");}
textbackground(BLACK);
}
//function for making color box:-(for any color)
void colorbox1(int size,int color)
{
int i;
textbackground(color);
for(i=1;i<=size;i++){cprintf(" ");}
textbackground(BLACK);
}
//center the string******************************************************
void center(char *str, int row, int color)
{
int c=40-strlen(str)/2;
go(row,c);
textcolor(color);
cprintf("%s",str);
textcolor(WHITE);
}
//***********************************************************************
void mytime(char *t)
{
   time_t timer;
   struct tm *tblock;

   /* gets time of day */
   timer = time(NULL);

   /* converts date/time to a structure */
   tblock = localtime(&timer);

  // printf("Local time is: %s", asctime(tblock));
    sprintf(t,"%2d:%2d:%2d",tblock->tm_hour,tblock->tm_min,tblock->tm_sec);
}
//***************************************************************************
void startpage()
{
char c;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("E-BUS MANAGMENT SYSTEM",5,YELLOW);
line1(10,15,25);
line1(10,56,66);
line1(18,15,25);
line1(18,56,66);
line2c(11,17,15);
line2c(11,17,66);
center("--------DEVELOPED BY--------",11,GREEN);
center("BROGRAMMERS PVT LTD (since 2021)",12,GREEN);
center("This application was build for social use only",13,GREEN);
center("& absolutely free for everyone who want to use",14,GREEN);
center("copyright(c) 2021 by BROGRAMMERS PVT ltd.",16,CYAN);
center("All right reserved",17,CYAN);
go(23,16); colorbox(51);
go(23,16); printf("--------------press ENTER for continue-------------");
c=getch();
if(c==13){ login(); }
}
//**********************************************************************
void login()
{
char userid[20],password[20],ch;
int i=0;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("E-BUS MANAGMENT SYSTEM",5,YELLOW);
go(20,16);colorbox1(51,RED);
go(9,22);printf("USER ID");go(9,35);printf(":");go(9,42);colorbox(20);
go(11,22);printf("PASSWORD");go(11,35);printf(":");go(11,42);colorbox(20);
go(20,33);textcolor(YELLOW);printf("enter USER NAME");textcolor(WHITE);
go(9,42);gets(userid);
go(20,33);textcolor(YELLOW);printf("enter the PASSWORD");textcolor(WHITE);
go(11,42);
while(i<20)
{
ch=getch();
if(ch==13){break;}
else if(ch==8)
{
if(i>0)
{
int n;
i--;
go(11,42);for(n=0;n<=i;n++){putchar('*');}
go(11,42);
}
}
else
{
password[i]=ch;
putchar('*');
i++;
}
}
password[i]='\0';
if(strcmp(userid,"admin")==0 && strcmp(password,"123456")==0)
{
//main menu page
mainmenu();
}
else
{
char a;
center("**USER ID AND PASSWORD NOT MATCHED :(",13,LIGHTGREEN+BLINK);
go(20,30);textcolor(YELLOW);printf("press t/q for try/quit");textcolor(WHITE);
go(19,30);printf("enter your choice:-");
a=getch();
if(a=='t'){login();}
else if(a=='q'){exit(0);}
}
}
//***********************************************************************
void mainmenu()
{
char ch;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO MAIN MENU",5,YELLOW);
go(21,16);colorbox1(51,RED);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
line2c(8,19,15);line2c(8,19,66);
center("* * * RECORD MANAGEMENT * * *",8,LIGHTMAGENTA);
center("* * * CHECK AVAILABLITY * * *",10,LIGHTCYAN);
center("* * * SEARCH ROUTES * * *",12,LIGHTGREEN);
center("* * * FARES * * *",14,LIGHTBLUE);
center("* * * VIEW RECORD * * *",16,MAGENTA);
center("* * * QUIT * * *",18,LIGHTGRAY+BLINK);
go(21,20);printf("enter the choice by pressing (R/C/S/F/V/Q)");
ch=getch();
if(ch==13){mainmenu();}
switch (ch)
{
case 'r':{recordm();break;}
case 'c':{check();break;}
case 's':{searchroute();break;}
case 'f':{fares();break;}
case 'v':{viewrecord();break;}
case 'q':{exit(0);}
default :{mainmenu();break;}
}
}
//*********************************************************************
void recordm()
{
char ch;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO RECORD MANAGEMENT",5,YELLOW);
go(21,16);colorbox1(51,RED);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
line2c(8,19,15);line2c(8,19,66);
center("* * * ADD NEW RECORD (BUS) * * *",9,LIGHTBLUE);
center("* * * ADD NEW RECORD (DRIVER'S) * * *",12,LIGHTGREEN);
center("* * * UPDATE PREVIOUS RECORD * * *",15,LIGHTRED);
center("* * * RETURN TO MAIN MENU * * *",18,LIGHTGRAY+BLINK);
go(21,21);printf("***Press (A/D/U/M) for following options***");
ch=getch();
switch(ch)
{
case 'a':{addrecord1(); break;}
case 'd':{addrecord2(); break;}
case 'u':{updaterecord(); break;}
case 'm':{mainmenu();break;}
default :{recordm();break;}
}
}
//************************************************************************
void addrecord1()
{
char ch,a,v;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO ADD NEW RECORD (BUS)",5,YELLOW);
go(21,16);colorbox1(51,RED);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
line2c(8,19,15);line2c(8,19,66);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\mainrecord.dat","rb+");
if(fp==NULL){fp=fopen("C:\\TURBOC3\\BIN\\bus\\mainrecord.dat","wb+");}
go(9,22);printf("Enter Bus no.");go(9,37);printf(":");go(9,42);colorbox(21);
go(11,22);printf("Enter route ");go(11,37);printf(":");go(11,42);colorbox(21);
go(12,51);textcolor(YELLOW+BLINK);cprintf("TO");textcolor(WHITE);
go(13,42);colorbox(21);
go(15,22);printf("DEPART\\ARRIVE ");go(15,37);printf(":");go(15,42);colorbox(21);
/*go(17,17);printf("TIME (H\\M\\S)");go(17,29);printf(":");go(17,31);colorbox(10);
go(17,42);printf("DATE (D\\M\\Y)");go(17,54);printf(":");go(17,56);colorbox(10);*/
go(21,33);printf("enter bus nunmer");
go(9,42);fflush(stdin);gets(b.busno);
if(strlen(b.busno)!=10)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){addrecord1();}
else if(v=='q'){recordm();}
else{addrecord1();}
}
go(21,33);printf("enter route from");
go(11,42);fflush(stdin);gets(b.from);
if(strlen(b.from)>21)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){addrecord1();}
else if(v=='q'){recordm();}
else{addrecord1();}
}
go(21,33);printf("enter route to  ");
go(13,42);fflush(stdin);gets(b.to);
if(strlen(b.to)>21)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){addrecord1();}
else if(v=='q'){recordm();}
else{addrecord1();}
}
go(21,25);printf(" enter arrival or departure of bus ");
go(15,42);fflush(stdin);gets(b.d);
/*sprintf(b.time,"%s",__TIME__);*/
mytime(b.time);
sprintf(b.date,"%s",__DATE__);

go(21,16);printf("* * * press (S/R/Q) for submit/reset/quit * * * ");
ch=getch();
if(ch=='s')
{
char a;
fseek(fp,0,SEEK_END);
fwrite(&b,sizeof(b),1,fp);
go(19,20);textcolor(LIGHTCYAN+BLINK);cprintf("* * record saved succesfully :)");go(20,20);printf("press any key to continue.....");textcolor(WHITE);
a=getch();
if(a=='q'){fseek(fp,0,SEEK_END);fclose(fp);recordm();}
else fseek(fp,0,SEEK_END);fclose(fp);addrecord1();
}
else if(ch=='r'){fseek(fp,0,SEEK_END);fclose(fp);addrecord1();}
else if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);recordm();}
else fseek(fp,0,SEEK_END);fclose(fp);addrecord1();
}
//************************************************************************
void addrecord2()
{
char ch,a,v;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO ADD NEW RECORD (DRIVER)",5,YELLOW);
go(21,16);colorbox1(51,RED);
line2c(8,19,15);line2c(8,19,66);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\driver.dat","rb+");
if(fp==NULL){fp=fopen("C:\\TURBOC3\\BIN\\bus\\driver.dat","wb+");}
go(9,22);printf("Driver name ");go(9,37);printf(":");go(9,42);colorbox(21);
go(11,22);printf("Bus no. ");go(11,37);printf(":");go(11,42);colorbox(21);
go(13,22);printf("Joining date");go(13,37);printf(":");go(13,42);colorbox(21);
go(15,22);printf("driver age ");go(15,37);printf(":");go(15,42);colorbox(21);
go(21,28);printf("* * * Enter driver name * * *");
go(9,42);fflush(stdin);gets(dri.name);
if(strlen(dri.name)>21||strlen(dri.name)==0)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){addrecord2();}
else if(v=='q'){recordm();}
else{addrecord2();}
}
go(21,24);printf("* * * Enter designated bus no. * * *");
go(11,42);fflush(stdin);gets(dri.busno);
if(strlen(dri.busno)!=10)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){addrecord2();}
else if(v=='q'){recordm();}
else{addrecord2();}
}
go(21,22);printf("* * * Enter joining date of driver * * *");
go(13,42);fflush(stdin);gets(dri.date);
if(strlen(dri.date)>11)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){addrecord2();}
else if(v=='q'){recordm();}
else{addrecord2();}
}
go(21,21);printf("* * * Enter the age of driver/employe * * *");
go(15,42);fflush(stdin);gets(dri.age);
if(strlen(dri.age)>2)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){addrecord2();}
else if(v=='q'){recordm();}
else{addrecord2();}
}
go(21,16);printf("* * * press (S/R/Q) for submit/reset/quit * * * ");
ch=getch();
if(ch=='s')
{
char a;
fseek(fp,0,SEEK_END);
fwrite(&dri,sizeof(dri),1,fp);
go(19,20);textcolor(LIGHTCYAN+BLINK);cprintf("* * record saved succesfully :)");go(20,20);printf("press any key to continue.....");textcolor(WHITE);
a=getch();
if(a=='q'){fseek(fp,0,SEEK_END);fclose(fp);recordm();}
else fseek(fp,0,SEEK_END);fclose(fp);addrecord2();
}
else if(ch=='r'){fseek(fp,0,SEEK_END);addrecord2();}
else if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);recordm();}
else fseek(fp,0,SEEK_END);fclose(fp);addrecord2();
}
//************************************************************************
void viewrecord()
{
char ch,a;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO VIEW RECORD",5,YELLOW);
go(21,16);colorbox1(51,RED);
line2c(8,19,15);line2c(8,19,66);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
center("* * * View buses record * * * ",10,LIGHTMAGENTA);
center("* * * View driver's record * * *",13,LIGHTCYAN);
center("* * * Quit * * *",16,LIGHTGRAY+BLINK);
go(21,16);printf("* * * press (B/D/Q) for buses/driver's/quit * * *");
ch=getch();
if(ch=='b'){viewbus();}
else if(ch=='d'){viewdriver();}
else if(ch=='q'){mainmenu();}
else viewrecord();

}
//************************************************************************
void viewdriver()
{
int i=10;
char ch,a;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
line1(7,6,74);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO DRIVER'S RECORD",5,YELLOW);
go(21,16);colorbox1(51,RED);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\driver.dat","rb+");
go(8,16);textcolor(LIGHTMAGENTA);cprintf("%-15s %-15s %-15s %-10s  ","DRIVER NAME","BUS NO.","JOINING DATE","AGE");textcolor(WHITE);
line1(9,6,74);
fseek(fp,0,SEEK_SET);
go(10,16);
while(fread(&dri,sizeof(dri),1,fp))
{
textcolor(LIGHTGREEN);cprintf("%-15s %-15s %-15s %-10s \n ",dri.name,dri.busno,dri.date,dri.age);textcolor(WHITE);
i++;
if(i>10){go(i,16);}
}
fseek(fp,0,SEEK_END);
go(21,26);printf("* * * press Q for quit * * *");ch=getch();
if(ch=='q'){fclose(fp);viewrecord();}
else{viewdriver();}
}
//************************************************************************
void updaterecord()
{
char ch,a;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO UPDATE RECORD",5,YELLOW);
go(21,16);colorbox1(51,RED);
line2c(8,19,15);line2c(8,19,66);
center("* * * Update bus'es record * * *",10,LIGHTGREEN);
center("* * * Update driver's record * * * ",13,LIGHTCYAN);
center("* * * Quit * * *",16,LIGHTGRAY+BLINK);
go(21,18);printf("* * * press (B/D/Q)for bus/driver/quit * * * ");
ch=getch();
if(ch=='b'){updatebus();}
else if(ch=='d'){updatedriver();}
else if(ch=='q'){recordm();}
else {updaterecord();}
}
//************************************************************************
void updatebus()
{
char ch,a;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO UPDATE BUS RECORD",5,YELLOW);
line2c(8,19,15);line2c(8,19,66);
go(21,16);colorbox1(51,RED);
center("* * * Update previous record * * *",11,LIGHTGREEN);
center("* * * Quit * * *",15,LIGHTGRAY+BLINK);
go(21,20);printf("* * * press (U/Q)for update bus/quit * * * ");
ch=getch();
if(ch=='u'){previous();}
else if(ch=='q'){updaterecord();}
else {updatebus();}
}
//************************************************************************
void previous()
{
char ch,a,bus[22],t[22],d[22];
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO UPDATE PREVIOUS RECORD",5,YELLOW);
line2c(8,19,15);line2c(8,19,66);
go(21,16);colorbox1(51,RED);
center("* * Search whether record exist or not * *",8,LIGHTMAGENTA+BLINK);
go(11,22);printf("Bus number");go(11,37);printf(":");go(11,42);colorbox(21);
go(13,22);printf("Date");go(13,37);printf(":");go(13,42);colorbox(21);
go(15,22);printf("Time");go(15,37);printf(":");go(15,42);colorbox(21);
go(21,28);printf("* * * Enter bus number * * *");
go(11,42);gets(bus);
go(21,28);printf("* * * Enter the - date * * *");
go(13,42);gets(d);
go(21,28);printf("* * * Enter the - time * * * ");
go(15,42);gets(t);
go(21,18);printf("* * * press (S/R/Q) for submit/reset/quit * * *");
ch=getch();
if(ch=='s')
{//**************
int i=0;
fp=fopen("C:\\TURBOC3\\BIN\\bus\\mainrecord.dat","rb+");
fseek(fp,0,SEEK_SET);
while(fread(&b,sizeof(b),1,fp))
{
if(strcmp(b.time,t)==0)
{
i=1;
break;
}
}
fseek(fp,0,SEEK_END);fclose(fp);
//value of i is assigen upto this part 0 or 1
if(i)//if i==1 means record available
{
char ch;
center("record has been found in data :)",19,LIGHTGRAY+BLINK);
go(21,18);printf("* * * press (U/R) for update data /reset  * * *");
ch=getch();
if(ch=='u')
{//when we press u for making update in file
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO UPDATE THE FOUND RECORD",5,YELLOW);
line2c(8,19,15);line2c(8,19,66);
go(21,16);colorbox1(51,RED);
go(9,22);printf("Enter Bus no.");go(9,37);printf(":");go(9,42);colorbox(21);
go(11,22);printf("Enter route ");go(11,37);printf(":");go(11,42);colorbox(21);
go(12,51);textcolor(YELLOW+BLINK);cprintf("TO");textcolor(WHITE);
go(13,42);colorbox(21);
go(15,22);printf("DEPART\\ARRIVE ");go(15,37);printf(":");go(15,42);colorbox(21);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\mainrecord.dat","rb+");
fseek(fp,0,SEEK_SET);
while(fread(&b,sizeof(b),1,fp))
{
if(strcmp(b.time,t)==0)
{
go(21,33);printf("enter bus nunmer");
go(9,42);fflush(stdin);gets(b.busno);
go(21,33);printf("enter route from");
go(11,42);fflush(stdin);gets(b.from);
go(21,33);printf("enter route to  ");
go(13,42);fflush(stdin);gets(b.to);
go(21,25);printf("enter arrival or departure of bus ");
go(15,42);fflush(stdin);gets(b.d);
fseek(fp,-sizeof(b),SEEK_CUR);
fwrite(&b,1,sizeof(b),fp);
fseek(fp,0,SEEK_END);
}
}
center("record updated succesflly :)",19,LIGHTGREEN+BLINK);
go(21,19);printf("* * * press (Q) for quiting page  * * * ");
a=getch();
if(a=='q'){previous();}
else{previous();}
}//when we press u for making update in file
else{previous();}
}
else
{//if record not matched
center("record not been found in data :(",19,LIGHTGRAY+BLINK);
go(21,18);printf("* * * press (ENTER) for reset all entries * * *");
ch=getch();
if(ch==13){previous();}
else{previous();}
}//if record not matched
//*****************
}
else if(ch=='r')
{
previous();
}
else if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);updatebus();}
else{previous();}
}
//************************************************************************
void updatedriver()
{
char driver[22],a[6],ch;
int i=0;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO UPDATE DRIVER'S RECORD",5,YELLOW);
line2c(8,19,15);line2c(8,19,66);
go(21,16);colorbox1(51,RED);
center("* * Search whether record exist or not * *",8,LIGHTMAGENTA+BLINK);
go(10,22);printf("Driver name");go(10,37);printf(":");go(10,42);colorbox(21);
go(12,22);printf("Age");go(12,37);printf(":");go(12,42);colorbox(21);
line1(13,16,65);
line1(18,16,65);
go(21,23);printf("* * * Enter the driver's name * * *");
go(10,42);fflush(stdin);gets(driver);
go(21,23);printf("* * * Enter the Driver's Age  * * *");
go(12,42);fflush(stdin);gets(a);
go(21,21);printf("* * * Enter (S/R) for submit/reset * * *");
fp=fopen("C:\\TURBOC3\\BIN\\bus\\driver.dat","rb+");
fseek(fp,0,SEEK_SET);
while(fread(&dri,sizeof(dri),1,fp))
{
if(strcmp(dri.name,driver)==0)
{//***if statement open
if(strcmp(dri.age,a)==0)
{
i=1;
go(14,22);textcolor(LIGHTGREEN);cprintf("Driver name");go(14,37);cprintf(":");go(14,42);cprintf("%s",dri.name);textcolor(WHITE);
go(15,22);textcolor(LIGHTGREEN);cprintf("Bus no.");go(15,37);cprintf(":");go(15,42);cprintf("%s",dri.busno);textcolor(WHITE);
go(16,22);textcolor(LIGHTGREEN);cprintf("Joining date");go(16,37);cprintf(":");go(16,42);cprintf("%s",dri.date);textcolor(WHITE);
go(17,22);textcolor(LIGHTGREEN);cprintf("Age");go(17,37);cprintf(":");go(17,42);cprintf("%s",dri.age);textcolor(WHITE);
center("record has been found in data :)",19,LIGHTGRAY+BLINK);
go(21,18);printf("* * * press (U/R) for update data /reset  * * *");
ch=getch();
if(ch=='u')
{//if ch=='u'
char ch;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO UPDATE DRIVER'S RECORD",5,YELLOW);
line2c(8,19,15);line2c(8,19,66);
go(21,16);colorbox1(51,RED);
center("* * Enter latest record for updatation * *",8,LIGHTMAGENTA+BLINK);
go(10,22);printf("Driver name");go(10,37);printf(":");go(10,42);colorbox(21);
go(12,22);printf("Bus no.");go(12,37);printf(":");go(12,42);colorbox(21);
go(14,22);printf("Joining date");go(14,37);printf(":");go(14,42);colorbox(21);
go(16,22);printf("Age");go(16,37);printf(":");go(16,42);colorbox(21);
go(21,23);printf("* * * Enter the driver's name * * *");
go(10,42);fflush(stdin);gets(dri.name);
go(21,23);printf("* * * Enter the resp BUS num. * * *");
go(12,42);fflush(stdin);gets(dri.busno);
go(21,23);printf("* * * Enter the joining date  * * *");
go(14,42);fflush(stdin);gets(dri.date);
go(21,23);printf("* * * Enter the Age of driver * * *");
go(16,42);fflush(stdin);gets(dri.age);
go(21,21);printf("* * * Press (S/Q) for submit/quit * * *");
ch=getch();
if(ch=='s')
{
char ch;
fseek(fp,-sizeof(dri),SEEK_CUR);
fwrite(&dri,1,sizeof(dri),fp);
center("record has been updated in data :)",19,LIGHTGRAY+BLINK);
go(21,18);printf("* * * press (R/Q) for Reset/quit  * * *");
ch=getch();
if(ch=='r'){updatedriver();}
else if(ch=='q'){updatedriver();}
else{updatedriver();}
}
else {updatedriver();}
}//if ch=='u'
else{updatedriver();}
}
}//***if statement close
}
if(i==0)
{
char ch;
center("record has not been found in data :(",19,LIGHTGRAY+BLINK);
go(21,18);printf("* * * press (R/Q) for update reset/quit  * * *");
ch=getch();
if(ch=='r'){updatedriver();}
else if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);updaterecord();}
else{updatedriver();}
}
}
//************************************************************************
void viewbus()
{
int i=10;
char ch,a;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
line1(7,6,74);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO BUS'ES RECORD",5,YELLOW);
go(21,16);colorbox1(51,RED);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\mainrecord.dat","rb+");
go(8,10);textcolor(LIGHTMAGENTA);cprintf("%-10s %-10s %-10s %-10s %-10s %-10s ","BUS NO.","FROM","TO","D/A","TIME","DATE");textcolor(WHITE);
line1(9,6,74);
fseek(fp,0,SEEK_SET);
go(10,10);
while(fread(&b,sizeof(b),1,fp))
{
textcolor(LIGHTCYAN);cprintf("%-10s %-10s %-10s %-10s %-10s %-10s\n ",b.busno,b.from,b.to,b.d,b.time,b.date);textcolor(WHITE);
i++;
if(i>10){go(i,10);}
}
fseek(fp,0,SEEK_END);
go(21,26);printf("* * * press Q for quit * * *");ch=getch();
if(ch=='q'){fclose(fp);viewrecord();}
else{viewbus();}
}
//************************************************************************
void check()
{
char f[51],t[51],d[22],ch,de[22]="arrive";
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
sprintf(d,"%s",__DATE__);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO CHECK AVAILABLITY",5,YELLOW);
go(21,16);colorbox1(51,RED);
line2c(8,19,15);line2c(8,19,66);
center("* * entre the LOCATION details :) * * ",8,LIGHTCYAN+BLINK);
go(12,22);printf("FROM location");go(12,37);printf(":");go(12,42);colorbox(21);
go(14,49);textcolor(LIGHTGREEN+BLINK);cprintf("* * *");textcolor(WHITE);
go(16,22);printf("TO location");go(16,37);printf(":");go(16,42);colorbox(21);
go(21,23);printf("* * * Enter the from location * * *");
go(12,42);fflush(stdin);gets(f);
go(21,23);printf("* * * Enter the  TO  location * * *");
go(16,42);fflush(stdin);gets(t);
go(21,18);printf("* * * Enter (S/R/Q) for submit/reset/quit * * *");
ch=getch();
fp=fopen("C:\\TURBOC3\\BIN\\bus\\mainrecord.dat","rb+");
fseek(fp,0,SEEK_SET);
if(ch=='s')
{//when we press ch=='s'open
char ch;
int i=10;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
line1(9,16,65);
go(8,22);textcolor(LIGHTMAGENTA);cprintf("%-10s %-10s %-10s %-10s ","BUS NO.","TO","TIME","DATE");textcolor(WHITE);
go(5,16);colorbox(50);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
go(5,16);center("WELCOME TO CHECK AVAILABLITY",5,YELLOW);
go(21,16);colorbox1(51,RED);
line2c(8,19,15);line2c(8,19,66);
go(10,21);
while(fread(&b,sizeof(b),1,fp))
{//while open
if(strcmp(b.date,d)==0)
{
if(strcmp(b.from,f)==0)
{
if(strcmp(b.to,t)==0)
{//if of to
if(strcmp(b.d,de)==0)
{
textcolor(LIGHTCYAN);cprintf("%-10s %-8s %-10s %-10s\n ",b.busno,b.to,b.time,b.date);textcolor(WHITE);
i++;
if(i>10){go(i,21);}
}
}// if of to
}
}
}//while close
go(21,17);printf("* * * Press any key to return to back page * * *");
ch=getch();
if(ch=='q'){check();}
else{check();}
}//when we press ch=='s'close
else if(ch=='r')
{
check();
}
else if(ch=='q')
{
fseek(fp,0,SEEK_END);
fclose(fp);
mainmenu();
}
else
{
check();
}
}
//************************************************************************
void searchroute()
{
char ch;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO ROUTES MANAGMENT",5,YELLOW);
go(21,16);colorbox1(51,RED);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
line2c(8,19,15);line2c(8,19,66);
center("* * * Register new route * * *",9,LIGHTGREEN);
center("* * * View registered route * * *",12,LIGHTMAGENTA);
center("* * * Search specific route * * *",15,YELLOW);
center("* * * Quit * * *",18,LIGHTGRAY+BLINK);
go(21,18);printf("* * * Press (R/V/S/Q) for given options * * *");
ch=getch();
if(ch=='r')
{
registerroute();
}
else if(ch=='v')
{
viewroute();
}
else if(ch=='s')
{
specificroute();
}
else if(ch=='q')
{
mainmenu();
}
else
{
searchroute();
}
}
//************************************************************************
void registerroute()
{
char ch,v;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO REGISTER NEW ROUTE",5,YELLOW);
go(21,16);colorbox1(51,RED);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
line2c(8,19,15);line2c(8,19,66);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\route.dat","rb+");
if(fp==NULL){fp=fopen("C:\\TURBOC3\\BIN\\bus\\route.dat","wb+");}
go(10,18);printf("Destination From ");go(10,37);printf(":");go(10,42);colorbox(21);
go(13,18);printf("Destionation To");go(13,37);printf(":");go(13,42);colorbox(21);
go(16,18);printf("Fare");go(16,37);printf(":");go(16,42);colorbox(21);
go(21,22);printf("* * * Enter destination starting * * *");
go(10,42);fflush(stdin);gets(rut.from);
if(strlen(rut.from)>21)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){registerroute();}
else if(v=='q'){searchroute();}
else{registerroute();}
}
go(21,22);printf("* * * Enter  destination  ending * * *");
go(13,42);fflush(stdin);gets(rut.to);
if(strlen(rut.to)>21)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){registerroute();}
else if(v=='q'){searchroute();}
else{registerroute();}
}
go(21,22);printf("* * * Enter total fare for route * * *");
go(16,42);fflush(stdin);gets(rut.fare);
if(strlen(rut.fare)<2)
{
go(21,20);printf("entry is invalid PRESS (R/Q) for reset/quit");
v=getch();
if(v=='r'){registerroute();}
else if(v=='q'){searchroute();}
else{registerroute();}
}
go(21,18);printf("* * * press (S/R/Q) for submit/reset/quit * * * ");
ch=getch();
if(ch=='s')
{
char a;
fseek(fp,0,SEEK_END);
fwrite(&rut,sizeof(rut),1,fp);
go(19,20);textcolor(LIGHTCYAN+BLINK);cprintf("* * record saved succesfully :)");go(20,20);printf("press any key to continue.....");textcolor(WHITE);
a=getch();
if(a=='q'){fseek(fp,0,SEEK_END);fclose(fp);searchroute();}
else fseek(fp,0,SEEK_END);fclose(fp);registerroute();
}
else if(ch=='r'){registerroute();}
else if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);searchroute();}
else {registerroute();}
}
//************************************************************************
void viewroute()
{
int i=10;
char ch;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO VIEW REGISTERED ROUTE",5,YELLOW);
go(21,16);colorbox1(51,RED);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
line2c(8,19,15);line2c(8,19,66);
line1(7,15,66);
line1(9,15,66);
go(8,22);textcolor(LIGHTMAGENTA);cprintf("%-15s %-15s %-10s ","DEST.FROM","DEST.TO","FARE");textcolor(WHITE);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\route.dat","rb+");
fseek(fp,0,SEEK_SET);
go(10,22);
while(fread(&rut,sizeof(rut),1,fp))
{
textcolor(LIGHTCYAN);cprintf("%-15s %-15s %-10s\n ",rut.from,rut.to,rut.fare);textcolor(WHITE);
i++;
if(i>10){go(i,22);}
}
go(21,26);printf("* * * PRESS (Q) for return * * *");
ch=getch();
if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);searchroute();}
else{viewroute();}
}
//************************************************************************
void specificroute()
{
int i=0;
char ch,f[51],t[51];
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO REGISTER NEW ROUTE",5,YELLOW);
go(21,16);colorbox1(51,RED);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
line2c(8,19,15);line2c(8,19,66);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\route.dat","rb+");
fseek(fp,0,SEEK_SET);
go(10,18);printf("Destination From ");go(10,37);printf(":");go(10,42);colorbox(21);
go(13,18);printf("Destionation To");go(13,37);printf(":");go(13,42);colorbox(21);
line1(15,23,58);
line1(19,23,58);
line2c(16,18,22);
line2c(16,18,59);
go(21,23);printf("* * * ENTER destination from * * *");
go(10,42);fflush(stdin);gets(f);
go(21,23);printf("* * * ENTER destination  to  * * *");
go(13,42);fflush(stdin);gets(t);
while(fread(&rut,sizeof(rut),1,fp))
{
if(strcmp(rut.from,f)==0)
{
if(strcmp(rut.to,t)==0)
{
i=1;
}
}
}
if(i==1)
{
go(17,24);textcolor(LIGHTCYAN+BLINK);
cprintf("Designated route found in record :)");textcolor(WHITE);
}
else
{
go(17,24);textcolor(LIGHTBLUE+BLINK);
cprintf("SORRY :( route not found in record ");textcolor(WHITE);
}
go(21,23);printf("* * * Enter (R/Q) for reset/quit * * *");
ch=getch();
if(ch=='r'){specificroute();}
else if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);searchroute();}
else{specificroute();}
}
//************************************************************************
void fares()
{
char ch,f[51],t[51],a;
clrscr();
//outside border:-
line1(2,2,79);
line1(24,2,79);
line2(3,23,2);
line2(3,23,78);
//inside box:-
line1(4,15,66);
line1(6,15,66);
line2c(5,5,15);
line2c(5,5,66);
go(5,16);colorbox(50);
go(5,16);center("WELCOME TO VIEW FARES OF ROUTE",5,YELLOW);
go(21,16);colorbox1(51,RED);
go(23,65);textcolor(LIGHTGREEN+BLINK);cprintf(__DATE__);go(23,6);cprintf(__TIME__);textcolor(WHITE);
line2c(8,19,15);line2c(8,19,66);
fp=fopen("C:\\TURBOC3\\BIN\\bus\\route.dat","rb+");
fseek(fp,0,SEEK_SET);
go(10,18);printf("Destination From ");go(10,37);printf(":");go(10,42);colorbox(21);
go(13,18);printf("Destionation To");go(13,37);printf(":");go(13,42);colorbox(21);
line1(15,23,58);
line1(19,23,58);
line2c(16,18,22);
line2c(16,18,59);
center("* * maximum FARE is * *",16,LIGHTGREEN+BLINK);
go(21,23);printf("* * * ENTER destination from * * *");
go(10,42);fflush(stdin);gets(f);
go(21,23);printf("* * * ENTER destination  to  * * *");
go(13,42);fflush(stdin);gets(t);
go(21,18);printf("* * * PRESS (S/R/Q) for submit/reset/quit * * *");
ch=getch();
if(ch=='s')
{//ch=='s'open
while(fread(&rut,sizeof(rut),1,fp))
{
if(strcmp(rut.from,f)==0)
{
if(strcmp(rut.to,t)==0)
{
go(18,39);textcolor(YELLOW);cprintf("%s Rs.",rut.fare);textcolor(WHITE);
}
}
}
go(21,18);printf("* * * PRESS (R/Q) for reset page/quit page * * *");
a=getch();
if(a=='r'){fseek(fp,0,SEEK_END);fclose(fp);fares();}
else if(a=='q'){fseek(fp,0,SEEK_END);fclose(fp);mainmenu();}
else{fseek(fp,0,SEEK_END);fclose(fp);fares();}
}//ch=='s'close
else if(ch=='r'){fseek(fp,0,SEEK_END);fclose(fp);fares();}
else if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);mainmenu();}
else{fseek(fp,0,SEEK_END);fclose(fp);fares();}
}
//go(21,18);printf("* * * PRESS (R/Q) for reset/quit * * *");
//ch=getch();
//if(ch=='r'){fseek(fp,0,SEEK_END);fclose(fp);fares();}
//else if(ch=='q'){fseek(fp,0,SEEK_END);fclose(fp);mainmenu();}
//else{fseek(fp,0,SEEK_END);fclose(fp);fares();}
//************************************************************************
void main()
{
clrscr();
startpage();
}