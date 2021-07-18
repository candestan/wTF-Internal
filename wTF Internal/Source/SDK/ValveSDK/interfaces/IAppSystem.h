#pragma once

#define CREATE_INTERFACE_STR "CreateInterface"

typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);
typedef void* (*InstantiateInterfaceFn)();

class IAppSystem
{
public:
    virtual bool                            Connect(CreateInterfaceFn factory) = 0;                                     // 0
    virtual void                            Disconnect() = 0;                                                           // 1
    virtual void*                           QueryInterface(const char* pInterfaceName) = 0;                             // 2
    virtual int                             Init() = 0;                                                                 // 3
    virtual void                            Shutdown() = 0;                                                             // 4
    virtual const void*                     GetDependencies() = 0;                                                      // 5
    virtual int                             GetTier() = 0;                                                              // 6
    virtual void                            Reconnect(CreateInterfaceFn factory, const char* pInterfaceName) = 0;       // 7
    virtual void                            UnkFunc() = 0;                                                              // 8
};