#pragma once
#include "PrintInterface.h"
#include <fstream>
#include <ostream>

template<class T, class U>
//class pair: public PrintInterface
class pair
{
private:
    T tag_;
    U key_;

public:
	pair():
		tag_{},
		key_{}
	{}
	
    pair(T tag, U key):
       tag_{tag},
       key_{key}
    {}
  
    pair(const pair& Pair):
       tag_{Pair.tag_},
       key_{Pair.key_}
    {}
  
    T get_tag() const
    {
        return tag_;
    }
  
    U get_key() const
    {
        return key_;
    }
	
	void set_tag(const T& Tag)
	{
		tag_ = Tag;
	}

	void set_key(const U& Key)
	{
		key_ = Key;
	}
	
	pair operator= (const pair& Pair)
	{
		tag_ = Pair.tag_;
		key_ = Pair.key_;
		
		return *this;
	}
	
	bool operator== (const pair& Pair) const
	{
		return true&&(key_ == Pair.key_)&&(tag_ == Pair.tag_);
	}
	
	bool operator!= (const pair& Pair) const
	{
		return !(*this==Pair);
	}

//    virtual void print_to_console(std::ostream& os) const override
//    {
//        os << "{" << tag_ << "," << key_ << "}" << '\n';
//    }
//
//    virtual void print_to_file(std::ofstream& ofs) const override
//    {
//        ofs << "{" << tag_ << "," << key_ << "}" << '\n';
//    }
}; 
