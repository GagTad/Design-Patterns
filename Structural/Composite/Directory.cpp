#include "Directory.h"
#include <iostream>
#include <algorithm> 

Directory::Directory(const std::string& name) : m_name(name) {}

void Directory::add(std::shared_ptr<IFileSystemComponent> component) {
    m_children.push_back(component);
}

void Directory::remove(std::shared_ptr<IFileSystemComponent> component) {
    auto it = std::find(m_children.begin(), m_children.end(), component);
    if (it != m_children.end()) {
        m_children.erase(it);
    }
}

long long Directory::getSize() const {
    long long totalSize = 0;

    std::cout << "[DEBUG] Calculating size for directory: " << m_name << std::endl;

    
    for (const auto& child : m_children) {
        totalSize += child->getSize();  
    }
    return totalSize;
}

void Directory::display(int indent) const {
 
    std::cout << std::string(indent, ' ') << "+ " << m_name << "/"
        << " (content size: " << this->getSize() << " bytes)" << std::endl;

    for (const auto& child : m_children) {
        child->display(indent + 4);
    }
}