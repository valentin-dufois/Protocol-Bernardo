//
//  flags.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-10-12.
//

#ifndef flags_hpp
#define flags_hpp

#include <boost/program_options.hpp>


namespace po = boost::program_options;

namespace pb {
namespace flags {

	extern po::variables_map args;

	inline void parse(const int &argc, const char * argv[], po::options_description &desc) {
		// Insert common options
		desc.add_options()
			("help", "Display help message")
			("interface", po::value<std::string>(), "Network interface to use");
		
		po::store(po::parse_command_line(argc, argv, desc), args);
		po::notify(args);
	}

} /* ::flags */
} /* ::pb */
#endif /* flags_hpp */
