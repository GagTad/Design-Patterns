#include "Shape.h"
#include "PrototypeRegistry.h"
#include <vector>

int main() {
    PrototypeRegistry registry;

    
    registry.addPrototype("BigRedCircle", std::make_unique<Circle>("Red", 20));
    registry.addPrototype("SmallBlueRectangle", std::make_unique<Rectangle>("Blue", 10, 5));

    std::cout << "--- Creating new shapes by cloning prototypes ---" << std::endl;


    auto shape1 = registry.create("BigRedCircle");
    auto shape2 = registry.create("SmallBlueRectangle");
    auto shape3 = registry.create("BigRedCircle"); 


    std::cout << "\n--- Verifying object instances ---" << std::endl;
    std::cout << "Address of original BigRedCircle prototype is not directly accessible here." << std::endl;
    std::cout << "Address of cloned shape1 (Circle): " << shape1.get() << std::endl;
    std::cout << "Address of cloned shape3 (Circle): " << shape3.get() << std::endl;
    if (shape1.get() != shape3.get()) {
        std::cout << "As expected, shape1 and shape3 are different objects." << std::endl;
    }


    std::cout << "\n--- Drawing all created shapes ---" << std::endl;
    std::vector<Shape*> createdShapes;
    if (shape1) createdShapes.push_back(shape1.get());
    if (shape2) createdShapes.push_back(shape2.get());
    if (shape3) createdShapes.push_back(shape3.get());

    for (const auto& shape : createdShapes) {
        shape->draw();
    }

    return 0;
}