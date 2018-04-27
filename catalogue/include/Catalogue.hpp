//
// Created by michal on 18.04.18.
//

#ifndef CATALOGUE_CATALOGUE_HPP
#define CATALOGUE_CATALOGUE_HPP

#include <map>
#include <string>
#include <vector>
#include <functional>


#include "Product.hpp"
class Catalogue{
public:
    using inventory_t = std::map<std::string,Product>;
    Catalogue (const inventory_t& inventory = inventory_t{}):_inventory(_inventory){}
    void addProduct(const Product& product);
    bool contains(std::string id)const;
    std::vector<Product> getProductsWithAppropriatePrice(std::function<bool (double)> predicate)const;
private:
    inventory_t _inventory;
};
#endif //CATALOGUE_CATALOGUE_HPP
