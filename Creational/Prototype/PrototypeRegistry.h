#pragma once

#include "Shape.h"
#include <map>
#include <string>
#include <memory>

class PrototypeRegistry {
private:
    std::map<std::string, std::unique_ptr<Shape>> m_prototypes;

public:
   
    void addPrototype(const std::string& key, std::unique_ptr<Shape> prototype) {
        m_prototypes[key] = std::move(prototype);
    }

   
    std::unique_ptr<Shape> create(const std::string& key) {
        if (m_prototypes.count(key)) {
           
            return m_prototypes.at(key)->clone();
        }
        return nullptr; 
    }
};