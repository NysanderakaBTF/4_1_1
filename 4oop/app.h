#ifndef APP_H
#define APP_H
#include<iostream>
#include "base.h"
class app : public base
{
public:
	app(base* p);
	void build_tree_objects();
	int exec_app();
};
#endif // !APP_H



