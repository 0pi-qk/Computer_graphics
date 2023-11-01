#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "windows.h"

using namespace sf;
using namespace std;
//6
int main() {
    setlocale(0, "");
    int lenght_s = 45; //размер сетки в пикселях
    int num_s = 20;  //количество клеток
    int point_x[2], point_y[2];
    /*/в области
    int x[5] = { -2,2,2,0,-2 };
    int y[5] = { -1,-1,4,6,4 };
    int xi[4] = { -7,7,7,-7 };
    int yi[4] = { -7,-7,7,7 };*/
    /*/вне области
    int x[5] = { 2,7,7,4,2 };
    int y[5] = { 1,1,5,8,5 };
    int xi[4] = { -1,1,1,-1 };
    int yi[4] = { -1,-1,1,1 };*/
    //пересекающий
    /*int x[5] = { -7,-1,2,8,6 };
    int y[5] = { -1,7,0,6,-6 };
    int xi[4] = { -5,5,5,-5 };
    int yi[4] = { -5,-5,5,5 };*/
    int x[5] = { -7,-1,2,8,6 };
    int y[5] = { -1,7,0,6,-6 };
    int xi[4] = { -1,1,1,-1 };
    int yi[4] = { -1,-1,1,1 };
    int n = 5;
    Texture tx;
    tx.create(lenght_s * num_s, lenght_s * num_s);
    RenderWindow window(VideoMode(lenght_s * num_s, lenght_s * num_s), "LR_5");  //создаем объект, который является главным окном приложения
    window.clear(Color(240, 240, 240));  // цвет фона
    ConvexShape convex;
    convex.setPointCount(4);
    point_x[0] = (lenght_s * 10) + (xi[0] * lenght_s);
    point_y[0] = (lenght_s * 10) - (yi[0] * lenght_s);
    convex.setPoint(0, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (xi[1] * lenght_s) - 1;
    point_y[0] = (lenght_s * 10) - (yi[1] * lenght_s);
    convex.setPoint(1, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (xi[2] * lenght_s) - 1;
    point_y[0] = (lenght_s * 10) - (yi[2] * lenght_s) + 1;
    convex.setPoint(2, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (xi[3] * lenght_s);
    point_y[0] = (lenght_s * 10) - (yi[3] * lenght_s) + 1;
    convex.setPoint(3, Vector2f(point_x[0], point_y[0]));
    convex.setFillColor(Color(241, 241, 241));
    window.draw(convex);
    //Сохдание сетки и осей
    RectangleShape line_y(Vector2f(lenght_s * num_s, 1));  //ось y
    line_y.rotate(90.f); // поворачиваем её на 90 градусов
    for (int i = lenght_s; i < lenght_s * num_s; i += lenght_s) {  // проход по всему экрану
        if (i == lenght_s * (num_s / 2))  //если в центре экрана, то рисуем ось у
            line_y.setFillColor(Color(254, 0, 0)); // устанавливаем цвет линии
        else //иначе
            line_y.setFillColor(Color(0, 0, 0)); // устанавливаем цвет линии
        line_y.move(lenght_s, 0); // перемещаем её в нижний ряд справа от прямоугольника
        window.draw(line_y); // отрисовка линии
    }
    RectangleShape line_x(Vector2f(lenght_s * num_s, 1));  //ось x
    for (int i = lenght_s; i < lenght_s * num_s; i += lenght_s) {  // проход по всему экрану
        if (i == lenght_s * (num_s / 2))  //если в центре экрана, то рисуем ось x
            line_x.setFillColor(Color(254, 0, 0)); // устанавливаем цвет линии
        else //иначе
            line_x.setFillColor(Color(0, 0, 0)); // устанавливаем цвет линии
        line_x.move(0, lenght_s); // перемещаем её в нижний ряд справа от прямоугольника
        window.draw(line_x); // отрисовка линии
    }
    for (int i = 0; i < n; i += 1) {
        int kl = -1, kr = -1;
        if ((x[i] <= xi[3]) && (y[i] >= yi[3])) kl = 9;
        else if ((y[i] >= yi[3]) && (x[i] >= xi[3]) && (x[i] <= xi[2])) kl = 8;
        else if ((y[i] >= yi[2]) && (x[i] >= xi[2])) kl = 10;
        else if ((x[i] <= xi[3]) && (y[i] >= yi[0]) && (y[i] <= yi[3])) kl = 1;
        else if ((x[i] >= xi[3]) && (x[i] <= xi[2]) && (y[i] >= yi[0]) && (y[i] <= yi[3])) kl = 0;
        else if ((x[i] >= xi[2]) && (y[i] >= yi[0]) && (y[i] <= yi[3])) kl = 2;
        else if ((y[i] <= yi[0]) && (x[i] <= xi[0])) kl = 5;
        else if ((y[i] <= yi[0]) && (x[i] >= xi[0]) && (x[i] <= xi[1])) kl = 4;
        else if ((y[i] <= yi[0]) && (x[i] >= xi[1])) kl = 6;

        if (i != n - 1) {
            if ((x[i + 1] <= xi[3]) && (y[i + 1] >= yi[3])) kr = 9;
            else if ((y[i + 1] >= yi[3]) && (x[i + 1] >= xi[3]) && (x[i + 1] <= xi[2])) kr = 8;
            else if ((y[i + 1] >= yi[2]) && (x[i + 1] >= xi[2])) kr = 10;
            else if ((x[i + 1] <= xi[3]) && (y[i + 1] >= yi[0]) && (y[i + 1] <= yi[3])) kr = 1;
            else if ((x[i + 1] >= xi[3]) && (x[i + 1] <= xi[2]) && (y[i + 1] >= yi[0]) && (y[i + 1] <= yi[3])) kr = 0;
            else if ((x[i + 1] >= xi[2]) && (y[i + 1] >= yi[0]) && (y[i + 1] <= yi[3])) kr = 2;
            else if ((y[i + 1] <= yi[0]) && (x[i + 1] <= xi[0])) kr = 5;
            else if ((y[i + 1] <= yi[0]) && (x[i + 1] >= xi[0]) && (x[i + 1] <= xi[1])) kr = 4;
            else if ((y[i + 1] <= yi[0]) && (x[i + 1] >= xi[1])) kr = 6;
            point_x[0] = (lenght_s * 10) + (x[i] * lenght_s);  //перевод в вторичную систему отсчета
            point_x[1] = (lenght_s * 10) + (x[i + 1] * lenght_s);
            point_y[0] = (lenght_s * 10) - (y[i] * lenght_s) + 1;
            point_y[1] = (lenght_s * 10) - (y[i + 1] * lenght_s) + 1;
        }
        else {
            if ((x[0] <= xi[3]) && (y[0] >= yi[3])) kr = 9;
            else if ((y[0] >= yi[3]) && (x[0] >= xi[3]) && (x[0] <= xi[2])) kr = 8;
            else if ((y[0] >= yi[2]) && (x[0] >= xi[2])) kr = 10;
            else if ((x[0] <= xi[3]) && (y[0] >= yi[0]) && (y[0] <= yi[3])) kr = 1;
            else if ((x[0] >= xi[3]) && (x[0] <= xi[2]) && (y[0] >= yi[0]) && (y[0] <= yi[3])) kr = 0;
            else if ((x[0] >= xi[2]) && (y[0] >= yi[0]) && (y[0] <= yi[3])) kr = 2;
            else if ((y[0] <= yi[0]) && (x[0] <= xi[0])) kr = 5;
            else if ((y[0] <= yi[0]) && (x[0] >= xi[0]) && (x[0] <= xi[1])) kr = 4;
            else if ((y[0] <= yi[0]) && (x[0] >= xi[1])) kr = 6;
            point_x[0] = (lenght_s * 10) + (x[i] * lenght_s);  //перевод в вторичную систему отсчета
            point_x[1] = (lenght_s * 10) + (x[0] * lenght_s);
            point_y[0] = (lenght_s * 10) - (y[i] * lenght_s) + 1;
            point_y[1] = (lenght_s * 10) - (y[0] * lenght_s) + 1;
        }


        if ((kr == 0) && (kl == 0)) {
            VertexArray func(Lines, 2);
            func[0].position = Vector2f(point_x[0], point_y[0]);  //начальные значения отрезка
            func[0].color = Color(0, 255, 0);
            func[1].position = Vector2f(point_x[1], point_y[1]);  //конечные значения отрезка
            func[1].color = Color(0, 255, 0);
            window.draw(func);
        }
        else if ((kl & kr) != 0) {
            VertexArray func(Lines, 2);
            func[0].position = Vector2f(point_x[0], point_y[0]);  //начальные значения отрезка
            func[0].color = Color(255, 0, 0);
            func[1].position = Vector2f(point_x[1], point_y[1]);  //конечные значения отрезка
            func[1].color = Color(255, 0, 0);
            window.draw(func);
        }
        else {
            VertexArray func(Lines, 2);
            func[0].position = Vector2f(point_x[0], point_y[0]);  //начальные значения отрезка
            func[0].color = Color(0, 50, 254);
            func[1].position = Vector2f(point_x[1], point_y[1]);  //конечные значения отрезка
            func[1].color = Color(0, 50, 254);
            window.draw(func);
        }
    }
    //Название осей
    VertexArray X(Lines, 4);  //название оси x
    X[0].position = Vector2f(((lenght_s * 20) - (lenght_s / 5)), ((lenght_s * 10) + (lenght_s / 5)));
    X[0].color = Color(254, 0, 0);
    X[1].position = Vector2f(((lenght_s * 19) + (lenght_s / 5)), ((lenght_s * 11) - (lenght_s / 5)));
    X[1].color = Color(254, 0, 0);
    X[2].position = Vector2f(((lenght_s * 19) + (lenght_s / 5)), ((lenght_s * 10) + (lenght_s / 5)));
    X[2].color = Color(254, 0, 0);
    X[3].position = Vector2f(((lenght_s * 20) - (lenght_s / 5)), ((lenght_s * 11) - (lenght_s / 5)));
    X[3].color = Color(254, 0, 0);
    window.draw(X);
    VertexArray Y(Lines, 4);  //название оси y
    Y[0].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), (lenght_s / 5));
    Y[0].color = Color(254, 0, 0);
    Y[1].position = Vector2f(((lenght_s * 9) + (lenght_s / 5)), (lenght_s - lenght_s / 5));
    Y[1].color = Color(254, 0, 0);
    Y[2].position = Vector2f(((lenght_s * 9) + (lenght_s / 5)), (lenght_s / 5));
    Y[2].color = Color(254, 0, 0);
    Y[3].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), (lenght_s / 2));
    Y[3].color = Color(254, 0, 0);
    window.draw(Y);
    VertexArray Z(Lines, 8);  // 0
    Z[0].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 11) - (lenght_s / 5)));
    Z[0].color = Color(254, 0, 0);
    Z[1].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 10) + (lenght_s / 5)));
    Z[1].color = Color(254, 0, 0);
    Z[2].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 10) + (lenght_s / 5)));
    Z[2].color = Color(254, 0, 0);
    Z[3].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 10) + (lenght_s / 5)));
    Z[3].color = Color(254, 0, 0);
    Z[4].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 10) + (lenght_s / 5)));
    Z[4].color = Color(254, 0, 0);
    Z[5].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 11) - (lenght_s / 5)));
    Z[5].color = Color(254, 0, 0);
    Z[6].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 11) - (lenght_s / 5)));
    Z[6].color = Color(254, 0, 0);
    Z[7].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 11) - (lenght_s / 5)));
    Z[7].color = Color(254, 0, 0);
    window.draw(Z);
    tx.update(window);
    tx.copyToImage().saveToFile("i.png");
    window.clear();
    Image image;
    image.loadFromFile("i.png");
    for (int _x = 0; _x < num_s*lenght_s; _x++) {
        for (int _y = 0; _y < num_s*lenght_s; _y++) {
            if (image.getPixel(_x, _y) == Color(0, 50, 254)) {
                if ((image.getPixel(_x - 1, _y) == Color(241, 241, 241)) || (image.getPixel(_x + 1, _y) == Color(241, 241, 241)) || (image.getPixel(_x, _y - 1) == Color(241, 241, 241)) || (image.getPixel(_x, _y + 1) == Color(241, 241, 241))) {
                    image.setPixel(_x, _y, Color(0, 255, 0));
                }
                else {
                    image.setPixel(_x, _y, Color(255, 0, 0));
                }
            }
        }
    }
    int t = 1;
    int k = 1; // 1 - синяя
    int _x = (lenght_s * 10) + (xi[3] * lenght_s), _y = (lenght_s * 10) - (yi[3] * lenght_s);
    for (int i = _x; i < ((lenght_s * 10) + (xi[2] * lenght_s)); i++) {
        if ((image.getPixel(i, _y) == Color(0, 255, 0)) || (image.getPixel(i, _y) == Color(255, 0, 0)) ){
            k = k * (-1);
            t = 0;
        }
        if (k == 1) {
            image.setPixel(i, _y, Color(0, 0, 255));
        }
        if (k == -1) {
            image.setPixel(i, _y, Color(0, 255, 0));
        }
    }
    _x = (lenght_s * 10) + (xi[2] * lenght_s) - 1, _y = (lenght_s * 10) - (yi[2] * lenght_s);
    for (int i = _y; i < ((lenght_s * 10) - (yi[1] * lenght_s)); i++) {
        if ((image.getPixel(_x, i) == Color(0, 255, 0)) || (image.getPixel(_x, i) == Color(255, 0, 0))) {
            k = k * (-1);
            t = 0;
        }
        if (k == 1) {
            image.setPixel(_x, i, Color(0, 0, 255));
        }
        if (k == -1) {
            image.setPixel(_x, i, Color(0, 255, 0));
        }
    }
    _x = (lenght_s * 10) + (xi[1] * lenght_s), _y = (lenght_s * 10) - (yi[1] * lenght_s);
    for (int i = _x; i > ((lenght_s * 10) + (xi[0] * lenght_s)); i--) {
        if ((image.getPixel(i, _y) == Color(0, 255, 0)) || (image.getPixel(i, _y) == Color(255, 0, 0))) {
            k = k * (-1);
            t = 0;
        }
        if (k == 1) {
            image.setPixel(i, _y, Color(0, 0, 255));
        }
        if (k == -1) {
            image.setPixel(i, _y, Color(0, 255, 0));
        }
    }
    _x = (lenght_s * 10) + (xi[0] * lenght_s) - 1, _y = (lenght_s * 10) - (yi[0] * lenght_s);
    for (int i = _y; i > ((lenght_s * 10) - (yi[3] * lenght_s)); i--) {
        if ((image.getPixel(_x, i) == Color(0, 255, 0)) || (image.getPixel(_x, i) == Color(255, 0, 0))) {
            k = k * (-1);
            t = 0;
        }
        if (k == 1) {
            image.setPixel(_x, i, Color(0, 0, 255));
        }
        if (k == -1) {
            image.setPixel(_x, i, Color(0, 255, 0));
        }
    }
    if (t == 1) {
        _x = (lenght_s * 10) + (xi[3] * lenght_s), _y = (lenght_s * 10) - (yi[3] * lenght_s);
        for (int i = _x; i < ((lenght_s * 10) + (xi[2] * lenght_s)); i++) {
            image.setPixel(i, _y, Color(0, 255, 0));
        }
        _x = (lenght_s * 10) + (xi[2] * lenght_s) - 1, _y = (lenght_s * 10) - (yi[2] * lenght_s);
        for (int i = _y; i < ((lenght_s * 10) - (yi[1] * lenght_s)); i++) {
            image.setPixel(_x, i, Color(0, 255, 0));
        }
        _x = (lenght_s * 10) + (xi[1] * lenght_s), _y = (lenght_s * 10) - (yi[1] * lenght_s);
        for (int i = _x; i > ((lenght_s * 10) + (xi[0] * lenght_s)); i--) {
            image.setPixel(i, _y, Color(0, 255, 0));
        }
        _x = (lenght_s * 10) + (xi[0] * lenght_s) - 1, _y = (lenght_s * 10) - (yi[0] * lenght_s);
        for (int i = _y; i > ((lenght_s * 10) - (yi[3] * lenght_s)); i--) {
            image.setPixel(_x, i, Color(0, 255, 0));
        }
    }
    Texture F;
    F.loadFromImage(image);
    Sprite sp(F);
    window.draw(sp);
    window.display();
    system("pause");
    return 0;
}
