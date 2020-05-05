#include "Interface_Element.h"
#include "SSD1306.h"

#ifndef PARAMETER_H_
#define PARAMETER_H_

#include <iostream>
#include <cstdio>
#include <stdint.h>
#include <cstdlib>

extern SSD1306 oled;
using namespace std;

class Parameter {
private:
	string headline;
	int value ;
	string unit;
    bool edit_mode ;
public:
	Parameter(string, int, string, bool ) ;
	bool if_changeable_value ;
	void sendToDisplay() ;
	Interface_Element::Action getButton(Interface_Element::Button) ;
	void sendErrorNoChangeable() ;
	char* stringToChar(string);
	//string getHeadLine();
};


#endif /* PARAMETER_H_ */
