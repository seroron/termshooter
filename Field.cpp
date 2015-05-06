#include "Field.h"

#include "NCursesManager.h"

Field::Field() {
}
	
Field::~Field() {
}
	
void Field::move(taskarg_sptr arg) {		
}
	
void Field::draw(taskarg_sptr arg) {
    
    // 枠
    attrset(COLOR_PAIR(NCursesManager::CC_WHITE));
    for(int i=FIELD_Y_MIN; i<=FIELD_Y_MAX; i++){
        ::move(i, FIELD_X_MIN-1);
        printw("|");
        ::move(i, FIELD_X_MAX+1);
        printw("|");
    }
		
    for(int i=FIELD_X_MIN; i<=FIELD_X_MAX; i++){
        ::move(FIELD_Y_MIN-1, i);
        printw("-");
        ::move(FIELD_Y_MAX+1, i);
        printw("-");
    }		
}
