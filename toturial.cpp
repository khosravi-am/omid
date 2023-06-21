// C++ program to demonstrate the
// use of std::reference_wrapper
#include <iostream>	
#include <functional>
using namespace std;

// int main ()
// {
// 	char a = 'g', b = 'e', c = 'e', d = 'k', e = 's';
	
// 	// creating an array of character "references":
// 	//reference_wrapper<char> ref[] = {a, b, c, d, e};
// 	char  ref[] = {a, b, c, d, e};
// 	for (char& s : ref)
// 		cout << s;
// 	cout << endl;
// 	return 0;
// }

template<typename N>
void change(N n) {
 //if n is std::reference_wrapper<int>, 
 // it implicitly converts to int& here.
	n += 1; 
}

int neg(int val) {
    return (-val);
}

class C
{
 public:
    static reference_wrapper<C> obj()
    {
       return object;
    }
    
    int x=10;
    int y=20;

 private:
    static C object;
    C(){};   
};
C C::object= C();

int main() {
    C& a=C::obj();
    C& b=C::obj();

    cout << &a << endl<<&b<<endl;
    a.x=a.x+b.y;
    cout << a.x << endl<<b.x<<endl;

    return (0);

}


