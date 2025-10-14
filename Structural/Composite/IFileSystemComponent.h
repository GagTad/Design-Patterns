#pragma once
#include <string> 

class IFileSystemComponent {
public:
 
    virtual long long getSize() const = 0;
    virtual void display(int indent = 0) const = 0;
    virtual ~IFileSystemComponent() = default;
};