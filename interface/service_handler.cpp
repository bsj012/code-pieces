#include <iostream>

using namespace std;

class connection
{
public:
	connection() { cout<<"connection"<<endl; }
};

class service_handler
{
public:
	service_handler() { cout << "service_handler" << endl; }
	/// Pure virtual method (defined by a subclass).
	virtual void open() = 0;

	/// Pure virtual method
	virtual void close() = 0;

private:
	connection* conn;
};

class acceptor
{
public:
	acceptor(service_handler* sh)
	{ 
		cout << "acceptor" << endl;
		sh->open();
	}
};

class setup_handler : public service_handler
{
public:
	setup_handler() { cout << "setup_handler" << endl; }
	void open() {
		cout << "setup_handler ... open()" << endl;
	}
	void close() {};
};


int main(int argc, char** argv)
{

	setup_handler sh;
	acceptor server(&sh);

	cout << "MAIN" << endl;
	return 0;
}
