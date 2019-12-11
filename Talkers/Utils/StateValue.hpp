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
	type(s.type), _v(s._v) {}

	StateValue(const bool v):
	type(boolType), _v(v) {}

	StateValue(const int v):
	type(intType), _v(v) {}

	StateValue(const double v):
	type(doubleType), _v(v) {}

	StateValue(const std::string v):
	type(stringType), _v(v) {}

	inline const bool& getBool() const {
		return *boost::get<bool>(&_v);
	}

	inline const int& getInt() const {
		return *boost::get<int>(&_v);
	}

	inline const double& getDouble() const {
		return *boost::get<double>(&_v);
	}

	inline const std::string& getString() const {
		return *boost::get<std::string>(&_v);
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

	operator const std::string& () const {
		return getString();
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

	StateValue& operator = (std::string val) {
		if(type == stringType)
			*boost::get<std::string>(&_v) = val;

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
			case stringType:
				return getString();
		}

		// Prevent warnings
		return "";
	}

	StateValue& operator = (const StateValue &s) {
		if(type == s.type)
			_v = s._v;

		return *this;
	}

	const enum ValueType {
		intType,
		doubleType,
		boolType,
		stringType
	} type;

private:
	boost::variant<int, double, bool, std::string> _v;
};

using State = std::map<std::string, StateValue>;

#endif /* StateValue_h */
