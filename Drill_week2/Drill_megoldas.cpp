#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "Simple_window.h"


using namespace Graph_lib;


int main(){
	
	Point starting_point {100, 100};
	Simple_window my_window {starting_point, 600, 400, "My window"};

	int origo_x = 600/2;
	int origo_y = 400/2;

	Axis  ax {Axis::x, {0, origo_y}, 600, 10, "x axis"};
	Axis  ay {Axis::y, {origo_x, 400}, 400, 10, "y axis"};

	Function szinusz (sin, 0, 10, Point(origo_x, origo_y), 1000, 20, 20);
	szinusz.set_color(Color::green);

	Polygon my_poly;
	my_poly.add (Point{100, 150});
	my_poly.add (Point{50, 250});
	my_poly.add (Point{80, 50});
	my_poly.set_style(Line_style::dash);
	my_poly.set_color(Color::blue);

	Rectangle my_rectangle {Point{350,250}, 100, 50};
	my_rectangle.set_fill_color(Color::red);

	Text my_text {Point{400, 200}, "asdasd"};
	my_text.set_font_size(50);
	my_text.set_font(Font::courier);

	Image my_image {Point{100, 100}, "badge.jpg"};

	Circle my_cirlce {Point{50,100}, 50};
	my_cirlce.set_color(Color::yellow);
	Mark my_mark {Point{200,100}, 'X'};


	my_window.attach(my_image);
	my_window.attach(ax);
	my_window.attach(ay);
	my_window.attach(my_text);
	my_window.attach(my_rectangle);
	my_window.attach(szinusz);
	my_window.attach(my_poly);
	my_window.attach(my_cirlce);
	my_window.attach(my_mark);
	
	
	my_window.wait_for_button();

}