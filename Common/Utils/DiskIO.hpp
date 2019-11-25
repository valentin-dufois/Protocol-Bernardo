//
//  diskIO.hpp
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

#include "../Network/Messages/messages.hpp"

namespace fs = std::filesystem;

namespace pb {
namespace diskIO {

/// Parse the specified file into a protobuf `Message` using the provided template class
/// @tparam T The `protobuf::Message` derived class to use for parsing the message
/// @param filename The file to read with its path
template<class T>
inline T * read(const std::string &filename) {
	protobuf::Message * content = new T();

	// Get the stream and parse
	std::ifstream input(filename, std::ios::in);
	content->ParseFromIstream(&input);

	return dynamic_cast<T *>(content);
}

/// Write the given message to the specified filename
/// @param filename The destination
/// @param content File content
inline void write(const std::string &filename, protobuf::Message * content) {
	std::ofstream output(filename, std::ofstream::out);

	content->SerializeToOstream(&output);

	return;
}

/// Create a new directory
/// @param directoryPath Path for the new directory
inline bool mkdir(const std::string &directoryPath) {
	if(fs::exists(directoryPath))
		return false;

	std::filesystem::create_directory(directoryPath);
	return true;
}

/// Rename a file. Can be used to move a file
/// @param from The original file
/// @param to The new file
inline void rename(const std::string &from, const std::string &to) {
	std::filesystem::rename(from, to);
}

/// List the content of the specified directory, ignore special paths ('.' & '..')
/// @param directoryPath The directory to parse
inline std::vector<std::string> ls(const std::string directoryPath) {
	std::vector<std::string> entries;

	// For each entry in the folder
	for(fs::directory_entry entry: fs::directory_iterator(directoryPath)) {
		entries.push_back(std::string(entry.path().filename()));
	}

	return entries;
}

/// Remove the specified file or folder. Wildcards car be used
/// @param path The path to the element to remove
inline void rm(const std::string path) {
	std::filesystem::remove_all(path);
}

} /* ::diskIO */
} /* ::pb */

#endif /* DiskIO_h */
