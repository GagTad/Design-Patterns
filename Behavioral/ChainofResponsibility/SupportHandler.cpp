#include "SupportHandler.h"

SupportHandler::SupportHandler() : nextHandler(nullptr) {}

void SupportHandler::setNext(SupportHandler* handler) {
    nextHandler = handler;
}
