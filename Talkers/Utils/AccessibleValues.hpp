//
//  AccessibleValues.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-12-04.
//

#ifndef AccessibleValues_h
#define AccessibleValues_h

enum AccessibleValues {
	BODY_COUNT,
	RECEIVED_QUESTIONS_COUNT,
	SUDDEN_MOVE,
	SUDDEN_MOVE_SPEED,
	AVG_MOVE_SPEED
};

inline std::string accessibleValueLabel(const AccessibleValues &valueID) {
	switch(valueID) {
		case BODY_COUNT: 				return "BODY_COUNT";
		case RECEIVED_QUESTIONS_COUNT: 	return "RECEIVED_QUESTIONS_COUNT";
		case SUDDEN_MOVE: 				return "SUDDEN_MOVE";
		case SUDDEN_MOVE_SPEED: 			return "SUDDEN_MOVE_SPEED";
		case AVG_MOVE_SPEED: 			return "AVG_MOVE_SPEED";
	}
}

#endif /* AccessibleValues_h */
