#pragma once

#include <iostream>
#include <string>
#include <memory>

class Shape {
protected:
    std::string m_color;

public:
    Shape(const std::string& color) : m_color(color) {}
    virtual ~Shape() = default;

  
    virtual std::unique_ptr<Shape> clone() const = 0;

    virtual void draw() const = 0;
};

class Circle : public Shape {
private:
    int m_radius;

public:
    Circle(const std::string& color, int radius) : Shape(color), m_radius(radius) {}

   
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(*this);
    }

    void draw() const override {
        std::cout << "Drawing a " << m_color << " circle with radius " << m_radius << "." << std::endl;
    }
};

class Rectangle : public Shape {
private:
    int m_width;
    int m_height;

public:
    Rectangle(const std::string& color, int width, int height)
        : Shape(color), m_width(width), m_height(height) {
    }

    
    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }

    void draw() const override {
        std::cout << "Drawing a " << m_color << " rectangle of size "
            << m_width << "x" << m_height << "." << std::endl;
    }
};