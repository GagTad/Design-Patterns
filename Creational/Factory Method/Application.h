#pragma once

#include "Document.h"
#include <memory>

// 4. Abstract Creator (Creator)
class Application {
public:
    virtual ~Application() = default;


    virtual std::unique_ptr<Document> createDocument() = 0;

    void newDocument() {
        std::cout << "Application: Core logic is running." << std::endl;
        std::unique_ptr<Document> doc = createDocument();
        doc->open();

        doc->close();
    }
};

// 5. Concrete Creator 1
class TextApplication : public Application {
public:

    std::unique_ptr<Document> createDocument() override {
        std::cout << "TextApplication: Creating a TextDocument." << std::endl;
        return std::make_unique<TextDocument>();
    }
};

// 6. Concrete Creator 2
class SpreadsheetApplication : public Application {
public:
    
    std::unique_ptr<Document> createDocument() override {
        std::cout << "SpreadsheetApplication: Creating a SpreadsheetDocument." << std::endl;
        return std::make_unique<SpreadsheetDocument>();
    }
};
