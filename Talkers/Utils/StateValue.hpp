//
//  StateValue.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-11-27.
//

#ifndef StateValue_h
#define StateValue_h

#include <boost/variant.hpp>

#include <string>
#include <map>

struct StateValue {

	StateValue(const StateValue &s):
	_v(s._v), type(s.type) {}

	StateValue(const bool v):
	_v(v), type(boolType) {}

	StateValue(const int v):
	_v(v), type(intType) {}

	StateValue(const double v):
	_v(v), type(doubleType) {}

	inline const bool& getBool() const {
		return *boost::get<bool>(&_v);
	}

	inline const int& getInt() const {
		return *boost::get<int>(&_v);
	}

	inline const double& getDouble() const {
		return *boost::get<double>(&_v);
	}

	operator const bool& () const {
		return getBool();
	}

	operator const int& () const {
		return getInt();
	}

	operator const double& () const {
		return getDouble();
	}

	StateValue& operator = (bool val) {
		if(type == boolType)
			*boost::get<bool>(&_v) = val;

		return *this;
	}

	StateValue& operator = (int val) {
		if(type == intType)
			*boost::get<int>(&_v) = val;

		return *this;
	}

	StateValue& operator = (double val) {
		if(type == doubleType)
			*boost::get<double>(&_v) = val;

		return *this;
	}

	inline std::string asString() const {
		switch(type) {
			case intType:
				return std::to_string(getInt());
			case doubleType:
				return std::to_string(getDouble());
			case boolType:
				return std::to_string(getBool());
		}
	}

	operator std::string () const {
		return asString();
	}

	StateValue& operator = (const StateValue &s) {
		if(type == s.type)
			_v = s._v;

		return *this;
	}

	const enum ValueType {
		intType,
		doubleType,
		boolType
	} type;

private:
	boost::variant<int, double, bool> _v;
};

using State = std::map<std::string, StateValue>;

#endif /* StateValue_h */
