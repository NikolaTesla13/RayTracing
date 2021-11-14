#include "Utils/Logger.h"
#include "Program.h"

int main(int argc, char* args[])
{
    Experiment::Logger::Initialize();
    Experiment::Random::Initialize();
    Experiment::Program::Initialize();
    return 0;
}