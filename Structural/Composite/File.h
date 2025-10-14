#pragma once
#include "IFileSystemComponent.h" 


class File : public IFileSystemComponent {
private:
    std::string m_name;
    long long m_size;

public:

    File(const std::string& name, long long size);
    long long getSize() const override;
    void display(int indent = 0) const override;
};