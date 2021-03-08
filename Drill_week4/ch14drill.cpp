#include <iostream>
#include <string>

class B1 {
	
	public:
		virtual void vf() { std::cout << "B1::vf()\n"; }
		void f() { std::cout << "B1::f()\n"; }
		virtual void pvf() =0;

};

class D1 : public B1 {
	
	public:
		void vf() { std::cout << "D1::vf()\n"; }
		void f() { std::cout << "D1::f()\n"; }
		void pvf() { std::cout << "D1::pvf\n"; }
	
};

class D2 : public D1 {

	public:
		void pvf() { std::cout << "D2::pvf()\n"; } 
};

class B2 {

	public:
		virtual void pvf() =0;
};

class D21 : public B2 {

	std::string D21_string = "D21string";

	public:
		void pvf() { std::cout << D21_string << std::endl; }
};

class D22 : public B2 {

	int D22_int = 22;
	void pvf() { std::cout << D22_int << std::endl; }

};

void f(B2& objectB2){
	objectB2.pvf();
}

int main()
{
/*
	B1 obj1;
	obj1.vf();
	obj1.f();
*/	
	D1 obj2;
	obj2.vf();
	obj2.f();

	B1& obj3 = obj2;
	obj3.vf();
	obj3.f();

	D2 obj4;
	obj4.f();
	obj4.vf();
	obj4.pvf();

	D21 objD21;
	D22 objD22;
	f(objD21);
	f(objD22);

}