//
//  S-603-00.hpp
//  Talkers
//
//  Created by Marie-Lou Barbier on 2019-12-07.
//

#ifndef S_603_00_hpp
#define S_603_00_hpp

#include "../../Output.hpp"

class S60300 : public Output {
public:

	S60300() : Output(60300,	// Output ID
		false,	// Is tree end ?
		604,	// Next Behaviour ID
		DELAY_DEFAULT,	// Is delayed
		DELAY_VALUE_DEFAULT,		// Delay value (seconds)
		DELAY_VARIANCE_DEFAULT,		// Delay variance (seconds)
		{		// Output values
		},
		{		// Captions
			"Je me base sur un nombre que je considère comme un seuil. Lorsque tu m'indiques un nombre, je me base sur ce seuil pour exprimer un avis."
		}) {}

	virtual bool isConditionValid(State &behaviourState) override {
		return true;
	};
};

#endif /* S_603_00_hpp */
