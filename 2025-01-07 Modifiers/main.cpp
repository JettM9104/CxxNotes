#include <iostream>
using namespace std;
#include <string>

class base {
public:
  int a;
  double b;
  string c;

  virtual int method1(int i) { // indicates that this will be overriden in a derived class
    return i * 2;
  }

  static int method2(double a) { // functions labelled static can be acceced without a objecy
    return a * a;
  }

  int method3(int g) noexcept { // cannot throw an exception
    return g * g * g;
  }

  int method4(int s) const { // This functino cannot be changed
    return g * g * g * g;
  }

  constexpr int method5(int d) { // This function will evaluate this during compile time but there are limitations
    return g * 9;
  }

  friend int method6(int k); // Functinos decladed freinds can be define outsiode of the class and still have acccess to private and public variables.

  friend int method7(base& hi);

  base(int a); // You have to declare the constructor if you want to write it outside the class

  base (double a) { // constructor
    this-> a = a;
  }

  base (string f, double e) : e(e), f(f) { // another syntax for constructor
    // a(b): sets a to parameter b
  }
  base() = default; // allows for no constuctor


protected:
  int d;
  double e;
  string f;

private:
  int g;
  double i;
  string j;


};
int method6(int k) { // This is a reguaar Functino that has access to base class
  return k * 20;
  // If you want it to make the variables accesible you will need to make a refrence of the base class
}

int method7(base& hi) {
  return hi.a;
}

base::base(int a) { // constructor outside of the functino
  this->a = a;
}

class derived : public base {
  int method1(int a) override { // override overrides this function: the parameters must be the same
    return a * 3;
  }
};


int main() {
  base h;

  h.a = 3;
}