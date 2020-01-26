//
//  S-205-00.hpp
//  Talkers
//
//  Created by Valentin Dufois on 2019-12-02.
//

#ifndef S_205_00_hpp
#define S_205_00_hpp

#include "../../Output.hpp"

class S20500: public Output {
public:

	S20500(): Output(20500,	// Output ID
					 false,	// Is tree end ?
					 206,	// Next Behaviour ID
					 DELAY_DEFAULT,	// Is delayed
					 DELAY_VALUE_DEFAULT,		// Delay value (seconds)
					 DELAY_VARIANCE_DEFAULT ,		// Delay variance (seconds)
					 {		// Output values
		"SUDDEN_MOVE_SPEED_TIMES_FROM_AVERAGE"
	},
					 {		// Captions
		"C'est {SUDDEN_MOVE_SPEED_TIMES_FROM_AVERAGE_STR} fois la vitesse moyenne des personnes présentes."
	}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		_state["SUDDEN_MOVE_SPEED_TIMES_FROM_AVERAGE_STR"] = std::to_string(std::get<double>(behaviourState["SUDDEN_MOVE_SPEED_TIMES_FROM_AVERAGE"]));
		return true;
	};
};

#endif /* S_205_00_hpp */
