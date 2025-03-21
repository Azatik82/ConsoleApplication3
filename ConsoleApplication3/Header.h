#ifndef SVG_H  // Защита от повторного включения
#define SVG_H

#include <fstream>  // Для работы с файлами
#include <string>   // Для работы со строками

// Класс для работы с SVG-файлом
class SVG {
private:
    std::ofstream file;  // Поток для записи в файл
    std::string filename;  // Имя файла

public:
    SVG(const std::string& filename);  // Конструктор
    ~SVG();  // Деструктор
    void AddToFile(const std::string& content);  // Метод для записи в файл
};

// Базовый класс для всех фигур
class Figure {
protected:
    int x, y;  // Координаты центра
    std::string stroke;  // Цвет границы
    std::string fill;    // Цвет заливки
    bool selected = false;  // Флаг выделения

public:
    Figure(int x, int y, const std::string& stroke = "black", const std::string& fill = "white");  // Конструктор
    virtual void AddTo(SVG& svg) const = 0;  // Чисто виртуальный метод для отрисовки
    void SetStroke(const std::string& color);  // Установка цвета границы
    void SetFill(const std::string& color);    // Установка цвета заливки
    void SetSelected(bool isSelected);  // Установка флага выделения
    static void DrawCircle(SVG& svg, int x, int y, int radius, const std::string& stroke = "black", const std::string& fill = "white");  // Статический метод для отрисовки круга
    static void DrawRectangle(SVG& svg, int x, int y, int width, int height, const std::string& stroke = "black", const std::string& fill = "white");  // Статический метод для отрисовки прямоугольника
};

// Класс для прямоугольника
class Rectangle : public Figure {
private:
    int width, height;  // Ширина и высота

public:
    Rectangle(int x, int y, int width, int height, const std::string& stroke = "black", const std::string& fill = "white");  // Конструктор
    void AddTo(SVG& svg) const override;  // Переопределение метода отрисовки
};

// Класс для круга
class Circle : public Figure {
private:
    int radius;  // Радиус

public:
    Circle(int x, int y, int radius, const std::string& stroke = "black", const std::string& fill = "white");  // Конструктор
    void AddTo(SVG& svg) const override;  // Переопределение метода отрисовки
};

// Класс для точки
class Point {
public:
    int x, y;  // Координаты точки

    Point(int x = 0, int y = 0);  // Конструктор
};

// Класс для круга, вписанного в квадрат
class CircleInSquare : public Rectangle, public Circle {
public:
    CircleInSquare(int x, int y, int size, const std::string& stroke = "black", const std::string& fill = "white");  // Конструктор
    void AddTo(SVG& svg) const override;  // Переопределение метода отрисовки
};

#endif  // Завершение защиты от повторного включения