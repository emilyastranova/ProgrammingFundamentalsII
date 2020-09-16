
//
//  Created by Tyler Harrison
//

#include <iostream>
#include "AlienType.h"
#include "MartianType.h"
#include "JuperterianType.h"

int main()
{
    AlienType ET = AlienType("ET", 2, 2); // AlienType allows you to choose custom amounts of eyes and legs
    ET.print();

    MartianType marty = MartianType("Marty"); // All Martians have 3 eyes and 2 legs
    marty.print();

    JuperterianType juny = JuperterianType("Juny"); // All Juperterians have 1 eye and 5 legs
    juny.print();

    return 0;
}
