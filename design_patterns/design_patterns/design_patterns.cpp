// design_patterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <mutex>
#include <cassert>
#include <vector>
#include <type_traits>

using namespace std;

template<typename T>
class Singleton
{
private:
	static T*               _instance  ;

public:
	static T* instance()
	{
		if (!_instance)
		{
			int a = 0; 
			static std::once_flag _flag;
			// auto lambda = [&]() { Singleton<T>::_instance = new T();  ++a; }; 
			std::call_once(_flag, [&]() { Singleton<T>::_instance = new T();  ++a; });
			//assert(a == 1); 
		}

		return _instance; 
	}
};

class Foo
{
public :
	void print() { cerr << "foo bar" << endl; }

};

Foo * Singleton<Foo>::_instance = 0; 
// std::once_flag Singleton<Foo>::_flag ;


template <typename T>
struct is_swapable
{
	static const bool value = false; 
};

template <>
struct is_swapable<int>
{
	static const bool value = true;
};

template <>
struct is_swapable<uint32_t>
{
	static const bool value = true;
};

template <>
struct is_swapable<uint64_t>
{
	static const bool value = true;
};

template <>
struct is_swapable<uint16_t>
{
	static const bool value = true;
};


template<typename T>
T byte_swap(T value)
{
	unsigned char *bytes = reinterpret_cast<unsigned char*>(&value);

	static_assert(is_swapable<T>::value , "cant swap this type  - custom_traits"); 
	static_assert(std::is_integral<T>::value && sizeof(T)>=2, "cant swap this type ");


	for (int i = 0; i < sizeof(T); i += 2)
	{
		auto swap = bytes[i];
		bytes[i] = bytes[i + 1];
		bytes[i + 1] = swap;
	}

	return value; 
}



/*******************************************************/
/*
- Proxy Pattern - 
- using inheritance - not templates

*/

namespace proxy
{
	class SubjectI
	{
	public:
		virtual void request() = 0;
		virtual ~SubjectI() {}
	};

	class RealSubject : public SubjectI
	{
	public:
		void request() {
			cout << "RealSubject.request()" << endl;
		}
	};

	class Proxy : public SubjectI
	{
	private:
		SubjectI* realSubject;
	public:
		Proxy() : realSubject(new RealSubject())
		{}
		~Proxy() {
			delete realSubject;
		}
		// Forward calls to the RealSubject:
		void request() {
			realSubject->request();
		}
	};
}; // namespace proxy

/*******************************************************/
/*
	Observer Pattern - MVC
	 - using inheritance - not templtes
	
*/

namespace observable
{
	class Observerable
	{
	public:
		virtual void notify() = 0;
	};

	class Observer : public Observerable
	{
	public:
		virtual void notify() override
		{
			cerr << "observer notified." << endl;
		}
	};

	class Model
	{
	public:
		void register_observer(Observerable* o)
		{
			_observers.push_back(o);
		}

		void notify()
		{
			for (auto o : _observers)
				o->notify();
		}

	private:
		vector<Observerable *> _observers;


	};
}; // namespace observable

int main()
{
	Singleton<Foo>::instance()->print();

	uint16_t i16 = 0x0100;

	int s16 = byte_swap(i16); 
	cerr << i16 << " : " << s16 << endl;

	// double ng = 123.4; ng = byte_swap(ng);

	
	proxy::Proxy p;
	p.request();


	getchar(); 

	return 0;
}

