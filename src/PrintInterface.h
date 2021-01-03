#pragma once
#include <iostream>
#include <fstream>

class PrintInterface
{
public:
	virtual ~PrintInterface() = default;
	
	virtual void print_to_console(std::ostream& os) const = 0;
	virtual void print_to_file(std::ofstream& ofs) const = 0;
	
	friend std::ostream& operator<< (std::ostream& os, \
	const PrintInterface& Obj)
	{
		Obj.print_to_console(os);
        return os;
	}
	
	friend std::ofstream& operator<< (std::ofstream& ofs, \
	const PrintInterface& Obj)
	{
		Obj.print_to_file(ofs);
		return ofs;
	}
};