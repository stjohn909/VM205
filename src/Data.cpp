#include "vm205/Data.h"

namespace vm205 {

Data::Data(int size):
	_size(size) {
	_values = new Value[size];
}

Data::~Data() {
	delete[] _values;
}

Value& Data::value(int index) {
	return _values[index];
}

Value& Data::operator[](int index) {
	return value(index);
}

int Data::size() const {
	return _size;
}

}