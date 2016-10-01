#include "BaseLoop.h"


using namespace std;
using namespace binaire;
using namespace ElementAlgorithmique;

BaseLoop::BaseLoop(const list< SmartPtr<Instruction> > &inst) noexcept : InstructionBlock(inst)
{}
