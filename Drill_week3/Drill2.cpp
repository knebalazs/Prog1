#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "Simple_window.h"


using namespace Graph_lib;


int main(){
	
	Simple_window my_window {Point {100,100}, 800, 1000, "window"};

	Lines my_grid;
	for (int x = 100; x<=800; x += 100)
		my_grid.add(Point{x,0}, Point{x,800});
	for (int y = 100; y<=800; y += 100)
		my_grid.add(Point{0,y}, Point{800,y});
	my_window.attach(my_grid);

	
	Vector_ref<Rectangle> rect;
	for (int i=0; i<8; i++){
		rect.push_back(new Rectangle {Point{i*100, i*100}, 100, 100});
		rect[i].set_fill_color(Color::red);
		my_window.attach(rect[i]);
	}
	
	
	Image my_image1{Point{200,400},"size200.jpg"};
	Image my_image2{Point{0,600},"size200.jpg"};
	Image my_image3{Point{400,0},"size200.jpg"};
	my_window.attach(my_image1);	
	my_window.attach(my_image2);	
	my_window.attach(my_image3);


	for(int i=0; i<=10; i++){
		Image moving_image {Point{randint(7)*100,randint(7)*100}, "size100.jpg"};
		my_window.attach(moving_image);
		my_window.wait_for_button();
}


}