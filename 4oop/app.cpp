#include "app.h"
#include <iostream>
#include <string>

app::app(base_c1* p) :base(p, "root")
{
}

//void app::build_tree_objects()
//{
//	base_c1* temp = nullptr;
//	std::string n_a, n_b;
//	std::cin >> n_a;
//	this->set_name(n_a);
//	do {
//		std::cin >> n_a >> n_b;
//		if (n_a != n_b) {
//			if (n_a == this->get_name()) {
//				temp = new base_c1(this, n_b);
//			}
//			else {
//				if (temp->get_name() == n_a)
//					temp = new base_c1(temp, n_b);
//				else
//					temp = new base_c1(temp->get_head_p(), n_b);
//			}
//		}
//	} while (n_a != n_b);
//
//}

void app::build_tree_objects()
{
	base* temp = nullptr;
	std::string n_a, n_b;
	int class_n;
	std::cin >> n_a;
	this->set_name(n_a);
	do {
		std::cin >> n_a;
		
		if (n_a != "endtree") { 
			cin>> n_b>>class_n;
			base* to_push = find_n(n_a);
			kolob++;
			switch (class_n)
				{
				//case 1:
				//	temp = new base_c1(this, n_b); // тут я не уверен какой класс нужно писать см задание
				//	break;
				case 2:
					temp = new base_c2(to_push, n_b);
					break;
				case 3:
					temp = new base_c3(to_push, n_b);
					break;
				case 4:
					temp = new base_c4(to_push, n_b);
					break;
				case 5:
					temp = new base_c5(to_push, n_b);
					break;
				case 6:
					temp = new base_c6(to_push, n_b);
					break;
				default:
					break;
				}
			//if (n_a == this->get_name()) {
			//	switch (class_n)
			//	{
			//	//case 1:
			//	//	temp = new base_c1(this, n_b); // тут я не уверен какой класс нужно писать см задание
			//	//	break;
			//	case 2:
			//		temp = new base_c2(this, n_b);
			//		break;
			//	case 3:
			//		temp = new base_c3(this, n_b);
			//		break;
			//	case 4:
			//		temp = new base_c4(this, n_b);
			//		break;
			//	case 5:
			//		temp = new base_c5(this, n_b);
			//		break;
			//	case 6:
			//		temp = new base_c6(this, n_b);
			//		break;
			//	default:
			//		break;
			//	}
			//}
			//else {
			//	if (temp->get_name() == n_a)
			//		temp = new base_c1(temp, n_b);
			//	else
			//		temp = new base_c1(temp->get_head_p(), n_b);
			//}
		}
	} while (n_a != "endtree");

}

int app::exec_app()
{
	//this->display();
	std::string k; 
	int n;
	for (int i = 0; i < kolob; i++) {
		cin >> k >> n;
		set_readiness(k, n);
	}
	print();
	cout<< endl << "The tree of objects and their readines"<<endl ;
	print_ready();
	return 0;
}

