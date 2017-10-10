cmake_minimum_required(VERSION 3.8)
project(Traducteur_Algo)

add_definitions(-Dundefined=0)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        expression/Expression.cpp
        expression/Expression.h
        expression/ValueExpression.h
        instruction/InstructionBlock.cpp
        instruction/InstructionBlock.h
        interface/AbstractDataTypeVisitor.h
        interface/AbstractOperation.h
        interface/AbstractOperationVisitor.h
        interface/AbstractOperator.h
        interface/AbstractOperatorVisitor.h
        interface/Expressionable.h
        interface/IExpressionVisitable.h
        interface/IExpressionVisitor.h
        interface/IFunction.h
        interface/IFunctionVisitable.h
        interface/IFunctionVisitor.h
        interface/IInstructionVisitable.h
        interface/IInstructionVisitor.h
        interface/Instructable.h
        operation/And.cpp
        operation/And.h
        operation/BitWiseOperation.cpp
        operation/BitWiseOperation.h
        operation/Division.cpp
        operation/Division.h
        operation/LogicOperation.cpp
        operation/LogicOperation.h
        operation/Multiplication.cpp
        operation/Multiplication.h
        operation/Not.cpp
        operation/Not.h
        operation/NumericOperation.cpp
        operation/NumericOperation.h
        operation/Or.cpp
        operation/Or.h
        operation/Substract.cpp
        operation/Substract.h
        operation/Sum.cpp
        operation/Sum.h
        type/AbstractDataType.cpp
        type/AbstractDataType.h
        type/AbstractDataTypeReference.cpp
        type/AbstractDataTypeReference.h
        type/Character.cpp
        type/Character.h
        type/ConstAbstractDataType.cpp
        type/ConstAbstractDataType.h
        type/DecimalDataType.cpp
        type/DecimalDataType.h
        type/NumericDataType.cpp
        type/NumericDataType.h
        type/ParametersUtility.cpp
        type/ParametersUtility.h
        type/ScalarDataType.cpp
        type/ScalarDataType.h
        Function.h
        main.cpp)

add_executable(Traducteur_Algo ${SOURCE_FILES})