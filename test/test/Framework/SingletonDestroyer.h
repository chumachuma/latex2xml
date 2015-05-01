#pragma once
#ifndef SINGLETON_DESTROYER
#define SINGLETON_DESTROYER

template <class SingletonClass>
class SingletonDestroyer {
public:
	SingletonDestroyer (SingletonClass* SInstance = 0) {
		SingletonInstance = SInstance; 
	};
	~SingletonDestroyer () {
		delete SingletonInstance;
		SingletonInstance = 0;
	};
	void SetSingletonInstance (SingletonClass* SInstance) {
		SingletonInstance = SInstance;
	};
private: 
	//Prevent users from making copies of a destroyer to avoid double deletion: 
	SingletonDestroyer (const SingletonDestroyer &);
	void operator = (const SingletonDestroyer &);
	SingletonClass* SingletonInstance; 
};

#endif