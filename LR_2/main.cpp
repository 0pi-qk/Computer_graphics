#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "windows.h"

using namespace sf;
using namespace std;

int main() {
    setlocale(0, "");
    int lenght_s = 45; //размер сетки в пикселях
    int num_s = 20;  //количество клеток
    int point_x[2], point_y[2];
    int x[5] = { 1,6,3,-2,-4 };
    int y[5] = { 3,7,-5,-3,9 };
    /*int x[5] = { 4,4,0,-4,-4 };
    int y[5] = { 7,2,-5,-2,7 };*/
    int n = 5;
    Texture tx;
    tx.create(lenght_s * num_s, lenght_s * num_s);
    RenderWindow window(VideoMode(lenght_s * num_s, lenght_s * num_s), "LR_2");  //создаем объект, который является главным окном приложения
    window.clear(Color(240, 240, 240));  // цвет фона
    ConvexShape convex;
    convex.setPointCount(5);
    point_x[0] = (lenght_s * 10) + (x[0] * lenght_s);
    point_y[0] = (lenght_s * 10) - (y[0] * lenght_s);
    convex.setPoint(0, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (x[1] * lenght_s);
    point_y[0] = (lenght_s * 10) - (y[1] * lenght_s);
    convex.setPoint(1, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (x[2] * lenght_s);
    point_y[0] = (lenght_s * 10) - (y[2] * lenght_s);
    convex.setPoint(2, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (x[3] * lenght_s);
    point_y[0] = (lenght_s * 10) - (y[3] * lenght_s);
    convex.setPoint(3, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (x[4] * lenght_s);
    point_y[0] = (lenght_s * 10) - (y[4] * lenght_s);
    convex.setPoint(4, Vector2f(point_x[0], point_y[0]));
    convex.setFillColor(Color(241, 241, 241));
    window.draw(convex);
    //Сохдание сетки и осей
    RectangleShape line_y(Vector2f(lenght_s * num_s, 1));  //ось y
    line_y.rotate(90.f); // поворачиваем её на 90 градусов
    for (int i = lenght_s; i < lenght_s * num_s; i += lenght_s) {  // проход по всему экрану
        if (i == lenght_s * (num_s / 2))  //если в центре экрана, то рисуем ось у
            line_y.setFillColor(Color(255, 0, 0)); // устанавливаем цвет линии
        else //иначе
            line_y.setFillColor(Color(0, 0, 0)); // устанавливаем цвет линии
        line_y.move(lenght_s, 0); // перемещаем её в нижний ряд справа от прямоугольника
        window.draw(line_y); // отрисовка линии
    }
    RectangleShape line_x(Vector2f(lenght_s * num_s, 1));  //ось x
    for (int i = lenght_s; i < lenght_s * num_s; i += lenght_s) {  // проход по всему экрану
        if (i == lenght_s * (num_s / 2))  //если в центре экрана, то рисуем ось x
            line_x.setFillColor(Color(255, 0, 0)); // устанавливаем цвет линии
        else //иначе
            line_x.setFillColor(Color(0, 0, 0)); // устанавливаем цвет линии
        line_x.move(0, lenght_s); // перемещаем её в нижний ряд справа от прямоугольника
        window.draw(line_x); // отрисовка линии
    }
    for (int i = 0; i < n; i++) {
        int k = 0;
        if (i != n - 1) {
            point_x[0] = x[i];
            point_y[0] = y[i];
            point_x[1] = x[i + 1];
            point_y[1] = y[i + 1];
        }
        else {
            point_x[0] = x[i];
            point_y[0] = y[i];
            point_x[1] = x[0];
            point_y[1] = y[0];
        }
        if (point_x[0] > point_x[1]) {
            int tmp = point_x[0]; point_x[0] = point_x[1]; point_x[1] = tmp;
            tmp = point_y[0]; point_y[0] = point_y[1]; point_y[1] = tmp;
        }
        point_x[0] = (lenght_s * 10) + (point_x[0] * lenght_s);  //перевод в вторичную систему отсчета
        point_x[1] = (lenght_s * 10) + (point_x[1] * lenght_s);
        point_y[0] = (lenght_s * 10) - (point_y[0] * lenght_s) + 1;
        point_y[1] = (lenght_s * 10) - (point_y[1] * lenght_s) + 1;
        k = 1;
        VertexArray func(Lines, 2);
        func[0].position = Vector2f(point_x[0], point_y[0]);  //начальные значения отрезка
        func[0].color = Color(0, 50, 255);
        func[1].position = Vector2f(point_x[1], point_y[1]);  //конечные значения отрезка
        func[1].color = Color(0, 50, 255);
        window.draw(func);
    }
    //Название осей
    VertexArray X(Lines, 4);  //название оси x
    X[0].position = Vector2f(((lenght_s * 20) - (lenght_s / 5)), ((lenght_s * 10) + (lenght_s / 5)));
    X[0].color = Color(255, 0, 0);
    X[1].position = Vector2f(((lenght_s * 19) + (lenght_s / 5)), ((lenght_s * 11) - (lenght_s / 5)));
    X[1].color = Color(255, 0, 0);
    X[2].position = Vector2f(((lenght_s * 19) + (lenght_s / 5)), ((lenght_s * 10) + (lenght_s / 5)));
    X[2].color = Color(255, 0, 0);
    X[3].position = Vector2f(((lenght_s * 20) - (lenght_s / 5)), ((lenght_s * 11) - (lenght_s / 5)));
    X[3].color = Color(255, 0, 0);
    window.draw(X);
    VertexArray Y(Lines, 4);  //название оси y
    Y[0].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), (lenght_s / 5));
    Y[0].color = Color(255, 0, 0);
    Y[1].position = Vector2f(((lenght_s * 9) + (lenght_s / 5)), (lenght_s - lenght_s / 5));
    Y[1].color = Color(255, 0, 0);
    Y[2].position = Vector2f(((lenght_s * 9) + (lenght_s / 5)), (lenght_s / 5));
    Y[2].color = Color(255, 0, 0);
    Y[3].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), (lenght_s / 2));
    Y[3].color = Color(255, 0, 0);
    window.draw(Y);
    VertexArray Z(Lines, 8);  // 0
    Z[0].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 11) - (lenght_s / 5)));
    Z[0].color = Color(255, 0, 0);
    Z[1].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 10) + (lenght_s / 5)));
    Z[1].color = Color(255, 0, 0);
    Z[2].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 10) + (lenght_s / 5)));
    Z[2].color = Color(255, 0, 0);
    Z[3].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 10) + (lenght_s / 5)));
    Z[3].color = Color(255, 0, 0);
    Z[4].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 10) + (lenght_s / 5)));
    Z[4].color = Color(255, 0, 0);
    Z[5].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 11) - (lenght_s / 5)));
    Z[5].color = Color(255, 0, 0);
    Z[6].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 11) - (lenght_s / 5)));
    Z[6].color = Color(255, 0, 0);
    Z[7].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 11) - (lenght_s / 5)));
    Z[7].color = Color(255, 0, 0);
    window.draw(Z);
    tx.update(window);
    tx.copyToImage().saveToFile("i.png");
    window.clear();
    while (window.isOpen()) {  //пока окно открыто
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed) {  //если пользователь нажал на закрытие окна
                window.close(); // тогда закрываем его
            }
        Image image;
        image.loadFromFile("i.png");
        int key = 1; //1 - фон, -1 -цвет
        for (int N = 1; N <= num_s; N++) {
            for (int Iy = 0; Iy < N; Iy++) {
                for (int _y = Iy * lenght_s; _y < ((Iy + 1) * lenght_s); _y++) {
                    for (int _x = 0; _x < (num_s * lenght_s); _x++) {
                        Color color = image.getPixel(_x, _y);
                        if (color == Color(241, 241, 241))
                            image.setPixel(_x, _y, Color(160, 255, 160));
                    }
                }
            }
            Sleep(500);
            Texture F;
            F.loadFromImage(image);
            Sprite sp(F);
            window.draw(sp);
            window.display();
        }
    }
    return 0;
}
