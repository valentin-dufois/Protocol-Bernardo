//
//  DiskIO.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-10-02.
//

#ifndef DiskIO_h
#define DiskIO_h

#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

#include "../Messages/messages.hpp"

namespace DiskIO {

template<class T>
inline T * read(const std::string &filename) {
	protobuf::Message * content = new T();

	// Get the stream and parse
	std::ifstream input(filename, std::ios::in);
	content->ParseFromIstream(&input);

	return dynamic_cast<T *>(content);
}

inline void write(const std::string &filename, protobuf::Message * content) {
	std::ofstream output(filename, std::ofstream::out);

	content->SerializeToOstream(&output);

	return;
}

inline bool mkdir(const std::string &directoryPath) {
	if(fs::exists(directoryPath))
		return false;

	std::filesystem::create_directory(directoryPath);
	return true;
}

inline void rename(const std::string &from, const std::string &to) {
	std::filesystem::rename(from, to);
}

inline std::vector<std::string> ls(const std::string folderPath) {
	std::vector<std::string> entries;

	// For each entry in the folder
	for(fs::directory_entry entry: fs::directory_iterator(folderPath)) {
		entries.push_back(std::string(entry.path().filename()));
	}

	return entries;
}

inline void rm(const std::string path, const bool &iterate = false) {
	if(iterate) {
		std::filesystem::remove_all(path);
		return;
	}
	std::filesystem::remove(path);
}

}

#endif /* DiskIO_h */
