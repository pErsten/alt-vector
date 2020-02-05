#include <iostream>
#include <cmath>
#include <vector>
#include "vec.h"

int main() {
	vec<int> a(3);
	a[0] = 5;
	a[1] = 6;
	a[2] = 89;
	a.addBack(8970);
	a.addBack(44);
	a.addBack(474);
	a.addBack(445);
	a.addBack(445);
	a.addBack(445);
	a.addBack(445);
	a.addBack(445);
	a.addBack(424);
	a.addBack(4);
	a.deleteBack();
	a.addBack(78);
	a.arrSort(-1);
	std::cout << a;
	std::cout << std::endl;
	std::cout << a.find(445, 0) << " " << a.find(445, -1) << " " << a.find(445);
	std::cout << std::endl;
	vec<std::string> b(2);
	b[0] = "My";
	b[1] = "name";
	b.addBack("is");
	b.addBack("Vlad");
	b.arrSort();
	std::cout << b;
	std::cout << std::endl;
	vec<char> c(4);
	c[0] = 'V';
	c[1] = 'l';
	c[2] = 'a';
	c[3] = 'd';
	c.arrSort();
	std::cout << c << std::endl;
	int row = 50;
	int col = 10;
	vec<vec<int>> d(row);
	d[0] = vec<int>(col);
	d[1] = vec<int>(col);
	d[0][2] = 7;
	d[1][3] = 8;
	std::cout << d[0][2] << " " << d[1][3];
	for (int i = 0; i < row; i++) {
		d[i] = vec<int>(col);
		for (int j = 0; j < col; j++) {
			d[i][j] = i*j;
		}
	}
	d[2].arrSort();
	for (int i = 0; i < row; i++) {
		std::cout << std::endl;
		for (int j = 0; j < col; j++) {
			std::cout << d[i][j] << " ";
		}
	}
	//std::cout << d[0][3];
	//std::vector<int> Tchlaine(1000), h;
	//std::cout << sizeof Tchlaine << " " << sizeof h;
	std::cout << "hgkdh";
	//vec<int> t = { 0,9,7 };
}
