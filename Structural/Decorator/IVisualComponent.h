#pragma once

class IVisualComponent {
public:
	virtual ~IVisualComponent() = default;
	virtual void draw() const = 0;
	virtual void resize() = 0;
};
