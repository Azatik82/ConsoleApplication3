#include "Header.h"  // ����������� ������������� �����

// ���������� ������� ������ SVG
SVG::SVG(const std::string& filename) : filename(filename) {
    file.open(filename);  // �������� ����� ��� ������
    file << "<svg width='500' height='500' xmlns='http://www.w3.org/2000/svg'>\n";  // ������ ��������� SVG
}

SVG::~SVG() {
    if (file.is_open()) {
        file << "</svg>\n";  // ���������� SVG-���������
        file.close();  // �������� �����
    }
}

void SVG::AddToFile(const std::string& content) {
    if (file.is_open()) {
        file << content;  // ������ ����������� � ����
    }
}

// ���������� ������� ������ Figure
Figure::Figure(int x, int y, const std::string& stroke, const std::string& fill)
    : x(x), y(y), stroke(stroke), fill(fill) {
}

void Figure::SetStroke(const std::string& color) {
    stroke = color;  // ��������� ����� �������
}

void Figure::SetFill(const std::string& color) {
    fill = color;  // ��������� ����� �������
}

void Figure::SetSelected(bool isSelected) {
    selected = isSelected;  // ��������� ����� ���������
}

void Figure::DrawCircle(SVG& svg, int x, int y, int radius, const std::string& stroke, const std::string& fill) {
    Circle circle(x, y, radius, stroke, fill);  // �������� �����
    circle.AddTo(svg);  // ��������� �����
}

void Figure::DrawRectangle(SVG& svg, int x, int y, int width, int height, const std::string& stroke, const std::string& fill) {
    Rectangle rect(x, y, width, height, stroke, fill);  // �������� ��������������
    rect.AddTo(svg);  // ��������� ��������������
}

// ���������� ������� ������ Rectangle
Rectangle::Rectangle(int x, int y, int width, int height, const std::string& stroke, const std::string& fill)
    : Figure(x, y, stroke, fill), width(width), height(height) {
}

void Rectangle::AddTo(SVG& svg) const {
    std::string color = selected ? "yellow" : fill;  // ����� ����� �������
    std::string rect = "<rect x='" + std::to_string(x - width / 2) + "' y='" + std::to_string(y - height / 2) +
        "' width='" + std::to_string(width) + "' height='" + std::to_string(height) +
        "' stroke='" + stroke + "' fill='" + color + "' />\n";  // ������������ SVG-���� ��� ��������������
    svg.AddToFile(rect);  // ������ � ����
}

// ���������� ������� ������ Circle
Circle::Circle(int x, int y, int radius, const std::string& stroke, const std::string& fill)
    : Figure(x, y, stroke, fill), radius(radius) {
}

void Circle::AddTo(SVG& svg) const {
    std::string color = selected ? "yellow" : fill;  // ����� ����� �������
    std::string circle = "<circle cx='" + std::to_string(x) + "' cy='" + std::to_string(y) +
        "' r='" + std::to_string(radius) + "' stroke='" + stroke + "' fill='" + color + "' />\n";  // ������������ SVG-���� ��� �����
    svg.AddToFile(circle);  // ������ � ����
}

// ���������� ������� ������ Point
Point::Point(int x, int y) : x(x), y(y) {}

// ���������� ������� ������ CircleInSquare
CircleInSquare::CircleInSquare(int x, int y, int size, const std::string& stroke, const std::string& fill)
    : Rectangle(x, y, size, size, stroke, fill), Circle(x, y, size / 2, stroke, fill) {
}

void CircleInSquare::AddTo(SVG& svg) const {
    Rectangle::AddTo(svg);  // ��������� ��������
    Circle::AddTo(svg);     // ��������� �����
}