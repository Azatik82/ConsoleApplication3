#include "Header.h"  // Подключение заголовочного файла

int main() {
    SVG svg("output.svg");  // Создание SVG-файла

    Rectangle rect1(100, 100, 80, 60);  // Создание прямоугольника
    rect1.SetFill("blue");  // Установка цвета заливки
    rect1.AddTo(svg);  // Отрисовка прямоугольника

    Circle circle1(200, 200, 50);  // Создание круга
    circle1.SetStroke("green");  // Установка цвета границы
    circle1.AddTo(svg);  // Отрисовка круга

    CircleInSquare cis(300, 300, 100);  // Создание круга, вписанного в квадрат
    cis.SetSelected(true);  // Выделение объекта
    cis.AddTo(svg);  // Отрисовка

    Figure::DrawCircle(svg, 400, 400, 30, "red", "pink");  // Отрисовка круга через статический метод
    Figure::DrawRectangle(svg, 400, 400, 60, 60, "black", "gray");  // Отрисовка прямоугольника через статический метод

    return 0;
}