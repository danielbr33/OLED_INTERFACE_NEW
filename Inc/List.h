#include "List_element.h"
#include "SSD1306.h"
#ifndef LIST_h_
#define LIST_H_

extern SSD1306 oled;
class List{
private:

    List_element *current_element;
    List_element *last_element ;
    List_element *first_element ;

    void addFirstElement(List_element *element);
    void addNextElement(List_element *element);

    uint16_t size = 0;

public :
    List() ;
    Parameter* getParameter();
    void addParameter(Parameter *parameter) ;
    void moveRight() ;
    void moveLeft() ;
    uint16_t getSize() ;
    char* stringToChar(string text);

   // void print();
};
#endif /* LIST_h_ */
