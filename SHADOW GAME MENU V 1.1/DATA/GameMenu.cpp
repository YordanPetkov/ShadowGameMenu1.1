#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include "DIS.cpp"
#include "enigma.cpp"
#include "TTT.cpp"
#include "SBJ.cpp"

using namespace std;
int main();
int loginsucces=0,flag2=0;
string nickgl;
string nickname,password;
void color(int i)
{
    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), i );
}
void passwordcin()
{
    password="";
    START:
    system("CLS");
    cout<<"                         Write your nickname and password"<<endl;
    cout<<"                 -nickname : ";cout<<nickname<<endl;
    cout<<"                 -password : ";
    char pass[32];
    int i=0,k;
    char a;
    for(i=0;;)
    {
        a=getch();
        k=a;
        if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
        {
            password=password+a;
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(k==8 && i>=1)
        {
            --i;
            system("CLS");
            cout<<"                         Write your nickname and password"<<endl;
            cout<<"                 -nickname : ";cout<<nickname<<endl;
            cout<<"                 -password : ";
            if(i!=0){for(int j=0;j<i;j++)cout<<"*";
            password.erase(i-1,1);}


        }
        if(k==13)
        {
            pass[i]='/0';
            break;
        }
    }
    if(i<=5)
    {
        cout<<"            Minimun 6 digits needed."<<endl;
        getch();
        goto START;
    }

}
void login()
{
        system("CLS");
        char membersfile[256];
        string prom,massive[255],loginmem;
        cout<<"                                        LOGIN"<<endl;
    cout<<endl;
        cout<<"                         Write your nickname and password"<<endl;
    cout<<"                 -nickname : ";cin>>nickname;cout<<endl;
    cout<<"                 -password : ";passwordcin();cout<<endl;
    ifstream reg ("members.txt",ios::in);
    int i=0;
    while(! reg.eof())
    {

        getline(reg, prom);
        massive[i]=prom;
        i++;
    }
    loginmem = nickname + " " + password;
    for(int j=0;j<=i;j++)
    {
        if(massive[j]==loginmem){system("CLS");MessageBox(NULL,"You are login successful","GameMenu",NULL | MB_ICONINFORMATION);cout<<endl;loginsucces=1;nickgl=nickname;return;}
    }

    system("CLS");MessageBox(NULL,"Error with login","GameMenu",NULL | MB_ICONSTOP);loginsucces=2;main();
}
void registration()
{
        system("CLS");
    cout<<"                                     REGISTRATION"<<endl;
    cout<<endl;
    cout<<"                         Write your nickname and password"<<endl;
    cout<<"                 -nickname : ";cin>>nickname;
    cout<<"                 -password : ";passwordcin();
    ofstream reg ("members.txt",ios::app);
    if(reg.is_open())
    {
        reg<<endl;
        reg<<nickname<<" ";
        reg<<password;
        reg.close();
        system("CLS");MessageBox(NULL,"You are register successful","GameMenu",NULL | MB_ICONINFORMATION);nickgl=nickname;
    }
}
void loginreg1()
{
    int sq=1;
    sq=1;
    STARTQUIT:
    system("CLS");
    cout<<"                         HELLO to GAME SHADOW MENU v 1.0"<<endl;
    cout<<endl;cout<<endl;
    if(sq==1)
    {cout<<"                        -> login"<<endl;
     cout<<"                           register"<<endl;sq=2;}
    else {
     cout<<"                           login"<<endl;
     cout<<"                        -> register";sq=1;}

    char a;
        int k;
        a=getch();
        k=a;
        if(k==13)
    {
        if(sq==1)
        {
            registration();
            return;
        }
        else
            {login();return;}
    }

        if(k==77 || k==72 || k==80 || k==75)
        {
            sq=(sq%2)+1;
            goto STARTQUIT;
        }
    else goto STARTQUIT;
}
void menugame()
{
    system("CLS");
    string loginreg,game;
    if(flag2==0)
    {
    if(loginsucces==2)MessageBox(NULL,"Error with login","GameMenu",NULL | MB_ICONSTOP);

    color(31);
    cout<<"                         HELLO to GAME SHADOW MENU v 1.0"<<endl;
    loginreg1();
    /*cout<<"                     -If you new in shadow menu please write : 'register'"<<endl;
    cout<<"                     -If you want to login in shadow menu write : 'login'"<<endl;
    cout<<endl;
    cin>>loginreg;
    if(loginreg == "login")login();
    if(loginreg == "register")registration();
    if(loginreg != "login" && loginreg != "register")main();
    */flag2=1;
    }
    cout<<"                     ";color(129);cout<<"-to play TicTacToe v2.2 write : 'TTT'"<<endl;color(31);
    color(27);cout<<"                     ";color(41);cout<<"-to play Shadow Black Jack write : 'SBJ'"<<endl;
    color(27);cout<<"                     ";color(15);cout<<"-to code in enigma write : 'enigma'"<<endl;color(31);
    color(28);cout<<"                     ";color(47);cout<<"-to play DiceInShadow v2.0 write : 'DIS'"<<endl;color(30);
    color(31);cout<<"                      To sign out write : 'exit'"<<endl;cout<<"                     ";
    cin>>game;
    color(31);
    if(game=="TTT")tttgame::TTTg(nickgl);
    if(game=="enigma")enigmagame::enigmag();
    if(game=="DIS")disgame::DISg(nickgl);
    if(game=="SBJ")SBJgame::SBJg(nickgl);
    if(game=="exit"){
            int ansbox;
            ansbox=MessageBox(NULL,"Do you want to sign out?","GameMenu",MB_YESNO | MB_ICONQUESTION);
            if(ansbox==7)menugame();
            flag2=0;
            menugame();
    }
    if(game!="TTT" && game!="enigma" && game!="DIS" && game!="SBJ" && game!="exit")main();
    menuorquit:
    system("CLS");
    cout<<"                         HELLO to GAME SHADOW MENU v 1.0"<<endl;
    cout<<"                         If you want to play new game write 'menu'"<<endl;
    cout<<"                         If you want to quit the game write 'quit'"<<endl;
    string menu;cout<<"                         ";
    cin>>menu;
    if(menu=="menu")main();
    if(menu=="quit")return ;
    if(menu!="quit" && menu!="menu")goto menuorquit;
}
int main()
{
    system("CLS");
    color(31);
    cout<<"                        HELLO to GAME SHADOW MENU v1.0"<<endl;
    menugame();
    return 0;
}
