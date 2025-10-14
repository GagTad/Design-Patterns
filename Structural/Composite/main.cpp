#include <iostream>
#include <memory>  

#include "File.h"
#include "Directory.h"

int main() {
    std::cout << "==========================================" << std::endl;
    std::cout << "   File System Simulator (Composite)      " << std::endl;
    std::cout << "==========================================" << std::endl << std::endl;
 
    auto root = std::make_shared<Directory>("root");
 
    auto documents = std::make_shared<Directory>("Documents");
    auto pictures = std::make_shared<Directory>("Pictures");
    auto music = std::make_shared<Directory>("Music");
 
    root->add(documents);
    root->add(pictures);
    root->add(music);

  
    // Documents
    documents->add(std::make_shared<File>("report.docx", 2048));
    documents->add(std::make_shared<File>("notes.txt", 512));

    // Pictures
    pictures->add(std::make_shared<File>("photo1.jpg", 4096));
    pictures->add(std::make_shared<File>("logo.png", 1024));

    // Music
    music->add(std::make_shared<File>("track1.mp3", 5120));
    music->add(std::make_shared<File>("track2.mp3", 6144));

 
    root->add(std::make_shared<File>("config.sys", 256));

   
    auto vacation_photos = std::make_shared<Directory>("Vacation2023");
    vacation_photos->add(std::make_shared<File>("beach.jpg", 3072));
    vacation_photos->add(std::make_shared<File>("mountain.jpg", 3584));
    pictures->add(vacation_photos);

     
    std::cout << "--- Displaying the entire file system structure ---" << std::endl;
   
    root->display();
    std::cout << std::endl;

    std::cout << "--- Calculating sizes of different components ---" << std::endl;
 
    auto report_file = std::make_shared<File>("temp_report.docx", 1234);
    std::cout << "Size of a single file (temp_report.docx): " << report_file->getSize() << " bytes" << std::endl;
 
    std::cout << "Total size of 'Pictures' directory: " << pictures->getSize() << " bytes" << std::endl;
 
    std::cout << "Total size of the entire file system ('root'): " << root->getSize() << " bytes" << std::endl;

    return 0;
}
