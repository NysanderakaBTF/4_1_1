#include "base.h"
#include <iostream>
#include <algorithm>
using namespace std;
base::base(base* h, std::string n)
{
	status = 0;
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

//void base::set_readiness(string na, int stat)
//{
//	bool ok = true;
//	base* now = find_n(na);
//	base* set = now;
//	if (now != nullptr && /* new piece*/ stat != 0) {
//		while (now->get_head_p() != nullptr) {
//			now = now->get_head_p();
//			if (now->status == 0) {
//				ok = false;
//				break;
//			}
//		}
//		if (ok) {
//			set->status = stat;
//		}
//		else {
//			set->status = 0;
//		}
//	}
//	if (stat == 0 && now != nullptr) {
//		while (now->get_head_p() != nullptr) {
//			now = now->get_head_p();
//			if (now->status == 0) {
//				ok = false;
//				break;
//			}
//		}
//		if (ok) {
//			for (int i = 0; i < ar_p.size(); i++) {
//				ar_p[i]->set_readiness(ar_p[i]->get_name(), 0);
//			}
//			status = 0;
//		}
//	}
//}
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
			if (stat != 0)
				set->status = stat;
			else {
				for (int i = 0; i < ar_p.size(); i++) {
					ar_p[i]->set_readiness(ar_p[i]->get_name(), 0);
				}
				set->status = 0;
			}
		}
		else {
			set->status = 0;
		}
	}
}

//void base::print() {
//	if (!ar_p.empty()) {
//		cout << '\n' << name << " ";
//	}
//	for (int i = 0; i < ar_p.size(); i++) {
//		if (i + 1 < ar_p.size()) {
//			cout << ar_p[i]->get_name() << " ";
//		}
//		else {
//			cout << ar_p[i]->get_name();
//		}
//	}
//
//	for (int i = 0; i < ar_p.size(); i++) {
//		ar_p[i]->print();
//	}
//}
void base::print() {
	if (this->get_head_p() == nullptr) {
		cout << name;
	}
	for (int i = 0; i < ar_p.size(); i++) {
		base* now = ar_p[i];
		string tabs = "";
		while (now->get_head_p() != nullptr) {
			now = now->get_head_p();
			tabs.push_back(' ');
			tabs.push_back(' ');
			tabs.push_back(' ');
			tabs.push_back(' ');
		}
		cout << endl<<tabs << ar_p[i]->get_name();
		ar_p[i]->print();
	}
}
void base::print_ready() {
	if (this->get_head_p() == nullptr) {
		if (this->status != 0) cout << name << " is ready";
			else cout << name << " is not ready";
	}
	for (int i = 0; i < ar_p.size(); i++) {
		base* now = ar_p[i];
		string tabs = "";
		while (now->get_head_p() != nullptr) {
			now = now->get_head_p();
			tabs.push_back(' ');
			tabs.push_back(' ');
			tabs.push_back(' ');
			tabs.push_back(' ');
		}
		cout << endl << tabs << ar_p[i]->get_name();
		if (ar_p[i]->status != 0) cout << " is ready";
		else cout << " is not ready";
		ar_p[i]->print_ready();
	}
}