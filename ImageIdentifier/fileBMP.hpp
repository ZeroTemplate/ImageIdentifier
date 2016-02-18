//
//  fileBMP.hpp
//  ImageIdentifier
//
//  Created by Bogdan Trastes on 18/02/16.
//  Copyright © 2016 Bogdan Trastes. All rights reserved.
//

#ifndef fileBMP_hpp
#define fileBMP_hpp

#include <vector>
#include "imageFile.h"

class fileBMP : public imageFile {
public:
    bool doOperation(){return true;}
    void setPath(std::string const &filePath){imageFile::setFilePath(filePath);}
    void Free() {delete this;}
    void printFileType() {std::cout << "File is BMP" << std::endl;}
    
public:
    static imageFile* Create() { return new fileBMP();}
};


#endif /* fileBMP_hpp */
