//
//  StateValue.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-27.
//

#ifndef StateValue_h
#define StateValue_h

#include <string>
#include <map>

struct StateValue{

	StateValue() = default;

	StateValue(const int v) {
		set(v);
	}

	StateValue(const double v) {
		set(v);
	}

	StateValue(const float v) {
		set(v);
	}

	StateValue(const bool v) {
		set(v);
	}

	inline void set(const int v) {
		_int = v;
		_type = intType;
	}

	inline void set(const double v) {
		_double = v;
		_type = doubleType;
	}

	inline void set(const float v) {
		_float = v;
		_type = floatType;
	}

	inline void set(const bool v) {
		_bool = v;
		_type = boolType;
	}

	inline int getInt() {
		return _int;
	}

	inline double getDouble() {
		return _double;
	}

	inline float getFloat() {
		return _float;
	}

	inline bool getBool() {
		return _bool;
	}

	inline std::string asString() const {
		switch(_type) {
			case intType:
				return std::to_string(_int);
			case doubleType:
				return std::to_string(_double);
			case floatType:
				return std::to_string(_float);
			case boolType:
				return _bool ? "Oui" : "Non";
		}
	}

	StateValue& operator = (int val) {
		set(val);
		return *this;
	}

	StateValue& operator = (double val) {
		set(val);
		return *this;
	}

	StateValue& operator = (float val) {
		set(val);
		return *this;
	}

	StateValue& operator = (bool val) {
		set(val);
		return *this;
	}

	operator std::string () const {
		switch(_type) {
			case intType:
				return std::to_string(_int);
			case doubleType:
				return std::to_string(_double);
			case floatType:
				return std::to_string(_float);
			case boolType:
				return std::to_string(_bool);
		}
	}

private:
	int _int;
	double _double;
	float _float;
	bool _bool;

	enum ValueType {
		intType,
		doubleType,
		floatType,
		boolType
	};

	ValueType _type;
};

using State = std::map<std::string, StateValue>;

#endif /* StateValue_h */
