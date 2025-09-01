#include "Game.h";
#include <vector>
#include <list>


int main()
{
    
   
    Game gm;    //create the handy dandy game object
    gm.init();

    for (int i = 0; i < 100; i++)   //100 rounds of chaos
    {
        cout << "TURN: " << i+1 << "\n";
        cout << "---------/" << "\n";

        //calling the functions in ascending order
        gm.render();
        gm.update();
        gm.battle();
        gm.stats();
        gm.clean();

    }

    cout << "FINAL RESULT STATS" << "\n";   //end screen after all the bloodshed
    gm.stats();
    
    return 0;
}
