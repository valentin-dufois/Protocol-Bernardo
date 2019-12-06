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

	inline void set(const bool v) {
		_bool = v;
		_type = boolType;
	}

	inline int getInt() const {
		return _int;
	}

	inline double getDouble() const {
		return _double;
	}

	inline bool getBool() const {
		return _bool;
	}

	inline std::string asString() const {
		switch(_type) {
			case intType:
				return std::to_string(_int);
			case doubleType:
				return std::to_string(_double);
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
			case boolType:
				return std::to_string(_bool);
		}
	}

	operator int () const {
		return _int;
	}

	operator double () const {
		return _int;
	}

	operator bool () const {
		return _int;
	}

private:
	int _int;
	double _double;
	bool _bool;

	enum ValueType {
		intType,
		doubleType,
		boolType
	};

	ValueType _type;
};

using State = std::map<std::string, StateValue>;

#endif /* StateValue_h */
