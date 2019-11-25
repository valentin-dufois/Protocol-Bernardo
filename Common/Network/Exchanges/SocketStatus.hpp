//
//  SocketStatus.hpp
//  pb-common
//
//  Created by Valentin Dufois on 2019-09-29.
//

#ifndef SocketStatus_h
#define SocketStatus_h

namespace pb {
namespace network {

/// Defines status a `Socket` can have in its lifetime
enum SocketStatus {
	idle,
	connecting,
	ready,
	closed
};

/// Defines available mechanisms for sending on a `Socket`
enum EmissionType {
	sync,
	async
};

/// Definese available formats when sending and receiving on a `Socket`
enum SocketFormat {
	protobuf,
	json
};

}
}

#endif /* SocketStatus_h */
