#include "Interface1.h"
//#include "Interface_Element.h"
Interface1::Interface1(){

	list_of_elements = new List();

	list_of_elements->addParameter(new Parameter("U battery" , 7.4 , "V", 0 )) ;
	list_of_elements->addParameter(new Parameter("Work time" , 2 , "h", 1)) ;
	list_of_elements->addParameter(new Parameter("Distance" , 100 , "m", 1)) ;
	list_of_elements->addParameter(new Parameter("En consumed" , 3 , "kWh", 0)) ;
	list_of_elements->addParameter(new Parameter("Temperature" , 20 , "C" , 0)) ;

    display();
}

Interface_Element::Action Interface1::getAction(Interface_Element::Button button){

	Interface_Element::Action action = list_of_elements->getParameter()->getButton(button);

	switch(action){
        case Interface_Element::ERROR_NO_CHANGEABLE:
            return Interface_Element::ERROR_NO_CHANGEABLE;

        case Interface_Element::MOVE_LEFT :
            list_of_elements->moveLeft() ;
            return Interface_Element::PRINT;

        case Interface_Element::MOVE_RIGHT:
            list_of_elements->moveRight();
            return Interface_Element::PRINT;

        case Interface_Element::DO_NOTHING:
            return Interface_Element::PRINT;
	}
}

void Interface1::display(){
    list_of_elements->getParameter()->sendToDisplay();
}

void Interface1::displayError(){
    list_of_elements->getParameter()->sendErrorNoChangeable() ;
}
