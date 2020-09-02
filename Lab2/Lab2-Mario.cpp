
#include <iostream>
#include <string>
using namespace std;

struct player
{

    string playerName; //Who is the player
    int lives;
    int coins;

    int level; //Where is the player
    int x_position;
    int y_position;

    bool special; //Is the player special - if so what items
    bool big;
    string special_items[5];
};

// Initilize the struct variables
void initilaize_variables(player &character, string myName)
{
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


//Print character
void printCharacter(player &character)
{

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

// Restart the character
void restart(player &character)
{
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
    printCharacter(character);
}

void movePlayer(player &character, string direction)
{
    if (direction == "right")
        character.x_position += 1;
    else if (character.x_position > 0) // Cant go negative in a sidescrolling game
        character.x_position -= 1;
    printCharacter(character);
}

void jump(player &character) // Increase player y and then decrease it again
{
    cout << "\t Name: \t\t\t" << character.playerName << "\n";
    for (int x = 0; x < 3; x++)
    {
        cout << "\t Y Position: \t\t" << character.y_position << "\n";
        character.y_position += 1;
    }
    for (int x = 2; x >= 0; x--)
    {
        cout << "\t Y Position: \t\t" << character.y_position << "\n";
        character.y_position -= 1;
    }
    cout << endl;
}

void setBig(player &character, bool isBig) // Make player grow
{
    character.big = isBig;
    printCharacter(character);
}

void levelUp(player &character) // Gain a life
{
    character.lives++;
    printCharacter(character);
}

void getCoin(player &character) // Increase coin amount by 1
{
    character.coins++;
    if (character.coins >= 100) // Level up if 100 coins
    {
        levelUp(character);
        character.coins = 0;
    }
    printCharacter(character);
}

void die(player &character) // Die and reset level to 1
{
    character.level = 0;
    printCharacter(character);
}

void takeDamage(player &character) // Die and reset level to 1
{
    if(character.big) // If big, make small
        setBig(character, false);
    else // Otherwise kill player and reset back to zero
        character.level = 0;
    printCharacter(character);
}

void nextLevel(player &character) // Go to next level
{
    character.level++;
    printCharacter(character);
}

void clearItems(player &character) // Go to next level
{
    for(int x = 0; x < 5; x++)
        character.special_items[x] = "None";
    printCharacter(character);
}

void toggleSpecial(player &character) // Go to next level
{
    character.special = !character.special;
    printCharacter(character);
}

void parseCommand(player &character, string command) // Read input from user and find corresponding function
{
    if (command == "help")
        cout << "Commands: stats, left, right, jump, grow, shrink, coin, levelup, die, nextlevel, clearitems, special, restart, quit" << endl
             << endl;
    else if (command == "right")
        movePlayer(character, command);
    else if (command == "left")
        movePlayer(character, command);
    else if (command == "jump")
        jump(character);
    else if (command == "grow")
        setBig(character, true);
    else if (command == "shrink")
        setBig(character, false);
    else if (command == "stats")
        printCharacter(character);
    else if (command == "coin")
        getCoin(character);
    else if (command == "levelup")
        levelUp(character);
    else if (command == "die")
        die(character);
    else if (command == "damage")
        takeDamage(character);
    else if (command == "nextlevel")
        nextLevel(character);
    else if (command == "clearitems")
        clearItems(character);
    else if (command == "special")
        toggleSpecial(character);
    else if (command == "restart")
        restart(character);
    else
        cout << "Invalid command. ";
}

void commandLoop(player &character) // For getting command from user repeatedly
{
    printCharacter(character);
    bool loop = true;
    string command = "";
    while (loop)
    {
        cout << "Enter a command (or type \"help\"): ";
        cin >> command;
        cout << endl;
        if (command == "quit") // Check if we need to quit application before parsing
            loop = false;

        else
            parseCommand(character, command); // Send command to function filled with conditional statements
    }
}

int main()
{
    player Mario;
    player Luigi;
    player &currentPlayer = Mario;
    initilaize_variables(Mario, "Mario");
    initilaize_variables(Luigi, "Luigi");
    commandLoop(currentPlayer);

    return 0;
}
