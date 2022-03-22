#include "app.h"
#include <iostream>
#include <string>

app::app(base_c1* p):base(p, "root")
{
}

void app::build_tree_objects()
{
	base_c1* temp = nullptr;
	std::string n_a, n_b;
	//if (this->get_head_p() == nullptr) {
		std::cin >> n_a;
		this->set_name(n_a);
	//}
	do{
		std::cin >> n_a >> n_b;
		if(n_a!=n_b) {
			if (n_a == this->get_name()) {
				temp = new base_c1(this, n_b);
			}
			else {
				if(temp->get_name()==n_a)
					temp = new base_c1(temp, n_b);
				else 
					temp = new base_c1(temp->get_head_p(), n_b);
			}
		}
	} while (n_a != n_b);

}

int app::exec_app()
{
	this->display();
	return 0;
}
