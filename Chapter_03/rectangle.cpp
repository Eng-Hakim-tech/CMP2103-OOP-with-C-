#include <iostream>

class Rectangle {
private:
    double width;
    double length;

public:
    // Constructor to initialize dimensions
    Rectangle(double w = 0.0, double l = 0.0) : width(w), length(l) {}

    // Setter for width
    void setWidth(double w) {
        if (w >= 0) width = w;
    }

    // Getter for width
    double getWidth() const {
        return width;
    }

    // Setter for length
    void setLength(double l) {
        if (l >= 0) length = l;
    }

    // Getter for length
    double getLength() const {
        return length;
    }

    // Function to calculate area
    double calculateArea() const {
        return width * length;
    }

    // Function to calculate perimeter
    double calculatePerimeter() const {
        return 2 * (width + length);
    }
};

int main() {
    // Creating a Rectangle object
    Rectangle rect;

    // Setting dimensions
    rect.setWidth(5.0);
    rect.setLength(10.0);

    // Retrieving and displaying dimensions
    std::cout << "Rectangle Dimensions: " << rect.getWidth() << " x " << rect.getLength() << std::endl;

    // Calculating and displaying area and perimeter
    std::cout << "Area: " << rect.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rect.calculatePerimeter() << std::endl;

    return 0;
}
