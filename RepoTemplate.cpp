//#include "RepoTemplate.h"
//
//
//template <class T> RepoTemplate<T>::RepoTemplate() {}
//
//
//
//template<class T>
//void RepoTemplate<T>::add(const T &e)
//{
//	elem.push_back(e);
//}
//
//template<class T>
//int RepoTemplate<T>::remove(const T & e)
//{
//	list<T>::iterator;
//	iterator= find(elem.begin(), elem.end(), e);
//	if(iterator!=elem.end()){
//		elem.erase(iterator);
//		return 0;
//	}
//	return -1;
//}
//
//template<class T>
//int RepoTemplate<T>::find(const T &e)
//{
//	list<T>::iterator;
//	iterator= find(elem.begin(), elem.end(), e);
//	if (iterator != elem.end()) return distance(elem.begin(), iterator);
//	return -1;
//}
//
//template<class T>
//int RepoTemplate<T>::size()
//{
//	return elem.size();
//	return 0;
//}
//
//template<class T>
//int RepoTemplate<T>::update(const T & vechi, const T nou)
//{
//	
//	for (T e : elem) {
//		if (e == vechi) {
//			e = nou;
//			return 0;
//		}
//	}
//	return -1;
//}
//
//template<class T>
//list<T> RepoTemplate<T>::getAll()
//{
//	return elem;
//	return list<T>();
//}
//
//template <class T> RepoTemplate<T>::~RepoTemplate()
//{
//}
