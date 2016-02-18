//
//  fileFactory.hpp
//  ImageIdentifier
//
//  Created by Bogdan Trastes on 18/02/16.
//  Copyright © 2016 Bogdan Trastes. All rights reserved.
//

#ifndef fileFactory_hpp
#define fileFactory_hpp

#include <string>
#include <map>

#include "imageFile.h"
#include "fileJPG.hpp"
#include "fileBMP.hpp"

enum IMG_TYPE {BMP = 0, JPG = 1, INVALID = -1};
#define IMG_OBJ_CODED 2

class fileFactory
{
private:
    fileFactory() {
        std::vector<std::uint8_t> BMPBytes = {0x42, 0x4D};
        std::vector<std::uint8_t> JPGBytes = {0xFF, 0xD8, 0xFF};
        
        Register(IMG_TYPE::BMP, &fileBMP::Create, BMPBytes);
        Register(IMG_TYPE::JPG, &fileJPG::Create, JPGBytes);
    }
    
    fileFactory(const fileFactory &) { }
    fileFactory &operator=(const fileFactory &) { return *this; }
    
    typedef std::map<IMG_TYPE, CreateImageObjFn>	FactoryMap;
    FactoryMap		m_FactoryMap;
    std::map<IMG_TYPE, std::vector<std::uint8_t>> headerMap;
    IMG_TYPE readFileHeader(const std::string &filePath);
    
public:
    ~fileFactory() { m_FactoryMap.clear(); }
    
    static fileFactory *Get();
    
    void Register(IMG_TYPE imagetype, CreateImageObjFn pfnCreate, std::vector<std::uint8_t> &data);
    imageFile *CreateOBJ(const std::string &filePath);
};

#endif /* fileFactory_hpp */
