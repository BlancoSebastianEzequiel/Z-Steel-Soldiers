#ifndef FLAG_BEHAVIOR_H
#define FLAG_BEHAVIOR_H

class Node;

#include "objectBehavior.h"

class FlagBehavior: public ObjectBehavior {
public:
    FlagBehavior(const object_t &settings, size_t type);
    ~FlagBehavior() override;
    bool canPassThrough() override;
    bool isFlag() override;
};


#endif //FLAG_BEHAVIOR_H
