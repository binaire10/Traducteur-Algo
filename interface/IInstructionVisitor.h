#ifndef IINSTRUCTIONVISITOR_H
#define IINSTRUCTIONVISITOR_H

class Expression;
class InstructionBlock;
class IInstructionVisitor
{
public:
    constexpr IInstructionVisitor() noexcept = default;
    virtual void visiteInstruction(const Expression &) = undefined;
    virtual void visiteInstruction(const InstructionBlock &) = undefined;
};

#endif // IINSTRUCTIONVISITOR_H
