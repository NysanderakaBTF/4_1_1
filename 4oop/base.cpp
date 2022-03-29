#include "base.h"
#include <iostream>
#include <algorithm>
using namespace std;
base::base(base* h, std::string n, int stat)
{
	status = stat;
	head = h;
	name = n;
	if (head != nullptr) {
		head->ar_p.emplace(head->ar_p.end(), this);
	}
}

void base::set_name(std::string n)
{
	name = n;
}

std::string base::get_name()
{
	return name;
}
//redo
void base::display()
{
	base* now = this;
	while (now->get_head_p() != nullptr) {
		now = now->get_head_p();
	}
	std::cout << now->get_name();
	if (now->ar_p.size() != 0) cout << endl<<'\t';
	while (now->ar_p.size() != 0) {
		std::cout << now->name;
		for (int i = 0; i < now->ar_p.size(); i++) {
			std::cout << "  " << now->ar_p[i]->get_name();
		}
		now = now->ar_p[now->ar_p.size() - 1];
		if (now->ar_p.size() != 0)
			std::cout << std::endl;
	}
}


void base::rebase(base* new_per)
{
	if (head != nullptr) {
		head->ar_p.erase(find(head->ar_p.begin(), head->ar_p.end(), this));
	}
	if (new_per != nullptr) {
		new_per->ar_p.emplace_back(this);
	}
	head = new_per;
}


base* base::get_head_p()
{
	return head;
}

base::~base() {
	for (int i = 0; i < ar_p.size(); i++) {
		delete ar_p[i];
	}
}

base* base::find_n(std::string n)
{
	if (this->name == n)
		return this;
	base* res=nullptr;
	for (int i = 0; i < ar_p.size(); i++) {
		res = ar_p[i]->find_n(n);
		if (res != nullptr) {
			return res;
		}
	}
	return nullptr;
}

void base::set_readiness(string na, int stat)
{
	bool ok = true;
	base* now = find_n(na);
	base* set = now;
	if (now != nullptr) {
		while (now->get_head_p() != nullptr) {
			now = now->get_head_p();
			if (now->status == 0) {
				ok = false;
				break;
			}
		}
		if (ok) {
			set->status = stat;
		}
		else {
			set->status = 0;
		}
	}
}

