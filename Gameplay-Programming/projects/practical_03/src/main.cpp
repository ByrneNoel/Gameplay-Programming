#include <iostream>
#include <ctime>

#include <./include/Player.h>
#include <./include/NPC.h>

using namespace std;

class Game
{
private:
    Player player;
    NPC npc;

    GameObject *winner = nullptr;

public:
    Game() : player("Knight"), npc("Dragon") 
    {
        srand(time(0));
    }

    void gameloop()
    {
        cout << "Let make a virtual ;-) Turn Based Console Game" << endl;
        
        cout << "Let go create a Player" << endl;
        player.walk();

        cout << "Let go create an NPC" << endl;
        npc.walk(); 
                

        // Main GameLoop
        while (player.getHealth() > 0 && npc.getHealth() > 0)
        {
            if (player.getCooldown() > 0) player.setCooldown(player.getCooldown() - 1);

            player.attack(npc); // Player attacks NPC - Bound at runtime to Player's attack()     

            if (npc.getCooldown() > 0) npc.setCooldown(npc.getCooldown() - 1);

            npc.attack(player); // NPC attacks Player - Bound at runtime to NPC's attack()
          
                

            // Check for winner
            if (player.getHealth() <= 0)
            {
                winner = &npc;
                break; // End loop if winner is determined
            }
            else if (npc.getHealth() <= 0)
            {
                winner = &player;
                break; // End loop if winner is determined
            }
        }

        // Output the winner
        if (winner)
        {
            std::cout << winner->getName() << " has won the battle!" << std::endl;
        }
    }
};

int main()
{
    Game game;
    game.gameloop();
    cin.get();
}
