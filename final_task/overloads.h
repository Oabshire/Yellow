#pragma once

#include <utility>
#include <iostream>

using namespace std;

template< class Key,class Value>
ostream& operator <<  (ostream & os, pair<Key, Value> p);
