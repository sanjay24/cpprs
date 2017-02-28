#ifndef __BLINK__STON__
#define __BLINK__STON__

#include <mutex>

// Singleton to dispatch the requests coming into 
// the server. Check the C++11 memory model for enhanced 
// thread safe signleton
  
namespace blink {
namespace util {
  template <typename T> 
    class Singleton {
      public:
        static T& instance() {
          if (mInstance == nullptr) {
            mMutex.lock(); 
            if (mInstance == nullptr) {
              mInstance = new T();
	    }
          }
	  mMutex.unlock();
	  return *mInstance;
	}
      protected:
	static T* mInstance;
	Singleton(){}
	T* operator=(const T*) {}

	static std::mutex mMutex;
    };
  }
}

template <typename T>
std::mutex blink::util::Singleton<T>::mMutex;

template <typename T>
T* blink::util::Singleton<T>::mInstance = nullptr;

#endif
