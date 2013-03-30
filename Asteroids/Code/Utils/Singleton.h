#ifndef _SINGLETON_H
#define _SINGLETON_H

namespace Util
{

//
// @TODO: Make threadsafe
//

template <class T>
class Singleton
{
public:
	//
	// Returns a mutable reference to the singleton object
	//
	static T& instance()
	{
		return *Singleton<T>::_getInstance();
	}

	//
	// Returns a constant reference to the singleton object
	//
	static const T& constInstance()
	{
		return *Singleton<T>::_getInstance();
	}

	//
	// Destroy the single object
	//
	void destroyInstance()
	{
		if(pInstance)
			delete Singleton<T>::_getInstance();
		pInstance = 0;
	}

protected:
	Singleton()
	{
	}

	virtual ~Singleton()
	{
		delete Singleton<T>::_getInstance();
	}

private:
	static T* pInstance;

	static T* _getInstance()
	{
		if(Singleton<T>::pInstance == 0)
		{
			pInstance = new T();
		}
		
		return pInstance;
	}
};

}

#define CreateSingleton(T) \
	template<> T* Util::Singleton<T>::pInstance = 0

#define DestroySingleton(T) \
	Util::T::destroyInstance()

#define SingletonFriend(T) \
	friend class Util::Singleton<T>

#endif