#ifndef IENGINE_H
#define IENGINE_H
class IEngine
{
public:
    virtual void run() = 0;

    virtual ~IEngine() = default;
};
#endif // IENGINE_H
