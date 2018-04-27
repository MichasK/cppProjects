//
// Created by michal on 18.04.18.
//
#include "Product.hpp"
#include "Catalogue.hpp"

bool Catalogue::contains(std::string id)const{
    return _inventory.find(id)!=_inventory.end();
}

void Catalogue::addProduct(const Product& product){
    _inventory.emplace(product.getId(),product);
}

std::vector<Product> Catalogue::getProductsWithAppropriatePrice(std::function<bool (double)> predicate)const{
    std::vector<Product> v;
    for(const auto& entry: _inventory){
        const auto& product = entry.second;
        if(predicate(product.getPrice())) v.push_back(product);
    }
    return v;
}



