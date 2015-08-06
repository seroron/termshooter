#include <ostream>

#include "TermShooter.h"
#include "NCursesManager.h"

int main()
{
    NCursesManager::getInst();
    
    TermShooter term_shooter;
    term_shooter.start();

    return 0;
}

