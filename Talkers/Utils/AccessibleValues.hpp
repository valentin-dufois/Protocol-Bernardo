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
	RECEIVED_QUESTIONS_COUNT
};

inline std::string accessibleValueLabel(const AccessibleValues &valueID) {
	switch(valueID) {
		case BODY_COUNT: 				return "BODY_COUNT";
		case RECEIVED_QUESTIONS_COUNT: 	return "RECEIVED_QUESTIONS_COUNT";
	}
}

#endif /* AccessibleValues_h */
