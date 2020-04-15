#pragma once
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

template <class T>class RepoTemplate
{
protected:
	list<T> elem;
public:
	RepoTemplate<T>() {}
	
	virtual void addElem(const T&e){
		elem.push_back(e);
	}

	virtual int delElem(const T& e) {
		typename list<T>::iterator it;
		it = find(elem.begin(), elem.end(), e);
		if (it != elem.end())
		{
			elem.erase(it);
			return 0;
		}
		return -1;
	}

	int findElem(const T&e) {
		int index = 0;
		for (T crt : elem) {
			index++;
			if (crt == e) return index;
		}
		return -1;
	}

	int size(){
		return elem.size();
		return 0;
	}

	virtual void updateElem(const T& s, const T nou) {
		replace(elem.begin(), elem.end(), s, nou);
	}

	list<T> getAll() {
		return elem;
		//return list<T>();
	}

	T getElemFromPos(int i) {
		typename list<T>::iterator it;
		int k = 0;
		for (it = elem.begin(); it != elem.end(); it++)
		{
			if (k == i)
				return *it;
			k++;

		}
		return T();
	}

	void clearElem() {elem.clear();}
	~RepoTemplate() {}
};