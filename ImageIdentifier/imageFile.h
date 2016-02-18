//
//  imageFile.h
//  ImageIdentifier
//
//  Created by Bogdan Trastes on 18/02/16.
//  Copyright © 2016 Bogdan Trastes. All rights reserved.
//

#ifndef imageFile_h
#define imageFile_h

#include <String>
#include <Vector>

class imageFile {
public:
    virtual bool doOperation() = 0;
    virtual void setFilePath(std::string const &filePath) {this->filePath = filePath;}
    virtual void printFileType() = 0;
    virtual void Free() = 0;
    
protected:
    std::string filePath;
//    imageFile();
};

typedef imageFile* (*CreateImageObjFn)(void);

#endif /* imageFile_h */
