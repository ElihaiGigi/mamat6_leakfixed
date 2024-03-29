#include "string-array.h"
StringArray::StringArray(){
    str_arr = new GenericString*[MAX_SEPARATION];
    GenericString* arr_elem;
    for(int i=0; i<MAX_SEPARATION; i++){
         arr_elem = new String();
         StringArray::set_element(arr_elem,i);
    }
}

StringArray::StringArray(const StringArray &other){
    str_arr = new GenericString*[MAX_SEPARATION];
    GenericString* elem;
    char* temp_str;
    for(int i=0;i<MAX_SEPARATION;i++) {
        temp_str = other.get_element(i)->as_string().get_string();
        elem = new String(temp_str);
        StringArray::set_element(elem, i);
    }
}

StringArray::~StringArray(){
        for(int i=0;i<MAX_SEPARATION;i++)
        {
            delete this->str_arr[i];
        }
        delete[] this->str_arr;
}

GenericString* StringArray::get_element(int index) const {
    return this->str_arr[index];
}

void StringArray::set_element( GenericString* str, int index){
    this->str_arr[index] = str;
}