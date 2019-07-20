#include "flagBehavior.h"

FlagBehavior::FlagBehavior(const object_t &settings, size_t type):
    ObjectBehavior(settings, type) {
}

FlagBehavior::~FlagBehavior() {}

bool FlagBehavior::canPassThrough() {
    return true;
}

bool FlagBehavior::isFlag() {
    return true;
}
