#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "windows.h"

using namespace sf;
using namespace std;
//5
int main() {
    setlocale(0, "");
    int lenght_s = 45; //размер сетки в пикселях
    int num_s = 20;  //количество клеток
    int point_x[2], point_y[2];
    int x[6] = { -3,4,-9,6,-6,4 };
    int y[6] = { -4,-2,9,7,-1,6 };
    int n = 6;
    Texture tx;
    tx.create(lenght_s * num_s, lenght_s * num_s);
    RenderWindow window(VideoMode(lenght_s * num_s, lenght_s * num_s), "LR_5");  //создаем объект, который является главным окном приложения
    window.clear(Color(240, 240, 240));  // цвет фона
    ConvexShape convex;
    convex.setPointCount(4);
    point_x[0] = (lenght_s * 10) + ((-5) * lenght_s);
    point_y[0] = (lenght_s * 10) - ((-5) * lenght_s);
    convex.setPoint(0, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (5 * lenght_s) - 1;
    point_y[0] = (lenght_s * 10) - ((-5) * lenght_s);
    convex.setPoint(1, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + (5 * lenght_s) - 1;
    point_y[0] = (lenght_s * 10) - (5 * lenght_s) + 1;
    convex.setPoint(2, Vector2f(point_x[0], point_y[0]));
    point_x[0] = (lenght_s * 10) + ((-5) * lenght_s);
    point_y[0] = (lenght_s * 10) - (5 * lenght_s) + 1;
    convex.setPoint(3, Vector2f(point_x[0], point_y[0]));
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
    for (int i = 0; i < n; i += 2) {
        int kl = -1, kr = -1;
        if ((x[i] <= (-5)) && (y[i] >= 5)) kl = 9;
        else if ((y[i] >= 5) && (x[i] >= (-5)) && (x[i] <= 5)) kl = 8;
        else if ((y[i] >= 5) && (x[i] >= 5)) kl = 10;
        else if ((x[i] <= (-5)) && (y[i] >= (-5)) && (y[i] <= 5)) kl = 1;
        else if ((x[i] >= (-5)) && (x[i] <= 5) && (y[i] >= (-5)) && (y[i] <= 5)) kl = 0;
        else if ((x[i] >= 5) && (y[i] >= (-5)) && (y[i] <= 5)) kl = 2;
        else if ((y[i] <= (-5)) && (x[i] <= (-5))) kl = 5;
        else if ((y[i] <= (-5)) && (x[i] >= (-5)) && (x[i] <= 5)) kl = 4;
        else if ((y[i] <= (-5)) && (x[i] >= 5)) kl = 6;
        if ((x[i + 1] <= (-5)) && (y[i + 1] >= 5)) kr = 9;
        else if ((y[i + 1] >= 5) && (x[i + 1] >= (-5)) && (x[i + 1] <= 5)) kr = 8;
        else if ((y[i + 1] >= 5) && (x[i + 1] >= 5)) kr = 10;
        else if ((x[i + 1] <= (-5)) && (y[i + 1] >= (-5)) && (y[i + 1] <= 5)) kr = 1;
        else if ((x[i + 1] >= (-5)) && (x[i + 1] <= 5) && (y[i + 1] >= (-5)) && (y[i + 1] <= 5)) kr = 0;
        else if ((x[i + 1] >= 5) && (y[i + 1] >= (-5)) && (y[i + 1] <= 5)) kr = 2;
        else if ((y[i + 1] <= (-5)) && (x[i + 1] <= (-5))) kr = 5;
        else if ((y[i + 1] <= (-5)) && (x[i + 1] >= (-5)) && (x[i + 1] <= 5)) kr = 4;
        else if ((y[i + 1] <= (-5)) && (x[i + 1] >= 5)) kr = 6;
        point_x[0] = (lenght_s * 10) + (x[i] * lenght_s);  //перевод в вторичную систему отсчета
        point_x[1] = (lenght_s * 10) + (x[i + 1] * lenght_s);
        point_y[0] = (lenght_s * 10) - (y[i] * lenght_s) + 1;
        point_y[1] = (lenght_s * 10) - (y[i + 1] * lenght_s) + 1;
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
    Texture F;
    F.loadFromImage(image);
    Sprite sp(F);
    window.draw(sp);
    VertexArray ram(Lines, 8);
    ram[0].position = Vector2f((lenght_s * 10) + ((-5) * lenght_s), (lenght_s * 10) - (5 * lenght_s) + 1);
    ram[0].color = Color(0, 50, 255);
    ram[1].position = Vector2f((lenght_s * 10) + (5 * lenght_s), (lenght_s * 10) - (5 * lenght_s) + 1);
    ram[1].color = Color(0, 50, 255);
    ram[2].position = Vector2f((lenght_s * 10) + (5 * lenght_s), (lenght_s * 10) - ((-5) * lenght_s) + 1);
    ram[2].color = Color(0, 50, 255);
    ram[3].position = Vector2f((lenght_s * 10) + ((-5) * lenght_s), (lenght_s * 10) - ((-5) * lenght_s) + 1);
    ram[3].color = Color(0, 50, 255);
    ram[4].position = Vector2f((lenght_s * 10) + (5 * lenght_s), (lenght_s * 10) - (5 * lenght_s) + 1);
    ram[4].color = Color(0, 50, 255);
    ram[5].position = Vector2f((lenght_s * 10) + (5 * lenght_s), (lenght_s * 10) - ((-5) * lenght_s) + 1);
    ram[5].color = Color(0, 50, 255);
    ram[6].position = Vector2f((lenght_s * 10) + ((-5) * lenght_s), (lenght_s * 10) - (5 * lenght_s) + 1);
    ram[6].color = Color(0, 50, 255);
    ram[7].position = Vector2f((lenght_s * 10) + ((-5) * lenght_s), (lenght_s * 10) - ((-5) * lenght_s) + 1);
    ram[7].color = Color(0, 50, 255);
    window.draw(ram);
    window.display();
    system("pause");
    return 0;
}
