cmake_minimum_required(VERSION 3.0)
project(struct_algo)

add_definitions(-Dundefined=0)

set(CMAKE_CXX_STANDARD 17)

if (UNIX AND NOT APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS "-static-libgcc -static-libstdc++")
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif ()

set(SOURCE_FILES
        expression/Expression.cpp
        expression/Expression.h
        expression/ValueExpression.h
        instruction/InstructionBlock.cpp
        instruction/InstructionBlock.h
        interface/AbstractDataTypeVisitor.h
        interface/AbstractOperation.h
        interface/AbstractOperationMember.h
        interface/AbstractOperationVisitor.h
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
        operation/Assign.cpp
        operation/Assign.h
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
        variable/Variable.cpp
        variable/Variable.h
        exception/BadCastParameters.cpp
        exception/BadCastParameters.h
        exception/InvalidExpression.cpp
        exception/InvalidExpression.h
        exception/TraductorException.cpp
        exception/TraductorException.h
        exception/ParametersCount.cpp
        exception/ParametersCount.h
        exception/BadModificator.cpp
        exception/BadModificator.h
        instruction/Conditional.cpp
        instruction/Conditional.h
        instruction/Loop.cpp
        instruction/Loop.h
        instruction/BreakLoop.cpp
        instruction/BreakLoop.h
        instruction/NextLoop.cpp
        instruction/NextLoop.h
        instruction/ForLoop.cpp
        instruction/ForLoop.h
        interface/Loopable.cpp
        interface/Loopable.h
        interface/LoopInstruction.cpp
        interface/LoopInstruction.h)
add_library(struct_algo SHARED ${SOURCE_FILES})
