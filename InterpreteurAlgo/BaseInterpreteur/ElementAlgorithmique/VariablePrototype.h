#pragma once
#include <typeindex>
#include <string>

namespace ElementAlgorithmique
{
    class VarType;
    class VariablePrototype;
}


namespace ElementAlgorithmique
{
    class VarType
    {
    public:
        enum ValueType : int{
            UNKNOWN = 0,
            INT = 1,
            CHAR = 2,
            UNSIGNED = 3,
            DOUBLE = 4,
            STRING = 5,
            ARRAYS = 8
        };

        VarType(bool isRefVar, bool isConst, unsigned ArrayLevel, const std::type_index &Type, unsigned Size) noexcept;
        VarType(bool isRefVar, bool isConst, unsigned ArrayLevel, const std::type_index &Type, VariablePrototype *Var) noexcept;

        const unsigned &getArrayLevel() const noexcept;
        std::type_index getType() const noexcept;
        unsigned &getSize() noexcept;
        VariablePrototype *getVar() noexcept;
        const VariablePrototype *getVar() const noexcept;

        void setArrayLevel(unsigned value) noexcept;
        void setType_Index(const std::type_index &Type) noexcept;
        void setSize(unsigned value) noexcept;
        void setVar(VariablePrototype *value) noexcept;
        void setIsRefVar(bool isRefVar) noexcept;
        void setIsConst(bool isConst) noexcept;
        bool getVariableType() const noexcept;
        bool getIsRefVar() const noexcept;
        bool getIsConst() const noexcept;
        bool operator ==(const VarType &output) const noexcept;

        static bool allowType(const ElementAlgorithmique::VarType &ty1);
        static bool isTranstypable(const ElementAlgorithmique::VarType &ty1, const ElementAlgorithmique::VarType &ty2);
        static ElementAlgorithmique::VarType getBestType(const ElementAlgorithmique::VarType &input, const ElementAlgorithmique::VarType &output);
        ValueType getValueType() const;

    private:
        unsigned m_ArrayLevel;
        std::type_index m_Type;
        bool m_VariableType;
        union{
            unsigned m_Size;
            VariablePrototype *m_Var;
        };

        bool m_isRefVar;
        bool m_isConst;
        ValueType m_ValueType;
    };

    class VariablePrototype
    {
    public:
        VariablePrototype() = default;
        VariablePrototype(const std::string &Name, bool isConst, bool isRefVar, const VarType &vType) noexcept;
        VariablePrototype(const std::string &Name, bool isConst, bool isRefVar, unsigned ArrayLevel, const std::type_index &Type, unsigned Size) noexcept;
        VariablePrototype(const std::string &Name, bool isConst, bool isRefVar, unsigned ArrayLevel, const std::type_index &Type, VariablePrototype *Var) noexcept;

        VarType &getVarTypeStructure() noexcept;
        const VarType &getVarTypeStructure() const noexcept;

        const std::string &getName() const noexcept;
        void setName(const std::string &value) noexcept;

    private:
        VarType m_sType = VarType(false, false, 0, typeid(void), 0u);
        std::string m_Name = {};
    };

    inline VarType::ValueType operator|(VarType::ValueType a, VarType::ValueType b)
    {return static_cast<VarType::ValueType>(static_cast<int>(a) | static_cast<int>(b));}

    inline VarType::ValueType operator&(VarType::ValueType a, VarType::ValueType b)
    {return static_cast<VarType::ValueType>(static_cast<int>(a) & static_cast<int>(b));}

    inline VarType::ValueType &operator|=(VarType::ValueType &a, VarType::ValueType b)
    {return reinterpret_cast<VarType::ValueType &>(reinterpret_cast<int &>(a) |= static_cast<int>(b));}

    inline VarType::ValueType &operator&=(VarType::ValueType &a, VarType::ValueType b)
    {return reinterpret_cast<VarType::ValueType &>(reinterpret_cast<int &>(a) &= static_cast<int>(b));}

    inline VarType::ValueType operator!(VarType::ValueType a)
    {return static_cast<VarType::ValueType>(!static_cast<int>(a));}
}
