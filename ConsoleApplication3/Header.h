#ifndef SVG_H  // ������ �� ���������� ���������
#define SVG_H

#include <fstream>  // ��� ������ � �������
#include <string>   // ��� ������ �� ��������

// ����� ��� ������ � SVG-������
class SVG {
private:
    std::ofstream file;  // ����� ��� ������ � ����
    std::string filename;  // ��� �����

public:
    SVG(const std::string& filename);  // �����������
    ~SVG();  // ����������
    void AddToFile(const std::string& content);  // ����� ��� ������ � ����
};

// ������� ����� ��� ���� �����
class Figure {
protected:
    int x, y;  // ���������� ������
    std::string stroke;  // ���� �������
    std::string fill;    // ���� �������
    bool selected = false;  // ���� ���������

public:
    Figure(int x, int y, const std::string& stroke = "black", const std::string& fill = "white");  // �����������
    virtual void AddTo(SVG& svg) const = 0;  // ����� ����������� ����� ��� ���������
    void SetStroke(const std::string& color);  // ��������� ����� �������
    void SetFill(const std::string& color);    // ��������� ����� �������
    void SetSelected(bool isSelected);  // ��������� ����� ���������
    static void DrawCircle(SVG& svg, int x, int y, int radius, const std::string& stroke = "black", const std::string& fill = "white");  // ����������� ����� ��� ��������� �����
    static void DrawRectangle(SVG& svg, int x, int y, int width, int height, const std::string& stroke = "black", const std::string& fill = "white");  // ����������� ����� ��� ��������� ��������������
};

// ����� ��� ��������������
class Rectangle : public Figure {
private:
    int width, height;  // ������ � ������

public:
    Rectangle(int x, int y, int width, int height, const std::string& stroke = "black", const std::string& fill = "white");  // �����������
    void AddTo(SVG& svg) const override;  // ��������������� ������ ���������
};

// ����� ��� �����
class Circle : public Figure {
private:
    int radius;  // ������

public:
    Circle(int x, int y, int radius, const std::string& stroke = "black", const std::string& fill = "white");  // �����������
    void AddTo(SVG& svg) const override;  // ��������������� ������ ���������
};

// ����� ��� �����
class Point {
public:
    int x, y;  // ���������� �����

    Point(int x = 0, int y = 0);  // �����������
};

// ����� ��� �����, ���������� � �������
class CircleInSquare : public Rectangle, public Circle {
public:
    CircleInSquare(int x, int y, int size, const std::string& stroke = "black", const std::string& fill = "white");  // �����������
    void AddTo(SVG& svg) const override;  // ��������������� ������ ���������
};

#endif  // ���������� ������ �� ���������� ���������