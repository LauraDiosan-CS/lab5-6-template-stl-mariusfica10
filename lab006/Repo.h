#pragma once
#include <vector>
using namespace std;

//repository class
template<class T>
class Repo {
private:
	vector<T> elemente;

public:

	Repo() {};

	
	//desc: adding a machine object to the repository
	//in  : a template class object
	//out : -
	void add(T e) {
		this->elemente.push_back(e);

	}

	//desc: returns all the objects from the repository
	//in  : -
	//out : all objects
	vector<T> getAll() {
		return this->elemente;
	}

	//desc: gets the number of objects from repository
	//in  : -
	//out : nubmer of objects
	int getSize() {
		return this->elemente.size();
	};

	//desc: destructor for repository class
	//in  : -
	//out : -
	~Repo() {
		this->elemente.clear();
	}

	//desc: deletes a template object,given by parameter
	//in  : p, template object
	//out : -
	void remove(T p) {
		typename vector<T>::iterator it;
		it = find(this->elemente.begin(), this->elemente.end(), p);
		if (!(it == this->elemente.end())) 
		{
			this->elemente.erase(it);
		}
	}

	//desc: returns all the objects from the repository
	//in  : -
	//out : all objects
	void update(T& p1, T& p2) {
		typename vector<T>::iterator it;
		it = find(this->elemente.begin(), this->elemente.end(), p1);
		if (!(it == this->elemente.end())) {

			*it = p2;
		}
	};

	//desc: clears the storage of the objects
	//in  : -
	//out : -
	void clear() {
		this->elemente.clear();
	}

	//desc: returns all the objects from the repository
	//in  : i - integer, position of the object we want to find
	//out : object in the position i
	T getPosition(int i) {

		return this->elemente[i];

	}

};