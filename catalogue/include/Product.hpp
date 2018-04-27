//
// Created by michal on 18.04.18.
//

#ifndef CATALOGUE_PRODUCT_HPP
#define CATALOGUE_PRODUCT_HPP

#include <string>
class Product{
private:
    std::string _id;
    std::string _name;
    double _price;
public:
    Product(std::string id,std::string name, double price):_id(id),_name(name),_price(price){};
    std::string getId()const{return _id;}
    std::string getName()const{return _name;}
    double getPrice()const{return _price;}
};
std::string to_string(const Product& product);
#endif //CATALOGUE_PRODUCT_HPP
