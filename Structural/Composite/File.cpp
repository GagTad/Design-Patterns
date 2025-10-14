#include "File.h"
#include <iostream>

File::File(const std::string& name, long long size)
    : m_name(name), m_size(size) {
}

long long File::getSize() const {
    return m_size;
}

void File::display(int indent) const {
    std::cout << std::string(indent, ' ') << "- " << m_name
        << " (" << m_size << " bytes)" << std::endl;
}