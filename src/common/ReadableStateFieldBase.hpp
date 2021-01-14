#include <Arduino.h>
#include <string>
#include <vector>
#include "ReadableStateFieldBase.hpp"
using namespace std;
class StateFieldRegistry
{
private:
    vector<ReadableStateFieldBase *> readable;
    vector<WritableStateFieldBase *> writable;

    //access readable and writable registries
    ReadableStateFieldBase *findReadableField(string &);
    WritableStateFieldBase *findWritableField(string &);

public:
    StateFieldRegistry();
}