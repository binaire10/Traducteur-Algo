#pragma once
#include "Expression.h"
#include <sstream>

namespace ElementAlgorithmique
{
    namespace MathExpression
    {
        template<typename INPUT>
        class CValue : public Expression
        {
        public:
            CValue(const INPUT &lValue) : Expression(VarType(false, true, 0, typeid(INPUT), 0u)), m_Value(lValue)
            {}

            void ToCppCode(std::ostream &Result) override
            {
                Result << m_Value;
            }
            bool isFinalValue() override
            {
                return true;
            }
        private:
            INPUT m_Value;
        };

        template<>
        class CValue<std::string> : public Expression
        {
        public:
            inline CValue(const std::string &lValue) : Expression(VarType(false, true, 0, typeid(std::string), 0u)), m_Value(lValue)
            {}

            inline void ToCppCode(std::ostream &Result) override
            {
                Result << '"' << m_Value << '"';
            }

            inline bool isFinalValue() override
            {
                return true;
            }
        private:
            std::string m_Value;
        };

        template<>
        class CValue<char> : public Expression
        {
        public:
            inline CValue(char lValue) : Expression(VarType(false, true, 0, typeid(char), 0u)), m_Value(lValue)
            {}

            inline void ToCppCode(std::ostream &Result) override
            {
                switch (m_Value)
                {
                case '\n':
                    Result << "'\n'";
                    break;
                case '\r':
                    Result << "'\r'";
                    break;
                case '\t':
                    Result << "'\t'";
                    break;
                case '\'':
                    Result << "'\\''";
                    break;
                default:
                    Result << '\'' << m_Value << '\'';
                    break;
                }
            }

            inline bool isFinalValue() override
            {
                return true;
            }
        private:
            char m_Value;
        };

        template<>
        class CValue<bool> : public Expression
        {
        public:
            inline CValue(char lValue) : Expression(VarType(false, true, 0, typeid(char), 0u)), m_Value(lValue)
            {}

            inline void ToCppCode(std::ostream &Result) override
            {
                Result << (m_Value ? "true" : "false");
            }

            inline bool isFinalValue() override
            {
                return true;
            }
        private:
            bool m_Value;
        };
    }
}
