#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
the function return the computer move
*/
char getComputerMove(){
    int move;

    //get a random number between 0-2
    srand(time(NULL));
    move = rand() % 3;

    if(move == 0){ // zero is rock
        return 'r';
    }
    else if(move == 1){ // one is paper
        return 'p';
    }
    else{// two is scissor
        return 's';
    }

}
// Return the result of the game
int result(char player, char computer){

    /*
        the switch statement use the case from the computer result to check the condition.
        Condition:
        rock vs. paper, paper wins
        rock vs. scissor, rock wins
        rock vs. rock, draw
        paper vs. paper, draw 
        paper vs. scissor, scissor wins
        paper vs. rock, paper wins
        scissor vs. scissor, draw
        scissor vs. paper , scissor wins
        scissor vs. rock, rock wins

    */
    switch (computer)
    {
        case 'r':
            if(player == 'r'){
                return 0;
            }
            if(player == 'p'){
                return 1;
            }
            if(player == 's'){
                return -1;
            }
        break;
        case 'p':
            if(player == 'p'){
                return 0;
            }
            if(player == 's'){
                return 1;
            }
            if(player == 'r'){
                return -1;
            }
        break;
        case 's':
            if(player == 's'){
                return 0;
            }
            if(player == 'p'){
                return -1;
            }
            if(player == 'r'){
                return 1;
            }
        break;
        default:
            cout << "Invalid\n";
        break;
    }
    return -1; 

}


int main(){

    //declared variable
    char playerMove;//player move
    char computeMove;//computer move
    int getresult;

    cout << " Welcome to Rock Paper Scissor Game\n"; //print a welcome statement

    cout << "\nEnter r for Rock, p for Paper, and s for Scissor\n";//print the choice for the game


    while(1){
        cin >> playerMove;//get the user input
        if(playerMove == 'r' || playerMove == 'p' || playerMove == 's'){//check if user selected one the choice
            break;
        }
        else{//if invalid choice ask user to select again 
            cout << "\n Invaild. Try again\n";
        }



    }

    computeMove = getComputerMove();//get the computer move from the function
    getresult = result(playerMove,computeMove);//get the result from the function

    if(getresult == 0){//if the result zero its draw
        cout << "\n Game Draw!\n";
    }
    else if(getresult == 1){//if the result is one player wins
        cout << "\n PLayer won!\n";
    }
    else{//computer wins
        cout << "\n Computer won!\n";
    }

    //Print the player move and computer move
    cout << "Player move: " << playerMove << endl;
    cout << "Computer move: " << computeMove << endl;




    
}