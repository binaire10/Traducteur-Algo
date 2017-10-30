#ifndef IINSTRUCTIONVISITOR_H
#define IINSTRUCTIONVISITOR_H

class ExpressionNaire;
class InstructionBlock;
class NextLoop;
class BreakLoop;
class ForLoop;
class Conditional;
class Loop;
class IInstructionVisitor
{
public:
    constexpr IInstructionVisitor() noexcept = default;
    virtual void visiteInstruction(const ExpressionNaire &) = undefined;
    virtual void visiteInstruction(const InstructionBlock &) = undefined;
    virtual void visiteInstruction(const NextLoop &) = undefined;
    virtual void visiteInstruction(const BreakLoop &) = undefined;
    virtual void visiteInstruction(const Conditional &) = undefined;
    virtual void visiteInstruction(const Loop &) = undefined;
    virtual void visiteInstruction(const ForLoop &) = undefined;
};

#endif // IINSTRUCTIONVISITOR_H
