#ifndef SRC_COMMAND
#define SRC_COMMAND

class Command
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
};

#endif /* SRC_COMMAND */
