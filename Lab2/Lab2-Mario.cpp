
#include <iostream>
#include <string>
using namespace std;

struct player {
    
    string playerName;  //Who is the player
    int lives;
    int coins;
    
    int level;  //Where is the player
    int x_position;
    int y_position;
    
    bool special; //Is the player special - if so what items
    bool big;
    string special_items[5];
    
} ;


// Initilize the struct variables
void initilaize_variables (player& character, string myName){
    character.playerName = myName;
    character.lives = 3;
    character.coins = 0;
    
    character.level = 0;
    character.x_position = 0;
    character.y_position = 0;
    
    character.special = false;
    character.big = false;
    character.special_items[0] = "Hammer";
    character.special_items[1] = "Red Mushroom";
    character.special_items[2] = "Green Mushroom";
    character.special_items[3] = "Cape";
    character.special_items[4] = "Star";
}

// Restart the character
void restart (player& character){
    character.lives = 3;
    character.coins = 0;
    character.special = false;
    character.big = false;
}

//Print character
void printCharacter(player& character) {

    // Print State
    cout << "\t Name: \t\t\t" << character.playerName << "\n";
    cout << "\t Lives: \t\t" << character.lives << "\n";
    cout << "\t Coins: \t\t" << character.coins << "\n";
    
    // Print Position
    cout << "\t Level: \t\t" << character.level << "\n";
    cout << "\t X Position: \t\t" << character.x_position << "\n";
    cout << "\t Y Position: \t\t" << character.y_position << "\n";
    
    // Print Special Items
    cout << "\t Character big?: \t" << character.big << "\n";
    cout << "\t Character special?: \t" << character.special << "\n";
    for (int i = 0; i < 5; i++)
     cout << "\t Special_Item[" << i << "]: \t" << character.special_items[i] << "\n";
    cout << endl;
}

void movePlayer(player& character, string direction)
{
    if(direction == "right")
        character.x_position += 1;
    else
        character.x_position -= 1;
    printCharacter(character);
}

void jump(player& character)
{
    cout << "\t Name: \t\t\t" << character.playerName << "\n";
    for(int x = 0; x < 3; x++)
    {
        cout << "\t Y Position: \t\t" << character.y_position << "\n";
        character.y_position += 1;
    }
    for(int x = 2; x >= 0; x--)
    {
        cout << "\t Y Position: \t\t" << character.y_position << "\n";
        character.y_position -= 1;
    }
    cout << endl;
}

void setBig(player& character, bool isBig)
{
    character.big = isBig;
    printCharacter(character);
}

void parseCommand(player& character, string command)
{
    if(command == "help")
        cout << "Commands: stats, left, right, jump, grow, shrink, quit" << endl << endl;
    else if(command == "right")
        movePlayer(character, command);
    else if(command == "left")
        movePlayer(character, command);
    else if(command == "jump")
        jump(character);
    else if(command == "grow")
        setBig(character, true);
    else if(command == "shrink")
        setBig(character, false);
    else if(command == "stats")
        printCharacter(character);
    else 
        cout << "Invalid command. ";
}

void commandLoop(player& character)
{
    printCharacter(character);
    bool loop = true;
    string command = "";
    while(loop)
    {
        cout << "Enter a command (or type \"help\"): ";
        cin >> command;
        cout << endl;
        if(command == "quit") // Check if we need to quit application before parsing
            loop = false;

        else
            parseCommand(character, command); // Send command to function filled with conditional statements

    }
}

int main () {
    player Mario;
    player Luigi;
    player &currentPlayer = Mario;
    initilaize_variables(Mario, "Mario");
    initilaize_variables(Luigi, "Luigi");
    commandLoop(currentPlayer);

    return 0;
}
