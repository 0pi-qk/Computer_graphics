#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

int main() {
    setlocale(0, "");
    cout << "Удерживайте кнопку Q для просмотра результат по алгоритму ЦДА" << endl << "Удерживайте кнопку W для просмотра результат по алгоритму Брезенхема";
    int lenght_s = 45; //размер сетки в пикселях
    int num_s = 21;  //количество клеток
    int point_x[2], point_y[2];
    int x1 = 2, y1 = -2, x2 = 10, y2 = -4;
    // x1 = 0, y1 = 0, x2 = 8, y2 = 3;
    //x1 = 0, y1 = 0, x2 = 7, y2 = -3;
    //x1 = -5, y1 = 2, x2 = 3, y2 = 9;
    //x1 = -9, y1 = -8, x2 = -1, y2 = -1;
    //x1 = -5, y1 = 2, x2 = 7, y2 = 5;
    //x1 = -8, y1 = -7, x2 = 5, y2 = -4;
    //x1 = -7, y1 = -8, x2 = -4, y2 = 4;
    //x1 = -3, y1 = -4, x2 = 7, y2 = -4;
    //x1 = 1, y1 = -7, x2 = 7, y2 = 9;
    //x1 = 1, y1 = 5, x2 = 8, y2 = -6;
    //x1 = -5, y1 = -5, x2 = 7, y2 = 7;
    //x1 = -7, y1 = 7, x2 = 5, y2 = -5;
    //x1 = -3, y1 = -1, x2 = 6, y2 = 7;
    //x1 = -3, y1 = 1, x2 = 6, y2 = -7;
    //x1 =-2, y1 =6, x2 =5, y2 =-8 ;
    //x1 =-2, y1 =-6, x2 = 3, y2 = 8;
    //x1 =-7, y1 =8, x2 =6, y2 = 1;
    //x1 =-7, y1 =-2, x2 =8, y2 = -6;
    //x1 = 0, y1 = 0, x2 = 1, y2 = 1;
    if (y1 < y2) {  //функция возрастает
        point_x[0] = (lenght_s * 10) + (x1 * lenght_s);  //перевод в вторичную систему отсчета
        point_x[1] = (lenght_s * 11) + (x2 * lenght_s);
        point_y[0] = (lenght_s * 11) - (y1 * lenght_s);
        point_y[1] = (lenght_s * 10) - (y2 * lenght_s);
    }
    if (y1 > y2) {  //функция убывает
        point_x[0] = (lenght_s * 10) + (x1 * lenght_s);  //перевод в вторичную систему отсчета
        point_x[1] = (lenght_s * 11) + (x2 * lenght_s);
        point_y[0] = (lenght_s * 10) - (y1 * lenght_s);
        point_y[1] = (lenght_s * 11) - (y2 * lenght_s);
    }
    if (y1 == y2) {  //функция постоянна
        point_x[0] = (lenght_s * 10) + (x1 * lenght_s);  //перевод в вторичную систему отсчета
        point_x[1] = (lenght_s * 11) + (x2 * lenght_s);
        point_y[0] = (lenght_s * 11) - (y1 * lenght_s);
        point_y[1] = (lenght_s * 11) - (y2 * lenght_s);
    }
    RenderWindow window(VideoMode(lenght_s * num_s, lenght_s * num_s), "LR_1");  //создаем объект, который является главным окном приложения
    while (window.isOpen()) {  //пока окно открыто
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)  //если пользователь нажал на закрытие окна
                window.close(); // тогда закрываем его
        window.clear(Color(240, 240, 240));  // цвет фона
        //Сохдание сетки и осей
        RectangleShape line_y(Vector2f(lenght_s * num_s, 1));  //ось y
        line_y.rotate(90.f); // поворачиваем её на 90 градусов
        for (int i = lenght_s; i < lenght_s * num_s; i += lenght_s) {  // проход по всему экрану
            if ((i == lenght_s * (num_s / 2)) || (i == lenght_s * (num_s / 2 + 1)))  //если в центре экрана, то рисуем ось у
                line_y.setFillColor(Color(255, 0, 0)); // устанавливаем цвет линии
            else //иначе
                line_y.setFillColor(Color(0, 0, 0)); // устанавливаем цвет линии
            line_y.move(lenght_s, 0); // перемещаем её в нижний ряд справа от прямоугольника
            window.draw(line_y); // отрисовка линии
        }
        RectangleShape line_x(Vector2f(lenght_s * num_s, 1));  //ось x
        for (int i = lenght_s; i < 1000; i += lenght_s) {  // проход по всему экрану
            if ((i == lenght_s * (num_s / 2)) || (i == lenght_s * (num_s / 2 + 1)))  //если в центре экрана, то рисуем ось x
                line_x.setFillColor(Color(255, 0, 0)); // устанавливаем цвет линии
            else //иначе
                line_x.setFillColor(Color(0, 0, 0)); // устанавливаем цвет линии
            line_x.move(0, lenght_s); // перемещаем её в нижний ряд справа от прямоугольника
            window.draw(line_x); // отрисовка линии
        }
        //рисуем график
        VertexArray func(Lines, 2);
        func[0].position = Vector2f(point_x[0], point_y[0]);  //начальные значения отрезка
        func[0].color = Color(0, 50, 255);
        func[1].position = Vector2f(point_x[1], point_y[1]);  //конечные значения отрезка
        func[1].color = Color(0, 50, 255);
        //Название осей
        VertexArray x(Lines, 4);  //название оси x
        x[0].position = Vector2f(((lenght_s * 21) - (lenght_s / 5)), ((lenght_s * 11) + (lenght_s / 5)));
        x[0].color = Color(255, 0, 0);
        x[1].position = Vector2f(((lenght_s * 20) + (lenght_s / 5)), ((lenght_s * 12) - (lenght_s / 5)));
        x[1].color = Color(255, 0, 0);
        x[2].position = Vector2f(((lenght_s * 20) + (lenght_s / 5)), ((lenght_s * 11) + (lenght_s / 5)));
        x[2].color = Color(255, 0, 0);
        x[3].position = Vector2f(((lenght_s * 21) - (lenght_s / 5)), ((lenght_s * 12) - (lenght_s / 5)));
        x[3].color = Color(255, 0, 0);
        VertexArray y(Lines, 4);  //название оси y
        y[0].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), (lenght_s / 5));
        y[0].color = Color(255, 0, 0);
        y[1].position = Vector2f(((lenght_s * 9) + (lenght_s / 5)), (lenght_s - lenght_s / 5));
        y[1].color = Color(255, 0, 0);
        y[2].position = Vector2f(((lenght_s * 9) + (lenght_s / 5)), (lenght_s / 5));
        y[2].color = Color(255, 0, 0);
        y[3].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), (lenght_s / 2));
        y[3].color = Color(255, 0, 0);
        VertexArray z(Lines, 8);  // 0
        z[0].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 12) - (lenght_s / 5)));
        z[0].color = Color(255, 0, 0);
        z[1].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 11) + (lenght_s / 5)));
        z[1].color = Color(255, 0, 0);
        z[2].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 11) + (lenght_s / 5)));
        z[2].color = Color(255, 0, 0);
        z[3].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 11) + (lenght_s / 5)));
        z[3].color = Color(255, 0, 0);
        z[4].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 11) + (lenght_s / 5)));
        z[4].color = Color(255, 0, 0);
        z[5].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 12) - (lenght_s / 5)));
        z[5].color = Color(255, 0, 0);
        z[6].position = Vector2f(((lenght_s * 9) + (lenght_s / 2)), ((lenght_s * 12) - (lenght_s / 5)));
        z[6].color = Color(255, 0, 0);
        z[7].position = Vector2f(((lenght_s * 10) - (lenght_s / 5)), ((lenght_s * 12) - (lenght_s / 5)));
        z[7].color = Color(255, 0, 0);
        //Алгоритм ЦДА
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            int len;  //приращение
            if ((abs(x2 - x1)) >= (abs(y2 - y1)))  //опредиляем наибольшее приращение
                len = abs(x2 - x1);
            else
                len = abs(y2 - y1);
            double Px, Py;  //одна =1 другая <1
            Px = (x2 - x1) / (double)len;  //dx
            Py = (y2 - y1) / (double)len;  //dy
            double X, Y;
            //начальные данные
            X = x2;
            Y = y2;
            //основной цикл
            for (int i = 0; i <= len; i++) {
                double Xn, Yn;  //временные переменные для расчета координат
                if (y1 < y2) {//переводим в другую систему отсчета
                    if (X >= 0)
                        Xn = (lenght_s * 10) + ((trunc(X)) * lenght_s);
                    else
                        Xn = (lenght_s * 10) + ((floor(X)) * lenght_s);
                    if (Y >= 0)
                        Yn = (lenght_s * 11) - ((trunc(Y)) * lenght_s);
                    else
                        Yn = (lenght_s * 11) - ((floor(Y)) * lenght_s);
                }
                if (y1 > y2) {
                    if (X >= 0)
                        Xn = (lenght_s * 10) + ((trunc(X)) * lenght_s);
                    else
                        Xn = (lenght_s * 10) + ((floor(X)) * lenght_s);
                    if (Y >= 0)
                        Yn = (lenght_s * 10) - ((trunc(Y)) * lenght_s);
                    else
                        Yn = (lenght_s * 10) - ((floor(Y)) * lenght_s);
                }
                if (y1 == y2) {
                    if (X >= 0)
                        Xn = (lenght_s * 10) + ((trunc(X)) * lenght_s);
                    else
                        Xn = (lenght_s * 10) + ((floor(X)) * lenght_s);
                    if (Y >= 0)
                        Yn = (lenght_s * 11) - ((trunc(Y)) * lenght_s);
                    else
                        Yn = (lenght_s * 11) - ((floor(Y)) * lenght_s);
                }
                RectangleShape DDA(Vector2f(lenght_s - 1, lenght_s - 1));  //оператор рисования прямоугольника
                if (point_x[0] > point_x[1])  //определяем позицию треугольника
                    DDA.move(Xn, Yn + 2);
                else if (y1 > y2)
                    DDA.move(Xn, Yn + 1);
                else
                    DDA.move(Xn, Yn - lenght_s + 1);
                DDA.setFillColor(Color(0, 255, 0));  //выбираем цвет
                window.draw(DDA);  //выводим на экран
                if (i == 0) {
                    X = x1;
                    Y = y1;
                    continue;
                }
                X = X + Px;  //находим следующие значения х у
                Y = Y + Py;
            }
        }
        //алгоритм Брезенхема
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            int dx = (x2 - x1 >= 0 ? 1 : -1);
            int dy = (y2 - y1 >= 0 ? 1 : -1);
            int Xn, Yn;  //временные переменные для расчета координат
            int lengthX = abs(x2 - x1);  //длина по х
            int lengthY = abs(y2 - y1);  //длина по у
            int length = max(lengthX, lengthY);  //максимальная длина
            // Начальные значения
            int X = x1;
            int Y = y1;
            int E = -lengthX;
            length++;
            // Основной цикл
            while (length--) {
                if (y1 < y2) {
                    if (X >= 0)
                        Xn = (lenght_s * 10) + (X * lenght_s);
                    else
                        Xn = (lenght_s * 10) + (X * lenght_s);
                    if (Y >= 0)
                        Yn = (lenght_s * 11) - (Y * lenght_s);
                    else
                        Yn = (lenght_s * 11) - (Y * lenght_s);
                }
                if (y1 > y2) {
                    if (X >= 0)
                        Xn = (lenght_s * 10) + (X * lenght_s);
                    else
                        Xn = (lenght_s * 10) + (X * lenght_s);
                    if (Y >= 0)
                        Yn = (lenght_s * 10) - (Y * lenght_s);
                    else
                        Yn = (lenght_s * 10) - (Y * lenght_s);
                }
                if (y1 == y2) {
                    if (X >= 0)
                        Xn = (lenght_s * 10) + (X * lenght_s);
                    else
                        Xn = (lenght_s * 10) + (X * lenght_s);
                    if (Y >= 0)
                        Yn = (lenght_s * 11) - (Y * lenght_s);
                    else
                        Yn = (lenght_s * 11) - (Y * lenght_s);
                }
                RectangleShape DDA(Vector2f(lenght_s - 1, lenght_s - 1));//оператор рисования прямоугольника
                if (point_x[0] > point_x[1])//определяем позицию треугольника
                    DDA.move(Xn, Yn + 2);
                else if (y1 > y2)
                    DDA.move(Xn, Yn + 1);
                else
                    DDA.move(Xn, Yn - lenght_s + 1);
                DDA.setFillColor(Color(0, 255, 255, 150));//выбираем цвет и прозрачность
                window.draw(DDA);//выводим на экран
                if (lengthY <= lengthX) {  // определяем в какой половине и находим следующие значения
                    X += dx;
                    E += 2 * lengthY;
                    if (E > 0) {
                        E -= 2 * lengthX;
                        Y += dy;
                    }
                }
                else {
                    Y += dy;
                    E += 2 * lengthX;
                    if (E > 0) {
                        E -= 2 * lengthY;
                        X += dx;
                    }
                }
            }
        }
        //обновление дисплея
        window.draw(func);
        window.draw(x);
        window.draw(y);
        window.draw(z);
        window.display();
    }

    return 0;
}
