#pragma once
#include "PrintInterface.h"
#include "indexList.h"
#include "Polygon2D.h"
#include <string>

class pairedList: public PrintInterface
{
private:
	size_t* tagList_;
	size_t* keyList_;
	size_t Size_;
	struct pair
	{
		size_t tag_;
		size_t key_;
		
		void print() const
		{
			std::cout << "{" << tag_ << "," << key_ << "}\n"; 
		}
	};
	
public:
	pairedList(const indexList& keys):
		Size_{keys.get_size()}
    {
		tagList_ = new size_t[Size_];
		keyList_ = new size_t[Size_];
		
		for(size_t idx{0}; idx !=Size_; idx++)
		{
			tagList_[idx] = idx;
			keyList_[idx] = keys[idx];
		}
	}

	pairedList(const pairedList& Pair):
		Size_{Pair.get_size()}
	{
		tagList_ = new size_t[Size_];
		keyList_ = new size_t[Size_];
		
		for(size_t idx{0}; idx !=Size_; idx++)
		{
			tagList_[idx] = idx;
			keyList_[idx] = Pair.keyList_[idx];
		}
	}
	
	~pairedList()
	{
		delete [] tagList_;
		delete [] keyList_;
	}
	
	pairedList& operator=(const pairedList& Pair)
	{
		if(this == &Pair) return *this;
		
		Size_ = Pair.Size_;
		
		delete[] tagList_;
		delete[] keyList_;
		
		tagList_ = new size_t[Size_];
		keyList_ = new size_t[Size_];
		
		for(size_t idx{0}; idx!=Size_; idx++)
		{
			tagList_[idx] = idx;
			keyList_[idx] = Pair.keyList_[idx];
		}
		
		return *this;
	}
	
	pairedList& operator=(pairedList&& Pair) noexcept
	{
		if(this == &Pair) return *this;
		
		Size_ = Pair.Size_;
		
		tagList_ = Pair.tagList_;
		keyList_ = Pair.keyList_;
		
		Pair.tagList_ = nullptr;
		Pair.keyList_ = nullptr;
		Pair.Size_ = 0;
		
		return *this;
	}
	
	const pair at(size_t idx) const
	{
		pair pairedVals;
		pairedVals.key_ = keyList_[idx];
		pairedVals.tag_ = tagList_[idx];
		
		return pairedVals;
	}
	
	pair at(size_t idx)
	{
		pair pairedVals;
		pairedVals.key_ = keyList_[idx];
		pairedVals.tag_ = tagList_[idx];
		
		return pairedVals;
	}
	
	pair& operator[] (const size_t idx)
	{
		pair pairedVals;
		pairedVals.key_ = keyList_[idx];
		pairedVals.tag_ = tagList_[idx];
		
		return pairedVals;
	}
	
	const pair& operator[] (const size_t idx) const
	{
		pair pairedVals;
		pairedVals.key_ = keyList_[idx];
		pairedVals.tag_ = tagList_[idx];
		
		return pairedVals;
	}
	
	void sort()
	{
		bool is_sorted;
		
		for(size_t idx{0}; idx != Size_-1; idx++)
		{
			is_sorted = false;
			for(size_t jdx{0}; jdx !=Size_-idx-1; jdx++)
			{
				if(keyList_[jdx] > keyList_[jdx+1])
				{
					swap(tagList_[jdx], tagList_[jdx+1]);
					swap(keyList_[jdx], keyList_[jdx+1]);
					is_sorted = true;
				}
			}
			if(!is_sorted) break;
		}
	}
	
	bool operator== (const pairedList& Pair)
	{
		if(Pair.Size_ != this->Size_) return false;
		else
		{
			bool tmp;
			for(size_t idx{0}; idx != Pair.Size_; idx++)
			{
				tmp = true && (keyList_[idx] == Pair.keyList_[idx])\
					&& (tagList_[idx] == Pair.tagList_[idx]);
			}
			return tmp;
		}
	}
	
	size_t get_size() const
	{
		return Size_;
	}
	
    virtual void print_to_console(std::ostream& os) const override
    {
		for(size_t idx{0}; idx != Size_; idx++)
		{
			this->at(idx).print();	
		}
    }

    virtual void print_to_file(std::ofstream& ofs) const override
    {
		for(size_t idx{0}; idx != Size_; idx++)
		{
			ofs << tagList_[idx] << " " << keyList_[idx] << '\n';	
		}
    }
};