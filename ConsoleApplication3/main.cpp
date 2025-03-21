#include "Header.h"  // ����������� ������������� �����

int main() {
    SVG svg("output.svg");  // �������� SVG-�����

    Rectangle rect1(100, 100, 80, 60);  // �������� ��������������
    rect1.SetFill("blue");  // ��������� ����� �������
    rect1.AddTo(svg);  // ��������� ��������������

    Circle circle1(200, 200, 50);  // �������� �����
    circle1.SetStroke("green");  // ��������� ����� �������
    circle1.AddTo(svg);  // ��������� �����

    CircleInSquare cis(300, 300, 100);  // �������� �����, ���������� � �������
    cis.SetSelected(true);  // ��������� �������
    cis.AddTo(svg);  // ���������

    Figure::DrawCircle(svg, 400, 400, 30, "red", "pink");  // ��������� ����� ����� ����������� �����
    Figure::DrawRectangle(svg, 400, 400, 60, 60, "black", "gray");  // ��������� �������������� ����� ����������� �����

    return 0;
}