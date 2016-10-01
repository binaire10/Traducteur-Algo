#pragma once
#include "BaseLoop.h"
#include "Expression.h"

namespace ElementAlgorithmique
{
    class LoopFor : public BaseLoop
    {
    public:
        LoopFor() = default;
        LoopFor(const binaire::SmartPtr<Expression> &start, const binaire::SmartPtr<Expression> &final) noexcept;
        LoopFor(const LoopFor &) = delete;
        LoopFor &operator=(const LoopFor &) = delete;
        void ToCppCode(std::ostream &Result) override;
        void setBegin(const binaire::SmartPtr<Expression> &value);
        void setFinal(const binaire::SmartPtr<Expression> &value);
        const binaire::SmartPtr<Expression> &getBegin() const;
        const binaire::SmartPtr<Expression> &getFinal() const;
        const VariablePrototype *getI() const;
        void setI(VariablePrototype *value);

    private:
        VariablePrototype *i = nullptr;
        binaire::SmartPtr<Expression> m_begin = binaire::SmartPtr<Expression>();
        binaire::SmartPtr<Expression> m_final = binaire::SmartPtr<Expression>();
    };
}
