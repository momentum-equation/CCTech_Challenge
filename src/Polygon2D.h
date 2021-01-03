#pragma once
#include "Point2D.h"
#include "PrintInterface.h"
#include "basicArithmetic.h"
#include "Point2DHelper.h"
#include "indexList.h"

class Polygon2D: public PrintInterface
{
private:
    const Point2D origin {0.,0.};
    Point2D* pPoint2D_;
    size_t Size_{};
    size_t mUnits_{};
	
	void swap_points(Point2D& pnt1, Point2D& pnt2)
	{
		Point2D tmp{pnt1};
		pnt1 = pnt2;
		pnt2 = tmp;
	}
	
	void reorder(Polygon2D& polygon, indexList& indxlist)
	{
		if(polygon.get_size() != indxlist.get_size()) return;
		bool is_sorted;
		
		for(size_t idx{0}; idx != polygon.get_size(); idx++)
		{
			is_sorted = false;
			for(size_t jdx{0}; jdx != polygon.get_size()-idx-1; jdx++)
			{
				if(indxlist[jdx] > indxlist[jdx+1])
				{
					swap_points(polygon[jdx], polygon[jdx+1]);
					swap(indxlist[jdx], indxlist[jdx+1]); 
					is_sorted = true;
				}
			}
			if(!is_sorted) break;
		}
	}
	
	void allocate_memory(size_t new_size)
    {
        mUnits_ = new_size;
        Point2D* tmp = new Point2D[mUnits_];
        for(size_t idx = 0; idx < Size_; idx++)
        {
            tmp[idx] = pPoint2D_[idx];
        }
        delete[] pPoint2D_;
        pPoint2D_ = tmp;
    }
	
public:
    Polygon2D()
    :
        Size_{0},
        mUnits_{2}
    {
        pPoint2D_ = new Point2D[mUnits_];
    }
	
    Polygon2D(const Polygon2D& polygon)
    :
        Size_{polygon.Size_},
        mUnits_{polygon.mUnits_}
    {
        pPoint2D_ = new Point2D[mUnits_];

        for(size_t idx = 0; idx != Size_; idx++)
        {
            for(size_t i = 0; i < 2; i++)
            {
                pPoint2D_[idx][i] = polygon.pPoint2D_[idx][i];
            }
        }
//		std::cout << "Copy\n";
    }
	
	Polygon2D(Polygon2D&& polygon) noexcept
	:
		Size_{(size_t&&)polygon.Size_},
		mUnits_{(size_t&&)polygon.mUnits_}
	{
		pPoint2D_ = polygon.pPoint2D_;
		
		polygon.Size_ = 0;
		polygon.mUnits_ = 0;
		polygon.pPoint2D_ = nullptr;
	}

    ~Polygon2D()
    {
        delete[] pPoint2D_;
    }
	
    size_t get_size() const
    {
        return Size_;
    }

    Point2D at(size_t i) const
    {
        return pPoint2D_[i];
    }
	
	Point2D begin() const
	{
		return pPoint2D_[0];
	}
	
	Point2D last() const
	{
		return pPoint2D_[Size_-1];
	}

    void append(const Point2D& point)
    {
        if(mUnits_ <= Size_)
        {
            allocate_memory(1.5*mUnits_);
        }
        pPoint2D_[Size_] = point;
        Size_++;
    }
	
	void append(const Polygon2D& polygon)
	{
		size_t increased_size = Size_ + polygon.Size_;
		size_t count{0};
		if(mUnits_ <= increased_size)
		{
			allocate_memory(1.5*(mUnits_+increased_size));
		}
		for(size_t idx{Size_}; idx != increased_size; idx++)
		{
			pPoint2D_[idx] = polygon[count]; 
			count++;
		}
		Size_ = increased_size;
	}

    void remove_last()
    {
        Size_--;
		mUnits_--;
        allocate_memory(mUnits_);
    }
	
	void clear()
	{
		Size_ = 0;
		mUnits_ = 0;
		allocate_memory(mUnits_);
	}
	
	void clear(size_t begin, size_t end)
	{
		size_t decreased_size = Size_-(end - begin+1);
		mUnits_ = 1.5*decreased_size;
		Point2D* tmp = new Point2D[decreased_size];
		
		size_t count{0};
		for(size_t idx{0}; idx != begin; idx++)
		{
			tmp[count] = pPoint2D_[idx];
			count++;
		}
		for(size_t idx{end+1}; idx != Size_; idx++)
		{
			tmp[count] = pPoint2D_[idx];
			count++;
		}
		
		Size_ = decreased_size;
		delete[] pPoint2D_;
		pPoint2D_ = tmp;
	}

	void slice(size_t begin, size_t end)
	{
		size_t count{0};
		Size_ = end - begin+1;
		mUnits_ = 1.5*Size_;
		Point2D* tmp = new Point2D[Size_];
		
		for(size_t idx{begin}; idx != end+1; idx++)
		{
			tmp[count] = pPoint2D_[idx];
			count++;
		}
		
		delete[] pPoint2D_;
		pPoint2D_ = tmp;
	}
		
	int search_x(const size_t& l, const size_t& r, const Point2D& point) 
	{
		if (r >= l) 
		{ 
			int mid = l + (r - l) / 2; 
	  
			if (pPoint2D_[mid] == point) 
				return mid;
	  
			if (pPoint2D_[mid].X() > point.X()) 
				return search_x(l, mid - 1, point); 
	  
			return search_x(mid + 1, r, point); 
		} 
	  
		return -1; 
	} 

	int search_y(const size_t& l, const size_t& r, const Point2D& point) 
	{ 
		if (r >= l) 
		{ 
			int mid = l + (r - l) / 2; 
	  
			if (pPoint2D_[mid] == point) 
				return mid;
	  
			if (pPoint2D_[mid].Y() > point.Y()) 
				return search_y(l, mid - 1, point); 
	  
			return search_y(mid + 1, r, point); 
		}
		
		return -1; 
	}

	indexList indexes() const
	{
		return indexList(0, Size_-1);
	}
	
	void sort_by_x()
	{
		
		bool is_sorted;
		
		for(size_t idx{0}; idx != Size_-1; idx++)
		{
			is_sorted = false;
			for(size_t jdx{0}; jdx != Size_-idx-1; jdx++)
			{
				if(pPoint2D_[jdx][0] >= pPoint2D_[jdx+1][0])
				{
					swap_points(pPoint2D_[jdx], pPoint2D_[jdx+1]);
					is_sorted = true;
				}
				else
				{
					continue;
				}
			}
			if(!is_sorted) break;
		}
	}

	void sort_by_y()
	{
		bool is_sorted;

		for (size_t idx{ 0 }; idx != Size_ - 1; idx++)
		{
			is_sorted = false;
			for (size_t jdx{ 0 }; jdx != Size_ - idx - 1; jdx++)
			{
				if (pPoint2D_[jdx][1] >= pPoint2D_[jdx + 1][1])
				{
					swap_points(pPoint2D_[jdx], pPoint2D_[jdx + 1]);
					is_sorted = true;
				}
				else
				{
					continue;
				}
			}
			if (!is_sorted) break;
		}
	}
	
	void reverse()
	{
		size_t count{0};
		Point2D* tmp = new Point2D[Size_];
		for(size_t idx{Size_-1}; idx != -1; idx--)
		{
			tmp[count] = pPoint2D_[idx];
			count++;
		} 
		delete[] pPoint2D_;
		pPoint2D_ = tmp;
	}

	bool is_vertex(size_t begin, size_t end, const Point2D& point)
	{
		if(end >= begin)
		{
			Polygon2D poly(*this);
			poly.sort_by_x();
			
			size_t mid = begin + (end - begin)/2;
			
			if(poly.at(mid) == point)
				return true;
			
			if(poly.at(mid).X() > point.X())
				return is_vertex(begin, mid-1, point);
			
			return is_vertex(mid+1, end, point);
		}
		
		return false;
	}

    Polygon2D& operator=(const Polygon2D& polygon)
    {
        for(size_t idx {0}; idx !=Size_; idx++)
        {
            for(size_t jdx {0}; jdx !=2; jdx++)
            {
                pPoint2D_[idx][jdx] = polygon.pPoint2D_[idx][jdx];
            }
        }
		return *this;
    }
	
	Polygon2D& operator=(Polygon2D&& polygon)
	{
		if(this == &polygon) return *this;
		
		pPoint2D_ = polygon.pPoint2D_;
		
		polygon.pPoint2D_ = nullptr;
		
		return *this;
	}

    Point2D& operator[](size_t idx)
    {
        return pPoint2D_[idx];
    }

    const Point2D& operator[](size_t idx) const
    {
        return pPoint2D_[idx];
    }
	
    Point2D east_bound() const
    {
		Polygon2D poly(*this);
		poly.sort_by_x();
		return poly.at(Size_-1);
    }

    Point2D west_bound() const
    {
		Polygon2D poly(*this);
		poly.sort_by_x();
		return poly.at(0);
    }

    Point2D north_bound() const
    {
		Polygon2D poly(*this);
		poly.sort_by_y();
		return poly.at(Size_-1);
    }

    Point2D south_bound() const
    {
		Polygon2D poly(*this); 
		poly.sort_by_y();
		return poly.at(0);
	}

    virtual void print_to_console(std::ostream& os) const override
    {
        for(size_t idx{0}; idx != Size_; idx++)
        {
            os << this->at(idx) << '\n';
        }
    }
    
    virtual void print_to_file(std::ofstream& ofs) const override
    {
    	for(size_t idx{0}; idx != Size_; idx++)
    	{
            ofs << this->at(idx) << '\n';
    	}
    }
};