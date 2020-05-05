#include "List.h"

//#define DEBUG

#ifdef DEBUG
string intToStr(int n){
	string tmp, ret;
	if(n < 0) {
		ret = "-";
		n = -n;
	}
	do {
		tmp += n % 10 + 48;
		n -= n % 10;
	}
	while(n /= 10);
	for(int i = tmp.size()-1; i >= 0; i--)
		ret += tmp[i];
	return ret;
}
#endif

List::List(){

}

char* List::stringToChar(string text){
	const int n = text.length();
	char tab[n];
	for(int i=0; i<n; i++)
		tab[i] = text[i] - (97-49);
	return tab;
}

void List::addFirstElement(List_element *element){
	first_element = current_element = last_element = element;
	size++;
}

void List::addNextElement(List_element *element){
    last_element->setNextPointer(element) ;
    first_element->setPrevPointer(element) ;
    element->setPrevPointer(last_element) ;
	last_element = element;
	last_element->setNextPointer(first_element) ;
	size++;
}

void List::addParameter(Parameter *parameter){
#ifdef DEBUG
	oled.ssd1306_SetCursor(5,10);
	oled.ssd1306_WriteString("Dodawanie elementu", Font_7x10, Black);
	oled.ssd1306_SetCursor(5,30);
	oled.ssd1306_WriteString(stringToChar(parameter->getHeadLine()), Font_7x10, Black);
	oled.ssd1306_UpdateScreen();
#endif

	if(size == 0){
		addFirstElement(new List_element(parameter));
	} else {
		addNextElement(new List_element(parameter));
	}

#ifdef DEBUG
	oled.ssd1306_SetCursor(5,50);
	oled.ssd1306_WriteString("Dodano, aktualny rozmiar listy", Font_7x10, Black);
	//cout << "Dodano, aktualny rozmiar listy: " << size << endl << endl;
#endif
	//     first_pointer =  ;
	//    if(first_element == 0)
	//    {
	//        cout << "Pierwszy " << endl;
	//
	//      current_element = first_element ;
	//    }
	//    else{
	//            cout << "Nie pierwszy " << endl;
	//        last_element = new List_element(parameter) ;
	//
	//        current_element->set_Next_Pointer(last_element);
	//       // first_element->set_Prev_Pointer(last_element);
	//
	//        last_element->set_Next_Pointer(first_element);
	//        //last_element->set_Prev_Pointer(current_element);
	//
	//        current_element = last_element ;
	//    }

}

Parameter* List::getParameter(){
    return current_element->getCurrentParameter() ;
}
/*
void List::print(){
	cout << "Rozmiar listy: " << size << endl;
	List_element *printing_element = first_element;
	for(int i = 0; i <size; i++){
		cout << "element: " << i << endl;
		printing_element->print();
		printing_element = printing_element->next;
	}
}
*/

uint16_t List::getSize(){
    return size ;
}

void List::moveRight(){
    current_element = current_element->getNextPointer() ;
}

void List::moveLeft(){
    current_element = current_element->getPrevPointer();
}
