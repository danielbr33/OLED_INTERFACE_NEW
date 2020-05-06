#include "Interface1_manager.h"
#define BUTTON_1 'a' // left
#define BUTTON_2 'd' // right
#define BUTTON_3 's' // down
#define SPECIAL_BUTTON 'w'

void Interface1_manager::interrupt(){
	if (edit_flag==true && button!=SPECIAL_BUTTON)
	    print( Ssd_1306->getAction(readKey()) );
	if (button==SPECIAL_BUTTON){
		if(edit_flag==false){
			edit_flag=true;
			oled.ssd1306_SetCursor(5,0);
			oled.ssd1306_WriteString("EDIT ON ", Font_11x18, Black);
			oled.ssd1306_UpdateScreen();
		}
		else{
			edit_flag=false;
			oled.ssd1306_SetCursor(5,0);
			oled.ssd1306_WriteString("EDIT OFF", Font_11x18, Black);
			oled.ssd1306_UpdateScreen();
		}
	}
	HAL_UART_Receive_DMA(&huart2, (uint8_t*)&button, 1);
}

void Interface1_manager::init(){
    Ssd_1306 = new Interface1 ;
    edit_flag=false;
	HAL_UART_Receive_DMA(&huart2, (uint8_t*)&button, 1);
}

Interface1_manager::Interface1_manager(){
}

Interface_Element::Button Interface1_manager::readKey(){
	switch(button){
	case BUTTON_1:
		return Interface_Element::LEFT_BUTTON;
	case BUTTON_2:
		return Interface_Element::RIGHT_BUTTON;
	case BUTTON_3:
		return Interface_Element::ENTER ;
	break;
	}
}

void Interface1_manager::print(Interface_Element::Action info) {

    if( info == Interface_Element::PRINT){
        Ssd_1306->display() ;
    }
    else if( info ==Interface_Element::ERROR_NO_CHANGEABLE){
        Ssd_1306->displayError() ;
    }
}
