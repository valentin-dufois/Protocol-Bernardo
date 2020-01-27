//
//  S-203-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_203_00_hpp
#define S_203_00_hpp

#include "../../Output.hpp"

class S20300: public Output {
public:

	S20300(): Output(20300,	// Output ID
					 false,	// Is tree end ?
					 204,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
		"SUDDEN_MOVE_SPEED"
	},
					 {		// Captions
		"À {SUDDEN_MOVE_SPEED_STR} mm/s exactement. Enfin d’après mes calculs."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		_state["SUDDEN_MOVE_SPEED_STR"] = std::to_string(std::get<double>(behaviourState["SUDDEN_MOVE_SPEED"]));
		_state["SUDDEN_MOVE_SPEED"] = behaviourState["SUDDEN_MOVE_SPEED"];
		return true;
	};
};

#endif /* S_203_00_hpp */
