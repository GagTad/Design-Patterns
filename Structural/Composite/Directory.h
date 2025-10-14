#pragma once
#include "IFileSystemComponent.h"
#include <vector>
#include <memory>  

 class Directory : public IFileSystemComponent {
private:
    std::string m_name;
    std::vector<std::shared_ptr<IFileSystemComponent>> m_children;

public:
 
    Directory(const std::string& name);
    void add(std::shared_ptr<IFileSystemComponent> component);
    void remove(std::shared_ptr<IFileSystemComponent> component);
    long long getSize() const override;
    void display(int indent = 0) const override;
};