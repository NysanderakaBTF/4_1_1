#include "base.h"
#include <iostream>
#include <algorithm>
using namespace std;
base::base(base* h, std::string n)
{
	this->head = h;
	name = n;
	if (this->head != nullptr) {
		this->head->ar_p.emplace(this->head->ar_p.end(),this);
	}
}

void base::set_name(std::string n)
{
	this->name = n;
}

std::string base::get_name()
{
	return this->name;
}

void base::display()
{
	
	base* now = this;
	while (now->get_head_p() != nullptr) {
		now = this->get_head_p();
	}
	std::cout << now->get_name();
	if (now->ar_p.size() != 0) cout << endl;
	while (now->ar_p.size() != 0) {
		std::cout << now->name;
		for (int i = 0; i < now->ar_p.size(); i++) {
			std::cout<< " " << now->ar_p[i]->get_name() ;
		}
		now = now->ar_p[now->ar_p.size() - 1];
		if(now->ar_p.size() != 0)
			std::cout << std::endl;
	}
}

void base::rebase(base* new_head)
{

	if (this->get_head_p() != nullptr && new_head != nullptr) {
		this->get_head_p()->ar_p.erase(find(this->get_head_p()->ar_p.begin(), this->get_head_p()->ar_p.end(),this));
		this->head = new_head;
		new_head->ar_p.emplace(new_head->ar_p.begin(),this);
	}
	else if (this->get_head_p() == nullptr) {
		new_head->get_head_p()->ar_p.erase(find(new_head->get_head_p()->ar_p.begin(), new_head->get_head_p()->ar_p.end(), new_head));
		this->head = new_head;
		new_head->head = nullptr;
		//root = new_head;
		new_head->ar_p.emplace(new_head->ar_p.begin(), this);
		
	}
}


base* base::get_head_p()
{
	return this->head;
}

/*base::base()
{
}*/
