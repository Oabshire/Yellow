#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <math.h>
#include <iomanip>
using namespace std;

class Figure {
public:
	virtual string Name() const  = 0 ;
	virtual double  Perimeter()const = 0;
	virtual double Area() const = 0;
};


class Triangle :public Figure {
public: 
	Triangle(int a, int b, int c)
	:A(a),B(b),C(c){
	}
	virtual string Name() const override {
		return "TRIANGLE";
	}
	virtual double  Perimeter() const override {
		return A+B+C;
	}
	virtual double Area() const  override {
		return sqrtl((Perimeter() / 2.0)*(Perimeter() / 2.0 - A)*(Perimeter() / 2.0 - B)*(Perimeter() / 2.0 - C));
	}
private:
	const int A, B, C;
};
class Rect : public Figure {
public:
	Rect(int w, int h) 
		:Width(w), Height(h) {
	}
	virtual string Name() const  override {
		return "RECT";
	}
	virtual double  Perimeter() const override {
		return (Width + Height) * 2;
	}
	virtual double Area()const override {
		return Width * Height;
	}
private:
	const int Width, Height;
};
class Circle : public Figure {
public:
	Circle(const int& r) 
	:R(r){
	}
	virtual string Name() const override {
		return "CIRCLE";
	}
	virtual double  Perimeter() const override {
		return (R*2*3.14);
	}
	virtual double Area() const override {
		return (R*R * 3.14);
	}
private:
	const int R;
};


shared_ptr<Figure>  CreateFigure(istringstream& is) {
	string figure;
	is >> figure;
	
	if (figure == "RECT") {
		int w, h;
		is >> w>> h;
		return (make_shared<Rect>(w, h));
	}
	else if (figure == "TRIANGLE") {
		int a, b, c;
		is >> a >> b >> c;
		return (make_shared <Triangle>(a, b, c));
	}
	else{
		int r;
		is >> r;
		return (make_shared <Circle>(r));
	}
}

int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}
