//
//  DiskIO.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-10-02.
//

#ifndef DiskIO_h
#define DiskIO_h

#include <iostream>
#include <fstream>

#include "../Messages/messages.hpp"

namespace DiskIO {
inline protobuf::Message * read(const std::string &filename) {

}

void write(const std::string &filename, protobuf::Message * &content);
}

#endif /* DiskIO_h */
