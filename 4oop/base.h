#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>
class base
{
protected:
	std::string name;
	base* head;
	std::vector<base*> ar_p;
public:

	base(base*, std::string = "Def_name");
	void set_name(std::string);
	std::string get_name();
	void display();
	void rebase(base* new_per);
	base* get_head_p();
	~base();

};
#endif 