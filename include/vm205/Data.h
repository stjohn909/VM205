/*
 * Copyright (C) 2015 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file Data.h
 * @brief 
 * @author Gunther Van Butsele
 */
#ifndef VM205_DATA_H
#define VM205_DATA_H

namespace vm205 {

typedef unsigned char Value;

class Data {
public:
	Data(int size);
	~Data();
	Value& value(int index);
	Value& operator[](int index);	
	int size() const;
protected:
private:
	Value* _values;
	int m_size;
};

}

#endif
