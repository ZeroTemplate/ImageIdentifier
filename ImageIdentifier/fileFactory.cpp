//
//  fileFactory.cpp
//  ImageIdentifier
//
//  Created by Bogdan Trastes on 18/02/16.
//  Copyright © 2016 Bogdan Trastes. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <array>

#include "fileFactory.hpp"

#define HEADER_LEN  18

fileFactory *fileFactory::Get() {
    static fileFactory instance;
    return &instance;
}

void fileFactory::Register(IMG_TYPE imageOBJ, CreateImageObjFn pfnCreate, std::vector<uint8_t> &data) {
    m_FactoryMap[imageOBJ] = pfnCreate;
    headerMap[imageOBJ] = data;
}

imageFile *fileFactory::CreateOBJ(const std::string &filePath) {
    
    IMG_TYPE type = readFileHeader(filePath);
    if (type == IMG_TYPE::INVALID) {
        return nullptr;
    }
    
    FactoryMap::iterator it = m_FactoryMap.find(type);
    if( it != m_FactoryMap.end() )
        return it->second();
    return nullptr;
}

IMG_TYPE fileFactory::readFileHeader(const std::string &filePath) {
    std::fstream file(filePath, std::ios::in | std::ios::binary);
    
    if (!file.is_open()) {
        std::cout << "File Not Found.\n";
    }
    
    std::uint8_t header[HEADER_LEN] = {0};
    file.read(reinterpret_cast<char*>(&header), sizeof(header));
    file.seekg(0, std::ios::beg);
    file.close();
    
    for (const auto &it : headerMap) {
        if (std::equal(it.second.begin(), it.second.end(), header)) {
            return it.first;
        }
    }
    
    return IMG_TYPE::INVALID;
}