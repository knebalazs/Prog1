#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "Simple_window.h"


using namespace Graph_lib;

double one(double x){ return 1; }
double slope(double x){ return x/2; }
double square(double x){ return x*x; }
double sloping_cos(double x){ return cos(x) + slope(x); }


int main(){

	Simple_window win { Point{100, 100}, 600, 600, "Function graphs"};


	Axis  ax {Axis::x, {100, 300}, 400, 20, "1 == 20 pixels"};
	Axis  ay {Axis::y, {300, 500}, 400, 20, "1 == 20 pixels"};
	ax.set_color(Color::red);
	ay.set_color(Color::red);
	win.attach(ax);
	win.attach(ay);


	Function function_one {one, -10, 11, Point(300, 300), 400, 20, 20};
	win.attach(function_one);
	Function function_slope {slope, -10, 11, Point(300, 300), 400, 20, 20};
	Text slope_text {Point{100, 380}, "x/2"};
	win.attach(function_slope);
	win.attach(slope_text);
	Function function_square {square, -10, 11, Point(300, 300), 400, 20, 20};
	win.attach(function_square);
	Function function_cos {cos, -10, 11, Point(300, 300), 400, 20, 20};
	function_cos.set_color(Color::blue);
	win.attach(function_cos);
	Function function_sloping_cos {sloping_cos, -10, 11, Point(300, 300), 400, 20, 20};
	win.attach(function_sloping_cos);




	win.wait_for_button();


}