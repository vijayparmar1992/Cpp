#include<iostream>
#include<thread>

using namespace std;

void displayFunction()
{
	cout << "Hello from displayFunction() \n";
}

class FunctionObject {
public:
	void operator()()
	{
		cout << "Hello from FunctionObject " << endl;
	}
};

class scoped_thread {
	std::thread t;
public:
	explicit scoped_thread(std::thread t_) : t(std::move(t_)) {
		if (!t.joinable()) throw std::logic_error("No thread");
	}
	~scoped_thread() {
		t.join();
		cout << "join" << endl;
	}
	scoped_thread(scoped_thread&) = delete;
	scoped_thread& operator=(scoped_thread const&) = delete;
};


int main()
{
	thread t1(displayFunction);

	FunctionObject f1;

	std::thread t2(f1);

	thread t3([] {cout << "Hello from a lambda" << endl; });

	t1.join();
	t2.join();
	t3.join();

	cout << "Get next thread ID " << endl;
	try {
		scoped_thread t4(std::thread([] { cout << std::this_thread::get_id() << endl; }));
		// The scoped_thread will join automatically when it goes out of scope
	}
	catch (const std::logic_error& e) {
		cerr << "Exception: " << e.what() << "\n";
	}


	cout << "Exiting program " << endl;
	return 0;
}
