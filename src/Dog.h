#pragma once

#include "Pet.h"

class Dog : public Pet {
public:
    Dog();
    void setGraphic() override;
};