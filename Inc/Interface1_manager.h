#include "Interface1.h"
#include "SSD1306.h"
#include "main.h"

#ifndef INTERFACE1MANAGER_H_
#define INTERFACE1MANAGER_H_

extern SSD1306 oled;
extern UART_HandleTypeDef huart2;
class Interface1_manager{
public:
	Interface1_manager() ;
    void print(Interface_Element::Action info);
    void interrupt();
private:
	Interface1 *Ssd_1306 ;
	Interface_Element::Button readKey() ;
	char button;
	bool edit_flag;
};
#endif /* INTERFACE1MANAGER_H_ */
