#pragma once
#include "Repo.h"
#include <fstream>
template<class T>


//class Repository with files, inherited from the repository class
// methods used add,getPosition,remove,getAll
// repository STL can use any of the Repository methods
class RepoSTL : public Repo<T> {
private:
	char* fileName;
public:

	//desc: constructor for repository file
	//  in: -
	// out: - 
	RepoSTL() : Repo<T>() {
		this->fileName = NULL;
	};

	//desc: destructor for repository file
	//  in: -
	// out: -
	~RepoSTL() {
		delete[] this->fileName;
	};

	//desc: constructor
	//  in: the file
	// out: -
	RepoSTL(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();

	};

	//desc: sets a repository file
	//  in: the file 
	// out: -
	void setFileName(const char* fileName) {

		if (this->fileName != NULL) {
			delete[] this->fileName;
		}
		if (fileName != NULL) {
			this->fileName = new char[strlen(fileName) + 1];
			strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		}
		else
			this->fileName = NULL;

	};

	//desc: constructor for copying of repository file 
	//  in: the file
	// out: -
	RepoSTL(const RepoSTL& r) {

		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		this->loadFromFile();
	}

	//desc: gets the objects from repository file
	//  in: -
	// out: -
	void loadFromFile() {

		if (this->fileName != NULL) {


			ifstream f(this->fileName);

			T elem;

			while (f >> elem) {

				Repo<T>::add(elem);

			}
			f.close();
		}
		else
			Repo<T>::clear();
	};

	//desc: saves the data to repository file
	//  in: - 
	// out: - 
	void saveToFile() {

		if (this->fileName != NULL) {

			ofstream f(this->fileName);
			int n = Repo<T>::getSize();
			for (int i = 0; i < n; i++)
				f << Repo<T>::getPosition(i)<<'\n';

			f.close();
		}
	};

	//desc: adds an object to repository file
	//  in:
	// out:
	void add(T p) {

		Repo<T>::add(p);
		this->saveToFile();
	};

	//desc: gets the number of objects in repository file
	//  in: - 
	// out: number of objects
	int getSize() {
		return Repo<T>::getSize();
	}

	//desc: removes a given object 
	//  in: object to remove
	// out: -
	void remove(T c) {
		Repo<T>::remove(c);
		this->saveToFile();
	}

	//desc: replaces an object with a new object 
	//  in: old object, new object
	// out: -
	void update(T& c1, T& c2) {
		Repo<T>::update(c1, c2);
		this->saveToFile();
	}

	//desc: inherited function of getAll from repository
	//  in: - 
	// out: all objets in repository file
	vector<T> getAll() {
		return Repo<T>::getAll();
	};

	//desc:overload for atribution for a file
	//  in: a repository file,constant 
	// out: the file
	RepoSTL<T>& operator=(const RepoSTL<T>& repo)
	{
		this->setFileName(repo.fileName);
		this->loadFromFile();

		return *this;
	}

};