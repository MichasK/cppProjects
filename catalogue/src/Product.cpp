//
// Created by michal on 18.04.18.
//

#include "Product.hpp"

#include <sstream>

std::string to_string(const Product &product) {
    std::ostringstream oss;
    oss << product.getName() << "[" << product.getId() << "]" << " : $" << product.getPrice();
    return oss.str();
}