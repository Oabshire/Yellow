#include "overloads.h"

template<typename Key, typename Value>
ostream& operator<< (ostream & os, pair<Key, Value>p) {
	os << p.first << " " << p.second;
	return os;
}
