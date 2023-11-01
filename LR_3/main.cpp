#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "windows.h"

using namespace sf;
using namespace std;

int main() {
    setlocale(0, "");
    /*int x[6] = { 85,100,20,20,62,62 };
    int y[6] = { 50,110,110,50,8,50 };*/
    int x[6] = { 85 , 100 , 20 , 20 ,37,77 };
    int y[6] = { 50, 110 , 110 , 50,50,8 };
    int n = 6;
    int X = 65, Y = 102;
    int lg = 150;
    Texture tx;
    tx.create(lg, lg);
    RenderWindow window(VideoMode(lg, lg), "LR_3");  //создаем объект, который является главным окном приложения
    window.clear(Color(240, 240, 240));  // цвет фона
    ConvexShape convex;
    convex.setPointCount(6);
    convex.setPoint(0, Vector2f(x[0], y[0]));
    convex.setPoint(1, Vector2f(x[1], y[1]));
    convex.setPoint(2, Vector2f(x[2], y[2]));
    convex.setPoint(3, Vector2f(x[3], y[3]));
    convex.setPoint(4, Vector2f(x[4], y[4]));
    convex.setPoint(5, Vector2f(x[5], y[5]));
    convex.setFillColor(Color(241, 241, 241));
    convex.move(10, 10);
    convex.setOutlineThickness(1);
    convex.setOutlineColor(Color(0, 50, 255));
    window.draw(convex);
    CircleShape square(15, 4);
    square.rotate(45.f);
    square.setPosition(72, 64);
    square.setOutlineThickness(1);
    square.setOutlineColor(Color(0, 50, 255));
    square.setFillColor(Color(240, 240, 240));
    window.draw(square);
    tx.update(window);
    tx.copyToImage().saveToFile("i.png");
    window.clear(Color(240, 240, 240));  // цвет фона
    while (window.isOpen()) {  //пока окно открыто
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed) {  //если пользователь нажал на закрытие окна
                window.close(); // тогда закрываем его
            }
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            Image image;
            image.loadFromFile("i.png");
            while (1) {
                Color color;
                for (int _y = Y; _y <= 120; _y++) {
                    for (int _x = X; _x >= 30; _x--) {
                        color = image.getPixel(_x, _y);
                        if (color == Color(241, 241, 241))
                            image.setPixel(_x, _y, Color(0, 0, 0));
                        color = image.getPixel(_x - 1, _y);
                        Sleep(1);
                        Texture F;
                        F.loadFromImage(image);
                        Sprite sp(F);
                        window.draw(sp);
                        window.display();
                    }
                    for (int _x = X; _x <= 110; _x++) {
                        color = image.getPixel(_x, _y);
                        if (color == Color(241, 241, 241))
                            image.setPixel(_x, _y, Color(0, 0, 0));
                        color = image.getPixel(_x - 1, _y);
                        Sleep(1);
                        Texture F;
                        F.loadFromImage(image);
                        Sprite sp(F);
                        window.draw(sp);
                        window.display();
                    }
                }
                for (int _y = Y; _y >= 18; _y--) {
                    for (int _x = X; _x >= 30; _x--) {
                        color = image.getPixel(_x, _y);
                        if (color == Color(241, 241, 241))
                            image.setPixel(_x, _y, Color(0, 0, 0));
                        color = image.getPixel(_x - 1, _y);
                        Sleep(1);
                        Texture F;
                        F.loadFromImage(image);
                        Sprite sp(F);
                        window.draw(sp);
                        window.display();
                    }
                    for (int _x = X; _x <= 110; _x++) {
                        color = image.getPixel(_x, _y);
                        if (color == Color(241, 241, 241))
                            image.setPixel(_x, _y, Color(0, 0, 0));
                        color = image.getPixel(_x - 1, _y);
                        Sleep(1);
                        Texture F;
                        F.loadFromImage(image);
                        Sprite sp(F);
                        window.draw(sp);
                        window.display();
                    }
                }
                break;
            }
        }
    }
    return 0;
}
