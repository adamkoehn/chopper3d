#ifndef SRC_COMMANDS_SHOOT
#define SRC_COMMANDS_SHOOT

#include <iostream>

#include "../Command.h"

class Shoot : public Command
{
public:
    virtual void Execute() override;
};

#endif /* SRC_COMMANDS_SHOOT */
