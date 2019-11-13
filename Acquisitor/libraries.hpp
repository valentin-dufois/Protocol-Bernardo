//
//  libraries.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef libraries_h
#define libraries_h

#define MACHINE_ACQUISITOR

// MARK: - OpenNI2/NiTE2
#ifdef __APPLE__
#    include <ni2/OpenNI.h>
#else
#    include <openni2/OpenNI.h>
#endif

#include <nite2/NiTE.h>

// MARK: - OpenCV
// #include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>
// #include <opencv2/imgproc/imgproc.hpp>

// MARK: - Commons

#include "../Common/Utils/flags.hpp"
#include "../Common/Utils/Log.hpp"
#include "../Common/Utils/maths.hpp"

#include "../Common/Structs/RawBody.hpp"

#endif /* libraries_h */
