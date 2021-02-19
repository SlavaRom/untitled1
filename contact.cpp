//
// Created by ne555 on 12.02.2021.
//

#include <string>
#include "contact.h"

contact::contact(const string& n, const int a,const string& p) {
    _name = n;
    _age = a;
    _phone = p;
}

ostream& operator<<(ostream& o, const contact& c){
    o << c.name() << '/' << c.age() << '/' << c.phone() << endl;
    return o;
}

const std::string contact::name() const{
    return _name;
}

const int contact::age() const{
    return _age;
}

const std::string contact::phone() const{
    return _phone;
}