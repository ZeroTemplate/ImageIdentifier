//
//  fileJPG.hpp
//  ImageIdentifier
//
//  Created by Bogdan Trastes on 18/02/16.
//  Copyright © 2016 Bogdan Trastes. All rights reserved.
//

#ifndef fileJPG_hpp
#define fileJPG_hpp

#include "imageFile.h"

class fileJPG : public imageFile {
public:
    bool doOperation() {return true;}
    void setFilePath(std::string const &filePath){imageFile::setFilePath(filePath);}
    void Free() {delete this;}
    void printFileType() {std::cout << "File is JPG" << std::endl;}
    
private:
    static std::vector<std::uint8_t> const JPGBytes;
    
public:
    static imageFile* Create() { return new fileJPG();}
};


#endif /* fileJPG_hpp */
