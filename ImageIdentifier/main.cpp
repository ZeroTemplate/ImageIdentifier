//
//  main.cpp
//  ImageIdentifier
//
//  Created by Bogdan Trastes on 18/02/16.
//  Copyright © 2016 Bogdan Trastes. All rights reserved.
//

#include <iostream>
#include "fileFactory.hpp"

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        std::cout << "The programm should be used with a parameter.\n"
                    "The second parameter is represented by the absolute path to the image file." << std::endl;
        return 0;
    }
    
    std::cout << "Path to file [" << argv[1] << "]" << std::endl;
    
    imageFile *pImageFile = fileFactory::Get()->CreateOBJ(argv[1]);

    if(pImageFile) {
        pImageFile->printFileType();
    } else {
        std::cout << "This image isn't supported yet. (Only JPG/BMP)" << std::endl;
    }
    
    if(pImageFile) {
        pImageFile->Free();
        pImageFile = nullptr;
    }
    
    return 0;
}
