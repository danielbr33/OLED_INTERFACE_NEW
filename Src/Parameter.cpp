#include "Parameter.h"
Parameter::Parameter(string h, int v, string u , bool ch ){
	headline = h;
	value = v ;
	unit = u ;
	if_changeable_value = ch;
	edit_mode = 0 ;
}

void Parameter::sendToDisplay()
{
	oled.ssd1306_SetCursor(5,30);
	oled.ssd1306_WriteString((char*)headline.c_str(), Font_7x10, Black);
	oled.ssd1306_SetCursor(5,50);
	char temp[15];
	sprintf(temp, "%d", value);
	oled.ssd1306_WriteString(temp, Font_7x10, Black);
	oled.ssd1306_UpdateScreen();
}
void Parameter::sendErrorNoChangeable(){
	oled.ssd1306_SetCursor(5,20);
	oled.ssd1306_WriteString("No change possible", Font_7x10, Black);
	oled.ssd1306_UpdateScreen();
}

Interface_Element::Action Parameter::getButton(Interface_Element::Button button){

    if( button == Interface_Element::ENTER){
        if(edit_mode){
                edit_mode=0;
        }
        else{
            if(if_changeable_value)
                edit_mode=1 ;
            else
                return Interface_Element::ERROR_NO_CHANGEABLE;
        }
        return Interface_Element::DO_NOTHING ;
    }
    else if(edit_mode) {
		if(button == Interface_Element::RIGHT_BUTTON){
			value++;
			return Interface_Element::DO_NOTHING ;
		}
		else if(button == Interface_Element::LEFT_BUTTON){
            value--;
            return Interface_Element::DO_NOTHING ;
		}
    }
    else if( button == Interface_Element::LEFT_BUTTON){
        return Interface_Element::MOVE_LEFT ;
    }
    else if( button == Interface_Element::RIGHT_BUTTON){
        return Interface_Element::MOVE_RIGHT ;
    }
}

/*
string Parameter::getHeadLine(){
	return this->headline;
}
*/
