// ExclusivePrt.hpp header guard
#ifndef EXCLUSIVE_PTR_HPP
#define EXCLUSIVE_PTR_HPP

template<typename T>
class ExclusivePtr
{
public:
	ExclusivePtr(T* pointer)
	{
		resource = pointer;
	}

	ExclusivePtr(const ExclusivePtr<T>& rhs) = delete;
	
	ExclusivePtr(ExclusivePtr<T>&& rhs)
	{
		resource = rhs.resource;
		rhs.resource = nullptr;
	}

	~ExclusivePtr()
	{
		delete resource;
	}

	void MakeExclusive(T* pointer)
	{
		delete resource;
		resource = pointer;
	}

protected:
private:
	T* resource;
};

//End of ExclusivePtr.hpp header guard
#endif
