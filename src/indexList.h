#pragma once
#include <cstddef>
#include <iostream>
#include "basicArithmetic.h"
#include "PrintInterface.h"

class indexList: public PrintInterface
{
private:
    ssize_t* pIndx_{nullptr};
    size_t Size_{0};

public:
    indexList(size_t nElements)
    :
        Size_{nElements}
    {
        pIndx_ = new ssize_t[nElements];
        for(size_t idx = 0; idx != Size_; idx++)
        {
            pIndx_[idx] = -1;
        }
    }
	
	indexList(size_t begin, size_t end)
	:
		Size_{end - begin +1}
	{
		pIndx_ = new ssize_t[Size_];
		for(size_t idx{begin}; idx != end+1; idx++)
		{
			pIndx_[idx] = idx;
		}
	}

    indexList(const indexList& list)
    :
        Size_{list.Size_}
    {
        pIndx_ = new ssize_t[Size_];
        for(size_t idx = 0; idx != Size_; idx++)
        {
            pIndx_[idx] = list.pIndx_[idx];
        }
    }

    indexList(indexList&& list)
    :
        Size_{list.Size_}
    {
        pIndx_ = new ssize_t[Size_];
        for(size_t idx{0}; idx !=Size_; idx++)
        {
            pIndx_[idx] = list.pIndx_[idx];            
        }
        list.pIndx_ = nullptr;
        list.Size_ = 0;
    }

    ~indexList()
    {
        delete[] pIndx_;
    }
    
    size_t get_size() const
    {
        return Size_;
    }

    void set_size(size_t s)
    {
        Size_ = s;
    }

    ssize_t at(size_t idx) const
    {
        return pIndx_[idx];
    }

    void trim()
    {
        size_t positives{0};
        for(size_t idx{0}; idx !=Size_; idx++)
        {
            if (this->at(idx) == -1) break;
            positives++;
        }

        Size_ = positives;
        ssize_t* tmp = new ssize_t [positives];
        for(size_t idx{0}; idx !=Size_; idx++)
        {
            tmp[idx] = pIndx_[idx];
        }
        
        delete pIndx_;
        
        pIndx_ = tmp;
    }
	
	void slice(size_t begin, size_t end)
	{
		size_t count{0};
		Size_ = end - begin +1;
		
		ssize_t* tmp = new ssize_t[Size_];
		for(size_t idx{begin}; idx != end+1; idx++)
		{
			tmp[count] = pIndx_[idx];
			count++;
		}
		
		delete [] pIndx_; 
		pIndx_ = tmp;
	}
	
	void sort()
	{
		bool swapped;
		for(size_t idx{0}; idx!=Size_-1; idx++)
		{
			swapped = false;
			for(size_t jdx{0}; jdx!=Size_-idx-1; jdx++)
			{
				if(pIndx_[idx] > pIndx_[idx+1])
				{
					swap(pIndx_[idx], pIndx_[idx+1]);
					swapped = true;
				}				
			}
			if(!swapped) break;
		}
	}

    indexList& operator=(const indexList& list)
    {
        if(this == &list) return *this;
        
        Size_ = list.Size_;
        
        delete[] pIndx_;
        pIndx_ = new ssize_t[Size_];

        for(size_t idx {0}; idx != list.get_size(); idx++)
        {
            pIndx_[idx] = list.pIndx_[idx];
        }
        
        return *this;
    }

    indexList& operator=(indexList&& list)
    {
        if(this == &list) return *this;
        
        Size_ = list.Size_;

        pIndx_= list.pIndx_;
        list.pIndx_ = nullptr;
        list.Size_ = 0;

        return *this;
    }
    
    ssize_t& operator[](size_t idx)
    {
        return pIndx_[idx];
    }

    const ssize_t& operator[](size_t idx) const
    {
        return pIndx_[idx];
    }

    bool operator== (const indexList& list)
    {
        if(list.Size_ != this->Size_) return false;
        else
        {
            bool tmp;
            for(size_t idx= 0; idx !=list.Size_; idx++)
            {
                tmp = true && (pIndx_[idx]==list.pIndx_[idx]);
            }
            return tmp;
        }
    }
	
	virtual void print_to_console(std::ostream& os) const override
	{
		for(size_t idx{0}; idx!=Size_; idx++)
		{
			os << pIndx_[idx] << " ";
		}
		os << '\n';
	}
	
	virtual void print_to_file(std::ofstream& ofs) const override
	{
		for(size_t idx{0}; idx!=Size_; idx++)
		{
			ofs << pIndx_[idx] << " ";
		}
		ofs << '\n';		
	}
//	
//	friend void sort_label_value_pair(pair<indexList, indexList> &Pair)
//	{
//		bool swapped;
//		for(size_t idx{0}; idx!=Pair.get_key().get_size()-1; idx++)
//		{
//			swapped = false;
//			for(size_t jdx{0}; jdx!=Pair.get_key().get_size()-idx-1; jdx++)
//			{
//				if(Pair.get_key().pIndx_[jdx] > Pair.get_key().pIndx_[jdx+1])
//				{
//					swap(Pair.get_tag().pIndx_[jdx], Pair.get_tag().pIndx_[jdx+1]);
//					swap(Pair.get_key().pIndx_[jdx], Pair.get_key().pIndx_[jdx+1]);
//					swapped = true;
//				}				
//			}
//			if(swapped == false) break;
//		}
//	}
}; 