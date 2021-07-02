#include <iostream>
#include <random>
#include <ctime>
#include<string>
using namespace std;
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
char x_player='X';
char o_player='O';
void show_board();
void mode();
void computer_vs_player();
void player_vs_player();
void get_x_player_choice();
void get_o_player_choice();
void get_computer_choice();

int count_board(char symbol)
{
    int total=0;
    for (int i=0;i<9;i++)
    {
        if (board[i]==symbol)
       { total+=1;}
    }
    return total;
}

char check_winner() {
    if(board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
        return board[0];
    if(board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
        return board[3];
    if(board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
        return board[6];
    if(board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
        return board[0];
    if(board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
        return board[1];
    if(board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
        return board[2];
    if(board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
        return board[0];
    if(board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
        return board[2];
    if(count_board('X') + count_board('O') < 9)
        return 'C';
    else
        return 'D';
}
void show_board()
{
    cout<<board[0]<<"   |  "<<board[1]<<" |  "<<board[2]<<endl;
    cout<<"____|"<<"____|"<<"____"<<endl;
    cout<<board[3]<<"   |  "<<board[4]<<" |  "<<board[5]<<endl;
    cout<<"____|"<<"____|"<<"____"<<endl;
    cout<<board[6]<<"   |  "<<board[7]<<" |  "<<board[8]<<endl;
    cout<<"    |"<<"    |"<<"    "<<endl;

}
void player_vs_player()
{
    string x_player_name;
    string o_player_name;
    cout<<"Enter 1st player name: ";
    cin>>x_player_name;
    cout<<"Enter 2nd player name: ";
    cin>>o_player_name;
    while (true)
    {
       system("cls");
       show_board();
       if (count_board('X')==count_board('O'))
       {
           cout<<x_player_name<<" 's Turn"<<endl;
           get_x_player_choice();
       }
       else
       {
           cout<<o_player_name<<" 's Turn"<<endl;
           get_o_player_choice();
       }
        char winner = check_winner();
        if(winner == 'X') {
            system("cls");
            show_board();
            cout << x_player_name << " Won The Game." << endl;
            break;
        }
        else if(winner == 'O') {
            system("cls");
            show_board();
            cout << o_player_name << " Won The Game." << endl;
            break;
        }
        else if(winner == 'D') {
            cout << "Game is draw!" << endl;
            break;
        }
       
    }
    

}

void get_x_player_choice()
{
    int choice;
    while(true)
    {
        cout<<"Select your Position (1-9)"<<endl;
        cin>>choice;
        choice--;
    if (choice<0 || choice>8)
    {
        cout<<"Select your Position (1-9) again"<<endl;
        cin>>choice;
    }
    else if(board[choice]!=' ')
    {
        cout<<"Please select another position"<<endl;
        cin>>choice;
    }
    else 
    {
         board[choice]='X';
    }
    break;
    }

}

void get_o_player_choice()
{
    int choice;
    while(true)
    {
        cout<<"Select your Position (1-9)"<<endl;
        cin>>choice;
        choice--;
    if (choice<0 || choice>8)
    {
        cout<<"Select your Position (1-9) again"<<endl;
        cin>>choice;
    }
    else if(board[choice]!=' ')
    {
        cout<<"Please select another position"<<endl;
        cin>>choice;
    }
    else 
    {
         board[choice]='O';
    }
    break;
    }

}
void get_computer_choice()
{
    int choice;
    srand(time(0));
    do
    {
        choice=rand()%10;
        break;
    }while(board[choice] != ' ');
    board[choice]='O';

}
int main()
{
    cout<<"Welcome to my game-TIC-TAC-TOE!I hope you would enjoy it.Let's start."<<endl;
    player_vs_player();
    return 0;
}
